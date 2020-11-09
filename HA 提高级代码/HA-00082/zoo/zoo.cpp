#include<bits/stdc++.h>

#define ll long long

using namespace std;

struct node
{
	int p,q;
}s[1000005];

int n,m,c,k;
//int num[10005];
ll ans=0;
int a[1000005];
bool ci[1000005];
bool ani[1500000];

string turn(int n)
{
	int cnt=0;
	string s;
	while(n>0)
	{
		s+=char(n%2+48);
		n/=2;
	}
	return s;
}

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	
	cin>>n>>m>>c>>k;
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		ani[tmp]=1;
	}
	for(int i=0;i<m;i++)
	{
		cin>>s[i].p>>s[i].q;
	}
	
	for(int i=0;i<pow(2,k);i++)
	{
		if(ani[i]==1)
		{
			string tmp=turn(i);
			for(int j=1;j<=m;j++)
			{
//				int temp=long(tmp/pow(10,s[j].p))%10;
//				int temp=num[tmp-s[j].p];
				char temp=tmp[tmp.length()-s[j].p];
				if(temp=='1')
				{
					ci[j]=1;
				}
			}
		}
	}
	for(int i=0;i<pow(2,k);i++)
	{
		string tmp=turn(i);
		for(int j=1;j<=m;j++)
		{
			char temp=tmp[tmp.length()+1-s[j].p];
			if(temp=='1'&&ani[i]==0&&ci[j]==1)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
