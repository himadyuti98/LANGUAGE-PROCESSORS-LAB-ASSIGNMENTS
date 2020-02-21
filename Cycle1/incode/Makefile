incode: incode.l incode.y
	bison -d incode.y
	flex incode.l
	gcc -o $@ incode.tab.c lex.yy.c -lfl
