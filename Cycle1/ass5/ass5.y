%{
#include<stdio.h>
#include<stdlib.h>
#include "ass5.h"

int yylex();

%}

%union {
	struct ast *a;
	double d;
	struct symbol *s;
	int fn;
}

%token <d> NUMBER
%token <s> NAME
%token EOL
%token IF THEN ELSE WHILE DO LET DISP
%token <fn> FUNC

%nonassoc <fn> CMP 
%nonassoc DISP
%right '='
%left '+' '-'
%left '*' '/'
%right '@'
%nonassoc '|' UM

%type <a> exp stmt list 

%start calclist

%%

stmt:	IF exp THEN list	{ $$ = newflow('I',$2,$4,NULL);}
	| IF exp THEN list ELSE list	{ $$ = newflow('I',$2,$4,$6);}
	| WHILE exp DO list	{$$= newflow('W',$2,$4,NULL);}
	|exp
;

list:		{$$=NULL;}
	| stmt ';' list { if($3 == NULL)
				$$ = $1;
			 else
				$$ = newast('L',$1,$3);
			}
;

exp:	exp CMP exp	{ $$ = newcmp($2,$1,$3); }
	| exp '+' exp	{ $$ = newast('+', $1, $3); }
	| exp '-' exp	{ $$ = newast('-', $1, $3); }
	| exp '*' exp	{ $$ = newast('*', $1, $3); }
	| exp '/' exp	{ $$ = newast('/', $1, $3); }
	| exp '@' exp	{ $$ = newast('@', $1, $3); }
	| '(' exp ')'	{ $$ = $2; }
	| '-' exp %prec UM	{ $$ = newast('M', $2, NULL); }
	| NUMBER	{ $$ = newnum($1); }
	| NAME		{ $$ = newref($1); }
	| LET NAME '=' exp	{ $$ = newasgn($2,$4); }
	//| DISP NAME	{ $$ = newref($2); }
	| DISP exp	{ $$ = newref(((struct symref *)$2)->s); }
;

calclist:
	| calclist stmt EOL	{
		printf("= %4.4g\n", eval($2));
		//treefree($2);
	}



