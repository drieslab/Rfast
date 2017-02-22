//Author: Manos Papadakis

#include <RcppArmadillo.h>
#include <vector>
#include <algorithm>

using namespace Rcpp;
using namespace std;

//[[Rcpp::export]]
double med(vector<double> x){
  double F;
  const int sz=x.size(),middle=sz/2-1;
  if(sz%2==0){
    nth_element(x.begin(),x.begin()+middle,x.end());
    F=(x[middle]+*(min_element(x.begin()+middle+1,x.end())))/2.0;
  }else{
    nth_element(x.begin(),x.begin()+middle+1,x.end());
    F=x[middle+1];
  }
  return F;
}

//returns median of a vector
RcppExport SEXP Rfast_med(SEXP xSEXP) {
BEGIN_RCPP
    RObject __result;
    RNGScope __rngScope;
    traits::input_parameter< vector<double> >::type x(xSEXP);
    __result = wrap(med(x));
    return __result;
END_RCPP
}
