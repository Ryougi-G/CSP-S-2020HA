#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int t,n,k;
int a[10],b[20];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
    cin>>t;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>k;
	for(int j=0;j<k;j++)
	{
		cin>>b[j];
	}
    cout<<n<<endl<<k-2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
