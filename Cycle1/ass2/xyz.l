%option noyywrap nodefault yylineno
%{
# include "xyz.h"
# include "xyz.tab.h"
%}

EXP ([Ee][-+]?[0-9]+)

%%

"+" |
"-" |
"*" |
"/" |
"|" |
"(" |
")" { return yytext[0]; }
[0-9]+"."[0-9]*{EXP}? |
"."?[0-9]+{EXP}? { yylval.d = atof(yytext); return NUMBER; }
\n  { return EOL; }
"//".* {}
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
