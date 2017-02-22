//Author: Manos Papadakis

#include <RcppArmadillo.h>
#include <vector>

using namespace Rcpp;
using namespace std;
using namespace arma;

// [[Rcpp::export]]
NumericVector rowMaxs(NumericMatrix x,const bool value){
  unsigned int i;
  const unsigned int p=x.nrow();
  mat X = mat(x.begin(), p, x.ncol(), false); 
  NumericVector F(p);
  NumericVector::iterator FF=F.begin();
  if(value){
  	colvec f=max(X,1);
  	colvec::iterator ff=f.begin();
  	for(;FF!=F.end();++FF,++ff)
      *FF=*ff;
  }else
    for(i=0;i<p;++i,++FF)
      *FF=(X.row(i)).index_max()+1;
  return F;
}

RcppExport SEXP Rfast_rowMaxs(SEXP xSEXP,SEXP valueSEXP) {
BEGIN_RCPP
    RObject __result;
    RNGScope __rngScope;
    traits::input_parameter< NumericMatrix >::type x(xSEXP);
    traits::input_parameter< const bool >::type value(valueSEXP);
    __result = wrap(rowMaxs(x,value));
    return __result;
END_RCPP
}
