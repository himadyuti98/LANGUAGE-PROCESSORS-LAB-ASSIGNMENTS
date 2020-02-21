#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "ass5.h"

static unsigned symhash(char *sym)
{
	unsigned int hash = 0;
	unsigned c;
	while(c = *sym++) 
		hash = hash*9 ^ c;
	return hash;
}

struct symbol * lookup(char* sym)
{
	struct symbol *sp = &symtab[symhash(sym)%NHASH];
	int scount = NHASH;

	while(--scount >= 0) {
		if(sp->name && !strcmp(sp->name, sym)) { return sp; }
		if(!sp->name) {
			sp->name = strdup(sym);
			sp->value = 0;
			return sp;
		}
		if(++sp >= symtab+NHASH) sp = symtab; 
	}
	yyerror("symbol table overflow\n");
	abort();
}

struct ast * newast(int nodetype, struct ast* l, struct ast* r)
{
	struct ast *a = malloc(sizeof(struct ast));
	
	a->nodetype = nodetype;
	a->l = l;
	a->r = r;
	return a;
}

struct ast * newnum(double d)
{
	struct numval *a = malloc(sizeof(struct numval));
	
	a->nodetype = 'K';
	a->number = d;
	return (struct ast*) a;
}

struct ast * newcmp(int nodetype, struct ast* l, struct ast* r)
{
	struct ast *a = malloc(sizeof(struct ast));
	
	a->nodetype = '0'+nodetype;
	a->l = l;
	a->r = r;
	return a;
}

struct ast * newref(struct symbol* s)
{
	struct symref *a = malloc(sizeof(struct symref));
	
	a->nodetype = 'N';
	a->s = s;
	return (struct ast *)a;
}

struct ast * newasgn(struct symbol *s, struct ast *v)
{
	struct symasgn *a = malloc(sizeof(struct symasgn));

	a->nodetype = '=';
	a->s = s;
	a->v = v;
	return (struct ast *)a;
}

struct ast * newflow(int nodetype, struct ast *cond, struct ast *tl, struct ast *el)
{
	struct flow *a = malloc(sizeof(struct flow));

	a->nodetype = nodetype;
	a->cond = cond;
	a->tl = tl;
	a->el = el;
	return (struct ast *)a;
}

/*void treefree(struct ast *a)
{
	switch(a->nodetype) {
	/* two subtrees 
		case '+':
		case '-':
		case '*':
		case '/':
		case '1': case '2': case '3':
		case '4': case '5': case '6':
		case 'L':
			treefree(a->r);
	/* one subtree 
		case '|':
		case 'M': case 'C': case 'F':
			treefree(a->l);
	/* no subtree 
		case 'K': case 'N':
			break;
		case '=':
			free( ((struct symasgn *)a)->v);
			break;
		case 'I': case 'W':
			free( ((struct flow *)a)->cond);
			if( ((struct flow *)a)->tl) 
				treefree( ((struct flow *)a)->tl);
			if( ((struct flow *)a)->el) 
				treefree( ((struct flow *)a)->el);
			break;
		default: printf("internal error: free bad node %c\n", a->nodetype);
		}

		free(a);
	}
}

*/

double eval( struct ast *a)
{
	double v;
	if(!a)
	{
		yyerror("null eval\n");
		return 0.0;
	}
	switch(a->nodetype)
	{
		case 'K': v = ((struct numval *)a)->number; break;
		case 'N': v = ((struct symref *)a)->s->value; break;
		case '=': v = ((struct symasgn *)a)->s->value = eval(((struct symasgn *)a)->v); break;
		case '+': v = eval(a->l) + eval(a->r); break;
		case '-': v = eval(a->l) - eval(a->r); break;
		case '*': v = eval(a->l) * eval(a->r); break;
		case '@': v = pow(eval(a->l),eval(a->r)); break;
		case '/': v = eval(a->l) / eval(a->r); break;
		case 'M': v = -eval(a->l); break;

		case '1': v = (eval(a->l) > eval(a->r))? 1 : 0; break;
		case '2': v = (eval(a->l) < eval(a->r))? 1 : 0; break;
		case '3': v = (eval(a->l) != eval(a->r))? 1 : 0; break;
		case '4': v = (eval(a->l) == eval(a->r))? 1 : 0; break;
		case '5': v = (eval(a->l) >= eval(a->r))? 1 : 0; break;
		case '6': v = (eval(a->l) <= eval(a->r))? 1 : 0; break;

		case 'I':
			if(eval(((struct flow *)a)->cond) != 0)
			{
				if( ((struct flow *)a)->tl) {
					v = eval( ((struct flow *)a)->tl);
				} 
				else
					v = 0.0;
			}
			else
			{
				if( ((struct flow *)a)->el) {
					v = eval( ((struct flow *)a)->el);
				} 
				else
					v = 0.0;
			}
			break;
	
		case 'W':
			v = 0.0;
			if( ((struct flow *)a)->tl) {
				while(eval(((struct flow *)a)->cond) != 0)
					v = eval(((struct flow*)a)->tl);
			}
			break;
		
		case 'D':
			v = 0.0;
			printf("disp\n");
			//v = ((struct symref *)a)->s->value;
			break;
		case 'L': eval(a->l); v = eval(a->r); break;

		default: printf("internal error: bad node %c\n", a->nodetype);
	}
	return v;
}
