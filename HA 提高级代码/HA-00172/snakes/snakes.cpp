#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,t;
long long k;
long long x,y;
long long we[1000000];
void eat()
{
	int flag=1;
while(flag==1)
{
	flag = 0;
	long long maxi = 0;
	long long maxx = 0;
	long long minx = 1000000000,mini = 100000000;
	for(int i=1; i<=n; i++)
	{
		if(maxx<=we[i] &&we[i]!=0)
		{
			maxx = we[i];
			maxi = i;
		}
	}
	long long max2 = 0,max2i = 0;
	for(int i=1; i<=n; i++)
	{
		if(max2<=we[i] && i!=maxi && we[i]!=0)
		{
			max2 = we[i];
			max2i = i;
		}
	}
	for(int i=n; i>=1; i--)
	{
		if(minx>=we[i] && we[i]!=0)
		{
			minx = we[i];
			mini = i;
		}
	}
	if((maxx-minx)>max2 || (maxx-minx)==max2 && maxi>mini)
	{
		we[maxi] = maxx-minx;
		we[mini] = 0;
		flag = 1;
	}
}
int sum = 0;
	for(int i=1; i<=n; i++)
	{
		if(we[i]!=0)
		{
			sum++;
		}
	}
	cout<<sum<<endl;
}

int main()
{
 	freopen("snakes.in","r",stdin);
 	freopen("snakes.out","w",stdout);
	cin>>t;
	for(int i=1; i<=t; i++)
	{
		if(i==1)
		{
			cin>>n;
			for(int j=1; j<=n; j++)
			{
				cin>>we[j];
			}
			eat();
			
		}
		else
		{
			cin>>k;
			for(int j=1; j<=k; j++)
			{
				cin>>x>>y;
				we[x] = y;
			}
			eat();
		}
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}

