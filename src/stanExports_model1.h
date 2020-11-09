// Generated by rstantools.  Do not edit by hand.

/*
    bsae is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    bsae is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with bsae.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.21.0
#include <stan/model/model_header.hpp>
namespace model_model1_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_model1");
    reader.add_event(54, 52, "end", "model_model1");
    return reader;
}
template <bool propto, typename T0__, typename T1__, typename T2__>
typename boost::math::tools::promote_args<T0__, T1__, T2__>::type
xbinomial_logit_lpdf(const T0__& y,
                         const T1__& m,
                         const T2__& eta, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__, T1__, T2__>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
    int current_statement_begin__ = -1;
    try {
        current_statement_begin__ = 5;
        return stan::math::promote_scalar<fun_return_scalar_t__>(((binomial_coefficient_log(m, y) + (y * stan::math::log(inv_logit(eta)))) + ((m - y) * stan::math::log((1 - inv_logit(eta))))));
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}
template <typename T0__, typename T1__, typename T2__>
typename boost::math::tools::promote_args<T0__, T1__, T2__>::type
xbinomial_logit_lpdf(const T0__& y,
                         const T1__& m,
                         const T2__& eta, std::ostream* pstream__) {
    return xbinomial_logit_lpdf<false>(y,m,eta, pstream__);
}
struct xbinomial_logit_lpdf_functor__ {
    template <bool propto, typename T0__, typename T1__, typename T2__>
        typename boost::math::tools::promote_args<T0__, T1__, T2__>::type
    operator()(const T0__& y,
                         const T1__& m,
                         const T2__& eta, std::ostream* pstream__) const {
        return xbinomial_logit_lpdf(y, m, eta, pstream__);
    }
};
#include <stan_meta_header.hpp>
class model_model1
  : public stan::model::model_base_crtp<model_model1> {
private:
        int n_obs;
        int n_mis;
        std::vector<int> ii_obs;
        std::vector<int> ii_mis;
        int n;
        vector_d y_obs;
        vector_d m;
public:
    model_model1(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_model1(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_model1_namespace::model_model1";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 10;
            context__.validate_dims("data initialization", "n_obs", "int", context__.to_vec());
            n_obs = int(0);
            vals_i__ = context__.vals_i("n_obs");
            pos__ = 0;
            n_obs = vals_i__[pos__++];
            check_greater_or_equal(function__, "n_obs", n_obs, 0);
            current_statement_begin__ = 11;
            context__.validate_dims("data initialization", "n_mis", "int", context__.to_vec());
            n_mis = int(0);
            vals_i__ = context__.vals_i("n_mis");
            pos__ = 0;
            n_mis = vals_i__[pos__++];
            check_greater_or_equal(function__, "n_mis", n_mis, 0);
            current_statement_begin__ = 13;
            validate_non_negative_index("ii_obs", "n_obs", n_obs);
            context__.validate_dims("data initialization", "ii_obs", "int", context__.to_vec(n_obs));
            ii_obs = std::vector<int>(n_obs, int(0));
            vals_i__ = context__.vals_i("ii_obs");
            pos__ = 0;
            size_t ii_obs_k_0_max__ = n_obs;
            for (size_t k_0__ = 0; k_0__ < ii_obs_k_0_max__; ++k_0__) {
                ii_obs[k_0__] = vals_i__[pos__++];
            }
            size_t ii_obs_i_0_max__ = n_obs;
            for (size_t i_0__ = 0; i_0__ < ii_obs_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "ii_obs[i_0__]", ii_obs[i_0__], 1);
                check_less_or_equal(function__, "ii_obs[i_0__]", ii_obs[i_0__], (n_obs + n_mis));
            }
            current_statement_begin__ = 14;
            validate_non_negative_index("ii_mis", "n_mis", n_mis);
            context__.validate_dims("data initialization", "ii_mis", "int", context__.to_vec(n_mis));
            ii_mis = std::vector<int>(n_mis, int(0));
            vals_i__ = context__.vals_i("ii_mis");
            pos__ = 0;
            size_t ii_mis_k_0_max__ = n_mis;
            for (size_t k_0__ = 0; k_0__ < ii_mis_k_0_max__; ++k_0__) {
                ii_mis[k_0__] = vals_i__[pos__++];
            }
            size_t ii_mis_i_0_max__ = n_mis;
            for (size_t i_0__ = 0; i_0__ < ii_mis_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "ii_mis[i_0__]", ii_mis[i_0__], 1);
                check_less_or_equal(function__, "ii_mis[i_0__]", ii_mis[i_0__], (n_obs + n_mis));
            }
            current_statement_begin__ = 16;
            context__.validate_dims("data initialization", "n", "int", context__.to_vec());
            n = int(0);
            vals_i__ = context__.vals_i("n");
            pos__ = 0;
            n = vals_i__[pos__++];
            check_greater_or_equal(function__, "n", n, 0);
            current_statement_begin__ = 17;
            validate_non_negative_index("y_obs", "n_obs", n_obs);
            context__.validate_dims("data initialization", "y_obs", "vector_d", context__.to_vec(n_obs));
            y_obs = Eigen::Matrix<double, Eigen::Dynamic, 1>(n_obs);
            vals_r__ = context__.vals_r("y_obs");
            pos__ = 0;
            size_t y_obs_j_1_max__ = n_obs;
            for (size_t j_1__ = 0; j_1__ < y_obs_j_1_max__; ++j_1__) {
                y_obs(j_1__) = vals_r__[pos__++];
            }
            current_statement_begin__ = 18;
            validate_non_negative_index("m", "n", n);
            context__.validate_dims("data initialization", "m", "vector_d", context__.to_vec(n));
            m = Eigen::Matrix<double, Eigen::Dynamic, 1>(n);
            vals_r__ = context__.vals_r("m");
            pos__ = 0;
            size_t m_j_1_max__ = n;
            for (size_t j_1__ = 0; j_1__ < m_j_1_max__; ++j_1__) {
                m(j_1__) = vals_r__[pos__++];
            }
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 22;
            validate_non_negative_index("y_mis", "n_mis", n_mis);
            num_params_r__ += n_mis;
            current_statement_begin__ = 23;
            num_params_r__ += 1;
            current_statement_begin__ = 24;
            validate_non_negative_index("phi", "n", n);
            num_params_r__ += n;
            current_statement_begin__ = 25;
            num_params_r__ += 1;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_model1() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 22;
        if (!(context__.contains_r("y_mis")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable y_mis missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("y_mis");
        pos__ = 0U;
        validate_non_negative_index("y_mis", "n_mis", n_mis);
        context__.validate_dims("parameter initialization", "y_mis", "vector_d", context__.to_vec(n_mis));
        Eigen::Matrix<double, Eigen::Dynamic, 1> y_mis(n_mis);
        size_t y_mis_j_1_max__ = n_mis;
        for (size_t j_1__ = 0; j_1__ < y_mis_j_1_max__; ++j_1__) {
            y_mis(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_lb_unconstrain(0, y_mis);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable y_mis: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 23;
        if (!(context__.contains_r("beta_0")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable beta_0 missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("beta_0");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "beta_0", "double", context__.to_vec());
        double beta_0(0);
        beta_0 = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(beta_0);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable beta_0: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 24;
        if (!(context__.contains_r("phi")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable phi missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("phi");
        pos__ = 0U;
        validate_non_negative_index("phi", "n", n);
        context__.validate_dims("parameter initialization", "phi", "vector_d", context__.to_vec(n));
        Eigen::Matrix<double, Eigen::Dynamic, 1> phi(n);
        size_t phi_j_1_max__ = n;
        for (size_t j_1__ = 0; j_1__ < phi_j_1_max__; ++j_1__) {
            phi(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(phi);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable phi: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 25;
        if (!(context__.contains_r("sigma_phi")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable sigma_phi missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("sigma_phi");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "sigma_phi", "double", context__.to_vec());
        double sigma_phi(0);
        sigma_phi = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, sigma_phi);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable sigma_phi: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 22;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> y_mis;
            (void) y_mis;  // dummy to suppress unused var warning
            if (jacobian__)
                y_mis = in__.vector_lb_constrain(0, n_mis, lp__);
            else
                y_mis = in__.vector_lb_constrain(0, n_mis);
            current_statement_begin__ = 23;
            local_scalar_t__ beta_0;
            (void) beta_0;  // dummy to suppress unused var warning
            if (jacobian__)
                beta_0 = in__.scalar_constrain(lp__);
            else
                beta_0 = in__.scalar_constrain();
            current_statement_begin__ = 24;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> phi;
            (void) phi;  // dummy to suppress unused var warning
            if (jacobian__)
                phi = in__.vector_constrain(n, lp__);
            else
                phi = in__.vector_constrain(n);
            current_statement_begin__ = 25;
            local_scalar_t__ sigma_phi;
            (void) sigma_phi;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_phi = in__.scalar_lb_constrain(0, lp__);
            else
                sigma_phi = in__.scalar_lb_constrain(0);
            // transformed parameters
            current_statement_begin__ = 29;
            validate_non_negative_index("eta", "n", n);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> eta(n);
            stan::math::initialize(eta, DUMMY_VAR__);
            stan::math::fill(eta, DUMMY_VAR__);
            stan::math::assign(eta,add(beta_0, multiply(sigma_phi, phi)));
            current_statement_begin__ = 31;
            validate_non_negative_index("y", "n", n);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> y(n);
            stan::math::initialize(y, DUMMY_VAR__);
            stan::math::fill(y, DUMMY_VAR__);
            // transformed parameters block statements
            current_statement_begin__ = 32;
            stan::model::assign(y, 
                        stan::model::cons_list(stan::model::index_multi(ii_obs), stan::model::nil_index_list()), 
                        y_obs, 
                        "assigning variable y");
            current_statement_begin__ = 33;
            stan::model::assign(y, 
                        stan::model::cons_list(stan::model::index_multi(ii_mis), stan::model::nil_index_list()), 
                        y_mis, 
                        "assigning variable y");
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 29;
            size_t eta_j_1_max__ = n;
            for (size_t j_1__ = 0; j_1__ < eta_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(eta(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: eta" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable eta: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            current_statement_begin__ = 31;
            size_t y_j_1_max__ = n;
            for (size_t j_1__ = 0; j_1__ < y_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(y(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: y" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable y: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            // model body
            current_statement_begin__ = 37;
            for (int i = 1; i <= n; ++i) {
                current_statement_begin__ = 38;
                lp_accum__.add(xbinomial_logit_lpdf<propto__>(get_base1(y, i, "y", 1), get_base1(m, i, "m", 1), get_base1(eta, i, "eta", 1), pstream__));
            }
            current_statement_begin__ = 40;
            lp_accum__.add(normal_log<propto__>(phi, 0, 1));
            current_statement_begin__ = 41;
            lp_accum__.add(normal_log<propto__>(beta_0, -(2), 1));
            current_statement_begin__ = 42;
            lp_accum__.add(normal_log<propto__>(sigma_phi, 0, 2.5));
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("y_mis");
        names__.push_back("beta_0");
        names__.push_back("phi");
        names__.push_back("sigma_phi");
        names__.push_back("eta");
        names__.push_back("y");
        names__.push_back("tau_phi");
        names__.push_back("rho");
        names__.push_back("log_lik");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(n_mis);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_model1_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> y_mis = in__.vector_lb_constrain(0, n_mis);
        size_t y_mis_j_1_max__ = n_mis;
        for (size_t j_1__ = 0; j_1__ < y_mis_j_1_max__; ++j_1__) {
            vars__.push_back(y_mis(j_1__));
        }
        double beta_0 = in__.scalar_constrain();
        vars__.push_back(beta_0);
        Eigen::Matrix<double, Eigen::Dynamic, 1> phi = in__.vector_constrain(n);
        size_t phi_j_1_max__ = n;
        for (size_t j_1__ = 0; j_1__ < phi_j_1_max__; ++j_1__) {
            vars__.push_back(phi(j_1__));
        }
        double sigma_phi = in__.scalar_lb_constrain(0);
        vars__.push_back(sigma_phi);
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            // declare and define transformed parameters
            current_statement_begin__ = 29;
            validate_non_negative_index("eta", "n", n);
            Eigen::Matrix<double, Eigen::Dynamic, 1> eta(n);
            stan::math::initialize(eta, DUMMY_VAR__);
            stan::math::fill(eta, DUMMY_VAR__);
            stan::math::assign(eta,add(beta_0, multiply(sigma_phi, phi)));
            current_statement_begin__ = 31;
            validate_non_negative_index("y", "n", n);
            Eigen::Matrix<double, Eigen::Dynamic, 1> y(n);
            stan::math::initialize(y, DUMMY_VAR__);
            stan::math::fill(y, DUMMY_VAR__);
            // do transformed parameters statements
            current_statement_begin__ = 32;
            stan::model::assign(y, 
                        stan::model::cons_list(stan::model::index_multi(ii_obs), stan::model::nil_index_list()), 
                        y_obs, 
                        "assigning variable y");
            current_statement_begin__ = 33;
            stan::model::assign(y, 
                        stan::model::cons_list(stan::model::index_multi(ii_mis), stan::model::nil_index_list()), 
                        y_mis, 
                        "assigning variable y");
            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            // write transformed parameters
            if (include_tparams__) {
                size_t eta_j_1_max__ = n;
                for (size_t j_1__ = 0; j_1__ < eta_j_1_max__; ++j_1__) {
                    vars__.push_back(eta(j_1__));
                }
                size_t y_j_1_max__ = n;
                for (size_t j_1__ = 0; j_1__ < y_j_1_max__; ++j_1__) {
                    vars__.push_back(y(j_1__));
                }
            }
            if (!include_gqs__) return;
            // declare and define generated quantities
            current_statement_begin__ = 46;
            double tau_phi;
            (void) tau_phi;  // dummy to suppress unused var warning
            stan::math::initialize(tau_phi, DUMMY_VAR__);
            stan::math::fill(tau_phi, DUMMY_VAR__);
            stan::math::assign(tau_phi,(1 / pow(sigma_phi, 2)));
            current_statement_begin__ = 47;
            validate_non_negative_index("rho", "n", n);
            Eigen::Matrix<double, Eigen::Dynamic, 1> rho(n);
            stan::math::initialize(rho, DUMMY_VAR__);
            stan::math::fill(rho, DUMMY_VAR__);
            stan::math::assign(rho,inv_logit(eta));
            current_statement_begin__ = 48;
            validate_non_negative_index("log_lik", "n", n);
            Eigen::Matrix<double, Eigen::Dynamic, 1> log_lik(n);
            stan::math::initialize(log_lik, DUMMY_VAR__);
            stan::math::fill(log_lik, DUMMY_VAR__);
            // generated quantities statements
            current_statement_begin__ = 49;
            for (int i = 1; i <= n; ++i) {
                current_statement_begin__ = 50;
                stan::model::assign(log_lik, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            xbinomial_logit_lpdf(get_base1(y, i, "y", 1), get_base1(m, i, "m", 1), get_base1(eta, i, "eta", 1), pstream__), 
                            "assigning variable log_lik");
            }
            // validate, write generated quantities
            current_statement_begin__ = 46;
            vars__.push_back(tau_phi);
            current_statement_begin__ = 47;
            size_t rho_j_1_max__ = n;
            for (size_t j_1__ = 0; j_1__ < rho_j_1_max__; ++j_1__) {
                vars__.push_back(rho(j_1__));
            }
            current_statement_begin__ = 48;
            size_t log_lik_j_1_max__ = n;
            for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
                vars__.push_back(log_lik(j_1__));
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    std::string model_name() const {
        return "model_model1";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t y_mis_j_1_max__ = n_mis;
        for (size_t j_1__ = 0; j_1__ < y_mis_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "y_mis" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "beta_0";
        param_names__.push_back(param_name_stream__.str());
        size_t phi_j_1_max__ = n;
        for (size_t j_1__ = 0; j_1__ < phi_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "phi" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_phi";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t eta_j_1_max__ = n;
            for (size_t j_1__ = 0; j_1__ < eta_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "eta" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t y_j_1_max__ = n;
            for (size_t j_1__ = 0; j_1__ < y_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "y" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "tau_phi";
        param_names__.push_back(param_name_stream__.str());
        size_t rho_j_1_max__ = n;
        for (size_t j_1__ = 0; j_1__ < rho_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "rho" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t log_lik_j_1_max__ = n;
        for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "log_lik" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t y_mis_j_1_max__ = n_mis;
        for (size_t j_1__ = 0; j_1__ < y_mis_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "y_mis" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "beta_0";
        param_names__.push_back(param_name_stream__.str());
        size_t phi_j_1_max__ = n;
        for (size_t j_1__ = 0; j_1__ < phi_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "phi" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_phi";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t eta_j_1_max__ = n;
            for (size_t j_1__ = 0; j_1__ < eta_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "eta" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t y_j_1_max__ = n;
            for (size_t j_1__ = 0; j_1__ < y_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "y" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "tau_phi";
        param_names__.push_back(param_name_stream__.str());
        size_t rho_j_1_max__ = n;
        for (size_t j_1__ = 0; j_1__ < rho_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "rho" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t log_lik_j_1_max__ = n;
        for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "log_lik" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
    }
}; // model
}  // namespace
typedef model_model1_namespace::model_model1 stan_model;
#ifndef USING_R
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
#endif
#endif
