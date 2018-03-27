# use conf-* for configuration.
SHELL = /bin/sh

default: compute

clean: 
	rm -f *.o systype compile load makelib compute

compile: \
warn-auto.sh conf-cc
	( cat warn-auto.sh; \
	echo exec "`head -1 conf-cc`" '-c $${1+"$$@"}' \
	) > compile
	chmod 755 compile

load: \
warn-auto.sh conf-ld
	( cat warn-auto.sh; \
	echo 'main="$$1"; shift'; \
	echo exec "`head -1 conf-ld`" \
	'-o "$$main" "$$main".o $${1+"$$@"}' \
	) > load
	chmod 755 load

makelib: \
warn-auto.sh systype
	( cat warn-auto.sh; \
	echo 'main="$$1"; shift'; \
	echo 'rm -f "$$main"'; \
	echo 'ar cr "$$main" $${1+"$$@"}'; \
	case "`cat systype`" in \
	sunos-5.*) ;; \
	unix_sv*) ;; \
	irix64-*) ;; \
	irix-*) ;; \
	dgux-*) ;; \
	hp-ux-*) ;; \
	sco*) ;; \
	*) echo 'ranlib "$$main"' ;; \
	esac \
	) > makelib
	chmod 755 makelib

systype: \
find-systype.sh conf-cc conf-ld trycpp.c
	( cat warn-auto.sh; \
	echo CC=\'`head -1 conf-cc`\'; \
	echo LD=\'`head -1 conf-ld`\'; \
	cat find-systype.sh; \
	) | sh > systype

socket.lib: \
trylsock.c compile load
	( ( ./compile trylsock.c && \
        ./load trylsock -lsocket ) >/dev/null 2>&1 \
        && echo -lsocket || exit 0 ) > socket.lib
	rm -f trylsock.o trylsock

init.o: \
compile init.c symbol.h y.tab.h
	./compile init.c

math.o: \
compile math.c
	./compile math.c

stack.o: \
compile stack.c
	./compile stack.c

symbol.o: \
compile symbol.c symbol.h y.tab.h
	./compile symbol.c

y.tab.o: \
compile y.tab.c symbol.h grammar.y
	(which yacc 2>&1 >/dev/null && \
		yacc -d grammar.y || exit 0)
	./compile y.tab.c

compute: \
load y.tab.o symbol.o math.o init.o stack.o
	./load y.tab symbol.o math.o init.o stack.o
	mv y.tab compute
