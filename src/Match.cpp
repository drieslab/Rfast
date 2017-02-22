//Author: Manos Papadakis

#include <RcppArmadillo.h>
#include <algorithm>
#include <vector>

using namespace Rcpp;
using namespace std;

//[[Rcpp::export]]
vector<int> Match(NumericVector x,IntegerVector key){
  vector<int> f(key.size());
  vector<int>::iterator F=f.begin();
  IntegerVector::iterator a=key.begin();
  NumericVector::iterator bg=x.begin();
  sort(x.begin(),x.end());
  for(;a!=key.end();++a,++F)
    *F=lower_bound(bg,x.end(),*a)-bg+1;
  return f;
}

RcppExport SEXP Rfast_Match(SEXP xSEXP,SEXP keySEXP) {
BEGIN_RCPP
    RObject __result;
    RNGScope __rngScope;
    traits::input_parameter< NumericVector >::type x(xSEXP);
    traits::input_parameter< IntegerVector >::type key(keySEXP);
    __result = wrap(Match(x,key));
    return __result;
END_RCPP
}
