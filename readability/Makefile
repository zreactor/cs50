CC=gcc
CFLAGS_SIMPLE=-I.
_DEPS = readability.h
_OBJ = readability.o parser.o
IDIR = ./include
ODIR=obj
LDIR =../lib
LIBS=-lm

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# pattern,replacement,text
# %, ./include/$ , readability.h   % is a wildcard

CFLAGS=-I$(IDIR)


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


readability: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)





