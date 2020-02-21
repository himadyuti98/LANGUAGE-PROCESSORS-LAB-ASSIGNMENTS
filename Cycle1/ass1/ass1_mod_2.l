%{

struct abc
{
	char c;
	int x;
	int y;
	int z;
};
char grammar_rules[20][20][20];
struct abc cf[20][20][20][20][2];
int count[20][20][20];
char tab[20][20][20];
void insert(char *,int);
int c=-1,f=0,k=0,h;
char w[20];
int m;
void print();
void cyk();
int present(char *, char *);
int added(char *, char, int);
int index1(char *, char, int);
char deriv[50];
int top=0;
char deriv2[70];
char* derivation(char*, int, int, int);
void derivate(char * , int , int*, int*, int*,int,int);
int minindex(char *,int);
int cnt=0;
void printwithoutstar(char *);
 
%}

%%

[A-Za-z]+	{printf("c=%d k=%d\n",c,k);insert(yytext,strlen(yytext)); } 
[ \t\n]	{c++; k=0;;
	if(c==h)
		{print();cyk();}	
	}
[\-]	{k++;}

%%

void printwithoutstar(char *s)
{
	for(int i=0;i<strlen(s);i++)
		if(s[i]!='*')
			printf("%c",s[i]);
	printf("\n");
}

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

int index1(char* p, char t, int n)
{//printf("yess,p=%s,t=%c,n=%d\n",p,t,n);
	for(int i=0;i<=n;i++){
		if(p[i]==t)
			return i;}
	//printf("return 0\n");
	return -1;
}


int present(char *p, char* g)
{
	int v=0;
	for(int i=0;i<h;i++)
	{
		for(int j=1;j<20;j++)
		{
			if(strcmp(p,grammar_rules[i][j])==0){		// && (added(g,grammar_rules[i][0][0],v+1)==0)
				printf("**g=%s,c=%c,v=%d\n",g,grammar_rules[i][0][0],v);
				g[v++]=grammar_rules[i][0][0];}
		}
	}
	g[v]='\0';
	return v;
}

int minindex(char *s,int n)
{
	for(int i=0;i<n;i++)
		if(s[i]>='A' && s[i]<='Z')
			return i;
	return n;
}

void derivate(char * p, int index, int x[], int y[], int z[],int n,int top)
{
	if(x[index]==-1 || y[index]==-1 ||z[index]==-1)
		derivate(p,index+1,x,y,z,n,top);
	//printf("%s %d\n",p,top);
	if(index>=n)
	{
		int f=0;
		for(int i=0;i<n;i++)
		{
			if(p[i]>='A' && p[i]<='B')
				f=1;
		}
		if(f==0)
			cnt++;
		printwithoutstar(deriv2);
		return;
	}
	char str[50],m[50];
	strncpy(m,deriv2,top);
	int x1[50],y1[50],z1[50],xx,yy,zz;
	for(int i=0;i<index;i++)
	{
		str[i]=p[i];
		x1[i]=x[i];
		y1[i]=y[i];
		z1[i]=z[i];
	}
	xx=x[index];
	yy=y[index];
	zz=z[index];
	
	for(int j=0;j<count[xx][yy][zz];j++)
	{
	
	str[index]=cf[x[index]][y[index]][z[index]][j][0].c;
	str[index+1]=cf[x[index]][y[index]][z[index]][j][1].c;
	x1[index]=cf[xx][yy][zz][j][0].x;
	y1[index]=cf[xx][yy][zz][j][0].y;
	z1[index]=cf[xx][yy][zz][j][0].z;
	//printf("pos %d %d %d\n",x1[index],y1[index],z1[index]);
	x1[index+1]=cf[xx][yy][zz][j][1].x;
	y1[index+1]=cf[xx][yy][zz][j][1].y;
	z1[index+1]=cf[xx][yy][zz][j][1].z;
	for(int i=index+1;i<n;i++)
	{
		str[i+1]=p[i];
		x1[i+1]=x[i];
		y1[i+1]=y[i];
		z1[i+1]=z[i];
	}
	str[n+1]='\0';
	//printf("->%s\n",str);
	memset(deriv2,'\0',70);
	strncpy(deriv2,m,top);
	strcat(deriv2,"->");
	strcat(deriv2,str);
	if(str[index]>='A' && str[index]<='Z')
		derivate(str,minindex(str,n+1),x1,y1,z1,n+1,top+2*(n+1));
	else if(str[index]>='a' && str[index]<='z')
		derivate(str,minindex(str,n+1),x1,y1,z1,n+1,top+2*(n+1));
	}

	for(int i=index+1;i<n;i++)
	{
		if(p[i]>='A' && p[i]<='Z'){
			memset(deriv2,'\0',70);
			strncpy(deriv2,m,top);///2+index+2*(i));
			//printf("toptop=%d index=%d i=%d %s\n",top,index,i,deriv2);
			derivate(p,i,x,y,z,n,top);}
	}
	strncpy(deriv2,m,top);
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

					cf[i][i][v][count[i][i][v]][0].c=w[i];
					cf[i][i][v][count[i][i][v]][1].c='*';
					cf[i][i][v][count[i][i][v]][0].x=-1;
					cf[i][i][v][count[i][i][v]][0].y=-1;
					cf[i][i][v][count[i][i][v]][0].z=-1;
					cf[i][i][v][count[i][i][v]][1].x=-1;
					cf[i][i][v][count[i][i][v]][1].y=-1;
					cf[i][i][v][count[i][i][v]][1].z=-1;
					count[i][i][v]=1;
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
								{
									cf[i][i+j][v][count[i][i+j][v]][0].c=p[0];
									cf[i][i+j][v][count[i][i+j][v]][0].x=i;
									cf[i][i+j][v][count[i][i+j][v]][0].y=l;
									cf[i][i+j][v][count[i][i+j][v]][0].z=a;
									cf[i][i+j][v][count[i][i+j][v]][1].x=l+1;
									cf[i][i+j][v][count[i][i+j][v]][1].y=i+j;
									cf[i][i+j][v][count[i][i+j][v]][1].z=b;
									cf[i][i+j][v][count[i][i+j][v]][1].c=p[1];
									count[i][i+j][v]++;
									tab[i][i+j][v++]=t[r];
									
								}
								else
								{	
									int o = index1(tab[i][i+j],t[r],v);
									cf[i][i+j][o][count[i][i+j][o]][0].c=p[0];
									cf[i][i+j][o][count[i][i+j][o]][0].x=i;
									cf[i][i+j][o][count[i][i+j][o]][0].y=l;
									cf[i][i+j][o][count[i][i+j][o]][0].z=a;
									cf[i][i+j][o][count[i][i+j][o]][1].x=l+1;
									cf[i][i+j][o][count[i][i+j][o]][1].y=i+j;
									cf[i][i+j][o][count[i][i+j][o]][1].z=b;
									cf[i][i+j][o][count[i][i+j][o]][1].c=p[1];
									count[i][i+j][o]++;
								}
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
	int o = index1(tab[0][m-1],grammar_rules[0][0][0],strlen(tab[0][m-1]));
	if(o==-1)
	{
		printf("not a member\n");
		return;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=i;j<m;j++)
		{
			for(int k=0;k<strlen(tab[i][j]);k++)
			{
				printf("%ccount=%d ",tab[i][j][k],count[i][j][k]);
				for(int l=0;l<count[i][j][k];l++)
				{
					printf("%c(%d,%d,%d)",cf[i][j][k][l][0].c,cf[i][j][k][l][0].x,cf[i][j][k][l][0].y,cf[i][j][k][l][0].z);
					printf("%c(%d,%d,%d)",cf[i][j][k][l][1].c,cf[i][j][k][l][1].x,cf[i][j][k][l][1].y,cf[i][j][k][l][1].z);
				}
				printf("*\t");
			}
			printf("#\t");
		}
		printf("$\n");
	}
	printf("hello\n");
	deriv[0]=grammar_rules[0][0][0];
	printf("hello\n");
	deriv[1]='\0';
	printf("%s\n",deriv);
	int x[50];
	int y[50];
	int z[50];
	x[0]=0;
	y[0]=m-1;
	z[0]=o;
	strcat(deriv2,deriv);
	top=1;
	derivate(deriv,0,x,y,z,1,top);
	printf("Total %d\n",cnt);
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
