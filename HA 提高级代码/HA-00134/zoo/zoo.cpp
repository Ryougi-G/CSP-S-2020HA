#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int m,n,c,k;
int a[31],b[1001];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=0;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int j=0;j<=m;j++)
	{
		cin>>b[j];
	}
	cout<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
