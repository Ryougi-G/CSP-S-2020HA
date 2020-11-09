#include<bits/stdc++.h>
using namespace std;
#define rint register int
typedef unsigned long long ull;
inline ull read()
{
	int f=1;
	ull x=0;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
map<ull,int> mp;
ull n,m,c,k,cnt,num;
vector<int> v[70];
bool vis[70];
ull ans,a[1000010],b[1000010];
int main()
{
	freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
	n=read();m=read();c=read();k=read();
	for(rint i=1;i<=n;i++)
	a[i]=read();
	for(rint i=1;i<=m;i++)
	{
		int x=read(),y=read();
		v[x].push_back(y);
	}
	for(rint i=1;i<=n;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(vis[j])
			continue;
			if((ull)a[i]&(1<<j))
			{
				vis[j]=1;
				for(int l=0;l<v[j].size();l++)
					mp[v[j][l]]=1;
			}
		}
	}
	for(int i=0;i<k;i++)
	{
		if(vis[i])
		{
		num++;
		continue;
	    }
		bool flag=true;
	    for(int j=0;j<v[i].size();j++)
	    {
	    	if(!mp[v[i][j]])
	    	{
	    		flag=false;
	    		break;
	    	}
	    }
	    if(flag==true)
	    num++;
	}
	ans=(ull)(1<<num)-n;
	cout<<ans;
	return 0;
}
