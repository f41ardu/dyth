/* gtheta.f -- translated by f2c (version 19940714).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#ifdef __cplusplus
extern "C" {
#endif
#include "f2c.h"

doublereal gtheta_(doublereal *h, doublereal *k, doublereal *l, doublereal *
	lambda, integer *imat, doublereal *t)
{
    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    double sqrt(doublereal), asin(doublereal);

    /* Local variables */
    extern doublereal gikn_(doublereal *, doublereal *);
    static doublereal a, hkl;


/* --- bragg winkel */

    if (*imat == 1) {
	a = 5.4305;
    }
    if (*imat == 2) {
	a = 3.567;
    }
    if (*imat == 3) {
	a = 5.658;
    }
    hkl = *h * *h + *k * *k + *l * *l;
    hkl = sqrt(hkl);
    ret_val = *lambda * hkl / (a * 2.);
    ret_val = asin(ret_val);
    if (*imat == 1) {
	a = gikn_(t, &ret_val);
/* 	write(6,*)' a: ',a */
	ret_val = *lambda * hkl / (a * 2.);
	ret_val = asin(ret_val);
    }
    return ret_val;
} /* gtheta_ */

#ifdef __cplusplus
	}
#endif
