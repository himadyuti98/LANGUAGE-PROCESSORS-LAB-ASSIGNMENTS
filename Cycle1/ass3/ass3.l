%{

#include<math.h>
#include<unistd.h>

char grammar_rules[20][20][20];
int c1[20],c2[20][20];
void insert(char *,int);
int c=-1,f=0,k=0,h;
void print();
void e_prod();
int present(int [],int,int);
void unit_prod();
int find(char);
void useless_sym();
int is_nullable(char);
int get_terminals(char *);
int get_variables(char *);
int pre(char[],char,int);
int all_present(char[],int,char[]);

void left_rec();

%}

%%

[A-Za-z$]+	{printf("c=%d k=%d\n",c,k);insert(yytext,strlen(yytext)); } 
[ \t\n]	{c1[c]++; c++; k=0; c1[c]=0;
	if(c==h)
		{e_prod(); unit_prod(); useless_sym(); left_rec();}
	}
[\-]	{k++; c1[c]++;}

%%

void insert(char *s, int n)
{
	for(int l=0;l<n;l++)
		grammar_rules[c][k][l]=s[l];
	c2[c][k]=n;
}

void print()
{
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<c1[i];j++)
			printf("%s ",grammar_rules[i][j]);
		printf("\n");
	}
}

int is_nullable(char c)
{
	for(int i=0;i<h;i++)
	{
		if(grammar_rules[i][0][0]==c)
		{
			for(int j=1;j<c1[i];j++)
			{
				if(grammar_rules[i][j][0]=='$')
					return 1;
			}
			break;
		}
	}
	return 0;
}
int present(int arr[],int n,int a)
{
	for(int i=0;i<n;i++)
		if(arr[i]==a)
			return 1;
	return 0;
}
void e_prod()
{
	print();
	for(int a=0;a<h;a++)
	{
		printf("c=%d\n",c1[a]);
		int c = c1[a];
		for(int b=1;b<c;b++)
		{
			printf("b=%d\n",b);
			if(b>=c1[a])
				break;
			int pos[20],z=0;
			for(int v=0;v<20;v++)
			{
				if(grammar_rules[a][b][v]>='A' && grammar_rules[a][b][v]<='Z' && is_nullable(grammar_rules[a][b][v])==1)
				{
					pos[z++]=v;
					//printf("a=%db=%dv=%d %c\n",a,b,v,grammar_rules[a][b][v]);
				}
			}
			for(int i=1;i<pow(2,z);i++)
			{
				int skip[20],y=0;
				for(int j=0;j<z;j++)
				{
					if((1<<j) & i)
					{
						skip[y++]=pos[j];
					}
				}
				printf("skip ");
				for(int j=0;j<y;j++)
					printf("%d ",skip[j]);
				printf("\n%s\n",grammar_rules[a][b]);
				char f[20];int m=0;
				for(int j=0;j<strlen(grammar_rules[a][b]);j++)
				{
						if(present(skip,y,j)==0){
						f[m++]=grammar_rules[a][b][j];
						printf("%d%c\n",j,grammar_rules[a][b][j]);}
				}
				f[m]='\0';
				printf("%s\n",f);
				c2[a][c1[a]]=m;
				strcpy(grammar_rules[a][c1[a]++],f);
				
			}
		}
	}
	for(int i=0;i<h;i++)
	{
		for(int j=1;j<c1[i];j++)
		{
			if(grammar_rules[i][j][0]=='$')
			{
				strcpy(grammar_rules[i][j],grammar_rules[i][--c1[i]]);
				break;
			}
		}
	}
	print();
}

int find(char c)
{
	for(int i=0;i<h;i++)
	{	
		if(c==grammar_rules[i][0][0])
			return i;
	}
}

void unit_prod()
{
	int f;
	abc:
	sleep(1);
	f=0;
	for(int i=0;i<h;i++)
	{
		int c = c1[i];
		for(int j=1;j<c;j++)
		{
			if(strlen(grammar_rules[i][j])==1 && grammar_rules[i][j][0]>='A' && grammar_rules[i][j][0]<='Z')
			{	
				int k = find(grammar_rules[i][j][0]);
				printf("k=%dc=%c\n",k,grammar_rules[i][j][0]);
				for(int l=1;l<c1[k];l++)
				{
					strcpy(grammar_rules[i][c1[i]++],grammar_rules[k][l]);
				}
				strcpy(grammar_rules[i][j],grammar_rules[i][--c1[i]]);
				f=1;
			}
		}
	}
	if(f==1)
		goto abc;
	else
		print();
}

int pre(char s[],char c,int n)
{
	for(int i=0;i<n;i++)
	{
		if(s[i]==c)
			return 1;
	}
	return 0;
}

int get_terminals(char s[])
{
	c=0;
	for(int i=0;i<h;i++)
	{
		for(int j=1;j<c1[i];j++)
		{
			for(int k=0;k<strlen(grammar_rules[i][j]);k++)
			{
				if(pre(s,grammar_rules[i][j][k],c)==0 && grammar_rules[i][j][k]>='a' && grammar_rules[i][j][k]<='z')
				{
					s[c++]=grammar_rules[i][j][k];
				}
			}
		}
	}
	s[c]='\0';
	return c;
}

int get_variables( char s[])
{
	c=0;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<c1[i];j++)
		{
			for(int k=0;k<strlen(grammar_rules[i][j]);k++)
			{
				if(pre(s,grammar_rules[i][j][k],c)==0 && grammar_rules[i][j][k]>='A' && grammar_rules[i][j][k]<='Z')
				{
					s[c++]=grammar_rules[i][j][k];
				}
			}
		}
	}
	s[c]='\0';
	return c;
}

int all_present(char * s, int n, char* c)
{
	for(int i=0;i<strlen(c);i++)
	{
		if(pre(s,c[i],n)==0)
			return 0;
	}
	return 1;
}

void useless_sym()
{
	char s[50];
	int n = get_terminals(s),un=0;
	char v[50];
	int o=get_variables(v);
	char uv[50];
	int f;
	char rv[50],urv[50];
	int rn=0,urn=0;
	rv[0]=grammar_rules[0][0][0];
	
	xyz:
	f=0;
	printf("hello\n");
	for(int i=0;i<n;i++)
		printf("%c ",s[i]);
	printf("%s\n",s);
	for(int i=0;i<h;i++)
	{
		for(int j=1;j<c1[i];j++)
		{
			printf("&**%s %s**\n",s,grammar_rules[i][j]);
			if(all_present(s,n,grammar_rules[i][j])==1 && pre(s,grammar_rules[i][0][0],n)==0)
			{
				s[n++]=grammar_rules[i][0][0];
				f=1;
			}
		}
	}
	if(f==1)
		goto xyz;
	printf("Useless\n");
	for(int i=0;i<o;i++)
	{
		if(pre(s,v[i],n)==0 && v[i]>='A' && v[i]<='Z')
		{
			uv[un++]=v[i];
			printf("%c ",v[i]);
		}
	}
	printf("\n");
	for(int i=0;i<h;i++)
	{
		if(pre(uv,grammar_rules[i][0][0],un))
		{
			for(int j=0;j<c1[h-1];j++)
			{
				strcpy(grammar_rules[i][j],grammar_rules[h-1][j]);
			}
			h--;
			i--;
			continue;
		}
		for(int j=1;j<c1[i];j++)
		{
			for(int k=0;k<strlen(grammar_rules[i][j]);k++)
			{
				if(pre(uv,grammar_rules[i][j][k],un))
				{
					strcpy(grammar_rules[i][j],grammar_rules[i][--c1[i]]);
					j--;
					break;
				}
			}
		}
	}
	print();

	for(int i=1;i<c1[0];i++)
	{
		for(int j=0;j<strlen(grammar_rules[0][j]);j++)
		{
			if(grammar_rules[0][i][j]>='A' && grammar_rules[0][i][j]<='Z' && pre(rv,grammar_rules[0][i][j],rn)==0)
			{
				rv[rn++]=grammar_rules[0][i][j];
			}
		}
	}
	
	for(int i=0;i<rn;i++)
	{
		int j = find(rv[i]);
		for(int k=1;k<c1[j];k++)
		{
			for(int l=0;l<strlen(grammar_rules[j][k]);l++)
			{
				if(grammar_rules[j][k][l]>='A' && grammar_rules[j][k][l]<='Z' && pre(rv,grammar_rules[j][k][l],rn)==0)
					rv[rn++]=grammar_rules[j][k][l];
			}
		}
	}
	

	printf("Unreachable\n");
	for(int i=0;i<o;i++)
	{
		if(pre(rv,v[i],n)==0 && v[i]>='A' && v[i]<='Z' && pre(uv,v[i],un)==0)
		{
			urv[urn++]=v[i];
			printf("%c ",v[i]);
		}
	}
	printf("\n");
	for(int i=0;i<h;i++)
	{
		if(pre(urv,grammar_rules[i][0][0],urn))
		{
			for(int j=0;j<c1[h-1];j++)
			{
				strcpy(grammar_rules[i][j],grammar_rules[h-1][j]);
			}
			h--;
			i--;
			continue;
		}
		for(int j=1;j<c1[i];j++)
		{
			for(int k=0;k<strlen(grammar_rules[i][j]);k++)
			{
				if(pre(urv,grammar_rules[i][j][k],urn))
				{
					strcpy(grammar_rules[i][j],grammar_rules[i][--c1[i]]);
					j--;
					break;
				}
			}
		}
	}
	print();
}

void left_rec()
{
	printf("removing immediate left recursion\n");
	int g=h;
	for(int i=0;i<g;i++)
	{
		int fl=0;
		char g[20][20];
		g[0][0]=grammar_rules[i][0][0];
		g[0][1]='1';
		g[0][2]='\0';
		int n=1;
		for(int j=1;j<c1[i];j++)
		{
			if(grammar_rules[i][j][0]==grammar_rules[i][0][0])
			{
				fl=1;
				int k;
				for(k=1;k<strlen(grammar_rules[i][j]);k++)
				{
					g[n][k-1]=grammar_rules[i][j][k];
				}
				g[n][k++]=g[0][0];
				g[n][k++]=g[0][1];
				g[n][k]='\0';
				strcat(g[n],g[0]);
				n++;
			}
		}
		if(fl==1)
		{
		for(int j=1;j<c1[i];j++)
		{
			if(grammar_rules[i][j][0]!=grammar_rules[i][0][0])
			{
				strcat(grammar_rules[i][j],g[0]);
			}
		}
		for(int j=1;j<c1[i];j++)
		{
			if(grammar_rules[i][j][0]==grammar_rules[i][0][0])
			{
				strcpy(grammar_rules[i][j],grammar_rules[i][--c1[i]]);
				j--;
			}
		}	
		for(int j=0;j<n;j++)
		{
			strcpy(grammar_rules[h][j],g[j]);
			//printf("%s ",grammar_rules[h][j]);
		}
		strcpy(grammar_rules[h][n],"$");
		//printf("\n");
		c1[h++]=n+1;
		}
	}
	print();
}

int main(int argc, char *argv[])
{
	printf("How many grammar rules?\n");
	scanf("%d",&h);
	printf("Enter the grammar rules\n");
	yylex();
}
