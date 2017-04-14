/* dyth2.f -- translated by f2c (version of 27 June 1992  14:50:07).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static doublereal c_b9 = 0.;
static integer c__9 = 9;
static integer c__1 = 1;
static integer c__7 = 7;
static integer c__5 = 5;
static integer c__2 = 2;

/* Main program */ MAIN__()
{
    /* Format strings */
    static char fmt_100[] = "(7f16.8)";
    static char fmt_110[] = "(257f16.8)";

    /* System generated locals */
    doublereal d__1, d__2, d__3, d__4, d__5, d__6, d__7;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6;
    olist o__1;

    /* Builtin functions */
    integer f_open();
    double atan(), d_imag();
    integer s_wsle(), do_lio(), e_wsle();
    double exp(), cos(), sin(), sqrt(), z_abs();
    void pow_zi(), z_div();
    double atan2();
    integer s_wsfe(), do_fio(), e_wsfe();
    /* Subroutine */ int s_stop();

    /* Local variables */
    static doublecomplex chih;
    static logical laue;
    static integer imat;
    static doublereal xend;
    static doublecomplex a[3];
    static doublereal b, h;
    static integer i;
    static doublereal k, l;
    static logical bragg;
    static doublereal alpha;
    static integer ndata;
    static doublereal y;
    static doublecomplex z;
    static logical sigma;
    static doublereal theta;
    static doublecomplex c1, c2, d0;
    static doublereal k0, gamma0, r1, r2, t1;
    static doublecomplex roots[2];
    static doublereal xstep;
    static doublecomplex x1, x2, d01, d02, dh;
    static doublereal lambda;
    static integer i_data__;
    static doublereal dp, pi, gammah, phaseb;
    extern doublereal gtheta_();
    static doublereal phasel;
    extern /* Subroutine */ int strfac_(), laueit_();
    static doublereal puffer[257], ib0, xstart;
    extern /* Subroutine */ int zroots_();
    static doublereal ibh;
    static integer ichoice;
    static doublereal dpp;
    static logical par;
    static doublereal mue, pol, asy;
    extern /* Subroutine */ int braggit_(), me_cexp__();
    static doublereal delta_theta__;
    static doublecomplex chi0, phi1, phi2;

    /* Fortran I/O blocks */
    static cilist io___11 = { 0, 6, 0, 0, 0 };
    static cilist io___12 = { 0, 6, 0, 0, 0 };
    static cilist io___14 = { 0, 6, 0, 0, 0 };
    static cilist io___15 = { 0, 6, 0, 0, 0 };
    static cilist io___23 = { 0, 6, 0, 0, 0 };
    static cilist io___27 = { 0, 6, 0, 0, 0 };
    static cilist io___30 = { 0, 6, 0, 0, 0 };
    static cilist io___31 = { 0, 6, 0, 0, 0 };
    static cilist io___32 = { 0, 6, 0, 0, 0 };
    static cilist io___34 = { 0, 6, 0, 0, 0 };
    static cilist io___62 = { 0, 77, 0, fmt_100, 0 };
    static cilist io___63 = { 0, 78, 0, fmt_100, 0 };
    static cilist io___65 = { 0, 79, 0, fmt_110, 0 };
    static cilist io___67 = { 0, 77, 0, 0, 0 };
    static cilist io___68 = { 0, 78, 0, 0, 0 };




/* --- Berechnung der Reflektionskurven (Intrinsickurven) */
/*     im Zweistrahlfall nach den im Zachariasen */
/*     angegebenen Gleichungen (modifiziert) */

/*     (C) 1993 Th. Rautenstrauch All Rights Resered */








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
    o__1.ofnm = "a.dat";
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

/* L100: */
/* L110: */

    pi = atan(1.) * 4.;

/*      do 1000 lambda=1.66264,1.66314,1.e-5 */
    for (lambda = 1.66289; lambda <= 1.66289; lambda += 1.) {
	i_data__ = 1;
/*      write(6,*) 'lambda :' */
/*      read(5,*) lambda */
/*      write(6,*) 'h,k,l :' */
/*      read(5,*) h,k,l */
	h = 1.;
	k = 1.;
	l = 1.;
/*      write(6,*) 'Material : Si 1 / C 2 /Ge 3' */
/*      read(5,*) imat */
	imat = 1;
	strfac_(&h, &k, &l, &lambda, &chih, &imat);
	strfac_(&c_b9, &c_b9, &c_b9, &lambda, &chi0, &imat);
	mue = pi * -2. * d_imag(&chi0) / (lambda * 1e-7);

	s_wsle(&io___11);
	do_lio(&c__9, &c__1, "chi0 :", 6L);
	do_lio(&c__7, &c__1, (char *)&chi0, (ftnlen)sizeof(doublecomplex));
	e_wsle();
	s_wsle(&io___12);
	do_lio(&c__9, &c__1, "chih :", 6L);
	do_lio(&c__7, &c__1, (char *)&chih, (ftnlen)sizeof(doublecomplex));
	e_wsle();

/*      write(6,*) ' Dicke in mm :' */
/*      read(5,*) t1 */
	t1 = 5.;
	s_wsle(&io___14);
	do_lio(&c__9, &c__1, "mue*t :", 7L);
	d__1 = mue * t1 * 10.;
	do_lio(&c__5, &c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsle();
/* so what cm */
	s_wsle(&io___15);
	do_lio(&c__9, &c__1, "I/I0 :", 6L);
	d__1 = exp(-mue * t1 * 10);
	do_lio(&c__5, &c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsle();

/* 123   write(6,*) 'Laue oder Bragg (1/2) ' */
/*      read(5,*) ichoice */
	ichoice = 2;
	if (ichoice == 1) {
	    laue = TRUE_;
	}
	if (ichoice == 2) {
	    bragg = TRUE_;
	}
/*      if(ichoice.ne.1.and.ichoice.ne.2)goto 123 */

/* 124   write(6,*) 'Pi oder Sigma Polarisation (1/2) ' */
/*      read(5,*) ichoice */
	ichoice = 2;
	if (ichoice == 1) {
	    par = TRUE_;
	}
	if (ichoice == 2) {
	    sigma = TRUE_;
	}
/*      if(ichoice.ne.1.and.ichoice.ne.2)goto 124 */

	k0 = 1. / (lambda * 1e-7);

	theta = gtheta_(&h, &k, &l, &lambda, &imat);

	s_wsle(&io___23);
	do_lio(&c__9, &c__1, "Theta Bragg : ", 14L);
	d__1 = theta * 180. / pi;
	do_lio(&c__5, &c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsle();

/*      write(6,*) ' asy :' */
/*      read(5,*) asy */
	asy = 0.;
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
	}

	s_wsle(&io___27);
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

	s_wsle(&io___30);
	do_lio(&c__9, &c__1, "Polarisation :", 14L);
	do_lio(&c__5, &c__1, (char *)&pol, (ftnlen)sizeof(doublereal));
	e_wsle();
	s_wsle(&io___31);
	do_lio(&c__9, &c__1, "b :", 3L);
	do_lio(&c__5, &c__1, (char *)&b, (ftnlen)sizeof(doublereal));
	e_wsle();

	s_wsle(&io___32);
	do_lio(&c__9, &c__1, "Dynamische Breite :", 19L);
	e_wsle();
	delta_theta__ = 2. / sin(theta * 2.) * pol * sqrt(abs(gammah) / abs(
		gamma0)) * z_abs(&chih);
	s_wsle(&io___34);
	d__1 = delta_theta__ * (180. / pi) * 3600.;
	do_lio(&c__5, &c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsle();
	ndata = 256;
/*      xstart = -23.47724114/3600.*pi/180. */
	xstart = pi * -.00929923365 / 180.;
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

	    zroots_(a, &c__2, roots, &c__1);

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

	    z__1.r = phi1.r * 0. - phi1.i * -1., z__1.i = phi1.r * -1. + 
		    phi1.i * 0.;
	    me_cexp__(&c1, &z__1);
	    z__1.r = phi2.r * 0. - phi2.i * -1., z__1.i = phi2.r * -1. + 
		    phi2.i * 0.;
	    me_cexp__(&c2, &z__1);

	    if (laue) {
		laueit_(&x1, &x2, &c1, &c2, &d0, &dh);
	    }

	    if (bragg) {
		braggit_(&x1, &x2, &c1, &c2, &d0, &dh);
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

	    s_wsfe(&io___62);
	    do_fio(&c__1, (char *)&lambda, (ftnlen)sizeof(doublereal));
	    d__3 = dpp + theta * 180. / pi;
	    do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&y, (ftnlen)sizeof(doublereal));
	    d__4 = ibh / abs(b);
	    do_fio(&c__1, (char *)&d__4, (ftnlen)sizeof(doublereal));
	    d__5 = ib0 / abs(b);
	    do_fio(&c__1, (char *)&d__5, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&phaseb, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&phasel, (ftnlen)sizeof(doublereal));
	    e_wsfe();

	    s_wsfe(&io___63);
	    do_fio(&c__1, (char *)&lambda, (ftnlen)sizeof(doublereal));
	    d__3 = dpp + theta * 180. / pi;
	    do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&y, (ftnlen)sizeof(doublereal));
	    d__4 = d01.r;
	    do_fio(&c__1, (char *)&d__4, (ftnlen)sizeof(doublereal));
	    d__5 = d_imag(&d01);
	    do_fio(&c__1, (char *)&d__5, (ftnlen)sizeof(doublereal));
	    d__6 = d02.r;
	    do_fio(&c__1, (char *)&d__6, (ftnlen)sizeof(doublereal));
	    d__7 = d_imag(&d02);
	    do_fio(&c__1, (char *)&d__7, (ftnlen)sizeof(doublereal));
	    e_wsfe();

	    puffer[i_data__ - 1] = ibh / abs(b);
	    ++i_data__;
/* L10: */
	}
	s_wsfe(&io___65);
	for (i = 1; i <= 257; ++i) {
	    do_fio(&c__1, (char *)&puffer[i - 1], (ftnlen)sizeof(doublereal));

	}
	e_wsfe();
	s_wsle(&io___67);
	e_wsle();
	s_wsle(&io___68);
	e_wsle();
/* L1000: */
    }
    s_stop("", 0L);
} /* MAIN__ */


/* Subroutine */ int me_cexp__(result, arg)
doublecomplex *result, *arg;
{
    /* System generated locals */
    doublereal d__1;
    doublecomplex z__1, z__2;

    /* Builtin functions */
    double atan(), d_imag(), d_mod(), exp(), cos(), sin();

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

/* Main program alias */ int two_beam__ () { MAIN__ (); }
