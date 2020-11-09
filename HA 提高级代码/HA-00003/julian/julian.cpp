#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q;
	int a[100010];
	cin>>q;
	for(int i=0;i<q;i++)
		cin>>a[i];
	int w=1178+365*4713+395+365*1582,e=1178+365*4713;
	long long n,y,r=0,rn=0,sy=0,sbn=0,bn=0;
	int b[14]={31,28,31,30,31,30,31,31,30,31,30};
	for(int i=0;i<q;i++)
	{
		if(a[i]<w)
		{
			if(a[i]<e)
			{
				rn=a[i]/1461;
				sy=a[i]%1461/365;
				n=4713-rn*4-sy;
				r=a[i]-1461*rn-365*sy;
				y=1;
				for(int j=0;j<12;j++)
				{
					if(r-b[j]<0) break;
					r-=b[j];
					y++;
				}
				if(a[i]%1461>60) r--;
				cout<<r+1<<' '<<y<<' '<<n<<' '<<"BC"<<endl;
			}
			else if(a[i]==w)
			     {
			     	cout<<"4 10 1582"<<endl;
			     	return 0;
				 }
			else
			{
				a[i]-=e;
				rn=a[i]/1461;
				sy=a[i]%1461/365;
				n=rn*4+sy;
				r=a[i]-1461*rn-365*sy;
				y=1;
				for(int j=0;j<11;j++)
				{
					if(r-b[j]<0) break;
					r-=b[j];
					y++;
				}
				if(a[i]%1461>60) r--;
				cout<<r+1<<' '<<y<<' '<<n+1<<endl;
			}
		}
		else
		{
			a[i]-=w;
			a[i]+=319;
			if(a[i]>=6939)
			{
				a[i]-=6939;
				sbn=a[i]/146097;
				bn=a[i]%146097/36524;
			}
			rn=a[i]%146097%36524/1461;
			//zrn=a[i]/1461;
			sy=a[i]%146097%36524%1461/365;
			n=sbn*400+bn*100+rn*4+sy;
			r=a[i]-sbn*146097-bn*36524-rn*1461-sy*365;
			//r+=56;
			y=1;
			for(int j=0;j<11;j++)
			{
				if(r-b[j]<0) break;
				r-=b[j];
				y++;
			}
			//if(a[i]%1461>60) r--;
			cout<<r<<' '<<y<<' '<<n+1582<<endl;
		}
	}
	return 0;
}
