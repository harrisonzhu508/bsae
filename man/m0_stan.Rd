% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/m0_constant.R
\name{m0_stan}
\alias{m0_stan}
\title{Fit constant Small Area Estimation model using \code{stan}.}
\usage{
m0_stan(sf, nsim_warm = 100, nsim_iter = 1000)
}
\arguments{
\item{sf}{A simple features object with some geometry.}

\item{nsim_warm}{Number of warmup samples, passed to \code{stan}.}

\item{nsim_iter}{Number of samples, passed to \code{stan}.}
}
\description{
Simply fits a constant (the mean). This is useful as a benchmark
for other models.
}
\examples{
m0_stan(mw)
}
