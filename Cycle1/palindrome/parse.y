%{
#include<stdio.h>
int yylex();
void yyerror();
int i=0;
struct abc
{
	char c;
	int type;
};
%}

%union
{
	struct abc *e;
}
%token EOL
%token 'a' 'b'
%type <e> E

%start S

%%

S: 
| S E EOL	{printf("yaas"); if($2->type==1) printf("valid\n"); else printf("invalid\n"); printf(">");}
;

E: 
|'a' E 'a'	
{	printf("one\n");	
	struct abc *a = malloc(sizeof(struct abc));  
	a->type = $2->type; 
	$$ = a; 
}
| 'b' E 'b'	
{	printf("two\n");
	struct abc *a = malloc(sizeof(struct abc));  
	a->type = $2->type; 
	$$ = a; 
}
| 'a'	
{	printf("three\n");
	struct abc *a = malloc(sizeof(struct abc));  
	a->type = 1; 
	$$ = a; 
}
| 'b'	
{	printf("four\n");
	struct abc *a = malloc(sizeof(struct abc));  
	a->type = 1; 
	$$ = a; 
}
| 'a' E 'b'	
{	printf("five\n");	
	struct abc *a = malloc(sizeof(struct abc));  
	a->type = 0; 
	$$ = a; 
}
| 'b' E 'a'	
{	printf("six\n");	
	struct abc *a = malloc(sizeof(struct abc));  
	a->type = 0; 
	$$ = a; 
}
;

%%

