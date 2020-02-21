%{

char grammar_rules[20][20][20];
char tab[20][20][20];
void insert(char *,int);
int c=-1,f=0,k=0,h;
char w[20];
int m;
void print();
void cyk();
int present(char *, char *);
int added(char *, char, int);

%}

%%

[A-Za-z]+	{printf("c=%d k=%d\n",c,k);insert(yytext,strlen(yytext)); } 
[ \t\n]	{c++; k=0;;
	if(c==h)
		{print();cyk();}	
	}
[\-]	{k++;}

%%

void insert(char *s, int n)
{
	for(int l=0;l<n;l++)
		grammar_rules[c][k][l]=s[l];
}

int added(char* p, char t, int n)
{//printf("yess,p=%s,t=%c,n=%d\n",p,t,n);
	for(int i=0;i<=n;i++){
		if(p[i]==t)
			return 1;}
	//printf("return 0\n");
	return 0;
}
int present(char *p, char* g)
{
	int v=0;
	for(int i=0;i<h;i++)
	{
		for(int j=1;j<20;j++)
		{
			if(strcmp(p,grammar_rules[i][j])==0 && added(g,grammar_rules[i][0][0],v+1)==0){
				printf("**g=%s,c=%c,v=%d\n",g,grammar_rules[i][0][0],v);
				g[v++]=grammar_rules[i][0][0];}
		}
	}
	g[v]='\0';
	return v;
}


void cyk()
{
	printf("cyk\n");
	for(int i=0;i<m;i++)
	{
		int v=0;
		for(int j=0;j<h;j++)
		{
			for(int z=0;z<20;z++)
			{
				if(w[i]==grammar_rules[j][z][0])
				{
					tab[i][i][v++]=grammar_rules[j][0][0];
				}
			}
		}
		if(v==0)
			tab[i][i][v++]='#';
		tab[i][i][v]='\0';
	}
	for(int j=1;j<m;j++)
	{
		for(int i=0;i<m-j;i++)
		{
			int v=0;
			for(int l=i;l<i+j;l++)
			{
				for(int a=0;a<strlen(tab[i][l]);a++)
				{
					for(int b=0;b<strlen(tab[l+1][i+j]);b++)
					{
						char p[3];
						p[0]=tab[i][l][a];p[1]=tab[l+1][i+j][b];p[2]='\0';
						char t[20];
						printf("i=%d,j=%d\n",i,i+j);
						int x=present(p,t);
						if(x>0)
						{
							for(int r=0;r<x;r++)
							{
								if(added(tab[i][i+j],t[r],v)==0)
									tab[i][i+j][v++]=t[r];
							}
						}
					}
				}
			}
			if(v==0)
			{
				tab[i][i+j][v++]='*';
			}
			tab[i][i+j][v]='\0';
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=i;j<m;j++)
			printf("%s ",tab[i][j]);
		printf("\n");
	}
}

void print()
{
	printf("in print w=%s\n",w);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<4;j++)
			printf("%s ",grammar_rules[i][j]);
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	printf("Enter the i/p string\n");
	scanf("%s",w);
	m=strlen(w);
	printf("How many grammar rules?\n");
	scanf("%d",&h);
	printf("Enter the grammar rules\n");
	//h++;
	yylex();
}
