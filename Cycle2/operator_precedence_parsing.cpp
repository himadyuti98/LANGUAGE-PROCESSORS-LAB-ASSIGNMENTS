#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<stack>
#include<iostream>

using namespace std;

int t;
char term[20];
int rm[20][20];
//int g;
//char gr[20][20];
char w[20];

int prec(char a, char b)
{
	for(int i=0;i<t;i++)
	{
		if(term[i]==a)
		{
			for(int j=0;j<t;j++)
				if(term[j]==b)
					return rm[i][j];
		}
	}
	return -2;
}

void reduce(int a)
{
	if(w[a]=='$')
		return;
	//cout<<"reducing "<<w[a]<<endl;
	char h[20];
	strcpy(h,w);
	//cout<<"before reduce: "<<w<<endl;
//	cout<<"a="<<a<<"w="<<w<<"w[a]="<<w[a]<<endl;
	if(w[a]=='i')
		w[a]='E';
	else
	{
		int b = strlen(w);
		w[a-1]='E';
		for(int i=a;i<strlen(w);i++)
		{
			w[i]=w[i+2];
		}
		w[b-1]='\0';
		w[b]='\0';
	}
	//cout<<"after reduce: "<<w<<endl;
}

int find(char a)
{
//	cout<<"finding "<<a<<" in "<<w<<endl;
	for(int i=0;i<strlen(w);i++)
		if(w[i]==a)
			return i;
}

int main()
{
	
	printf("how many terminals?\n");
	scanf("%d",&t);
	cout<<"Enter the terminals\n";
	for(int i=0;i<t;i++)
		cin>>term[i];
	printf("enter the relationship matrix\n");
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<t;j++)
		{
			int x;
			scanf("%d",&x);
		/*	if(x=='<')
				rm[i][j]=-1;
			else if(x=='>')
				rm[i][j]=1;
			else
				rm[i][j]=0;*/
				rm[i][j]=x;
		//	printf("%d ", rm[i][j]);
		}
		//cout<<endl;
	}
	/*printf("how many grammar rules?\n");
	scanf("%d",g);
	printf("enter the grammar rules\n");
	for(int i=0;i<g;i++)
	{
		scanf("%s",gr[i]);
	}*/
	cout<<"Enter the input string\n";
	cin>>w;
	strcat(w,"$");
	stack <char> s;
	s.push('$');
	int ip=0;
	while(ip<strlen(w) && !s.empty())
	{
		if(prec(s.top(),w[ip])==-1)
		{

			//cout<<"ip="<<ip<<"w="<<w<<"pushed"<<w[ip]<<endl;
			s.push(w[ip]);
			ip++;
		}
		else
		{
			//printf("ip = %d %s\n",ip, w);
			//printf("prec = %d\n", prec(s.top(),w[ip]));
			//cout<<s.top()<<" "<<w[ip]<<endl;
			cout<<w<<endl;
			reduce(find(s.top()));
			//cout<<"poped"<<s.top();
			if(s.top()=='i')
				s.pop();
			else
			{
				ip--;
				ip--;
				s.pop();
			}
		}
		//cout<<"ip="<<ip<<endl;
	}
	//cout<<"*************************\n";
	while(!s.empty())
	{
		
		reduce(find(s.top()));
		s.pop();
		printf("%s\n", w);
	}
}

/*
Write a program to implement operator precedence parsing (Precedence
table is given and do parsing from precedence table).
*/