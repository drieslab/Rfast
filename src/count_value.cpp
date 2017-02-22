//Author: Manos Papadakis

#include <RcppArmadillo.h>
#include <Rcpp.h>
#include <vector>

using namespace Rcpp;

//[[Rcpp::export]]
int count_value(std::vector<double> x,double value){
  int s=0;
  for(std::vector<double>::iterator a=x.begin();a!=x.end();++a)
    if(*a==value)
      s++;
  return s;
}

RcppExport SEXP Rfast_count_value(SEXP xSEXP,SEXP valueSEXP){
BEGIN_RCPP
    RObject __result;
    RNGScope __rngScope;
    traits::input_parameter< std::vector<double> >::type x(xSEXP);
    traits::input_parameter< double >::type value(valueSEXP);
    __result = wrap(count_value(x,value));
    return __result;
END_RCPP
}
