#include<bits/stdc++.h>
using namespace std;
int T;
int k;
int n;
int x,y;
int a[1000000];
int ant;
void work1(int xx,int yy)
{
	a[xx]=yy;
}
void work(int xx)
{
	int sum=xx;
	int z=xx;
	sort(a+1,a+z+1);
	if(z==2)
	{   
		sum=1;
		return;
	}
	if((a[z]-a[1])>a[2])
	{
		sum--;
		a[z]=a[z]-a[1];
		for(int i=1;i<=z-1;i++)
		{
			a[i]=a[i+1];

		}	
		if(z-1==0)
			return;
		else
		{
				
			work(z--);
		}
	}
	else
		sum=z;
	ant=sum;

}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>T;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	work(n);
	cout<<ant;
	for(int i=2;i<=T;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>y;
			work1(x,y);
		}
		work(k);
		cout<<endl<<ant-1;
	}	
	return 0;
}
