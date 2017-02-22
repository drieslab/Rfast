//Author: Manos Papadakis

#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace std;
using namespace arma;

// [[Rcpp::export]]
arma::rowvec colsums(NumericMatrix x){
  arma::mat X = mat(x.begin(), x.nrow(), x.ncol(), false); 
  return sum(X, 0); 
}

RcppExport SEXP Rfast_colsums(SEXP xSEXP) {
BEGIN_RCPP
    RObject __result;
    RNGScope __rngScope;
    traits::input_parameter< NumericMatrix >::type x(xSEXP);
    __result = wrap(colsums(x));
    return __result;
END_RCPP
}
