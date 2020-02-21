%{
	#include"parse.tab.h"
	extern int i;
%}

%%

"b" |
"a" { printf("sent %c\n",yytext[0]);return yytext[0]; }
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
	yyparse();
	if(i==0)
		printf("hovalid\n"); 
	else
		printf("hoinvalid\n");
}
