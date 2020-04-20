all: scanner

clean:
	@$(RM) lex.yy.c scanner



lex.yy.c:
	flex ./scanner.l

scanner: lex.yy.c
	gcc $^ -lfl -o scanner
