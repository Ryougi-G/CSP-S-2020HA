#include<bits/stdc++.h>
using namespace std;
const int g=1000005;
int n,m,c,k,hash[g];
unsigned long long a,sum;
bool f[g],b[70];
pair<int,int> x[g];

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		sum|=a;
	}
	for(int i=1;i<=m;i++)
		scanf("%d%d",&x[i].second,&x[i].first);
	sort(x+1,x+m+1);
	for(int i=1;i<=m;i++)
	{
		if(x[i].first==x[i-1].first)
			hash[i]=hash[i-1];
		else hash[i]=hash[i-1]+1;
		if(((unsigned long long)1<<x[i].second)&sum)//要购买第hash[i]种饲料
			f[hash[i]]=1;
	}
	for(int i=1;i<=m;i++)
		if(!f[hash[i]])//没有饲料
			if(!b[x[i].second])//不能有x[i].second
			{
				b[x[i].second]=1;//只标记一次
				k--;
			}
	cout<<((unsigned long long)1<<k)-n;
	return 0;
}

