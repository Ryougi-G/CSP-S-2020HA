#include<bits/stdc++.h>
using namespace std;
struct snake{
	int xg;
	int num;
	int s[10000];
	int ans;
}a[50];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int n,zj,num0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			cin>>a[i].num;
			a[i].ans=a[i].num;
		    for(int j=0;j<a[i].num;j++) cin>>a[i].s[j];
		}
		else 
		{
			a[i].num=a[i-1].num;
			a[i].ans=a[i].num;
			cin>>a[i].xg;
			for(int j=0;j<a[i].xg;j++)
			{
				cin>>zj;
				cin>>a[i].s[zj-1];
			} 
		}
		sort(a[i].s,a[i].s+a[i].num);
	}
		
	for(int i=0;i<n;i++)
	{
		if(a[i].num==3&&a[i].s[2]-a[i].s[0]<a[i].s[1]) a[i].ans=3;
		if(a[i].num==3&&a[i].s[2]-a[i].s[0]==a[i].s[1]) a[i].ans=2;
		if(a[i].num==3&&a[i].s[2]-a[i].s[0]>a[i].s[1]) a[i].ans=1;
	}
	for(int i=0;i<n;i++) cout<<a[i].ans<<endl;
	return 0;
}
