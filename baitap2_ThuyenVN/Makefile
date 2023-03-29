CC=gcc
TARGET=main
HDRS+=	link_list.h
HDRS+=	recursive.h
CSRCS+=	main.c
CSRCS+=	link_list.c
CSRCS+=	recursive.c

# OBJSDIR=./build
OBJ=main.o	link_list.o	recursive.o
DEPS=link_list.h	recursive.h

$(TARGET):	$(OBJ)
	$(CC)	-o	$@	$(OBJ)
%.o:	%.c	$(DEPS)
	$(CC)	-c	$<
clean:
	rm	-f	$(TARGET)	$(OBJ)