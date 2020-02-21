xyz: xyz.l xyz.y xyz.h
	bison -d xyz.y
	flex -oxyz.lex.c xyz.l
	gcc -o $@ xyz.tab.c xyz.lex.c xyz.c
