#include<bits/stdc++.h>
using namespace std;

char gr[20][20];
int g;
int M[30][30];
int t,v;
char terms[20],vars[20];
string w;

int nullable(char a)
{
	for(int i=0;i<g;i++)
	{
		if(gr[i][0]==a && gr[i][1]=='#')
		{
			return 1;
		}
	}
	return 0;
}

string firstvar(char a)
{
	string f;
	for(int i=0;i<g;i++)
		{
			if(gr[i][0]==a)
			{
				if(gr[i][1]<'A' || gr[i][1]>'Z')
				{
				
					f+=gr[i][1];
				}
				else
					f+=firstvar(gr[i][1]);
			}
		}
		return f;
}

string firststr(char * a)
{
	string f;
	
	if(strlen(a)==1)
	{
		f+=firstvar(a[0]);
	}
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>='A' && a[i]<='Z')
		{
			f+=firstvar(a[i]);
			if(nullable(a[i])==0)
				break;
		}
		else
		{
			f = a[i];
			break;
		}
	}
	return f;
}

void terms_and_vars()
{
	t=0;
	set<char> s;
	for(int i=0;i<g;i++)
	{
		if(s.find(gr[i][0])==s.end())
		{
			s.insert(gr[i][0]);
			vars[v++]=gr[i][0];
		}
		for(int j=1;j<strlen(gr[i]);j++)
		{
			if(gr[i][j]<'A' || gr[i][j]>'Z')
			{
				if(s.find(gr[i][j])==s.end() && gr[i][j]!='#')
				{
					s.insert(gr[i][j]);
					terms[t++]=gr[i][j];
				}
			}
			if(gr[i][j]>='A' && gr[i][j]<='Z')
			{
				if(s.find(gr[i][j])==s.end())
				{
					s.insert(gr[i][j]);
					vars[v++]=gr[i][j];
				}
			}
		}
	}
}

int index1(char arr[],char a,int n)
{
	for(int i=0;i<n;i++)
		if(arr[i]==a)
			return i;
}

string follow(char a,int count)
{	
	if(count==g)
		return "";
	string f;
	if(a==gr[0][0])
		f+="$";
	for(int i=0;i<g;i++)
	{
		for(int j=1;j<strlen(gr[i]);j++)
		{
			if(gr[i][j]==a)
			{
				char t1[20];
				for(int k=j+1;k<strlen(gr[i]);k++)
					t1[k-j-1]=gr[i][k];
				t1[strlen(gr[i])-j-1]='\0';
				string d = firststr(t1);
				for(int k=0;k<d.length();k++)
					if(d[k]!='#' && find(f.begin(),f.end(),d[k])==f.end())
						f+=d[k];
				bool flag = 0, fl=0;
				for(int k=0;k<strlen(t1);k++){
					if(t1[k]>='A' && t1[k]<='Z'){
						fl=1;
						if( !nullable(t1[k])){
						flag=1;}}}
				if((flag==0 && fl==1) || (strlen(t1)==0))
				{
					string h = follow(gr[i][0],count+1);
					for(int k=0;k<h.length();k++)
						if(h[k]!='#' && find(f.begin(),f.end(),h[k])==f.end())
							f+=h[k];
				}
			}
		}
	}
	return f;
}

string print_contents(stack <char> s)
{
	string f;
	while(!s.empty())
	{
		f+=s.top();
		s.pop();
	}
	reverse(f.begin(),f.end());
	return f;
}

void replace(string &f,char s[])
{
	for(int i=f.length()-1;i>=0;i--)
	{
		if(f[i]==s[0])
		{
			string t;
			for(int j=0;j<i;j++)
				t+=f[j];
			if(s[1]!='#'){
			for(int j=1;j<strlen(s);j++)
				t+=s[j];}
			for(int j=i+1;j<f.length();j++)
				t+=f[j];
			f=t;	
			return;
		}
	}
	
}

int main()
{
	cout<<"How many rules?\n";
	cin>>g;
	cout<<"Enter the grammar rules\n";
	for(int i=0;i<g;i++)
		cin>>gr[i];

	terms_and_vars();
	terms[t++]='$';
	
	for(int i=0;i<g;i++)
	{
		char t1[20];
		memset(t1,'\0',20);
		for(int j=1;j<strlen(gr[i]);j++)
			t1[j-1]=gr[i][j];
		string f = firststr(t1);
		
		bool flag = 0;
		for(int j=0;j<f.length();j++)
		{
			if(f[j]=='#')
			{
				flag=1;
				continue;
			}
			M[index1(vars,gr[i][0],v)][index1(terms,f[j],t)]=i+1;
		}
		if(flag==1)
		{	
			
			string fol = follow(gr[i][0],1);
			for(int j=0;j<fol.length();j++)
				M[index1(vars,gr[i][0],v)][index1(terms,fol[j],t)]=i+1;
			M[index1(vars,gr[i][0],v)][index1(terms,'$',t)]=i+1;
		}
	}
	cout<<"terminals: ";
	for(int i=0;i<t;i++)
		cout<<terms[i]<<" ";
	cout<<"\nvariables: ";
	for(int i=0;i<v;i++)
		cout<<vars[i]<<" ";
	cout<<endl;
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<t;j++)
			cout<<M[i][j]<<" ";
		cout<<endl;
	}
	cout<<"enter input string"<<endl;
	cin>>w;
	stack <char> s;
	s.push('$');
	s.push(gr[0][0]);
	string stcon=print_contents(s);
	cout<<stcon<<endl;
	for(int i=0;i<w.length();i++)
	{
		char h = s.top();
		
		//if(h!=NULL){
		//	string j=print_contents(s);
			//cout<<j<<endl;}

		s.pop();
		if(h==NULL)
		{
			i--;
			continue;
		}
		if((h>='A' && h<='Z') || h=='#')
		{
			int j = M[index1(vars,h,v)][index1(terms,w[i],t)]-1;
			if(j==-1)
			{
				cout<<"h="<<h<<" w[i]="<<w[i]<<"i="<<i<<endl;
				cout<<"error"<<endl;
				return 1;
			}
			//cout<<"applying"<<gr[j]<<endl;
			replace(stcon,gr[j]);
			cout<<stcon<<endl;
			if(gr[j][1]!='#'){
			for(int k=strlen(gr[j]);k>=1;k--)
				s.push(gr[j][k]);}
			i--;
		}
		else if(h=='$')
			break;
		
			
	}
	while(!s.empty())
	{
		char h = s.top();
		if(h=='$')
			break;
		if(h!=NULL)
			print_contents(s);
		s.pop();
		if(h!=NULL){
		int j = M[index1(vars,h,v)][index1(terms,'$',t)]-1;
		if(j==-1)
		{
			cout<<"h="<<h<<endl;
			cout<<"error"<<endl;
			return 1;
		}
		replace(stcon,gr[j]);
		cout<<stcon<<endl;}
	}
	return 0;
}

/*
Question:
Write a program to design a predictive parser (Construct the parse table for
the grammar and show the derivation sequence for an input string of the
grammar ).
*/