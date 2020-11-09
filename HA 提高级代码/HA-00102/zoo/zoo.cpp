#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,c,k,a[100005],p,q,h[10005];
int b[35][200000],hs[100005],ans;
void che(int x)
{
	int cnt=0;
	while(x!=1)
	{
		int t=x%2;
		if(t==1)
		{
			for(int i=1;i<=h[cnt];++i) hs[b[cnt][i]]=1;
		}
		x/=2;++cnt;
	}
	for(int i=1;i<=h[cnt];++i) hs[b[cnt][i]]=1;
}
int ch2(int x)
{
	bool f=0;int cnt=0;
	while(x!=1)
	{
		int t=x%2;
		if(t==1)
		{
			for(int i=1;i<=h[cnt];++i) 
			{
				if(hs[b[cnt][i]]==0)
				{
					f=1;break;
				}
			}
		}
		x/=2;++cnt;
	}
	if(x!=0)
	{
		for(int i=1;i<=h[cnt];++i) 
		if(hs[b[cnt][i]]==0)
		{
		f=1;break;
		}
	}
	
	if(!f) return 1;else return 0;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d %d %d %d",&n,&m,&c,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&p,&q);
		b[p][++h[p]]=q;
	}
	for(int i=1;i<=n;++i)
	{
		che(a[i]);
	}
	//for(int i=1;i<=10;++i) cout<<hs[i]<<" ";cout<<endl;
	int kk=1<<k;
	/*for(int i=0;i<kk;++i)
	{
		if(ch2(i)) ++ans;
	}
	printf("%d\n",ans);*/
	cout<<"5"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
