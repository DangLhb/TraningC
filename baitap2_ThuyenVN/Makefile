CC=gcc
TARGET=main
HDRS+=	link_list.h
CSRCS+=main.c
CSRCS+=	link_list.c

# OBJSDIR=./build
OBJ=main.o	link_list.o
DEPS=link_list.h

$(TARGET):	$(OBJ)
	$(CC)	-o	$@	$(OBJ)
%.o:	%.c	$(DEPS)
	$(CC)	-c	$<
clean:
	rm	-f	$(TARGET)	$(OBJ)