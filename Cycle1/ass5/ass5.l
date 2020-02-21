%option noyywrap nodefault yylineno
%{
# include "ass5.h"
# include "ass5.tab.h"
%}

EXP	([Ee][-+]?[0-9]+)

%%

"+" |
"-" |
"*" |
"/" |
"@" |
"=" |
"," |
";" |
"(" |
")" 	{ return yytext[0]; }

">"	{yylval.fn = 1; return CMP;}
"<"	{yylval.fn = 2; return CMP;}
"!="	{yylval.fn = 3; return CMP;}
"=="	{yylval.fn = 4; return CMP;}
">="	{yylval.fn = 5; return CMP;}
"<="	{yylval.fn = 6; return CMP;}

"if"	{return IF;}
"else"	{return ELSE;}
"then"	{return THEN;}
"while"	{return WHILE;}
"do"	{return DO;}
"let"	{return LET;}
"display"	{return DISP;}

[a-zA-Z][a-zA-Z0-9]*	{yylval.s = lookup(yytext); return NAME;}
[0-9]+"."[0-9]*{EXP}? |
"."?[0-9]+{EXP}?	{yylval.d = atof(yytext); return NUMBER;}

[ \t]	

\n	{return EOL;}

.	{yyerror("Mystery character"); }

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
