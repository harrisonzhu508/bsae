// bym2_integrated.stan: Fully Bayesian integrated kernel with IID noise plus CV

functions {
  real xbinomial_logit_lpdf(real y, real m, real eta) {
    return(lchoose(m, y) + y * log(inv_logit(eta)) + (m - y) * log(1 - inv_logit(eta)));
  }
  
  matrix cov_matern32(matrix D, real l) {
    int n = rows(D);
    matrix[n, n] K;
    real norm_K;
    real sqrt3;
    sqrt3 = sqrt(3.0);
    
    for(i in 1:(n - 1)){
      // Diagonal entries (apart from the last)
      K[i, i] = 1;
      for(j in (i + 1):n){
        // Off-diagonal entries
        norm_K = D[i, j] / l;
        K[i, j] = (1 + sqrt3 * norm_K) * exp(-sqrt3 * norm_K); // Fill lower triangle
        K[j, i] = K[i, j]; // Fill upper triangle
      }
    }
    K[n, n] = 1;
    
    return(K);
  }
  
  matrix cov_sample_average(int n, int L, real l, matrix S) {
    matrix[n, n] K;
    matrix[L * n, L * n] kS = cov_matern32(S, l);

    // Diagonal entries
    for(i in 1:n){
      K[i, i] = mean(kS[(L * (i - 1) + 1):(i * L), (L * (i - 1) + 1):(i * L)]);
    }
  
    // Off-diagonal entries
    for(i in 1:(n - 1)) {
      for(j in (i + 1):n) {
        K[i, j] = mean(kS[(L * (i - 1) + 1):(i * L), (L * (j - 1) + 1):(j * L)]);
        K[j, i] = K[i, j]; 
      }
    }
    return(K);
  }
}

data {
  int<lower=0> n_obs; // Number of observed regions
  int<lower=0> n_mis; // Number of missing regions
  
  int<lower = 1, upper = n_obs + n_mis> ii_obs[n_obs];
  int<lower = 1, upper = n_obs + n_mis> ii_mis[n_mis];

  int<lower=0> n; // Number of regions n_obs + n_mis
  vector[n_obs] y_obs; // Vector of observed responses
  vector[n] m; // Vector of sample sizes
  vector[n] mu; // Prior mean vector
  int L; // Number of Monte Carlo samples
  matrix[n * L, n * L] S; // Distances between all points
}

parameters {
  vector<lower=0>[n_mis] y_mis; // Vector of missing responses
  real beta_0; // Intercept
  vector[n] u; // Structured spatial effects
  vector[n] v; // Unstructured spatial effects
  real<lower=0, upper=1> pi; // Proportion unstructured vs. structured variance
  real<lower=0> sigma_phi; // Standard deviation of spatial effects
  real<lower=0> l; // Kernel lengthscale
}

transformed parameters {
  vector[n] phi = sqrt(1 - pi) * v + sqrt(pi) * u; // Spatial effects
  vector[n] eta = beta_0 + sigma_phi * phi;
  
  vector[n] y;
  y[ii_obs] = y_obs;
  y[ii_mis] = y_mis;
}

model {
  matrix[n, n] K = cov_sample_average(n, L, l, S);
  // I could do this?
  // matrix[n, n] L = cholesky_decompose(K);
  // y ~ multi_normal_cholesky(mu, L);
  l ~ gamma(1, 1);
  sigma_phi ~ normal(0, 2.5); // Weakly informative prior
  beta_0 ~ normal(-2, 1);
  pi ~ beta(0.5, 0.5);
  v ~ normal(0, 1);
  u ~ multi_normal(mu, K);
  for(i in 1:n) {
    y[i] ~ xbinomial_logit(m[i], eta[i]); 
  }
}

generated quantities {
  real tau_phi = 1 / sigma_phi^2; // Precision of spatial effects
  vector[n] rho = inv_logit(beta_0 + sigma_phi * phi);
  vector[n] log_lik;
  for (i in 1:n) {
    log_lik[i] = xbinomial_logit_lpdf(y[i] | m[i], eta[i]);
  }
}

