        function gtheta(h,k,l,lambda,imat,t)
c
c --- bragg winkel
c
        implicit none
        integer imat
        real h,k,l,t
        real hkl,a,lambda,gtheta
	real gikn

        if(imat .eq. 1) a = 5.4305
        if(imat .eq. 2) a = 3.567
        if(imat .eq. 3) a = 5.658
        hkl = h*h + k*k + l*l
        hkl = sqrt(hkl)
        gtheta = lambda*hkl/(2.e0*a)
        gtheta = asin(gtheta)
	if(imat.eq.1) then
	a = gikn(t,gtheta)
c	write(6,*)' a: ',a
	gtheta = lambda*hkl/(2.*a)
	gtheta = asin(gtheta)
	endif
        return
        end
c
