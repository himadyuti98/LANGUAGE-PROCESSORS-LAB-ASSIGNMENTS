ass5: ass5.l ass5.y ass5.h
	bison -d ass5.y
	flex ass5.l
	gcc -o $@ ass5.tab.c lex.yy.c ass5.c -lm
