%{
	#include "regex.tab.h"
	extern YYSTYPE yylval;
	extern int yylex();
	void yyerror(char *s);
%}

%%
"|" |
"+" |
"*" |
"(" |
")"	{return yytext[0];}
[0-9a-z]+	{strcpy(yylval.s,yytext) ; return TERM;} 
\n	{return EOL;}

%%

int main()
{
	printf("> ");
	
	return yyparse();
}
void yyerror(char *s)
{
	printf("%s\n",s);
}
