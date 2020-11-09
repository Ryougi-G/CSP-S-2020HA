#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
long long a[10000000],q[10000000],du[100][1000000],sum=0;//a为有哪几种动物，q为规则中某个指令出现的次数； 
bool mai[10000000],cun[10000000];//第几种已买 
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cun[a[i]]=1;
	}
	int c=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
//		cun[x]=1;
		q[x]++;
		du[x][q[x]]=y;
		if(x>c) c=x;
	}
	long long zhong=pow(2,k-1)-1+pow(2,k-1);
	for(int i=1;i<=n;i++)
	{
		int xu=0;
//		bool flag=0;
//		
//int s=a[i]
		while(a[i]>0&&xu<=c)
		{
			xu++;
			int qwq=a[i]%2;
			a[i]/=2;
			if(!qwq) continue;
			else 
			{
				for(long long j=1;j<=q[xu-1];j++)
				{
					mai[du[xu-1][j]]=1;
				}
			}
		}
	}
	for(long long i=0;i<=zhong;i++)
	{
		if(!cun[i]) 
		{   int xu=0;
			bool flag=0;
			long long s=i;
			while(s>0&&xu<=c) 
			{
				xu++;
				int qwq=s%2;
				s/=2;
				if(!qwq) continue;
				else
				{
					for(long long j=1;j<=q[xu-1];j++)
					{
						if(!mai[du[xu-1][j]]) 
						{
							flag=1;
							break;
						}
					}
				}
			}
			if(flag==0) sum++;
		}
	}
//	if(cun[0]) sum-=1;
	cout<<sum;
	return 0;
}
