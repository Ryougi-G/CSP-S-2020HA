#include<bits/stdc++.h>
using namespace std;
int T,n,k[20],x[20][100100];
unsigned long long ,y[20][100100];
struct she
{
	int id;
	unsigned long long tl;
}t[1000100]
void shuru()
{
	cin>>T;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i].tl;t[i].id=i;
	}
	for(int i=2;i<=T;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i];j++)
		{
			cin>>x[i][j]>>y[i][j];
		}
	}
}
void zd()
{
	sort(tl+1,tl+1+n);
	
}
int main()
{
	shuru();
	zd();
	return 0;
}
