extern int yylineno;
void yyerror(char *s);

struct symbol
{
	char * name;
	double value;
};

#define NHASH 9997

struct symbol symtab[NHASH];

struct symbol *lookup(char*);

/* node types
* + - * / |
* 0-7 comparison ops, bit coded 04 equal, 02 less, 01 greater
* M unary minus
* L expression or statement list
* I IF statement
* W WHILE statement
* N symbol ref
* = assignment
* S list of symbols
* F built in function call
* C user function call
*/

struct ast {
	int nodetype;
	struct ast *l;
	struct ast *r;
};

struct flow
{
	int nodetype;
	struct ast *cond;
	struct ast *tl;
	struct ast *el;
};

struct numval
{
	int nodetype;
	double number;
};

struct symref
{
	int nodetype;
	struct symbol *s;
};

struct symasgn
{
	int nodetype;
	struct symbol *s;
	struct ast *v;
};

struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newcmp(int cmptype, struct ast *l, struct ast *r);
struct ast *newref(struct symbol *s);
struct ast *newasgn(struct symbol *s, struct ast *v);
struct ast *newnum(double d);
struct ast *newflow(int nodetype, struct ast *cond, struct ast *tl, struct ast *tr);

double eval(struct ast *);

void treefree(struct ast *);





