% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/m4_wicar.R
\name{m4_stan}
\alias{m4_stan}
\title{Fit weighted ICAR Small Area Estimation model using \code{stan}.}
\usage{
m4_stan(sf, nsim_warm = 100, nsim_iter = 1000)
}
\arguments{
\item{sf}{A simple features object with some geometry.}

\item{nsim_warm}{Number of warmup samples, passed to \code{stan}.}

\item{nsim_iter}{Number of samples, passed to \code{stan}.}
}
\description{
Fit weighted ICAR Small Area Estimation model using \code{stan}.
}
\examples{
m4_stan(mw, nsim_warm = 0, nsim_iter = 100)
}
