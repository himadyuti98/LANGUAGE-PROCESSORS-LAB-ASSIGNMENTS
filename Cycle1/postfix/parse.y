%{
#include<stdio.h>
int yylex();
void yyerror();
%}

%token NUMBER EOL
%left '+' '-'
%left '*' '/'

%start S

%%

S: 
| S E EOL	{printf("\n> ");}
;

E: E '+' E	{printf("+");}
| E '-' E	{printf("-");}
| E '*' E	{printf("*");}
| E '/' E	{printf("/");}
| '(' E ')'     {}
| NUMBER	{printf("%d", yyval);}

;

%%

