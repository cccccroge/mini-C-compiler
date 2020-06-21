all:
	flex -o src/lex.yy.c src/scanner.l
	byacc -b src/y -d -v src/parser.y
	g++ -w -o codegen src/symbol.c src/lex.yy.c src/y.tab.c -lfl

clean:
	rm -f codegen src/lex.yy.c src/y.output src/y.tab.c src/y.tab.h
