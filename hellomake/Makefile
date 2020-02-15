CC=gcc
CFLAGS_SIMPLE=-I.
_DEPS = hellomake.h
_OBJ = hellomake.o hellofunc.o
IDIR = ./include
ODIR=obj
LDIR =../lib
LIBS=-lm

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# pattern-substring replacement



CFLAGS=-I$(IDIR)

.PHONY: clean

# phone says do not look for a file named clean

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# look for the .o files in the ODIR, or obj/*.o


# %.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)

# tells make that all .o files depend on .c versions of the same file, and DEPS files
# so that it will remake ./hellomake when hellomake.h changes


hellomake-simple: hellomake.c hellofunc.c
	gcc -o hellomake hellomake.c hellofunc.c -I.  

# -I includes directory . to library searchpath
# Must be a TAB before gcc command, or no separator error
# hellomake.c, hellofunc.c are the dependencies

hellomake2: hellomake.o hellofunc.o
	$(CC) -o hellomake hellomake.o hellofunc.o

# putting hellomake.o, hellofunc.o in dependencies list means make will compile hellomake.c, hellofunc.c first

hellomake3: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS_SIMPLE)

# $@ tells it to put it in the object on the left side of :, so essentially -o hellomake3
# $^ refers to right side of :, so $(OBJ) or hellomake.o hellofunc.o

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# clean:
# 	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 



