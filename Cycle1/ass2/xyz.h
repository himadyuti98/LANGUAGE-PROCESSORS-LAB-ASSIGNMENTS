
extern int yylineno; /* from lexer */

void yyerror(char *s);

/* nodes in the abstract syntax tree */
struct ast {
	int nodetype;
	struct ast *l;
	struct ast *r;
};

struct numval {
	int nodetype;
	int number;
};

struct ast *newast(int nodetype, struct ast *l, struct ast *r);

struct ast *newnum(double d);

double eval(struct ast *);

void treefree(struct ast *);

//void printtree(struct ast *);

void postorder(struct ast *);
