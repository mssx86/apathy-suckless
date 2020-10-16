CC      ?= x86_64-apathy-linux-musl-gcc
CFLAGS  += -std=c99 -D_XOPEN_SOURCE=600 -DVERSION=\"0.8.4-apathy\" -I/usr/include/freetype2 
LDFLAGS += -s -lX11 -lXft -lXrender -lfontconfig -lfreetype -lm -lrt -lutil 

SRC      = st.c x.c
OBJ      = $(SRC:.c=.o)

all: st

.c.o:
	${CC} -c ${CFLAGS} ${CPPFLAGS} $<

st: ${OBJ}
	${CC} -o $@ ${OBJ} ${CFLAGS} ${LDFLAGS}

clean:
	rm -f st $(OBJ)

install: st
	mkdir -p    $(DESTDIR)/usr/bin
	cp    -f st $(DESTDIR)/usr/bin
	chmod 755   $(DESTDIR)/usr/bin/st
	tic   -sx   st.info

.PHONY: all clean install
