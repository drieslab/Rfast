//Author: Manos Papadakis

// This file was generated by compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>
#include "mn.h"

using namespace Rcpp;
using namespace std;
using namespace arma;

//[[Rcpp::export]]
vector<double> poisson_only(mat x, colvec y,long double ylogy){
  unsigned int i,d=2,n=x.n_rows,pcols=x.n_cols;
  char e='e';
  mat z(n,2),inv_L2(d,d),tmp,ytr=y.t();
  vec m(n),z_col_1(n);
  vector<double> L(pcols);
  vector<double>::iterator LL=L.begin();
  double dif,sm=0.0,szm=0.0,sz2m=0.0,t,lgmeany=log(mean(y));
  colvec b_old(d),b_new(d),L1(d),yhat(n);
  z.col(0)=ones(n);
  for(i=0;i<pcols;++i,++LL){
  	b_old(0)=lgmeany;
  	b_old(1)=0;
    z.col(1)=x.col(i);
    z_col_1=z.col(1);
    for(dif=1.0;dif>0.000000001;){
      sm=szm=sz2m=0.0;
      yhat=z*b_old;
      m=(e^yhat);
      L1=z.t()*(y-m);
      sm=sum(m);
      szm=sum(m*z_col_1);
      sz2m=sum(m*(z_col_1^2));
      t=1.0/(sm*sz2m-szm*szm);
      inv_L2.at(0,0)=sz2m*t;
      inv_L2.at(0,1)=inv_L2.at(1,0)=-szm*t;
      inv_L2.at(1,1)=sm*t;
      b_new=b_old+inv_L2*L1;
      dif=sum(abs(b_new-b_old));
      b_old=b_new;
    }
    *LL=2.0*(ylogy-y*yhat);
  }
  return L;
}

// poisson
RcppExport SEXP Rfast_poisson_only(SEXP xSEXP,SEXP ySEXP,SEXP ylogySEXP) {
BEGIN_RCPP
    RObject __result;
    RNGScope __rngScope;
    traits::input_parameter< mat >::type x(xSEXP);
    traits::input_parameter< colvec >::type y(ySEXP);
    traits::input_parameter< long double >::type ylogy(ylogySEXP);
    __result = wrap(poisson_only(x,y,ylogy));
    return __result;
END_RCPP
}
