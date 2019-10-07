# This is a Makefile to compile and link linked_lists successfully

# Define macros for compiler and compiler flags i.e. path to header files
CC = gcc
CFLAGS = -I$(IDIR) -Wall -pedantic

# Define macros for folder location
IDIR = ./include
ODIR = ./obj
LDIR = ./lib
SDIR = ./src

# Define macro for libraries included e.g. math and pthread
LIBS = -lm -lpthread 

# Define macro for the dependencies i.e. the header files needed for compilation, including paths
_DEPS = ll_lib.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# Define macro for the object files which will be compiled including paths
_OBJ = ll_lib.o linked_lists.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Define a rule for compiling the object files (gcc -c -o <objects> <sources> <flags> <libs>)
$(ODIR)/%.o : $(SDIR)/%.c $(DEPS)
	$(info Compiling $@...)
	@$(CC) -c -o $@ $< $(CFLAGS)
	$(info Successfully compiled $@!)

# Define a rule for compiling the final executable using the object files previously compiled
linked_lists: $(OBJ)
	$(info Compiling $@...)
	@$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	$(info Successfully compiled $@!)

# Define a rule for clean all object files and executable
.PHONY: clean
clean:
	$(info Cleaning up...)
	@rm -f $(ODIR)/*.o linked_lists
	$(info Cleaned. Exiting...)

# Define a rule for make all, which should be to execute the rule of linked_lists
.PHONY: all
all: linked_lists
	$(info Exiting...)

