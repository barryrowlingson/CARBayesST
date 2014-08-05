// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// linpredcompute
NumericVector linpredcompute(NumericMatrix X, const int nsites, const int p, NumericVector beta, NumericVector offset);
RcppExport SEXP CARBayesST_linpredcompute(SEXP XSEXP, SEXP nsitesSEXP, SEXP pSEXP, SEXP betaSEXP, SEXP offsetSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< NumericMatrix >::type X(XSEXP );
        Rcpp::traits::input_parameter< const int >::type nsites(nsitesSEXP );
        Rcpp::traits::input_parameter< const int >::type p(pSEXP );
        Rcpp::traits::input_parameter< NumericVector >::type beta(betaSEXP );
        Rcpp::traits::input_parameter< NumericVector >::type offset(offsetSEXP );
        NumericVector __result = linpredcompute(X, nsites, p, beta, offset);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// quadform
double quadform(IntegerVector W_duplet1, IntegerVector W_duplet2, const int n_duplet, const int nsites, NumericVector phi, NumericVector nneighbours, double diagonal, double offdiagonal);
RcppExport SEXP CARBayesST_quadform(SEXP W_duplet1SEXP, SEXP W_duplet2SEXP, SEXP n_dupletSEXP, SEXP nsitesSEXP, SEXP phiSEXP, SEXP nneighboursSEXP, SEXP diagonalSEXP, SEXP offdiagonalSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< IntegerVector >::type W_duplet1(W_duplet1SEXP );
        Rcpp::traits::input_parameter< IntegerVector >::type W_duplet2(W_duplet2SEXP );
        Rcpp::traits::input_parameter< const int >::type n_duplet(n_dupletSEXP );
        Rcpp::traits::input_parameter< const int >::type nsites(nsitesSEXP );
        Rcpp::traits::input_parameter< NumericVector >::type phi(phiSEXP );
        Rcpp::traits::input_parameter< NumericVector >::type nneighbours(nneighboursSEXP );
        Rcpp::traits::input_parameter< double >::type diagonal(diagonalSEXP );
        Rcpp::traits::input_parameter< double >::type offdiagonal(offdiagonalSEXP );
        double __result = quadform(W_duplet1, W_duplet2, n_duplet, nsites, phi, nneighbours, diagonal, offdiagonal);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// poissoncarupdate
List poissoncarupdate(List W_list, const int nsites, NumericVector phi, double tau2, const NumericVector y, const double phi_tune, double rho_num, double rho_den, NumericVector offset);
RcppExport SEXP CARBayesST_poissoncarupdate(SEXP W_listSEXP, SEXP nsitesSEXP, SEXP phiSEXP, SEXP tau2SEXP, SEXP ySEXP, SEXP phi_tuneSEXP, SEXP rho_numSEXP, SEXP rho_denSEXP, SEXP offsetSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< List >::type W_list(W_listSEXP );
        Rcpp::traits::input_parameter< const int >::type nsites(nsitesSEXP );
        Rcpp::traits::input_parameter< NumericVector >::type phi(phiSEXP );
        Rcpp::traits::input_parameter< double >::type tau2(tau2SEXP );
        Rcpp::traits::input_parameter< const NumericVector >::type y(ySEXP );
        Rcpp::traits::input_parameter< const double >::type phi_tune(phi_tuneSEXP );
        Rcpp::traits::input_parameter< double >::type rho_num(rho_numSEXP );
        Rcpp::traits::input_parameter< double >::type rho_den(rho_denSEXP );
        Rcpp::traits::input_parameter< NumericVector >::type offset(offsetSEXP );
        List __result = poissoncarupdate(W_list, nsites, phi, tau2, y, phi_tune, rho_num, rho_den, offset);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// poissonindepupdate
List poissonindepupdate(const int nsites, NumericVector theta, double tau2, const NumericVector y, const double theta_tune, NumericVector offset);
RcppExport SEXP CARBayesST_poissonindepupdate(SEXP nsitesSEXP, SEXP thetaSEXP, SEXP tau2SEXP, SEXP ySEXP, SEXP theta_tuneSEXP, SEXP offsetSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< const int >::type nsites(nsitesSEXP );
        Rcpp::traits::input_parameter< NumericVector >::type theta(thetaSEXP );
        Rcpp::traits::input_parameter< double >::type tau2(tau2SEXP );
        Rcpp::traits::input_parameter< const NumericVector >::type y(ySEXP );
        Rcpp::traits::input_parameter< const double >::type theta_tune(theta_tuneSEXP );
        Rcpp::traits::input_parameter< NumericVector >::type offset(offsetSEXP );
        List __result = poissonindepupdate(nsites, theta, tau2, y, theta_tune, offset);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// poissonbetaupdate
double poissonbetaupdate(NumericMatrix X, const int nsites, const int p, NumericVector beta, NumericVector proposal, NumericVector offset, NumericVector y, NumericVector prior_meanbeta, NumericVector prior_varbeta);
RcppExport SEXP CARBayesST_poissonbetaupdate(SEXP XSEXP, SEXP nsitesSEXP, SEXP pSEXP, SEXP betaSEXP, SEXP proposalSEXP, SEXP offsetSEXP, SEXP ySEXP, SEXP prior_meanbetaSEXP, SEXP prior_varbetaSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< NumericMatrix >::type X(XSEXP );
        Rcpp::traits::input_parameter< const int >::type nsites(nsitesSEXP );
        Rcpp::traits::input_parameter< const int >::type p(pSEXP );
        Rcpp::traits::input_parameter< NumericVector >::type beta(betaSEXP );
        Rcpp::traits::input_parameter< NumericVector >::type proposal(proposalSEXP );
        Rcpp::traits::input_parameter< NumericVector >::type offset(offsetSEXP );
        Rcpp::traits::input_parameter< NumericVector >::type y(ySEXP );
        Rcpp::traits::input_parameter< NumericVector >::type prior_meanbeta(prior_meanbetaSEXP );
        Rcpp::traits::input_parameter< NumericVector >::type prior_varbeta(prior_varbetaSEXP );
        double __result = poissonbetaupdate(X, nsites, p, beta, proposal, offset, y, prior_meanbeta, prior_varbeta);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// Zupdate
NumericMatrix Zupdate(NumericMatrix Z, NumericMatrix Offset, NumericMatrix Y, const double alpha, NumericMatrix lambda, const int nsites, const int ntime, const int G, NumericVector SS, double Gstar);
RcppExport SEXP CARBayesST_Zupdate(SEXP ZSEXP, SEXP OffsetSEXP, SEXP YSEXP, SEXP alphaSEXP, SEXP lambdaSEXP, SEXP nsitesSEXP, SEXP ntimeSEXP, SEXP GSEXP, SEXP SSSEXP, SEXP GstarSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< NumericMatrix >::type Z(ZSEXP );
        Rcpp::traits::input_parameter< NumericMatrix >::type Offset(OffsetSEXP );
        Rcpp::traits::input_parameter< NumericMatrix >::type Y(YSEXP );
        Rcpp::traits::input_parameter< const double >::type alpha(alphaSEXP );
        Rcpp::traits::input_parameter< NumericMatrix >::type lambda(lambdaSEXP );
        Rcpp::traits::input_parameter< const int >::type nsites(nsitesSEXP );
        Rcpp::traits::input_parameter< const int >::type ntime(ntimeSEXP );
        Rcpp::traits::input_parameter< const int >::type G(GSEXP );
        Rcpp::traits::input_parameter< NumericVector >::type SS(SSSEXP );
        Rcpp::traits::input_parameter< double >::type Gstar(GstarSEXP );
        NumericMatrix __result = Zupdate(Z, Offset, Y, alpha, lambda, nsites, ntime, G, SS, Gstar);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// alphaupdate
double alphaupdate(IntegerMatrix Z, const int nsites, NumericMatrix logratio, const int ntime);
RcppExport SEXP CARBayesST_alphaupdate(SEXP ZSEXP, SEXP nsitesSEXP, SEXP logratioSEXP, SEXP ntimeSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< IntegerMatrix >::type Z(ZSEXP );
        Rcpp::traits::input_parameter< const int >::type nsites(nsitesSEXP );
        Rcpp::traits::input_parameter< NumericMatrix >::type logratio(logratioSEXP );
        Rcpp::traits::input_parameter< const int >::type ntime(ntimeSEXP );
        double __result = alphaupdate(Z, nsites, logratio, ntime);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// Xupdate
List Xupdate(NumericMatrix Wspace, NumericMatrix Y, NumericMatrix offset, const int K, const int N, NumericMatrix X, double tau2, double proposalsdX);
RcppExport SEXP CARBayesST_Xupdate(SEXP WspaceSEXP, SEXP YSEXP, SEXP offsetSEXP, SEXP KSEXP, SEXP NSEXP, SEXP XSEXP, SEXP tau2SEXP, SEXP proposalsdXSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< NumericMatrix >::type Wspace(WspaceSEXP );
        Rcpp::traits::input_parameter< NumericMatrix >::type Y(YSEXP );
        Rcpp::traits::input_parameter< NumericMatrix >::type offset(offsetSEXP );
        Rcpp::traits::input_parameter< const int >::type K(KSEXP );
        Rcpp::traits::input_parameter< const int >::type N(NSEXP );
        Rcpp::traits::input_parameter< NumericMatrix >::type X(XSEXP );
        Rcpp::traits::input_parameter< double >::type tau2(tau2SEXP );
        Rcpp::traits::input_parameter< double >::type proposalsdX(proposalsdXSEXP );
        List __result = Xupdate(Wspace, Y, offset, K, N, X, tau2, proposalsdX);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}