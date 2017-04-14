/* dyth.f -- translated by f2c (version 19940714).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#ifdef __cplusplus
extern "C" {
#endif
#include "f2c.h"

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;
static integer c__5 = 5;
static integer c__3 = 3;
static doublereal c_b30 = 0.;
static integer c__7 = 7;
static integer c__2 = 2;

/* Main program */ MAIN__()
{
    /* Format strings */
    static char fmt_100[] = "(8f16.8)";

    /* System generated locals */
    doublereal d__1, d__2, d__3, d__4, d__5, d__6, d__7, d__8;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6;
    olist o__1;

    /* Builtin functions */
    integer f_open(olist *);
    double atan(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_rsle(cilist *), e_rsle();
    double d_imag(doublecomplex *), exp(doublereal), cos(doublereal), sin(
	    doublereal), z_abs(doublecomplex *), sqrt(doublereal);
    void pow_zi(doublecomplex *, doublecomplex *, integer *), z_div(
	    doublecomplex *, doublecomplex *, doublecomplex *);
    double atan2(doublereal, doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static doublereal ibhh;
    static doublecomplex chih;
    static logical laue;
    static integer imat;
    static doublereal xend;
    static doublecomplex a[3];
    static doublereal b, h, k, l;
    static logical bragg;
    static doublereal t, alpha;
    static integer ndata;
    static doublereal y;
    static doublecomplex z;
    static logical sigma;
    static doublereal theta;
    static doublecomplex c1, c2, d0;
    static doublereal k0, gamma0, r1, r2, t1;
    static doublecomplex roots[2];
    static doublereal xstep;
    static doublecomplex x1, x2, d00, d01, d02, dh;
    static doublereal lambda, dp, pi, gammah, phaseb;
    extern doublereal gtheta_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *);
    static doublereal phasel;
    extern /* Subroutine */ int strfac_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublecomplex *, integer *), laueit_(
	    doublecomplex *, doublecomplex *, doublecomplex *, doublecomplex *
	    , doublecomplex *, doublecomplex *);
    static doublereal ib0, xstart;
    extern /* Subroutine */ int zroots_(doublecomplex *, integer *, 
	    doublecomplex *, logical *);
    static doublereal ib00, ibh;
    static doublecomplex dhh;
    static integer ichoice;
    static doublereal dpp;
    static logical par;
    static doublereal mue, pol, asy;
    extern /* Subroutine */ int braggit_(doublecomplex *, doublecomplex *, 
	    doublecomplex *, doublecomplex *, doublecomplex *, doublecomplex *
	    ), me_cexp__(doublecomplex *, doublecomplex *);
    static doublereal delta_theta__;
    static doublecomplex chi0, phi1, phi2;

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 6, 0, 0, 0 };
    static cilist io___3 = { 0, 5, 0, 0, 0 };
    static cilist io___5 = { 0, 6, 0, 0, 0 };
    static cilist io___6 = { 0, 5, 0, 0, 0 };
    static cilist io___10 = { 0, 6, 0, 0, 0 };
    static cilist io___11 = { 0, 5, 0, 0, 0 };
    static cilist io___13 = { 0, 6, 0, 0, 0 };
    static cilist io___14 = { 0, 5, 0, 0, 0 };
    static cilist io___19 = { 0, 6, 0, 0, 0 };
    static cilist io___20 = { 0, 6, 0, 0, 0 };
    static cilist io___21 = { 0, 6, 0, 0, 0 };
    static cilist io___22 = { 0, 5, 0, 0, 0 };
    static cilist io___24 = { 0, 6, 0, 0, 0 };
    static cilist io___25 = { 0, 6, 0, 0, 0 };
    static cilist io___26 = { 0, 6, 0, 0, 0 };
    static cilist io___27 = { 0, 5, 0, 0, 0 };
    static cilist io___31 = { 0, 6, 0, 0, 0 };
    static cilist io___32 = { 0, 5, 0, 0, 0 };
    static cilist io___37 = { 0, 6, 0, 0, 0 };
    static cilist io___38 = { 0, 6, 0, 0, 0 };
    static cilist io___39 = { 0, 5, 0, 0, 0 };
    static cilist io___43 = { 0, 6, 0, 0, 0 };
    static cilist io___46 = { 0, 6, 0, 0, 0 };
    static cilist io___47 = { 0, 6, 0, 0, 0 };
    static cilist io___48 = { 0, 6, 0, 0, 0 };
    static cilist io___50 = { 0, 6, 0, 0, 0 };
    static cilist io___82 = { 0, 77, 0, fmt_100, 0 };
    static cilist io___83 = { 0, 79, 0, fmt_100, 0 };
    static cilist io___84 = { 0, 78, 0, fmt_100, 0 };




/* --- Berechnung der Reflektionskurven (Intrinsickurven) */
/*     im Zweistrahlfall nach den im Zachariasen */
/*     angegebenen Gleichungen (modifiziert) */

/*     (C) 1993.94,95  Th. Rautenstrauch All Rights Resered */








    o__1.oerr = 0;
    o__1.ounit = 77;
    o__1.ofnmlen = 5;
    o__1.ofnm = "2.dat";
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);
    o__1.oerr = 0;
    o__1.ounit = 78;
    o__1.ofnmlen = 5;
    o__1.ofnm = "3.dat";
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);
    o__1.oerr = 0;
    o__1.ounit = 79;
    o__1.ofnmlen = 5;
    o__1.ofnm = "4.dat";
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

/* L100: */

    pi = atan(1.) * 4.;

    s_wsle(&io___2);
    do_lio(&c__9, &c__1, "lambda :", 8L);
    e_wsle();
    s_rsle(&io___3);
    do_lio(&c__5, &c__1, (char *)&lambda, (ftnlen)sizeof(doublereal));
    e_rsle();
    s_wsle(&io___5);
    do_lio(&c__9, &c__1, "h,k,l :", 7L);
    e_wsle();
    s_rsle(&io___6);
    do_lio(&c__5, &c__1, (char *)&h, (ftnlen)sizeof(doublereal));
    do_lio(&c__5, &c__1, (char *)&k, (ftnlen)sizeof(doublereal));
    do_lio(&c__5, &c__1, (char *)&l, (ftnlen)sizeof(doublereal));
    e_rsle();
    s_wsle(&io___10);
    do_lio(&c__9, &c__1, "Material : Si 1 / C 2 /Ge 3", 27L);
    e_wsle();
    s_rsle(&io___11);
    do_lio(&c__3, &c__1, (char *)&imat, (ftnlen)sizeof(integer));
    e_rsle();
    s_wsle(&io___13);
    do_lio(&c__9, &c__1, " Temperatur [K] ", 16L);
    e_wsle();
    s_rsle(&io___14);
    do_lio(&c__5, &c__1, (char *)&t, (ftnlen)sizeof(doublereal));
    e_rsle();
    d__1 = h;
    d__2 = k;
    d__3 = l;
    d__4 = lambda;
    strfac_(&d__1, &d__2, &d__3, &d__4, &chih, &imat);
    d__1 = lambda;
    strfac_(&c_b30, &c_b30, &c_b30, &d__1, &chi0, &imat);
    mue = pi * -2. * d_imag(&chi0) / (lambda * 1e-7);

    s_wsle(&io___19);
    do_lio(&c__9, &c__1, "chi0 :", 6L);
    do_lio(&c__7, &c__1, (char *)&chi0, (ftnlen)sizeof(doublecomplex));
    e_wsle();
    s_wsle(&io___20);
    do_lio(&c__9, &c__1, "chih :", 6L);
    do_lio(&c__7, &c__1, (char *)&chih, (ftnlen)sizeof(doublecomplex));
    e_wsle();

    s_wsle(&io___21);
    do_lio(&c__9, &c__1, " Dicke in mm :", 14L);
    e_wsle();
    s_rsle(&io___22);
    do_lio(&c__5, &c__1, (char *)&t1, (ftnlen)sizeof(doublereal));
    e_rsle();
    s_wsle(&io___24);
    do_lio(&c__9, &c__1, "mue*t :", 7L);
    d__1 = mue * t1 * 10.;
    do_lio(&c__5, &c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    e_wsle();
/* so what cm */
    s_wsle(&io___25);
    do_lio(&c__9, &c__1, "I/I0 :", 6L);
    d__1 = exp(-mue * t1 * 10);
    do_lio(&c__5, &c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    e_wsle();

L123:
    s_wsle(&io___26);
    do_lio(&c__9, &c__1, "Laue oder Bragg (1/2) ", 22L);
    e_wsle();
    s_rsle(&io___27);
    do_lio(&c__3, &c__1, (char *)&ichoice, (ftnlen)sizeof(integer));
    e_rsle();
    if (ichoice == 1) {
	laue = TRUE_;
    }
    if (ichoice == 2) {
	bragg = TRUE_;
    }
    if (ichoice != 1 && ichoice != 2) {
	goto L123;
    }

L124:
    s_wsle(&io___31);
    do_lio(&c__9, &c__1, "Pi oder Sigma Polarisation (1/2) ", 33L);
    e_wsle();
    s_rsle(&io___32);
    do_lio(&c__3, &c__1, (char *)&ichoice, (ftnlen)sizeof(integer));
    e_rsle();
    if (ichoice == 1) {
	par = TRUE_;
    }
    if (ichoice == 2) {
	sigma = TRUE_;
    }
    if (ichoice != 1 && ichoice != 2) {
	goto L124;
    }

    k0 = 1. / (lambda * 1e-7);

    theta = gtheta_(&h, &k, &l, &lambda, &imat, &t);

    s_wsle(&io___37);
    do_lio(&c__9, &c__1, "Theta Bragg : ", 14L);
    d__1 = theta * 180. / pi;
    do_lio(&c__5, &c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    e_wsle();

    s_wsle(&io___38);
    do_lio(&c__9, &c__1, " asy :", 6L);
    e_wsle();
    s_rsle(&io___39);
    do_lio(&c__5, &c__1, (char *)&asy, (ftnlen)sizeof(doublereal));
    e_rsle();
    asy = asy * pi / 180.;

/* Laue */
    if (laue) {
	gamma0 = cos(theta - asy);
	gammah = cos(theta + asy);
    }
/* Bragg */
    if (bragg) {
	gamma0 = sin(theta + asy);
	gammah = -sin(theta - asy);
/*         gamma0 =  sin(theta - asy) */
/*         gammah =  sin(theta + asy) */
    }

    s_wsle(&io___43);
    do_lio(&c__5, &c__1, (char *)&gamma0, (ftnlen)sizeof(doublereal));
    do_lio(&c__5, &c__1, (char *)&gammah, (ftnlen)sizeof(doublereal));
    e_wsle();

    b = gamma0 / gammah;

    if (par) {
	pol = cos(theta * 2.);
/* paralell Pol */
    }

    if (sigma) {
	pol = 1.;
    }

    s_wsle(&io___46);
    do_lio(&c__9, &c__1, "Polarisation :", 14L);
    do_lio(&c__5, &c__1, (char *)&pol, (ftnlen)sizeof(doublereal));
    e_wsle();
    s_wsle(&io___47);
    do_lio(&c__9, &c__1, "b :", 3L);
    do_lio(&c__5, &c__1, (char *)&b, (ftnlen)sizeof(doublereal));
    e_wsle();

    s_wsle(&io___48);
    do_lio(&c__9, &c__1, "Dynamische Breite :", 19L);
    e_wsle();
/*      delta_theta = 2./sin(2.*theta)*pol* */
/*     .              sqrt(abs(gammah)/abs(gamma0))*cabs(chih) */
    delta_theta__ = abs(pol) * 2. * z_abs(&chih) / (sin(theta * 2.) * sqrt((
	    d__1 = gamma0 / gammah, abs(d__1))));
    s_wsle(&io___50);
    d__1 = delta_theta__ * (180. / pi) * 3600.;
    do_lio(&c__5, &c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    e_wsle();
    ndata = 256;
/*      xstart = -23.47724114/3600.*pi/180. */
/*      xstart = -33.47724114/3600.*pi/180. */
    xstart = pi * -.0041666666666666666 / 180.;
    xend = -xstart;
    xstep = (xend - xstart) / ndata;
    d__1 = xend;
    d__2 = xstep;
    for (dp = xstart; d__2 < 0 ? dp >= d__1 : dp <= d__1; dp += d__2) {

	dpp = -dp * (180. / pi);

/* *3600.e0 */
	alpha = dp * 2. * sin(theta * 2.);

	d__3 = 1 - b;
	z__3.r = d__3 * chi0.r, z__3.i = d__3 * chi0.i;
	z__2.r = z__3.r / 2., z__2.i = z__3.i / 2.;
	d__4 = b / 2 * alpha;
	z__1.r = z__2.r + d__4, z__1.i = z__2.i;
	z.r = z__1.r, z.i = z__1.i;

	y = -z.r / (sqrt((abs(b))) * chih.r);

	pow_zi(&z__3, &chi0, &c__2);
	z__4.r = alpha * chi0.r, z__4.i = alpha * chi0.i;
	z__2.r = z__3.r - z__4.r, z__2.i = z__3.i - z__4.i;
	z__6.r = pol * chih.r, z__6.i = pol * chih.i;
	pow_zi(&z__5, &z__6, &c__2);
	z__1.r = z__2.r - z__5.r, z__1.i = z__2.i - z__5.i;
	a[0].r = z__1.r, a[0].i = z__1.i;

	d__3 = alpha * 2.;
	z__3.r = d__3, z__3.i = 0.;
	z__5.r = chi0.r * 2., z__5.i = chi0.i * 2.;
	z__4.r = z__5.r / b, z__4.i = z__5.i / b;
	z__2.r = z__3.r - z__4.r, z__2.i = z__3.i - z__4.i;
	z__6.r = chi0.r * 2., z__6.i = chi0.i * 2.;
	z__1.r = z__2.r - z__6.r, z__1.i = z__2.i - z__6.i;
	a[1].r = z__1.r, a[1].i = z__1.i;

	d__3 = 4. / b;
	z__1.r = d__3, z__1.i = 0.;
	a[2].r = z__1.r, a[2].i = z__1.i;

	zroots_(a, &c__2, roots, (logical*)&c__1);

	d01.r = roots[0].r, d01.i = roots[0].i;
	d02.r = roots[1].r, d02.i = roots[1].i;

	z__3.r = d01.r * 2., z__3.i = d01.i * 2.;
	z__2.r = z__3.r - chi0.r, z__2.i = z__3.i - chi0.i;
	z__4.r = pol * chih.r, z__4.i = pol * chih.i;
	z_div(&z__1, &z__2, &z__4);
	x1.r = z__1.r, x1.i = z__1.i;
	z__3.r = d02.r * 2., z__3.i = d02.i * 2.;
	z__2.r = z__3.r - chi0.r, z__2.i = z__3.i - chi0.i;
	z__4.r = pol * chih.r, z__4.i = pol * chih.i;
	z_div(&z__1, &z__2, &z__4);
	x2.r = z__1.r, x2.i = z__1.i;

	d__3 = pi * 2. * t1 * k0;
	z__2.r = d__3 * d01.r, z__2.i = d__3 * d01.i;
	z__1.r = z__2.r / gamma0, z__1.i = z__2.i / gamma0;
	phi1.r = z__1.r, phi1.i = z__1.i;
	d__3 = pi * 2. * t1 * k0;
	z__2.r = d__3 * d02.r, z__2.i = d__3 * d02.i;
	z__1.r = z__2.r / gamma0, z__1.i = z__2.i / gamma0;
	phi2.r = z__1.r, phi2.i = z__1.i;

	z__1.r = phi1.r * 0. - phi1.i * -1., z__1.i = phi1.r * -1. + phi1.i * 
		0.;
	me_cexp__(&c1, &z__1);
	z__1.r = phi2.r * 0. - phi2.i * -1., z__1.i = phi2.r * -1. + phi2.i * 
		0.;
	me_cexp__(&c2, &z__1);

	if (laue) {
	    laueit_(&x1, &x2, &c1, &c2, &d0, &dh);
	    laueit_(&x2, &x1, &c2, &c1, &d00, &dhh);
	}

	if (bragg) {
	    braggit_(&x1, &x2, &c1, &c2, &d0, &dh);
	    braggit_(&x2, &x1, &c2, &c1, &d00, &dhh);
	}

	r1 = dh.r;
	r2 = d_imag(&dh);
	phaseb = atan2(r1, r2) + pi / 2.;

	r1 = d0.r;
	r2 = d_imag(&d0);
	phasel = atan2(r1, r2) + pi / 2.;

/* Computing 2nd power */
	d__3 = z_abs(&dh);
	ibh = d__3 * d__3;
/* Computing 2nd power */
	d__3 = z_abs(&d0);
	ib0 = d__3 * d__3;

/* Computing 2nd power */
	d__3 = z_abs(&dhh);
	ibhh = d__3 * d__3;
/* Computing 2nd power */
	d__3 = z_abs(&d00);
	ib00 = d__3 * d__3;

	s_wsfe(&io___82);
	do_fio(&c__1, (char *)&lambda, (ftnlen)sizeof(doublereal));
	d__3 = dpp + theta * 180. / pi;
	do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y, (ftnlen)sizeof(doublereal));
	d__4 = dpp * 3600;
	do_fio(&c__1, (char *)&d__4, (ftnlen)sizeof(doublereal));
	d__5 = ibh / abs(b);
	do_fio(&c__1, (char *)&d__5, (ftnlen)sizeof(doublereal));
	d__6 = ib0 / abs(b);
	do_fio(&c__1, (char *)&d__6, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&phaseb, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&phasel, (ftnlen)sizeof(doublereal));
	e_wsfe();
/*     .    y,.5*(1-b)*dpp*3600, */

	s_wsfe(&io___83);
	do_fio(&c__1, (char *)&lambda, (ftnlen)sizeof(doublereal));
	d__3 = dpp + theta * 180. / pi;
	do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y, (ftnlen)sizeof(doublereal));
	d__4 = dpp * 3600;
	do_fio(&c__1, (char *)&d__4, (ftnlen)sizeof(doublereal));
	d__5 = ibhh / abs(b);
	do_fio(&c__1, (char *)&d__5, (ftnlen)sizeof(doublereal));
	d__6 = ib00 / abs(b);
	do_fio(&c__1, (char *)&d__6, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&phaseb, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&phasel, (ftnlen)sizeof(doublereal));
	e_wsfe();
/*     .   .5*(1.-1./b)*dpp*3600, */

	s_wsfe(&io___84);
	d__3 = dpp + theta * 180. / pi;
	do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y, (ftnlen)sizeof(doublereal));
	d__4 = -dp * 3600.;
	do_fio(&c__1, (char *)&d__4, (ftnlen)sizeof(doublereal));
	d__5 = d01.r;
	do_fio(&c__1, (char *)&d__5, (ftnlen)sizeof(doublereal));
	d__6 = d_imag(&d01);
	do_fio(&c__1, (char *)&d__6, (ftnlen)sizeof(doublereal));
	d__7 = d02.r;
	do_fio(&c__1, (char *)&d__7, (ftnlen)sizeof(doublereal));
	d__8 = d_imag(&d02);
	do_fio(&c__1, (char *)&d__8, (ftnlen)sizeof(doublereal));
	e_wsfe();

/* L10: */
    }
    s_stop("", 0L);
    return 0;
} /* MAIN__ */


/* Subroutine */ int me_cexp__(doublecomplex *result, doublecomplex *arg)
{
    /* System generated locals */
    doublereal d__1;
    doublecomplex z__1, z__2;

    /* Builtin functions */
    double atan(doublereal), d_imag(doublecomplex *), d_mod(doublereal *, 
	    doublereal *), exp(doublereal), cos(doublereal), sin(doublereal);

    /* Local variables */
    static doublereal iarg, rarg, emuet, pi, resultiarg, resultrarg;


/* --- Zerlegung der complexen Exponentialfunktion */
/*    Auswertung der trignometischen Funktionen ueber */
/*    Hauptwerte */


    pi = atan(1.) * 4.;

    result->r = 0., result->i = 0.;

    rarg = arg->r;
    iarg = d_imag(arg);

    d__1 = pi * 2.;
    iarg = d_mod(&iarg, &d__1);

    if (rarg >= 0.) {
	if (rarg >= 20.) {
	    emuet = exp(20.);
	} else {
	    emuet = exp(rarg);
	}
    }

    if (rarg < 0.) {
	if (rarg <= -20.) {
	    emuet = exp(-20.);
	} else {
	    emuet = exp(rarg);
	}
    }

    resultrarg = cos(iarg);
    resultiarg = sin(iarg);

    z__2.r = resultrarg, z__2.i = resultiarg;
    z__1.r = emuet * z__2.r, z__1.i = emuet * z__2.i;
    result->r = z__1.r, result->i = z__1.i;
    return 0;

} /* me_cexp__ */

/* Main program alias */ int two_beam__ () { MAIN__ (); return 0; }
#ifdef __cplusplus
	}
#endif
