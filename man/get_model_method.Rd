% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/processing.R
\name{get_model_method}
\alias{get_model_method}
\title{Helper function to extract model fitted and methodology used from a string.}
\usage{
get_model_method(string)
}
\arguments{
\item{string}{A string containing the method name followed by the model
name, seperated by a "-". For example \code{"stan_2"}.}
}
\value{
A list containing \code{method_name} and \code{model_name}.
}
\description{
Helper function to extract model fitted and methodology used from a string.
}
\examples{
get_model_method("inla_1")
}
