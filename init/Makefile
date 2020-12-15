CC        ?= x86_64-apathy-linux-musl-gcc-gcc
AR        ?= x86_64-apathy-linux-musl-gcc-ar
RANLIB    ?= x86_64-apathy-linux-musl-gcc-ranlib
CFLAGS    += -std=c99 -D_FILE_OFFSET_BITS=64 -D_XOPEN_SOURCE=700 -D_GNU_SOURCE

LIBUTILSRC = libutil/agetcwd.c   libutil/agetline.c  libutil/apathmax.c       \
             libutil/concat.c    libutil/ealloc.c    libutil/eprintf.c        \
             libutil/estrtol.c   libutil/estrtoul.c  libutil/explicit_bzero.c \
             libutil/passwd.c    libutil/proc.c      libutil/putword.c        \
             libutil/recurse.c   libutil/strlcat.c   libutil/strlcpy.c        \
             libutil/strtonum.c  libutil/tty.c
LIBUTILOBJ = $(LIBUTILSRC:.c=.o)

LIBUTIL    = libutil.a
UBASE      = ctrlaltdel getty halt killall5 login respawn
INIT       = init

OBJ        = $(UBASE:=.o) $(LIBUTILOBJ) $(INIT:=.o)
SRC        = $(UBASE:=.c) $(INIT:=.c)

all: $(UBASE) $(INIT)

$(UBASE): $(LIBUTIL)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBUTIL): $(LIBUTILOBJ)
	$(AR)     rc $@ $?
	$(RANLIB)    $@

install: all
	mkdir -pv            $(DESTDIR)/mss/init/bin
	cp    -fv  $(UBASE)  $(DESTDIR)/mss/init/bin
	cd                   $(DESTDIR)/mss/init/bin && chmod 755 $(UBASE)

	mkdir -pv            $(DESTDIR)/sbin
	cp    -fv  $(INIT)   $(DESTDIR)/sbin/init


clean:
	rm    -f  $(UBASE) $(INIT) $(LIBUTIL) $(OBJ) $(LIB)

.PHONY:
	all install clean
