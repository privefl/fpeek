// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// nlines_
int nlines_(std::string filename);
RcppExport SEXP _fpeek_nlines_(SEXP filenameSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type filename(filenameSEXP);
    rcpp_result_gen = Rcpp::wrap(nlines_(filename));
    return rcpp_result_gen;
END_RCPP
}
// head_str_
std::vector< std::string> head_str_(std::string filename, int n);
RcppExport SEXP _fpeek_head_str_(SEXP filenameSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type filename(filenameSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(head_str_(filename, n));
    return rcpp_result_gen;
END_RCPP
}
// head_print_
void head_print_(std::string filename, int n);
RcppExport SEXP _fpeek_head_print_(SEXP filenameSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type filename(filenameSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    head_print_(filename, n);
    return R_NilValue;
END_RCPP
}
// tail_str_
std::vector< std::string> tail_str_(std::string filename, int n);
RcppExport SEXP _fpeek_tail_str_(SEXP filenameSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type filename(filenameSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(tail_str_(filename, n));
    return rcpp_result_gen;
END_RCPP
}
// tail_print_
void tail_print_(std::string filename, int n);
RcppExport SEXP _fpeek_tail_print_(SEXP filenameSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type filename(filenameSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    tail_print_(filename, n);
    return R_NilValue;
END_RCPP
}
// grep_print_
void grep_print_(std::string filename, std::string regexp);
RcppExport SEXP _fpeek_grep_print_(SEXP filenameSEXP, SEXP regexpSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type filename(filenameSEXP);
    Rcpp::traits::input_parameter< std::string >::type regexp(regexpSEXP);
    grep_print_(filename, regexp);
    return R_NilValue;
END_RCPP
}
// file_iconv_
void file_iconv_(std::string filename, std::string encoding, std::string encto);
RcppExport SEXP _fpeek_file_iconv_(SEXP filenameSEXP, SEXP encodingSEXP, SEXP enctoSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type filename(filenameSEXP);
    Rcpp::traits::input_parameter< std::string >::type encoding(encodingSEXP);
    Rcpp::traits::input_parameter< std::string >::type encto(enctoSEXP);
    file_iconv_(filename, encoding, encto);
    return R_NilValue;
END_RCPP
}
// less_
void less_(std::string filename, int n);
RcppExport SEXP _fpeek_less_(SEXP filenameSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type filename(filenameSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    less_(filename, n);
    return R_NilValue;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_fpeek_nlines_", (DL_FUNC) &_fpeek_nlines_, 1},
    {"_fpeek_head_str_", (DL_FUNC) &_fpeek_head_str_, 2},
    {"_fpeek_head_print_", (DL_FUNC) &_fpeek_head_print_, 2},
    {"_fpeek_tail_str_", (DL_FUNC) &_fpeek_tail_str_, 2},
    {"_fpeek_tail_print_", (DL_FUNC) &_fpeek_tail_print_, 2},
    {"_fpeek_grep_print_", (DL_FUNC) &_fpeek_grep_print_, 2},
    {"_fpeek_file_iconv_", (DL_FUNC) &_fpeek_file_iconv_, 3},
    {"_fpeek_less_", (DL_FUNC) &_fpeek_less_, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_fpeek(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
