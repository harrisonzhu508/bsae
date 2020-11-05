// model2.stan: ICAR

data {
  int<lower=1> n; // Number of regions
  int y[n]; // Vector of responses
  int m[n]; // Vector of sample sizes
  
  // Data structure for graph input
  int<lower=1> n_edges;
  int<lower=1, upper=n> node1[n_edges];
  int<lower=1, upper=n> node2[n_edges];
  
  real<lower=0> scaling_factor; // Scales variance of structured spatial effects
}

parameters {
  real beta_0; // Intercept
  vector[n] u; // Unscaled spatial effects
  real<lower=0> sigma_phi; // Standard deviation of spatial effects
}

transformed parameters {
  vector[n] phi = sqrt(1 / scaling_factor) * u; // Spatial effects
  real tau_phi = 1 / sigma_phi^2; // Precision of spatial effects
}

model {
  y ~ binomial_logit(m, beta_0 + sigma_phi * phi);
  
  target += -0.5 * dot_self(u[node1] - u[node2]); // Spatial prior when sigma_phi = 1
  // i.e. this is the covariance matrix we compute the GV of when scaling
  sum(u) ~ normal(0, 0.001 * n); // Soft sum-to-zero constraint
  
  beta_0 ~ normal(-2, 1);
  sigma_phi ~ normal(0, 2.5); // Weakly informative prior
}

generated quantities {
  vector[n] rho = inv_logit(beta_0 + sigma_phi * phi);
  vector[n] log_lik;
  for (i in 1:n) {
    log_lik[i] = binomial_logit_lpmf(y[i] | m[i], beta_0 + sigma_phi * phi[i]);
  }
}