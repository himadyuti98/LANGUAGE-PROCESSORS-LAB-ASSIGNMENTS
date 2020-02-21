%{
	#include"parse.tab.h"
	//extern int yylval;
%}

%%

"+" |
"-" |
"*" |
"/" |
"|" |
"(" |
")" { return yytext[0]; }
[0-9]+ { strcpy(yylval.buff,yytext); return NUMBER; }
\n  { return EOL; }
[ \t]  {}
.  { printf("Mystery character %c\n", *yytext); }


%%

void yyerror(char *s)
{
	printf("%s\n",s);
}
int main()
{
	printf("> ");
	return yyparse();
}
