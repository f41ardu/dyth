CFLAGS = -O4 -funroll-loops

f77FLAGS = -r8R -C++

.c.o:
	gcc $(CFLAGS) -c $<

.f.c:
	f2c $(f77FLAGS) $<

O = dyth.o gtheta.o c.o myeb.o roots.o bragg.o plin8.o blc8.o blr8.o gikn.o

L = -lf2c -lm -lc 

main : $(O)
	gcc -o dyth $(O) $(L)

# DEPENDENCIES

