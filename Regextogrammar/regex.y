%{
	#include<stdio.h>
	#include<string.h>
	//using namespace std;
	char sym = 'A';
	void yyerror(char *s);
	extern int yylex();

%}

%union {
	char s[20];
	struct rule
	{
		char lhs;
		char rhs[20];
	} r;
}

%token EOL '+' '*' '|' 
%token <s> TERM
%type <r> E

%start prog

%%

prog : 
|	prog T EOL	{}

;


T :	E	{ sym = 'A'; printf("S->%c\n> ",$1.lhs);} 
;
E:	E E	
{	$$.lhs = sym; 
	char s[20];
	memset(s,'\0',20);
	s[0] = $1.lhs;
	s[1] = $2.lhs;
	s[2]='\0';
	memset($$.rhs,'\0',20);
	strcpy($$.rhs,s);
	sym++;
	//cout<<$$.lhs<<"->"$$.rhs<<endl;
	printf("%c->%s EE\n",$$.lhs,$$.rhs);
}
| E '|' E	
{	$$.lhs = sym;
	sym++;
	char s[20];
	memset(s,'\0',20);
	s[0]=$1.lhs;
	s[1]='|';
	s[2]=$3.lhs;
	memset($$.rhs,'\0',20);
	strcpy($$.rhs,s);
	//cout<<$$.lhs<<"->"$$.rhs<<endl;
	printf("%c->%s E|E\n",$$.lhs,$$.rhs);	
}
| '(' E ')'
{
	$$.lhs = $2.lhs;
	strcpy($$.rhs, $2.rhs);
}
| '('E')''*'
{
	$$.lhs = sym;
	char s[20];
	memset(s,'\0',20);
	s[0]=sym;
	s[1]=sym;
	s[2]='|';
	s[3]=$2.lhs;
	s[4]='|';
	s[5]='#';
	memset($$.rhs,'\0',20);
	strcpy($$.rhs,s);
	sym++;
	//cout<<$$.lhs<<"->"$$.rhs<<endl;
	printf("%c->%s (E)*\n",$$.lhs,$$.rhs);	
}
| E '*'
{	$$.lhs = sym;
	char s[20];
	memset(s,'\0',20);
	s[0]=sym;
	s[1]=sym;
	s[2]='|';
	s[3]=$1.lhs;
	s[4]='|';
	s[5]='#';
	memset($$.rhs,'\0',20);
	strcpy($$.rhs,s);
	sym++;
	//cout<<$$.lhs<<"->"$$.rhs<<endl;
	printf("%c->%s E*\n",$$.lhs,$$.rhs);	
}
| '('E')''+'
{	$$.lhs = sym;
	char s[20];
	memset(s,'\0',20);
	s[0]=sym;
	s[1]=sym;
	s[2]='|';
	s[3]=$2.lhs;
	memset($$.rhs,'\0',20);
	strcpy($$.rhs,s);
	sym++;
	//cout<<$$.lhs<<"->"$$.rhs<<endl;
	printf("%c->%s (E)+\n",$$.lhs,$$.rhs);	
}
| E '+'
{	$$.lhs = sym;
	char s[20];
	memset(s,'\0',20);
	s[0]=sym;
	s[1]=sym;
	s[2]='|';
	s[3]=$1.lhs;
	memset($$.rhs,'\0',20);
	strcpy($$.rhs,s);
	sym++;
	//cout<<$$.lhs<<"->"$$.rhs<<endl;
	printf("%c->%s E+\n",$$.lhs,$$.rhs);	
}
| TERM '|' TERM
{
	$$.lhs = sym;
	sym++;
	char s[20];
	memset(s,'\0',20);
	strcpy(s,$1);
	strcat(s,"|");
	strcat(s,$3);
	memset($$.rhs,'\0',20);
	strcpy($$.rhs,s);
	printf("%c->%s term | term\n",$$.lhs,$$.rhs);
}
| TERM	
{	$$.lhs = sym;
	sym++;
	memset($$.rhs,'\0',20);
	strcpy($$.rhs,$1);
	//cout<<$$.lhs<<"->"$$.rhs<<endl;
	printf("%c->%s term\n",$$.lhs,$$.rhs);	
}

;

%%
