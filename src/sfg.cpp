#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
List points_cpp(NumericMatrix pts, CharacterVector gdim = "XY") {
	int n = pts.nrow();
	List out(n);
	CharacterVector cls = CharacterVector::create(gdim[0], "POINT", "sfg");
	for (int i = 0; i < n; i++) {

		NumericVector lp = pts(i, _);
		lp.attr("class") = cls;
		out[i] = lp;
	}
	return out;
}

// This function a helper to the implementation of
// `[.sfc`. It allows access to the [] operator for
// the underlying list without the cost of an
// expensive unclass() call.
// [[Rcpp::export]]
SEXP CPP_getAt(SEXP sfc, SEXP index) {
	size_t i = INTEGER(index)[0] - 1;
	return VECTOR_ELT(sfc, i);
}
