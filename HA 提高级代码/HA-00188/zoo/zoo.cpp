#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll sum[70];
ll ans=2;
ll cou;
bool can[70];
bool cancan[100000010];
vector<ll>qwq[70];
ll n,m,c,k,qq,ani,req1,req2;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	memset(can,true,sizeof(can));
	cin>>n>>m>>c>>k;
	for(int i=1;i<=k;i++)ans*=2;
	for(int i=1;i<=n;i++)
	{
		qq=0;
		cin>>ani;
		while(ani)
		{
			if(ani&1)sum[qq++]++;
			ani=ani>>1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>req1>>req2;
		qwq[req1].push_back(req2);
		if(sum[req1])
		{
			cancan[req2]=true;
			can[req1]=true;
		}
		if((!sum[req1])&&(!cancan[req2]))
			can[req1]=false;
	}
	for(int i=0;i<=k;i++)
	{
		for(int j=0;j<qwq[i].size();j++)
		{
			if(cancan[qwq[i][j]])
			{
				can[i]=true;
				break;
			}
		}
	}
	for(int i=0;i<k;i++)
	{
		if(!can[i])ans/=2;
	}
	/*for(int i=1;i<=cou;i++)
	{
		ans*=2;
	}*/
	ans-=n;
	cout<<ans;
	return 0;
}
