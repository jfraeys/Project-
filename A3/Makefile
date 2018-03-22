#
# Makefile for TINY
# Using flex and yacc
#

CC = gcc

CFLAGS =

OBJS = y.tab.o lex.yy.o analyze.o symtable.o util.o main.o

cminus: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -ly -ll

main.o: main.c globals.h util.h scan.h parse.h
	$(CC) $(CFLAGS) -c $<

util.o: util.c util.h globals.h y.tab.h
	$(CC) $(CFLAGS) -c $<

analyze.o: analyze.c globals.h symtable.h analyze.h
	$(CC) $(CFLAGS) -c analyze.c

symtable.o: symtable.c symtable.h
		$(CC) $(CFLAGS) -c $<

lex.yy.c: cminus.l
	flex cminus.l

lex.yy.o: lex.yy.c globals.h util.h y.tab.h
	$(CC) $(CFLAGS) -c lex.yy.c

y.tab.c: cminus.y
	yacc -d -v cminus.y

y.tab.o: y.tab.c globals.h util.h scan.h parse.h
	$(CC) $(CFLAGS) -c y.tab.c

run:
	./cminus $(ARGS)

clean:
	rm -f cminus $(OBJS) lex.yy.c y.tab.h y.tab.c y.output
