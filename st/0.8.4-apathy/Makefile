CC       = clang
CPPFLAGS = -D_XOPEN_SOURCE=600 -I/usr/include/freetype2 \
           -DVERSION=\"0.8.4-apathy\"
CFLAGS   = -std=c99 -O2
LDFLAGS  = -s -lm -lrt -lX11 -lutil -lXft -lXrender -lfontconfig -lfreetype

SRC = st.c x.c
OBJ = $(SRC:.c=.o)

all: st

.c.o:
	${CC} -c ${CFLAGS} ${CPPFLAGS} $<

st: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f st $(OBJ)

install: st
	mkdir -p    $(DESTDIR)/usr/bin
	cp    -f st $(DESTDIR)/usr/bin
	chmod 755   $(DESTDIR)/usr/bin/st
	tic   -sx   st.info

.PHONY: all clean install
