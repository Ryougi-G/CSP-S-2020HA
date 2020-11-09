#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct snak{
	ll tili;
	int num;
};
snak batt[50050],cop1[50050],cop2[50050];
int T,m,n,k,x,y;
ll ans;
bool fir;
bool chan()
{
	cop1[m].tili-=cop1[1].tili;
	for(int i=m;i>1;i--)
	{
		if(cop1[i].tili<cop1[i-1].tili||(cop1[i].tili==cop1[i-1].tili&&cop1[i].num<cop1[i-1].num))swap(cop1[i],cop1[i-1]);
		else
		{
			break;
		}
	}
	for(int i=m;i>1;i--)
	{
		cop2[i-1]=cop1[i];
	}
	for(int i=m-1;i>=1;i--)
	{
		cop1[i]=cop2[i];
	}
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		if(!fir)
		{
			cin>>n;
			m=n;
			for(int i=1;i<=n;i++)
			{
				cin>>batt[i].tili;
				batt[i].num=i;
			}
		}
		else 
		{
			cin>>k;
			for(int i=1;i<=k;i++)
			{
				cin>>x>>y;
				batt[x].tili=y;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cop1[i]=batt[i];
			cop2[i]=batt[i];
		}
		if(cop1[m].tili-cop1[1].tili>=cop1[m-1].tili)
		{
			if(cop1[m].tili==cop1[2].tili&&cop1[m].num>cop1[2].num)
			{
				chan();
				ans++;
			}
			else if(cop1[m].tili-cop1[1].tili>cop1[2].tili)
			{
				chan();
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
