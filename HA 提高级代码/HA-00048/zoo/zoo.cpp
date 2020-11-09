#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define il inline
#define res register int
#define ll long long
using namespace std;

il int read()
{
	int x=0,f=0,c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return f?-x:x;
}
const int N=1e6+10;
map< int , bool > mp;
bool vis[70];
struct Node
{
	int x,y;	
}a[N];

bool ans[70];

int n,m,c,k;
int ope;
int main()
{
	
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	
	n=read(); m=read(); c=read(); k=read();
	for(res i=1;i<=n;i++)	
	{
		int x=read();  ope|=x;
	}
	for(res i=1;i<=m;i++)
	{
		int p=read(),q=read(); a[i].x=p; vis[p]=1; a[i].y=q; 
		if( ((ope>>p)&1) ) mp[q]=1;
	}
	for(res i=0;i<k;i++)
	{
		if(!vis[i]) continue;
		for(res j=1;j<=m;j++)
		{
			if(a[j].x==i) 
				if( !mp[ a[j].y ] ) 
				{
					ans[i]=1;
					break;
				}
		}
	}

	int cnt=0;
	for(res i=0;i<k;i++)
		if(!ans[i]) cnt++;
	
	int ret=(1<<cnt)-n;
	printf("%d",ret);
	return 0;
	
}
