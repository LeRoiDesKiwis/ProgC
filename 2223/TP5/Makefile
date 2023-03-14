
SHELL = /bin/bash

INSTALL = cp
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA    = $(INSTALL)

#########################################################
# Compiler and options
#########################################################

ASSERT = ./SEMAPHORE
FICHIER = ./FICHIER
SEMAPHORE = ./SEMAPHORE
#DIR_EXT = $(ASSERT) $(FICHIER) $(SEMAPHORE)
DIR_EXT =  $(FICHIER) $(SEMAPHORE)

CC = gcc
CPP = gcc -E

#INCDIR = -I. -I$(ASSERT) -I$(FICHIER) -I$(SEMAPHORE)
INCDIR = -I. -I$(FICHIER) -I$(SEMAPHORE)

CPPFLAGS = $(INCDIR) -D_XOPEN_SOURCE=500
#CPPFLAGS = $(INCDIR) -D_XOPEN_SOURCE=500 -DNDEBUG

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

#-------
# programme exemple
#-------
BIN_exemple = exemple

SRC_LOC_exemple = exemple.c
SRC_EXT_exemple = $(ASSERT)/myassert.c $(SEMAPHORE)/Semaphore.c
SRC_exemple = $(SRC_LOC_exemple) $(SRC_EXT_exemple)

OBJ_LOC_exemple = $(subst .c,.o,$(SRC_LOC_exemple))
OBJ_EXT_exemple = $(subst .c,.o,$(SRC_EXT_exemple))
OBJ_exemple = $(subst .c,.o,$(SRC_exemple))

DFILES_LOC_exemple = $(subst .c,.d,$(SRC_LOC_exemple))
DFILES_EXT_exemple = $(subst .c,.d,$(SRC_EXT_exemple))
DFILES_exemple = $(subst .c,.d,$(SRC_exemple))


#-------
# programme exercice 1b
#-------
BIN_exercice_1b = exercice_1b

SRC_LOC_exercice_1b = exercice_1b.c
SRC_EXT_exercice_1b = $(ASSERT)/myassert.c $(SEMAPHORE)/Semaphore.c
SRC_exercice_1b = $(SRC_LOC_exercice_1b) $(SRC_EXT_exercice_1b)

OBJ_LOC_exercice_1b = $(subst .c,.o,$(SRC_LOC_exercice_1b))
OBJ_EXT_exercice_1b = $(subst .c,.o,$(SRC_EXT_exercice_1b))
OBJ_exercice_1b = $(subst .c,.o,$(SRC_exercice_1b))

DFILES_LOC_exercice_1b = $(subst .c,.d,$(SRC_LOC_exercice_1b))
DFILES_EXT_exercice_1b = $(subst .c,.d,$(SRC_EXT_exercice_1b))
DFILES_exercice_1b = $(subst .c,.d,$(SRC_exercice_1b))


#-------
# programme exercice 1c
#-------
BIN_exercice_1c = exercice_1c

SRC_LOC_exercice_1c = exercice_1c.c
SRC_EXT_exercice_1c = $(ASSERT)/myassert.c $(SEMAPHORE)/Semaphore.c $(FICHIER)/fichier.c
SRC_exercice_1c = $(SRC_LOC_exercice_1c) $(SRC_EXT_exercice_1c)

OBJ_LOC_exercice_1c = $(subst .c,.o,$(SRC_LOC_exercice_1c))
OBJ_EXT_exercice_1c = $(subst .c,.o,$(SRC_EXT_exercice_1c))
OBJ_exercice_1c = $(subst .c,.o,$(SRC_exercice_1c))

DFILES_LOC_exercice_1c = $(subst .c,.d,$(SRC_LOC_exercice_1c))
DFILES_EXT_exercice_1c = $(subst .c,.d,$(SRC_EXT_exercice_1c))
DFILES_exercice_1c = $(subst .c,.d,$(SRC_exercice_1c))


#-------
# programme exercice 1c_bis
#-------
BIN_exercice_1c_bis = exercice_1c_bis

SRC_LOC_exercice_1c_bis = exercice_1c_bis.c
SRC_EXT_exercice_1c_bis = $(ASSERT)/myassert.c $(SEMAPHORE)/Semaphore.c $(FICHIER)/fichier.c
SRC_exercice_1c_bis = $(SRC_LOC_exercice_1c_bis) $(SRC_EXT_exercice_1c_bis)

OBJ_LOC_exercice_1c_bis = $(subst .c,.o,$(SRC_LOC_exercice_1c_bis))
OBJ_EXT_exercice_1c_bis = $(subst .c,.o,$(SRC_EXT_exercice_1c_bis))
OBJ_exercice_1c_bis = $(subst .c,.o,$(SRC_exercice_1c_bis))

DFILES_LOC_exercice_1c_bis = $(subst .c,.d,$(SRC_LOC_exercice_1c_bis))
DFILES_EXT_exercice_1c_bis = $(subst .c,.d,$(SRC_EXT_exercice_1c_bis))
DFILES_exercice_1c_bis = $(subst .c,.d,$(SRC_exercice_1c_bis))


#-------
# programme exercice 1d
#-------
BIN_exercice_1d = exercice_1d

SRC_LOC_exercice_1d = exercice_1d.c
SRC_EXT_exercice_1d = $(ASSERT)/myassert.c $(SEMAPHORE)/Semaphore.c $(FICHIER)/fichier.c
SRC_exercice_1d = $(SRC_LOC_exercice_1d) $(SRC_EXT_exercice_1d)

OBJ_LOC_exercice_1d = $(subst .c,.o,$(SRC_LOC_exercice_1d))
OBJ_EXT_exercice_1d = $(subst .c,.o,$(SRC_EXT_exercice_1d))
OBJ_exercice_1d = $(subst .c,.o,$(SRC_exercice_1d))

DFILES_LOC_exercice_1d = $(subst .c,.d,$(SRC_LOC_exercice_1d))
DFILES_EXT_exercice_1d = $(subst .c,.d,$(SRC_EXT_exercice_1d))
DFILES_exercice_1d = $(subst .c,.d,$(SRC_exercice_1d))


#-------
# programme exercice 1d
#-------
BIN_exercice_1e = exercice_1e

SRC_LOC_exercice_1e = exercice_1e.c
SRC_EXT_exercice_1e = $(ASSERT)/myassert.c $(SEMAPHORE)/Semaphore.c
SRC_exercice_1e = $(SRC_LOC_exercice_1e) $(SRC_EXT_exercice_1e)

OBJ_LOC_exercice_1e = $(subst .c,.o,$(SRC_LOC_exercice_1e))
OBJ_EXT_exercice_1e = $(subst .c,.o,$(SRC_EXT_exercice_1e))
OBJ_exercice_1e = $(subst .c,.o,$(SRC_exercice_1e))

DFILES_LOC_exercice_1e = $(subst .c,.d,$(SRC_LOC_exercice_1e))
DFILES_EXT_exercice_1e = $(subst .c,.d,$(SRC_EXT_exercice_1e))
DFILES_exercice_1e = $(subst .c,.d,$(SRC_exercice_1e))


#-------
# programme exercice 2b
#-------
BIN_exercice_2b = exercice_2b

SRC_LOC_exercice_2b = exercice_2b.c
SRC_EXT_exercice_2b = $(ASSERT)/myassert.c $(SEMAPHORE)/Semaphore.c
SRC_exercice_2b = $(SRC_LOC_exercice_2b) $(SRC_EXT_exercice_2b)

OBJ_LOC_exercice_2b = $(subst .c,.o,$(SRC_LOC_exercice_2b))
OBJ_EXT_exercice_2b = $(subst .c,.o,$(SRC_EXT_exercice_2b))
OBJ_exercice_2b = $(subst .c,.o,$(SRC_exercice_2b))

DFILES_LOC_exercice_2b = $(subst .c,.d,$(SRC_LOC_exercice_2b))
DFILES_EXT_exercice_2b = $(subst .c,.d,$(SRC_EXT_exercice_2b))
DFILES_exercice_2b = $(subst .c,.d,$(SRC_exercice_2b))


#-------
# programme exercice 2d
#-------
BIN_exercice_2d = exercice_2d

SRC_LOC_exercice_2d = exercice_2d.c
SRC_EXT_exercice_2d = $(ASSERT)/myassert.c $(SEMAPHORE)/Semaphore.c
SRC_exercice_2d = $(SRC_LOC_exercice_2d) $(SRC_EXT_exercice_2d)

OBJ_LOC_exercice_2d = $(subst .c,.o,$(SRC_LOC_exercice_2d))
OBJ_EXT_exercice_2d = $(subst .c,.o,$(SRC_EXT_exercice_2d))
OBJ_exercice_2d = $(subst .c,.o,$(SRC_exercice_2d))

DFILES_LOC_exercice_2d = $(subst .c,.d,$(SRC_LOC_exercice_2d))
DFILES_EXT_exercice_2d = $(subst .c,.d,$(SRC_EXT_exercice_2d))
DFILES_exercice_2d = $(subst .c,.d,$(SRC_exercice_2d))


#-------
# programme exercice 2e
#-------
BIN_exercice_2e = exercice_2e

SRC_LOC_exercice_2e = exercice_2e.c
SRC_EXT_exercice_2e = $(ASSERT)/myassert.c $(SEMAPHORE)/Semaphore.c
SRC_exercice_2e = $(SRC_LOC_exercice_2e) $(SRC_EXT_exercice_2e)

OBJ_LOC_exercice_2e = $(subst .c,.o,$(SRC_LOC_exercice_2e))
OBJ_EXT_exercice_2e = $(subst .c,.o,$(SRC_EXT_exercice_2e))
OBJ_exercice_2e = $(subst .c,.o,$(SRC_exercice_2e))

DFILES_LOC_exercice_2e = $(subst .c,.d,$(SRC_LOC_exercice_2e))
DFILES_EXT_exercice_2e = $(subst .c,.d,$(SRC_EXT_exercice_2e))
DFILES_exercice_2e = $(subst .c,.d,$(SRC_exercice_2e))


#-------
# programme exercice 3
#-------
BIN_exercice_3 = exercice_3

SRC_LOC_exercice_3 = exercice_3.c
SRC_EXT_exercice_3 = $(ASSERT)/myassert.c $(SEMAPHORE)/Semaphore.c  $(FICHIER)/fichier.c
SRC_exercice_3 = $(SRC_LOC_exercice_3) $(SRC_EXT_exercice_3)

OBJ_LOC_exercice_3 = $(subst .c,.o,$(SRC_LOC_exercice_3))
OBJ_EXT_exercice_3 = $(subst .c,.o,$(SRC_EXT_exercice_3))
OBJ_exercice_3 = $(subst .c,.o,$(SRC_exercice_3))

DFILES_LOC_exercice_3 = $(subst .c,.d,$(SRC_LOC_exercice_3))
DFILES_EXT_exercice_3 = $(subst .c,.d,$(SRC_EXT_exercice_3))
DFILES_exercice_3 = $(subst .c,.d,$(SRC_exercice_3))


#-------
# tous
#-------
BINS = $(BIN_exemple) \
       $(BIN_exercice_1b) \
       $(BIN_exercice_1c) \
       $(BIN_exercice_1c_bis) \
       $(BIN_exercice_1d) \
       $(BIN_exercice_1e) \
       $(BIN_exercice_2b) \
       $(BIN_exercice_2d) \
       $(BIN_exercice_2e) \
       $(BIN_exercice_3)
SRCS = $(SRC_exemple) \
       $(SRC_exercice_1b) \
       $(SRC_exercice_1c) \
       $(SRC_exercice_1c_bis) \
       $(SRC_exercice_1d) \
       $(SRC_exercice_1e) \
       $(SRC_exercice_2b) \
       $(SRC_exercice_2d) \
       $(SRC_exercice_2e) \
       $(SRC_exercice_3)
OBJS_LOC = $(OBJ_LOC_exemple) \
           $(OBJ_LOC_exercice_1b) \
           $(OBJ_LOC_exercice_1c) \
           $(OBJ_LOC_exercice_1c_bis) \
           $(OBJ_LOC_exercice_1d) \
           $(OBJ_LOC_exercice_1e) \
           $(OBJ_LOC_exercice_2b) \
           $(OBJ_LOC_exercice_2d) \
           $(OBJ_LOC_exercice_2e) \
           $(OBJ_LOC_exercice_3)
OBJS_EXT = $(OBJ_EXT_exemple) \
           $(OBJ_EXT_exercice_1b) \
           $(OBJ_EXT_exercice_1c) \
           $(OBJ_EXT_exercice_1c_bis) \
           $(OBJ_EXT_exercice_1d) \
           $(OBJ_EXT_exercice_1e) \
           $(OBJ_EXT_exercice_2b) \
           $(OBJ_EXT_exercice_2d) \
           $(OBJ_EXT_exercice_2e) \
           $(OBJ_EXT_exercice_3)
OBJS = $(OBJ_exemple) \
       $(OBJ_exercice_1b) \
       $(OBJ_exercice_1c) \
       $(OBJ_exercice_1c_bis) \
       $(OBJ_exercice_1d) \
       $(OBJ_exercice_1e) \
       $(OBJ_exercice_2b) \
       $(OBJ_exercice_2d) \
       $(OBJ_exercice_2e) \
       $(OBJ_exercice_3)
DFILESS_LOC = $(DFILES_LOC_exemple) \
              $(DFILES_LOC_exercice_1b) \
              $(DFILES_LOC_exercice_1c) \
              $(DFILES_LOC_exercice_1c_bis) \
              $(DFILES_LOC_exercice_1d) \
              $(DFILES_LOC_exercice_1e) \
              $(DFILES_LOC_exercice_2b) \
              $(DFILES_LOC_exercice_2d) \
              $(DFILES_LOC_exercice_2e) \
              $(DFILES_LOC_exercice_3)
DFILESS_EXT = $(DFILES_EXT_exemple) \
              $(DFILES_EXT_exercice_1b) \
              $(DFILES_EXT_exercice_1c) \
              $(DFILES_EXT_exercice_1c_bis) \
              $(DFILES_EXT_exercice_1d) \
              $(DFILES_EXT_exercice_1e) \
              $(DFILES_EXT_exercice_2b) \
              $(DFILES_EXT_exercice_2d) \
              $(DFILES_EXT_exercice_2e) \
              $(DFILES_EXT_exercice_3)
DFILESS = $(DFILES_exemple) \
          $(DFILES_exercice_1b) \
          $(DFILES_exercice_1c) \
          $(DFILES_exercice_1c_bis) \
          $(DFILES_exercice_1d) \
          $(DFILES_exercice_1e) \
          $(DFILES_exercice_2b) \
          $(DFILES_exercice_2d) \
          $(DFILES_exercice_2e) \
          $(DFILES_exercice_3)


#########################################################
# explicite rules
#########################################################

all: $(BINS)

$(BIN_exemple): $(OBJ_exemple)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ_exemple) $(LDFLAGS)

$(BIN_exercice_1b): $(OBJ_exercice_1b)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ_exercice_1b) $(LDFLAGS)

$(BIN_exercice_1c): $(OBJ_exercice_1c)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ_exercice_1c) $(LDFLAGS)

$(BIN_exercice_1c_bis): $(OBJ_exercice_1c_bis)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ_exercice_1c_bis) $(LDFLAGS)

$(BIN_exercice_1d): $(OBJ_exercice_1d)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ_exercice_1d) $(LDFLAGS)

$(BIN_exercice_1e): $(OBJ_exercice_1e)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ_exercice_1e) $(LDFLAGS)

$(BIN_exercice_2b): $(OBJ_exercice_2b)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ_exercice_2b) $(LDFLAGS)

$(BIN_exercice_2d): $(OBJ_exercice_2d)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ_exercice_2d) $(LDFLAGS)

$(BIN_exercice_2e): $(OBJ_exercice_2e)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ_exercice_2e) $(LDFLAGS)

$(BIN_exercice_3): $(OBJ_exercice_3)
	@echo "creating" $@
	@$(CC) $(CFLAGS) -o $@ $(OBJ_exercice_3) $(LDFLAGS)

#########################################################
# generic rules
#########################################################
install:
	@echo install to do

uninstall:
	@echo uninstall to do

clean:
	@echo "deleting" $(OBJS_LOC) $(DFILESS_LOC)
	@$(RM) $(OBJS_LOC) $(DFILESS_LOC)

distclean: clean
	@echo "deleting" $(BINS)
	@$(RM) $(BINS)

cleanall: clean
	@for dir in $(DIR_EXT); \
	do \
		pushd $$dir > /dev/null; \
		make -s clean; \
		popd > /dev/null; \
	done

distcleanall: cleanall
	@echo "deleting" $(BINS)
	@$(RM) $(BINS)

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
