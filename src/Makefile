TARGET=list
CC=gcc
CFLAGS=-I../include -g
OBJS=main.o list.o
SRCS=main.c list.c

${TARGET}: ${OBJS}
	${CC} ${CFLAGS} -o ${TARGET} ${OBJS}

main.o: main.c ../include/list.h
list.o: list.c ../include/list.h
