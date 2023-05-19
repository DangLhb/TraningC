CC=gcc
TARGET=main
HDRS+=	function.h
CSRCS+=	main.c
CSRCS+=	function.c

OBJ=main.o	function.o
DEPS=function.h

$(TARGET):	$(OBJ)
	$(CC)	-o	$@	$(OBJ)
%.o:	%.c	$(DEPS)
	$(CC)	-c	$<
clean:
	rm	-f	$(TARGET)	$(OBJ)