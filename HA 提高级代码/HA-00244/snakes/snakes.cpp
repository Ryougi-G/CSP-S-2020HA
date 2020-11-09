#include<bits/stdc++.h>
using namespace std;
long long q,w,e;
int a[2001];
long long num[2001][2001];
long long ans[2001];
int main()
{
	freopen("snakes,in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>a[i];
		for(int l=1;l<=a[i];l++)
		{
			cin>>num[i][l];
		}
	}
	for(int i=1;i<=q;i++)
	{
		ans[i]=a[i];
		for(int l=1;l<=a[i];l++)
		{
			int k=1;
			num[i][a[i]]=num[i][a[i]]-num[i][k];
			while(num[i][a[i]]>num[i][a[i]-1])
			{
				ans[i]++;
				k++;
				num[i][a[i]]=num[i][a[i]]-num[i][k];
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<ans[i];
	}
	return 0;
}

