
SHELL = /bin/bash

INSTALL = cp
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA    = $(INSTALL)

#########################################################
# Compiler and options
#########################################################

ASSERT = .
DIR_EXT = $(ASSERT)

CC = gcc
CPP = gcc -E

INCDIR = -I. -I$(ASSERT)

CPPFLAGS = $(INCDIR)
#CPPFLAGS = $(INCDIR) -DNDEBUG

CFLAGS = -g -Wall -Wextra -pedantic -std=c99
#CFLAGS = -O -Wall -Wextra -pedantic -std=c99


#LIBS = -ljpeg -lXaw -lm
LIBS = 

#LDFLAGS = -L/usr/local/X11R6/lib -L../jpeg $(LIBS)
LDFLAGS = $(LIBS)



#########################################################
# Common prefix for installation directories.
#########################################################

#prefix = /usr/local
prefix = .
exec_prefix = ${prefix}

bindir  = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec

libdir = ${exec_prefix}/lib
infodir = ${prefix}/info
includedir = ${prefix}/include
mandir = ${prefix}/man

srcdir  = .


#########################################################
# bin, sources, ...
#########################################################

BIN = test

SRC_LOC = test.c \
          Semaphore.c
SRC_EXT = $(ASSERT)/myassert.c
SRC = $(SRC_LOC) $(SRC_EXT)

OBJ_LOC = $(subst .c,.o,$(SRC_LOC))
OBJ_EXT = $(subst .c,.o,$(SRC_EXT))
OBJ = $(subst .c,.o,$(SRC))

DFILES_LOC = $(subst .c,.d,$(SRC_LOC))
DFILES_EXT = $(subst .c,.d,$(SRC_EXT))
DFILES = $(subst .c,.d,$(SRC))


#########################################################
# explicite rules
#########################################################

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

install:
	@echo install to do

uninstall:
	@echo uninstall to do

clean:
	@echo "deleting" $(OBJ_LOC) $(DFILES_LOC)
	@$(RM) $(OBJ_LOC) $(DFILES_LOC)

distclean: clean
	@echo "deleting" $(BIN)
	@$(RM) $(BIN)

cleanall: clean
	@for dir in $(DIR_EXT); \
	do \
		pushd $$dir > /dev/null; \
		make -s clean; \
		popd > /dev/null; \
	done

distcleanall: cleanall
	@echo "deleting" $(BIN)
	@$(RM) $(BIN)

mostlyclean:
	@echo mostlyclean to do

maintainer-clean:
	@echo maintainer-clean to do

TAGS:
	@echo TAGS to do

info:
	@echo info to do


#########################################################
# Implicite rules
#########################################################

#.SILENT:

.SUFFIXES : .c .o .d

%.o : %.c
	@if [ "$<" = "`basename $<`" ];\
	then\
	   echo 'compiling' $< ;\
	   $(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@ ;\
	else\
	   cd `dirname $<` ;\
	   make -s `basename $@` ;\
	fi

%.d : %.c
	@if [ "$<" = "`basename $<`" ];\
	then\
	   $(SHELL) -ec '$(CC) -MM $(CPPFLAGS) $< \
	   | sed '\''s/\($*\.o\)[ :]*/\1 $@ : /g'\'' > $@' ;\
	fi

# include dependance files
-include $(DFILES)
