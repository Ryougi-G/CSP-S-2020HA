#include<bits/stdc++.h>
using namespace std;
int q[10000000];
struct ans{
	int y=-4713,m=1,d=1;
	bool bc=true;
}a[99];
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>q[i];
	for(int i=0;i<n;i++)
	{
		while(q[i]>=31)
		{
			q[i]-=31;
			a[i].m++;//1
			if(q[i]<28) break;
			if(a[i].y%4==0&&q[i]<29) break;
			
			if(a[i].y%4==0) 
			{
				q[i]-=29;
				a[i].m++;
			}
			else
			{
				q[i]-=28;
				a[i].m++;
			}//2
			
			if(q[i]<31) break;
			q[i]-=31;
			a[i].m++;//3
			
			if(q[i]<30) break;
			q[i]-=30;
			a[i].m++;//4
			
			if(q[i]<31) break;
			q[i]-=31;
			a[i].m++;//5
			
			if(q[i]<30) break;
			q[i]-=30;
			a[i].m++;//6
			
			if(q[i]<31) break;
			q[i]-=31;
			a[i].m++;//7
			
			if(q[i]<31) break;
			q[i]-=31;
			a[i].m++;//8
			
			if(q[i]<30) break;
			q[i]-=30;
			a[i].m++;//9
			
			if(q[i]<31) break;
			q[i]-=31;
			a[i].m++;//10
			
			if(q[i]<30) break;
			q[i]-=30;
			a[i].m++;//11
			
			if(q[i]<31) break;
			q[i]-=31;
			a[i].m++;//12
			
			if(q[i]>0)
			{
				a[i].y++;
				a[i].m=1;
			}
			if(a[i].y==0) a[i].y++;
		}
		if(a[i].y>0) a[i].bc=false;
		a[i].d+=q[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i].d<<" "<<a[i].m<<" "<<abs(a[i].y);
		if(a[i].bc) cout<<" BC";
		cout<<endl;
	}
	return 0;
}
