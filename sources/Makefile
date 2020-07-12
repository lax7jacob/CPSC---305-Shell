CC = gcc
CFLAGS = -g -Wall

default: mainshell

mainshell:  main.o line_handler.o pipe_handler.o file_handler.o prompt.o intcmd.o extcmd.o
	$(CC) $(CFLAGS) -o mainshell main.o line_handler.o pipe_handler.o file_handler.o prompt.o intcmd.o extcmd.o


main.o: main.c shell.h
	$(CC) $(CFLAGS) -c main.c


line_handler.o: line_handler.c shell.h
	$(CC) $(CFLAGS) -c line_handler.c

pipe_handler.o: pipe_handler.c shell.h
	$(CC) $(CFLAGS) -c pipe_handler.c

file_handler.o: file_handler.c shell.h
	$(CC) $(CFLAGS) -c file_handler.c

prompt.o: prompt.c shell.h
	$(CC) $(CFLAGS) -c prompt.c

intcmd.o: intcmd.c shell.h
	$(CC) $(CFLAGS) -c intcmd.c

extcmd.o: extcmd.c shell.h
	$(CC) $(CFLAGS) -c extcmd.c

clean:
	rm -f mainshell *.o

