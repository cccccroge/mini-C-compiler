all:
	flex scanner.l
	byacc -d -v parser.y
	gcc -o parser lex.yy.c y.tab.c -lfl

clean:
	rm -f parser lex.yy.c y.output y.tab.c y.tab.h
