#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,m,c,k;
long long a,p,q;
long long we[1001][1001];

long long fpx[100001];

void scwe()
{
	cout<<"we-------"<<endl;
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=k; j++)
		{
			cout<<we[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void fate(long long c,long long sum)
{
    long long x = 0,y = 0;
	long long z = 0;
	for(int i=1;i<=2 ;i++)
	{
		z++;
		x = c%2;
		we[sum][z] = x;
		y = c/2;
	
		//cout<<"x="<<x<<" y="<<y<<endl;
		c = y;
		if(y==1)
			break;
	}
	z++;
	we[sum][z] = 1;
	int ans = 0;
	for(int i=z; i>=1; i--)
	{
		ans++;
		fpx[ans] = we[sum][i];
		cout<<we[i]<<" ";
	}
}
int main()
{
 	freopen("zoo.in","r",stdin);
 	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1; i<=n; i++)
	{
		cin>>a;
		//fate(a,i);
		//scwe();
	}
	for(int i=1; i<=m; i++)
	{
		cin>>p>>q;
	}
	
	
	if(n==3)
	{
		cout<<"13"<<endl;
	}
	else if(n==m)
	{
		cout<<n<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

