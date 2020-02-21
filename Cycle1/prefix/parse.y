%{
#include<stdio.h>
int yylex();
void yyerror();
%}
%union{
	char buff[20];
}
%token NUMBER EOL
%left '+' '-'
%left '*' '/'

%type <buff> E NUMBER S
%start S

%%

S: 
| S E EOL	{printf("%s\n> ",$2);}
;

E: E '+' E	{sprintf($$,"+%s%s",$1,$3); printf("%s\n",$$);}
| E '-' E	{sprintf($$,"-%s%s",$1,$3);printf("%s\n",$$);}
| E '*' E	{sprintf($$,"*%s%s",$1,$3);printf("%s\n",$$);}
| E '/' E	{sprintf($$,"/%s%s",$1,$3);printf("%s\n",$$);}
| '(' E ')'     {sprintf($$,"%s", $2);printf("%s\n",$$);}
| NUMBER	{sprintf($$,"%s", yyval.buff);printf("%s\n",$$);}

;

%%

