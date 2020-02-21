#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include "xyz.h"
struct ast *newast(int nodetype, struct ast *l, struct ast *r)
{
	struct ast *a = malloc(sizeof(struct ast));

	if(!a) {
		yyerror("out of space");
		exit(0);
	}

	a->nodetype = nodetype;
	a->l = l;
	a->r = r;
	return a;
}
struct ast *newnum(double d)
{
	struct numval *a = malloc(sizeof(struct numval));
	if(!a) {
		yyerror("out of space");
		exit(0);
	}
	a->nodetype = 'K';
	a->number = d;
	return (struct ast *)a;
}

double eval(struct ast *a)
{
	double v; 
	switch(a->nodetype) {
	case 'K': v = ((struct numval *)a)->number; break;
	case '+': v = eval(a->l) + eval(a->r); break;
	case '-': v = eval(a->l) - eval(a->r); break;
	case '*': v = eval(a->l) * eval(a->r); break;
	case '/': v = eval(a->l) / eval(a->r); break;
	case '|': v = eval(a->l); if(v < 0) v = -v; break;
	case 'M': v = -eval(a->l); break;
	default: printf("internal error: bad node %c\n", a->nodetype);
	}
	return v;
}

void treefree(struct ast *a)
{
	switch(a->nodetype) {
	case '+':
	case '-':
	case '*':
	case '/':
		treefree(a->r);
	/* one subtree */
	case '|':
	case 'M':
		treefree(a->l);
	/* no subtree */
	case 'K':
		free(a);
		break;

	default: printf("internal error: free bad node %c\n", a->nodetype);
	}
}


void postorder(struct ast *a)
{
	if(a->nodetype!='K')
	{
		if(a->nodetype=='M')
		{
			postorder(a->l);
		}
		else
		{
			postorder(a->l);
			postorder(a->r);
		}
	}
	if(a->nodetype=='K')
		printf("%d",((struct numval *)a)->number);
	else
	{
		if(a->nodetype=='M')
			printf("um");
		else
			printf("%c",a->nodetype);
	}
}
