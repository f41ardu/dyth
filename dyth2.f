      program two_beam
c
c      
c --- Berechnung der Reflektionskurven (Intrinsickurven)
c     im Zweistrahlfall nach den im Zachariasen  
c     angegebenen Gleichungen (modifiziert) 
c     
c     (C) 1993 Th. Rautenstrauch All Rights Resered 
c
c
c
c
c
c
      implicit none
c      
      complex  chi0,chih,q,z,D,z1,z2,x1,x2,d01,d02
      complex  c1,c2,phi1,phi2
      complex DH,D0
      complex ca,cb,cc
      complex a(3),roots(2)
      real IB0,IBH
      real lambda,pol 
      real gamma0,gammah,b,alpha,theta,dp,k0,t1,dpp,asy,y
      real pi
      real gtheta ,delta_theta
      real h,k,l
      real r1,r2,phaseB,phaseL
      real xstart,xend,xstep
      real mue
      real puffer(257)
c      
      integer ichoice,imat,ndata,i_data,i
      logical laue,bragg,par,sigma
      open(77,file='2.dat')
      open(78,file='3.dat')
      open(79,file='a.dat')
c
100   format(7f16.8)
110   format(257f16.8)
c      
      pi = 4.e0*atan(1.e0)  
c      
c      do 1000 lambda=1.66264,1.66314,1.e-5
      do 1000 lambda=1.66289,1.66289
      i_data = 1
c      write(6,*) 'lambda :'
c      read(5,*) lambda
c      write(6,*) 'h,k,l :'
c      read(5,*) h,k,l
      h = 1
      k = 1
      l = 1
c      write(6,*) 'Material : Si 1 / C 2 /Ge 3' 
c      read(5,*) imat
      imat = 1
      call strfac(real(h),real(k),real(l),real(lambda),chih,imat)
      call strfac(0.e0,0.e0,0.e0,real(lambda),chi0,imat)
      mue = -2.e0*pi*aimag(chi0)/(lambda*1e-7)  
c      
      write(6,*) 'chi0 :',chi0
      write(6,*) 'chih :',chih
c
c      write(6,*) ' Dicke in mm :'
c      read(5,*) t1
      t1 = 5.
      write(6,*) 'mue*t :',mue*t1*10. ! so what cm
      write(6,*) 'I/I0 :',exp(-mue*t1*10)
c
c123   write(6,*) 'Laue oder Bragg (1/2) '
c      read(5,*) ichoice
      ichoice = 2
      if(ichoice.eq.1) laue=.true.
      if(ichoice.eq.2) bragg=.true.
c      if(ichoice.ne.1.and.ichoice.ne.2)goto 123
c
c124   write(6,*) 'Pi oder Sigma Polarisation (1/2) '
c      read(5,*) ichoice
      ichoice = 2
      if(ichoice.eq.1) par=.true.
      if(ichoice.eq.2) sigma=.true.
c      if(ichoice.ne.1.and.ichoice.ne.2)goto 124
c
      k0 = 1.d0/(lambda*1e-7)
c      
      theta = gtheta(h,k,l,lambda,imat)
c      
      write(6,*) 'Theta Bragg : ',theta*180.d0/pi
c        
c      write(6,*) ' asy :'      
c      read(5,*) asy
      asy = 0.
      asy =  asy*pi/180.e0
c
c Laue 
      if(laue) then
         gamma0 = cos(theta - asy)
         gammah = cos(theta + asy)
      endif
c Bragg
      if(bragg) then
         gamma0 =  sin(theta + asy)
         gammah = -sin(theta - asy)
      endif
c
      write(6,*) gamma0,gammah
c     
      b = gamma0/gammah
c     
      if(par) then
        pol = cos(2.e0*theta) !paralell Pol
      endif
c     
      if(sigma) then
         pol = 1.e0     
      endif
c      
      write(6,*) 'Polarisation :',pol
      write(6,*) 'b :',b
c     
      write(6,*) 'Dynamische Breite :'
      delta_theta = 2./sin(2.*theta)*pol*
     .              sqrt(abs(gammah)/abs(gamma0))*cabs(chih)
      write(6,*) delta_theta*(180./pi)*3600.
      ndata = 256
c      xstart = -23.47724114/3600.*pi/180. 
      xstart = -33.47724114/3600.*pi/180. 
      xend   = -xstart
      xstep = (xend-xstart)/ndata
      do 10 dp = xstart,xend,xstep
c         
         dpp = -dp*(180.e0/pi)!*3600.e0
c         
         alpha = 2.d0*dp*sin(2.d0*theta)
c         
         z = chi0*(1 - b)/2. + b/2*alpha
c
         y = -real(z)/(sqrt(abs(b))*real(chih))  
c         
         a(1) = chi0**2 - chi0 * alpha - (pol*chih)**2
c         
         a(2) = cmplx(2.*alpha,0.) - 2.*chi0/b - 2.*chi0
c         
         a(3) = cmplx(4./b,0.)
c
         call zroots(a,2,roots,.true.)
c         
         d01 = roots(1)
         d02 = roots(2)
c         
         x1 = (2.*d01-chi0)/(pol*chih)
         x2 = (2.*d02-chi0)/(pol*chih)
c         
         phi1 = 2.0*pi*t1*k0*d01/gamma0
         phi2 = 2.0*pi*t1*k0*d02/gamma0
c         
         call me_cexp(c1,(0.e0,-1.e0)*phi1)
         call me_cexp(c2,(0.e0,-1.e0)*phi2)
c
         if(laue) then
            call laueit(x1,x2,c1,c2,d0,dh)
         endif
c        
         if(bragg) then
             call braggit(x1,x2,c1,c2,d0,dh)
         endif
c         
         r1 = real(dh)
         r2 = aimag(dh)
         phaseB = atan2(r1,r2)+pi/2.
c         
         r1 = real(d0)
         r2 = aimag(d0)
         phaseL = atan2(r1,r2)+pi/2.
c         
         IBH = CABS(DH)**2
         IB0 = CABS(D0)**2
c        
         write(77,100) lambda,real(dpp + theta*180./pi),y, 
     .   real(IBH/abs(b)),real(IB0/abs(b)),real(phaseB),real(phaseL)
c         
         write(78,100) lambda,(dpp + theta*180./pi),y,real(d01),
     .                  aimag(d01),real(d02),aimag(d02)    
c
         puffer(i_data) = IBH/abs(b)
         i_data = i_data + 1
10       continue
         write(79,110) (puffer(i),i=1,257)
         write(77,*)
         write(78,*)
1000     continue         
         stop
         end
c
        subroutine me_cexp(result,arg)
c
c--- Zerlegung der complexen Exponentialfunktion
c    Auswertung der trignometischen Funktionen ueber 
c    Hauptwerte  
c
        complex result,arg
        real rarg,iarg,pi
        real resultrarg,resultiarg
        real emuet
c
        pi = 4.e0*atan(1.e0)
c
        result = (0.e0,0.e0)
c        
        rarg = real(arg)
        iarg = aimag(arg)
c
        iarg = mod(iarg,2.e0*pi)
c        
        if(rarg.ge.0.e0) then
           if(rarg.ge.20.0) then 
             emuet = exp(20.0)
           else
             emuet=exp(rarg)
           endif
        endif
c        
        if(rarg.lt.0.e0) then
           if(rarg.le.-20.0) then
              emuet = exp(-20.0)
           else 
              emuet=exp(rarg)
           endif
        endif
c        
        resultrarg=cos(iarg)
        resultiarg=sin(iarg)
c
        result = emuet*cmplx(resultrarg,resultiarg)
        return
c        
        end
 
