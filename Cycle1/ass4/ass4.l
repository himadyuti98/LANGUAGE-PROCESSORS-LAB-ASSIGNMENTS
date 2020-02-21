%{
FILE *f;
char buffer[4096];
int k;
void special(char*,int);
void normal(char*,int);
void number(char*,int);
void ws();
void retain(char *, int);
%}

%%

himadyuti |
bhanja |
pineapple |
banana |
mango	{special(yytext,strlen(yytext));}

[A-Za-z]+	{normal(yytext,strlen(yytext));}

[0-9]+	{number(yytext,strlen(yytext));}

[ \t\n]+	{ws();}
.	{retain(yytext, strlen(yytext));}

%%

void special(char* s,int n)
{
	char t[n],r[n];
	for(int i=0;i<n-2;i++)
	{
		//t[i+2]=s[i];
		*(t+i+2)=*(s+i);
	}
	//t[0]=s[n-2];
	//t[1]=s[n-1];
	*t=*(s+n-2);
	*(t+1)=*(s+n-1);
	for(int i=0;i<n;i++)
	{
		r[n-i-1]=t[i];
	}
	strncat(buffer,r,n);
}

void normal(char* s, int n)
{
	char t[n],r[n];
	for(int i=0;i<n;i++)
	{
		if(s[i]>='A' && s[i]<='Z')
		{
			t[i]=(s[i]-'A'+k)%26+'A';
		}
		else
		{
			t[i]=(s[i]-'a'+k)%26+'a';
		}
	}
	for(int i=0;i<n;i++)
	{
		r[n-i-1]=t[i];
	}
	strncat(buffer,r,n);
}
void number(char* s, int n)
{
	int m=n/2;
	char a[m],b[m],c[2];
	c[0]=s[m];
	c[1]='\0';
	for(int i=0;i<m;i++)
		a[i]=s[i];
	if(n&1)
		m++;
	for(int i=m,j=0;i<n;i++,j++)
		b[j]=s[i];
	if(n&1)
		strncat(buffer,b,m-1);
	else
		strncat(buffer,b,m);
	if(n&1)
		strcat(buffer,c);
	if(n&1)
		strncat(buffer,a,m-1);
	else
		strncat(buffer,a,m);
}

void ws()
{
	strcat(buffer," ");
}

void retain(char* s, int n)
{
	strncat(buffer,s,n);
}
int main(int argc, char* argv[])
{
	if(argc<2)
	{
		printf("enter file name in argument\n");
		return 1;
	}
	if(argc>2)
	{
		printf("considering only %s\n",argv[1]);
	}
	printf("k=");
	scanf("%d",&k);
	f=fopen(argv[1],"r");
	yyrestart(f);
	yylex();
	fclose(f);
	printf("%s\n",buffer);
	f=fopen(argv[1],"w");
	fputs(buffer,f);
}
