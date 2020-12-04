CC = gcc
CFLAGS = -ansi -Wall -Iincludes

IRIR = ./includes/
SRCDIR = ./src/
BINDIR = ./bin/

SOURCES = $(SRCDIR)*.c

all: contactList

contactList: $(BINDIR)main.o $(BINDIR)contactList.o
	$(CC) $(BINDIR)main.o $(BINDIR)contactList.o -o $@

$(BINDIR)main.o: $(SRCDIR)main.c
	$(CC) $(CFLAGS) -c $(SRCDIR)main.c -o $@

$(BINDIR)contactList.o: $(SRCDIR)contactList.c
	$(CC) $(CFLAGS) -c $(SRCDIR)contactList.c -o $@

run: 
	./contactList

clean:
	rm ./bin/*.o ./contactList

