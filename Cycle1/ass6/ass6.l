%option noyywrap nodefault yylineno case-insensitive
%{
struct symbol {
	char *name;
	struct ref *reflist;
};

struct ref {
	struct ref *next;
	int freq;
	int lineno;
	char *filename;
};

int n;

#define NHASH 9997
struct symbol symtab[NHASH];
struct symbol *lookup(char*);
void addref(int, char*, char*);
char *curfilename;

%}
%%

[a-z]+(\'(s|t))?	{ addref(yylineno,curfilename, yytext); }
.|\n	

%%

struct symbol * lookup(char* sym)
{
	for(int i=0;i<n;i++)
	{
		if(!strcmp(symtab[i].name,sym))
			return &symtab[i];
	}
	struct symbol *sp=&symtab[n];
	n++;
	if(n>=NHASH)
	{
		fputs("symbol table overflow\n", stderr);
		abort();
	}
	sp->name=strdup(sym);
	sp->reflist=0;
	return sp;
}

void addref(int lineno,char* filename,char* word)
{
	struct ref *r;
	struct symbol *sp= lookup(word);
	if(sp->reflist && sp->reflist->lineno==lineno && sp->reflist->filename==filename)
	{
		sp->reflist->freq++;
		return;
	}
	
	r = malloc(sizeof(struct ref));
	if(!r) {fputs("out of space\n", stderr); abort(); }
	
	r->next=sp->reflist;
	r->filename=filename;
	r->freq=1;
	r->lineno=lineno;
	sp->reflist=r;
}

/*static int symcompare(const void *a, const void *b)
{
	const struct symbol *x=*a;
	const struct symbol *y=*b;
	if(!a->name)
	{
		if(!b->name)
			return 0;
		return 1;
	}
	if(!b->name)
		return -1;
	return strcmp(a->name,b->name);
}*/

void printrefs()
{
	struct symbol *sp;
	
	//qsort(symtab, n, sizeof(struct symbol), symcompare);
	
	for(sp=symtab; sp->name && sp<symtab+n; sp++)
	{
		printf("\n%s :\n",sp->name);
		struct ref *rp=sp->reflist;
		int tot=0;
		for(;rp;rp=rp->next)
		{
			printf("Filename: %s\tLineno: %d\tFrequency: %d\n",rp->filename,rp->lineno,rp->freq);
			tot+=rp->freq;
		}
		printf("Total frequency of %s = %d\n",sp->name,tot);
	}
}

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		curfilename="(stdin)";
		yylineno=1;
		yylex();
	}
	else
	{
		for(int i=1;i<argc;i++)
		{
			FILE *f = fopen(argv[i],"r");
			if(!f)
			{
				perror(argv[1]);
				return 1;
			}
			curfilename=argv[i];
			yyrestart(f);
			yylineno=1;
			yylex();
			fclose(f);
		}
	}
	printrefs();
	return 0;
}
