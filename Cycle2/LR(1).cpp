#include<bits/stdc++.h>

using namespace std;

char grammar[20][20];
int n;
map<pair<int,char>,int> gototab;
map<pair<int,char>,pair<char,int>> action;

void init()
{
	/*strcpy(grammar[0],"AS");
	strcpy(grammar[1],"SCC");
	strcpy(grammar[2],"CcC");
	strcpy(grammar[3],"Cd");	
	/*strcpy(grammar[4],"TF");
	strcpy(grammar[5],"F(E)");
	strcpy(grammar[6],"Fa");
	*/
	//n=4;*/
	strcpy(grammar[0],"AE");
	strcpy(grammar[1],"ET+E");
	strcpy(grammar[2],"ET");
	strcpy(grammar[3],"TF*T");	
	strcpy(grammar[4],"TF");
	strcpy(grammar[5],"F(E)");
	strcpy(grammar[6],"Fa");
	n=7;
}

string nonkernel(char g[])
{
	string s;
	s+=g[0];
	s+=".";
	for(int i=1;i<strlen(g);i++)
		s+=g[i];
	return s;
}

int nullable(char a)
{
	for(int i=0;i<n;i++)
	{
		if(grammar[i][0]==a && grammar[i][1]=='#')
		{
			return 1;
		}
	}
	return 0;
}


string firstvar(char a)
{
	string f;
	for(int i=0;i<n;i++)
		{
			if(grammar[i][0]==a)
			{
				if(grammar[i][1]<'A' || grammar[i][1]>'Z')
				{
				
					f+=grammar[i][1];
				}
				else
					f+=firstvar(grammar[i][1]);
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

string follow(char a,int count)
{	
	if(count==n)
		return "";
	string f;
	if(a==grammar[0][0])
		f+="$";
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<strlen(grammar[i]);j++)
		{
			if(grammar[i][j]==a)
			{
				char t1[20];
				for(int k=j+1;k<strlen(grammar[i]);k++)
					t1[k-j-1]=grammar[i][k];
				t1[strlen(grammar[i])-j-1]='\0';
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
					string h = follow(grammar[i][0],count+1);
					for(int k=0;k<h.length();k++)
						if(h[k]!='#' && find(f.begin(),f.end(),h[k])==f.end())
							f+=h[k];
				}
			}
		}
	}
	return f;
}

int grammarno(string f)
{
	for(int i=0;i<n;i++)
	{
		bool flag = 0;
		if(f[0]==grammar[i][0])
		{
			for(int j=1;j<strlen(grammar[i]);j++)
			{
				if(f[j]!=grammar[i][j])
				{
					flag = 1;
					break;
				}
			}
			if(flag==0)
				return i;
		}
	}
}


void closure(set<pair<string,char>> &s)
{
	bool f;
	while(1)
	{
		set<pair<string,char>> t;
		t = s;
		for(set<pair<string,char>> ::iterator it=s.begin(); it!=s.end(); it++)
		{
			string f = (*it).first;
			for(int i=0;i<f.length();i++)
			{
				if(f[i]=='.')
				{
					for(int j=0;j<n;j++)
					{
						if(grammar[j][0]==f[i+1])
						{
							char z[20];
							int l = 0;
							for(int k = i+2;k<f.length();k++)
								z[l++]=f[k];
							z[l++]=(*it).second;
							string fir = firststr(z);
							string nonk = nonkernel(grammar[j]);
							for(int k=0;k<fir.length();k++)
								s.insert(make_pair(nonk,fir[k]));
						}
					}
					break;
				}
			}
		}
		if(t==s)
			break;
	}
}

void printlritems(set<set<pair<string,char>>> I)
{
	int k=0;
	for(set<set<pair<string,char>>> ::iterator i=I.begin(); i!=I.end(); i++,k++)
	{
		set<pair<string,char>> t = *i;
		cout<<endl<<"I"<<k<<"-----------------------------------------------------"<<endl;
		for(set<pair<string,char>> ::iterator j=t.begin(); j!=t.end(); j++)
		{
			cout<<(*j).first<<","<<(*j).second<<endl;
		}
	}
}


set<set<pair<string,char>>> getlr1items()
{
	set<set<pair<string,char>>> I; 
	set<pair<string,char>> s;
	s.insert(make_pair(nonkernel(grammar[0]),'$'));
	closure(s);
	I.insert(s);
	while(1)
	{
		//printlritems(I);
		set<set<pair<string,char>>> J;
		J = I;
		int k=0;
		for(set<set<pair<string,char>>> ::iterator i=I.begin(); i!=I.end(); i++,k++)
		{
			set<pair<string,char>> t = *i;
			for(set<pair<string,char>> ::iterator j=t.begin(); j!=t.end(); j++)
			{
				string f = (*j).first;
				int l = f.find('.');
				if(l!=f.length()-1)
				{
					char a = f[l+1];
					vector<pair<string,char>> v;
					for(set<pair<string,char>> ::iterator it=t.begin(); it!=t.end(); it++)
					{
						string f1 = (*it).first;
						char b = (*it).second;
						int c = f1.find('.');
						{
							if(f1[c+1]==a)
								v.push_back(make_pair(f1,b));
						}
					}
					set<pair<string,char>> t1;
					for(int it=0;it<v.size();it++)
					{
						string f1;
						for(int h=0;h<(v[it].first).length();h++)
						{
							if((v[it].first)[h]=='.' )
							{
								f1+=(v[it].first)[h+1];
								f1+=(v[it].first)[h];
								h++;
								continue;
							}
							f1+=(v[it].first)[h];
						}
						t1.insert(make_pair(f1,(v[it].second)));
						
					}
					closure(t1);
					I.insert(t1);
					pair<int,char> p = make_pair(k,a);
					int d = distance(I.begin(),I.find(t1));
					pair<char,int> q = make_pair('s',d);
					gototab[p]=d;
					if(a<'A' || a>'Z')
						action[p]=q;
				}
				else
				{
					int d = grammarno(f);
					pair<char,int> q = make_pair('r',d);
					pair<int,char> p = make_pair(k,(*j).second);
					action[p] = q;
				}
		}
		} 
		if(I==J)
		{
			printlritems(I);
			break;
		}
	}
	return I;
}

int main()
{
	init();
	set<set<pair<string,char>>> I = getlr1items();	
	cout<<endl<<endl;
	for(map<pair<int,char>,int>::iterator i = gototab.begin();i!=gototab.end();i++)
	{
		cout<<"goto["<<i->first.first<<","<<i->first.second<<"]="<<i->second<<endl;
	}
	cout<<endl<<endl;
	for(map<pair<int,char>,pair<char,int>>::iterator i = action.begin();i!=action.end();i++)
	{
		cout<<"action["<<i->first.first<<","<<i->first.second<<"] = ["<<i->second.first<<","<<i->second.second<<"]"<<endl;
	}

}

/*
Question:
Write a program to find LR(1) items for the following expression grammar
and construct Canonical LR table assuming that the operators ‘+’ and ‘*’
are right associative and + has higher precedence than *
E  -> E + E | E * E | (E) | id
*/