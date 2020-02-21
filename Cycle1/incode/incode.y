

%{
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
extern int yyparse();
extern FILE *yyin;
void yyerror();

struct symbol{
	char name[20];
	int type;
};

#define NHASH 9997
struct symbol symtab[NHASH];
int nh=0;

struct symbol * lookup(char* sym)
{
	for(int i=0;i<nh;i++)
	{
		if(!strcmp(symtab[i].name,sym))
			return &symtab[i];
	}
	return NULL;
	/*struct symbol *sp=&symtab[n];
	n++;
	if(n>=NHASH)
	{
		fputs("symbol table overflow\n", stderr);
		abort();
	}
	sp->name=strdup(sym);
	return sp;*/
}

void addref(char* name,int type)
{
	struct ref *r;
	struct symbol *sp= lookup(name);
	
	if(sp==NULL)
	{
		printf("here\n");
		strcpy(symtab[nh].name,name);
		printf("here\n");
		symtab[nh].type=type;
		printf("here\n");
		nh++;
		printf("here\n");
	}
	else
	{
		printf("redeclaration\n");
	}
}

struct exprType{

	char *addr;
	char *code;
	
};

int n=1;
int nl = 1;
char *var;
char num_to_concatinate[15];
char num_to_concatinate_l[15];
char *ret,*ret2;
char *temp;

char *label;
char *label2;
char *check;

char *begin, *begin2, *begin3;

char *b1;
char *b2;

char *s1;
char *s2;

struct exprType *to_return_expr;

char * newTemp(){
	
	char *newTemp = (char *)malloc(20);
	strcpy(newTemp,"t");
	sprintf(num_to_concatinate,"%d",n);
	strcat(newTemp,num_to_concatinate);
		
	n++;
	return newTemp;
}

char * newLabel(){
	
	char *newLabel = (char *)malloc(50);
	strcpy(newLabel,"L");
	sprintf(num_to_concatinate_l,"%d",nl);
	strcat(newLabel,num_to_concatinate_l);
		
	nl++;
	return newLabel;
}
%}

%start startSym

%union {
	int ival;
	float fval;
	char *sval;
	struct exprType *EXPRTYPE;
}
%token <ival> DIGIT
%token <fval> FLOAT
%token <sval> ID IF ELSE WHILE FOR TYPES REL_OPT OR AND NOT TRUE FALSE MAIN EOL
%token <sval> '+' '-' '*' '/' '^' '%' '\n' '=' ';' '?' ':'
%type <sval> list list2 text text2 number construct block dec bool program startSym
%type <EXPRTYPE> expr stat stat2


%left OR
%left AND
%left NOT
%left REL_OPT
%right '='
%left '+' '-'
%left '*' '/' '%'
%right '^'

%%

startSym:	MAIN '(' ')' '{' program '}'
		{
			printf("hello\n");
			s1 = $5;
			label = newLabel();

			check = strstr (s1,"NE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (s1,"NE");
				}
			check = strstr (s1,"NEXT");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (s1,"NEXT");
				}

			ret = (char *)malloc(strlen(s1)+50);
			ret[0] = 0;

			strcat(ret,s1);
			strcat(ret,"\n");
			strcat(ret,label);
			strcat(ret," : end !!!!!\n");
			
			printf("\n----------  INTERMEDIATE CODE ----------\nmain:\n");
			puts(ret);

			$$ = ret;
		}
		;

program : 	program construct
		{

			s1 = $1;
			s2 = $2;

			label = newLabel();

			check = strstr (s1,"NE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (s1,"NE");
				}
			check = strstr (s1,"NEXT");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (s1,"NEXT");
				}
			ret = (char *)malloc(strlen($1)+strlen($2)+40);
			ret[0] = 0;
			strcat(ret,$1);
			strcat(ret,"\n");
			strcat(ret,label);
			strcat(ret," : ");
			strcat(ret,$2);

			printf("program construct\n");

			puts(ret);
			$$ = ret;
		}
		|
		construct
		{
			printf("Final Construct \n");
			puts($1);
			$$ = $1;
		}
		|
		list
		{	
			printf("Final list \n");
			puts($1);
			$$ = $1;
		}
		;

construct :     list
		{
			$$=$1;
		}
		|
		block
		{
			$$ = $1;
		}
		|
		FOR '(' list2 ';' bool ';' list2 ')' block
		{
				printf("Inside FOR\n");
				begin = newLabel();
				begin2 = newLabel();
				begin3 = newLabel();
				label = newLabel();
				b1=$5;
				s1=$3;
			check = strstr (s1,"NEXT");
			while(check!=NULL){
				strncpy (check,begin,strlen(begin));
				strncpy (check+strlen(begin),"    ",(4-strlen(begin)));
				check = strstr (s1,"NEXT");
				}

			ret = (char *)malloc(strlen(b1)+strlen(s1)+40);
			ret[0] = 0;
			ret2 = (char *)malloc(strlen(b1)+strlen(s1)+60);
			ret2[0] = 0;
			strcat(ret,begin);
			strcat(ret," : ");
			strcat(ret,s1);
			strcat(ret,"\n");
			strcpy(ret2,ret);
			b1 = $5;
			s1 = $9;
			
			label = newLabel();
			check = strstr (b1,"TRUE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TRUE");
				}

			check = strstr (b1,"FAIL");
			while(check!=NULL){
				strncpy (check,"NEXT",4);
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"FAIL");
				}

			check = strstr (s1,"NEXT");
			while(check!=NULL){
				strncpy (check,begin2,strlen(begin2));
				strncpy (check+strlen(begin2),"    ",(4-strlen(begin2)));
				check = strstr (s1,"NEXT");
				}

			ret = (char *)malloc(strlen(b1)+strlen(s1)+40);
			ret[0] = 0;
			strcat(ret,begin3);
			strcat(ret," : ");
			strcat(ret,b1);
			strcat(ret,"\n");
			strcat(ret,label);
			strcat(ret," : ");
			strcat(ret,s1);

			strcat(ret2,ret);
			s1[0]=0;
			s1=$7;
			check = strstr (s1,"NEXT");
			while(check!=NULL){
				strncpy (check,begin2,strlen(begin));
				strncpy (check+strlen(begin2),"    ",(4-strlen(begin)));
				check = strstr (s1,"NEXT");
				}

			ret = (char *)malloc(strlen(b1)+strlen(s1)+40);
			ret[0] = 0;
			strcat(ret,"\n");
			strcat(ret,begin2);
			strcat(ret," : ");
			
			strcat(ret,s1);
			strcat(ret,"\n");
			strcat(ret,"goto ");
			strcat(ret,begin3);
			
			strcat(ret2,ret);
			
			$$ = ret2;
		}
		|
		WHILE '(' bool ')' block
		{
			printf("Inside WHILE\n");
			b1 = $3;
			s1 = $5;
			begin = newLabel();
			label = newLabel();
			check = strstr (b1,"TRUE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TRUE");
				}

			check = strstr (b1,"FAIL");
			while(check!=NULL){
				strncpy (check,"NEXT",4);
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"FAIL");
				}

			check = strstr (s1,"NEXT");
			while(check!=NULL){
				strncpy (check,begin,strlen(begin));
				strncpy (check+strlen(begin),"    ",(4-strlen(begin)));
				check = strstr (s1,"NEXT");
				}

			ret = (char *)malloc(strlen(b1)+strlen(s1)+40);
			ret[0] = 0;
			strcat(ret,begin);
			strcat(ret," : ");
			strcat(ret,b1);
			strcat(ret,"\n");
			strcat(ret,label);
			strcat(ret," : ");
			strcat(ret,s1);

			strcat(ret,"\n");
			strcat(ret,"goto ");
			strcat(ret,begin);
			puts($5);
			printf("\nFinal return from while\n");
			puts(ret);

			$$ = ret;
	
		}
		|
		IF '(' bool ')' block
		{
			printf("Inside IF\n");
			
			label = newLabel();
			b1 = $3;

			check = strstr (b1,"TRUE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TRUE");
				}
			
			check = strstr (b1,"FAIL");
			
			while(check!=NULL){
				strncpy (check,"NEXT",4);
				//strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"FAIL");
				}

			ret = (char *)malloc(strlen(b1)+strlen($5)+4);
			ret[0] = 0;
			strcat(ret,b1);
			strcat(ret,"\n");
			strcat(ret,label);
			strcat(ret," : ");
			strcat(ret,$5);
			
			puts(ret);
			$$ = ret;
		}
		|
		IF '(' bool ')' block ELSE block
		{
			printf("Inside if then else\n");

			b1 = $3;
			label = newLabel();

			check = strstr (b1,"TRUE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TRUE");
				}
			

			label2 = newLabel();
			check = strstr (b1,"FAIL");

			while(check!=NULL){
				strncpy (check,label2,strlen(label2));
				strncpy (check+strlen(label2),"    ",(4-strlen(label2)));
				check = strstr (b1,"FAIL");
				}

			ret = (char *)malloc(strlen(b1)+strlen($5)+strlen($7)+20);
			ret[0] = 0;
			strcat(ret,b1);
			strcat(ret,"\n");
			strcat(ret,label);
			strcat(ret," : ");
			strcat(ret,$5);
			strcat(ret,"\n");
			strcat(ret,"goto NEXT");
			strcat(ret,"\n");
			strcat(ret,label2);
			strcat(ret," : ");
			strcat(ret,$7);
			
			puts(ret);

			$$ = ret;
	
		}
		|
		bool '?' list2 ':' list2 ';'
		{
			printf("Inside ternary\n");

			b1 = $1;
			label = newLabel();

			check = strstr (b1,"TRUE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TRUE");
				}
			

			label2 = newLabel();
			check = strstr (b1,"FAIL");

			while(check!=NULL){
				strncpy (check,label2,strlen(label2));
				strncpy (check+strlen(label2),"    ",(4-strlen(label2)));
				check = strstr (b1,"FAIL");
				}

			ret = (char *)malloc(strlen(b1)+strlen($3)+strlen($5)+20);
			ret[0] = 0;
			strcat(ret,b1);
			strcat(ret,"\n");
			strcat(ret,label);
			strcat(ret," : ");
			strcat(ret,$3);
			strcat(ret,"\n");
			strcat(ret,"goto NEXT");
			//strcat(ret,label2);
			strcat(ret,"\n");
			strcat(ret,label2);
			strcat(ret," : ");
			strcat(ret,$5);
			
			puts(ret);

			$$ = ret;
		}
		;

block:		'{' list '}'
		{
			printf("Inside block\n");
			$$ = $2;
		}
		|
		'{' construct '}'
		{
			printf("Inside block\n");
			$$ = $2;
		}
		|
		'{''}'
		;
list2:	stat2
		{
			printf("Inside list stat2\n");
			$$ = $1->code;
			printf("Exit list stat2\n");
		}
	;

list:   stat               /* Base Condition */
		{
			printf("Inside list stat\n");
			$$ = $1->code;
			printf("Exit list stat\n");
		}
         |
        list stat
		{
			printf("Inside list\n");
			ret = (char *)malloc(strlen($1)+strlen($2->code)+4);
			ret[0] = 0;

			strcat(ret,$1);
			strcat(ret,"\n");
			strcat(ret,$2->code);
		
			printf("Inside list stat \n");
			puts(ret);
			$$ = ret;
		}
	 |
        list error '\n'
         {
		printf("Inside list\n");
           yyerrok;
         }
         ;

stat2:	'(' stat2 ')'
	{
		$$=$2;
	}
	|
	dec '=' expr
	{
		printf("stat2 Dec and Assignment statement \n");
	    
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		//strcat(ret,to_return_expr->addr);
		
		strcat(ret,$1);
		strcat(ret,"=");
		strcat(ret,$3->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($1)+strlen($3->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
		printf("Exiting stat2\n");
	}
	|
	text '=' expr
	{
		printf("stat2 blah Assignment statement \n");
	    if(strcmp($1,"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		//strcat(ret,to_return_expr->addr);
		
		strcat(ret,$1);
		strcat(ret,"=");
		strcat(ret,$3->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($1)+strlen($3->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
		}
		else
			exit(0);
	}
	|
	expr 
         {
		printf("inside stat2 expr\n");
		$$ = $1;
           
         }
	 |
	 dec 
         {
		printf("stat2 dec\n");
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = $1;
		
		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;
		
		$$ = to_return_expr;
           
         }
	|
	text '+' '=' expr
	{
		printf("$$$$$$$$$$$$$$$$$$$$ %s\n",$1);
		if(strcmp($1,"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,$1);
		strcat(ret,"+");
		strcat(ret,$4->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($4->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($4->code[0]!=0){
			strcat(temp,$4->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,$1);
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
		}
		else
			exit(0);
	    
	}
	|
	text '-' '=' expr
	{
		printf("$$$$$$$$$$$$$$$$$$$$\n");
		if(strcmp($1,"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,$1);
		strcat(ret,"-");
		strcat(ret,$4->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($4->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($4->code[0]!=0){
			strcat(temp,$4->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,$1);
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
		}
		else
			exit(0);
	    }
	|
	text '*' '=' expr
	{
		printf("$$$$$$$$$$$$$$$$$$$$\n");
		if(strcmp($1,"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,$1);
		strcat(ret,"*");
		strcat(ret,$4->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($4->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($4->code[0]!=0){
			strcat(temp,$4->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,$1);
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
		}
		else
			exit(0);
		}
	    |
	text '/' '=' expr
	{
		printf("$$$$$$$$$$$$$$$$$$$$\n");
		if(strcmp($1,"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,$1);
		strcat(ret,"/");
		strcat(ret,$4->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($4->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($4->code[0]!=0){
			strcat(temp,$4->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,$1);
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
		}
		else
			exit(0);
	    
         }
;

stat:    ';'
	 {
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = $1;
		
		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;
		
		$$ = to_return_expr;
	 }
	 |
	 expr ';'
         {
		$$ = $1;
           
         }
	 |
	 dec ';'
         {
		printf("stat dec\n");
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = $1;
		
		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;
		
		$$ = to_return_expr;
           
         }
         |
         text '=' expr ';'
         {
		if(strcmp($1,"undeclared")!=0){
	    printf("Assignment statement \n");

		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,$1);

		strcat(ret,"=");
		strcat(ret,$3->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($3->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
	    
		}
		else
			exit(0);
		//printf(" %s = %s \n",$1,$3->addr);
          
	    
         }
	 |
	 dec '=' expr ';'
         {
	    printf("Dec and Assignment statement \n");
	    
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		//strcat(ret,to_return_expr->addr);
		
		strcat(ret,$1);
		strcat(ret,"=");
		strcat(ret,$3->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($1)+strlen($3->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
			
		//printf(" %s = %s \n",$1,$3->addr);
          printf("Exit Dec and Assignment statement \n");
	    
         }
	
	|
	text '+' '=' expr ';'
	{
		printf("$$$$$$$$$$$$$$$$$$$$\n");
		if(strcmp($1,"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,$1);
		strcat(ret,"+");
		strcat(ret,$4->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($4->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($4->code[0]!=0){
			strcat(temp,$4->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,$1);
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
		}
		else
			exit(0);
	    
	}
	|
	text '-' '=' expr ';'
	{
		printf("$$$$$$$$$$$$$$$$$$$$\n");
		if(strcmp($1,"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,$1);
		strcat(ret,"-");
		strcat(ret,$4->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($4->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($4->code[0]!=0){
			strcat(temp,$4->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,$1);
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
		}
		else
			exit(0);
	    }
	|
	text '*' '=' expr ';'
	{
		printf("$$$$$$$$$$$$$$$$$$$$\n");
		if(strcmp($1,"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,$1);
		strcat(ret,"*");
		strcat(ret,$4->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($4->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($4->code[0]!=0){
			strcat(temp,$4->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,$1);
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
		}
		else
			exit(0);
		}
	    |
	text '/' '=' expr ';'
	{
		printf("$$$$$$$$$$$$$$$$$$$$\n");
		if(strcmp($1,"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,$1);
		strcat(ret,"/");
		strcat(ret,$4->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($4->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($4->code[0]!=0){
			strcat(temp,$4->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,$1);
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
		}
		else
			exit(0);
	    
         }
         ;

dec : 		TYPES text2 
		{	printf("hellllllllllllooooooooooo\n");
			$$ = $2;
			addref($2,TYPES);
		}
		;

bool : 	 	expr REL_OPT expr
		{
			printf("Inside rel opt\n");

			temp = (char *)malloc(strlen($1->code)+strlen($3->code)+50);
			temp[0] = 0;
	
			if($1->code[0]!=0){
				strcat(temp,$1->code);
				strcat(temp,"\n");
				}
			if($3->code[0]!=0){
				strcat(temp,$3->code);
				strcat(temp,"\n");
				}

			ret = (char *)malloc(50);
			ret[0] = 0;
			strcat(ret,"if(");
			strcat(ret,$1->addr);
			strcat(ret,$2);
			strcat(ret,$3->addr);
			strcat(ret,") goto TRUE \n goto FAIL");

			strcat(temp,ret);

			$$ = temp;
			printf("exiting bool relop\n");
		}
		|
		bool OR bool
		{
			printf("Inside OR\n");
			
			b1 = $1;
			b2 = $3;

			label = newLabel();

			check = strstr (b1,"FAIL");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"FAIL");
				}
			
			temp = (char *)malloc(strlen(b1)+strlen(b2)+10);
			temp[0] = 0;

			strcat(temp,b1);
			strcat(temp,"\n");
			strcat(temp,label);
			strcat(temp," : ");
			strcat(temp,b2);

			$$ = temp;
			printf("exiting bool\n");
		}
		|
		bool AND bool
		{
			printf("Inside AND\n");

			b1 = $1;
			b2 = $3;

			label = newLabel();

			check = strstr (b1,"TRUE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TRUE");
				}
			
			temp = (char *)malloc(strlen(b1)+strlen(b2)+10);
			temp[0] = 0;

			strcat(temp,b1);
			strcat(temp,"\n");
			strcat(temp,label);
			strcat(temp," : ");
			strcat(temp,b2);

			$$ = temp;
			printf("exiting bool\n");
		}
		|
		NOT '(' bool ')'
		{
			printf("Inside NOT\n");
			puts($3);

			b1 = $3;

			label = "TEFS";

			check = strstr (b1,"TRUE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				//strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TRUE");
				}
			
			label = "TRUE";
			check = strstr (b1,"FAIL");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				//strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"FAIL");
				}

			label = "FAIL";
			check = strstr (b1,"TEFS");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				//strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TEFS");
				}
			
			$$ = b1;
			printf("exiting bool\n");
		}
		|
		'(' bool ')'
		{
			$$ = $2;
			printf("exiting bool bracket\n");
		}
		|
		TRUE
		{
			printf("Inside TRUE\n");

			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,"\ngoto TRUE");
			
			$$ = ret;
			printf("exiting bool\n");
		}
		|
		FALSE
		{
			printf("Inside FALSE\n");
			
			printf("Inside TRUE\n");

			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,"\ngoto FAIL");
			
			$$ = ret;
			printf("exiting bool\n");
		}
		;

expr:    '(' expr ')'
         {
           $$ = $2;
         }
         |
	 expr '^' expr
         {
		printf("Exponential : ");
		
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,$1->addr);
		strcat(ret,"^");
		strcat(ret,$3->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);
			strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
	
         }
	 |
         expr '*' expr
         {

           printf("Multiplication : ");
	   	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,$1->addr);
		strcat(ret,"*");
		strcat(ret,$3->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);
			strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
           
         }
         |
         expr '/' expr
         {
           printf("Division : ");
	  	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,$1->addr);
		strcat(ret,"/");
		strcat(ret,$3->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);
			strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
	   
         }
         |
         expr '%' expr
         {
           printf("Modulo Division : ");
	   	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,$1->addr);
		strcat(ret,"%");
		strcat(ret,$3->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);
			strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
         }
         |
         expr '+' expr
         {
           printf("Addition : ");
	   	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,$1->addr);
		strcat(ret,"+");
		strcat(ret,$3->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);
			strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	$$ = to_return_expr;
         }
         |
         expr '-' expr
         {
	   printf("Subtraction : ");
           	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,$1->addr);
		strcat(ret,"-");
		strcat(ret,$3->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);
			strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);
		
		to_return_expr->code = temp;

           	$$ = to_return_expr;
		
         }
         |
	expr '&' expr
         {
	   printf("And : ");
           	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,$1->addr);
		strcat(ret,"&");
		strcat(ret,$3->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);
			strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);
		
		to_return_expr->code = temp;

           	$$ = to_return_expr;
		
         }
	|
	expr '|' expr
         {
	   printf("Or : ");
           	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,$1->addr);
		strcat(ret,"|");
		strcat(ret,$3->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen($1->code)+strlen($3->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ($1->code[0]!=0){
			strcat(temp,$1->code);
			strcat(temp,"\n");
			}
		if ($3->code[0]!=0){
			strcat(temp,$3->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);
		
		to_return_expr->code = temp;

           	$$ = to_return_expr;
		
         }
         |
	 text {
		if(strcmp($1,"undeclared")!=0){
		printf("Inside text\n");
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = $1;

		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;

		$$ = to_return_expr;
		printf("Exit text\n");
		}
		else
			exit(0);
		}
         |
         number {
		printf("Inside Number\n");
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = $1;
		
		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;
		
		$$ = to_return_expr;}
         ;

text: 	ID
         {
		printf("Inside Identifier11111 : %s\n",$1);
		if(lookup($1)==NULL)
		{
			printf("variable undeclared : %s\n",$1);
			strcpy($$,"undeclared");
		}
		else
		{
           		$$ = $1;
			printf("Exit Identifier : %s\n",$1);
		}
         }
	  ;

text2: 	ID
         {
		printf("Inside Identifier22222 : %s\n",$1);
		/*if(lookup($1)==NULL)
		{
			printf("variable undeclared : %s\n",$1);
			strcpy($$,"undeclared");
			
		}*/
		//else
		{
           		$$ = $1;
			printf("Exit Identifier : %s\n",$1);
		}
         }
	  ;

number:  DIGIT
         {
		printf("Inside DIGIT : %d\n",$1);
		var = (char *)malloc(20);
           	snprintf(var, 10,"%d",$1);
		$$ = var;
           
         } 
	 |
         FLOAT
         {
		printf("Inside FLOAT : %f\n",$1);
		var = (char *)malloc(20);
           	snprintf(var, 10,"%f",$1);
		$$ = var;
           
         } 
	;
	
%%

int main() {
	// open a file handle to a particular file:
	FILE *myfile = fopen("input.txt", "r");
	// make sure it is valid:
	if (!myfile) {
		printf("I can't open a.snazzle.file!");
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	
}

void yyerror(const char *s) {
	printf("EEK, parse error!  Message: ");
	puts(s);
	
	exit(-1);
}

