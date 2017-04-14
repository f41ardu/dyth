/* gikn.f -- translated by f2c (version 19940714).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#ifdef __cplusplus
extern "C" {
#endif
#include "f2c.h"

doublereal gikn_(doublereal *t, doublereal *thetabragg)
{
    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    double atan(doublereal), tan(doublereal);

    /* Local variables */
    static doublereal a0, pi;
    extern doublereal deltatheta_(doublereal *);


/* --- berechnet fuer einen Braggwinkel, die temperaturabhaengige */
/*     Gitterkonstante */
/* 8v7 miukbnmutttbuuuuuuuuuuuummmmmmuzcnvh ccccnnbzzd<essxd */
    pi = atan(1.) * 4.;
    a0 = 5.431002;
    ret_val = a0 * (1. - deltatheta_(t) / tan(pi / 2. - *thetabragg) * 5e-6);
    return ret_val;
} /* gikn_ */


doublereal deltatheta_(doublereal *t)
{
    /* System generated locals */
    doublereal ret_val, d__1, d__2, d__3, d__4, d__5, d__6;

    /* Local variables */
    static doublereal a0, a1, a2, a3, a4, a5, sum;



/* --- parameter nach bartonitz */

    a0 = 15.76;
    a1 = -.04246;
    a2 = .001353;
    a3 = -1.006e-5;
    a4 = 2.433e-8;
    a5 = -2.12e-11;

/* Computing 2nd power */
    d__1 = *t;
/* Computing 3rd power */
    d__2 = *t, d__3 = d__2;
/* Computing 4th power */
    d__4 = *t, d__4 *= d__4;
/* Computing 5th power */
    d__5 = *t, d__6 = d__5, d__5 *= d__5;
    sum = a0 + a1 * *t + a2 * (d__1 * d__1) + a3 * (d__3 * (d__2 * d__2)) + 
	    a4 * (d__4 * d__4) + a5 * (d__6 * (d__5 * d__5));

    ret_val = sum;
    return ret_val;
} /* deltatheta_ */

#ifdef __cplusplus
	}
#endif
