#include<bits/stdc++.h>
using namespace std;
long long a[1100000];
int x,xx,yy,zz;
int work(int k)
{
		if(k<=365)
		{
			int num1=k/365;
			int num2=k-num1*365;
			if(k%365!=0) 
			{
				long long ans=num2/29+1;
				if(ans==1) cout<<num2+1<<' '<<1<<' '<<4713-num1<<' '<<"BC"<<endl;
				if(ans==2) cout<<num2-31<<' '<<2<<' '<<4713-num1<<' '<<"BC"<<endl;
				if(ans==3) cout<<num2-59<<' '<<3<<' '<<4713-num1<<' '<<"BC"<<endl;
				if(ans==4) cout<<num2-90<<' '<<4<<' '<<4713-num1<<' '<<"BC"<<endl;
				if(ans==5) cout<<num2-121<<' '<<5<<' '<<4713-num1<<' '<<"BC"<<endl;
				if(ans==6) cout<<num2-151<<' '<<6<<' '<<4713-num1<<' '<<"BC"<<endl;
				if(ans==7) cout<<num2-182<<' '<<7<<' '<<4713-num1<<' '<<"BC"<<endl;
				if(ans==8) cout<<num2-213<<' '<<8<<' '<<4713-num1<<' '<<"BC"<<endl;
				if(ans==9) cout<<num2-243<<' '<<9<<' '<<4713-num1<<' '<<"BC"<<endl;
				if(ans==10) cout<<num2-274<<' '<<10<<' '<<4713-num1<<' '<<"BC"<<endl;
				if(ans==11) cout<<num2-304<<' '<<11<<' '<<4713-num1<<' '<<"BC"<<endl;
				if(ans==12) cout<<num2-335<<' '<<12<<' '<<4713-num1<<' '<<"BC"<<endl;
			}
			if(k%365==0) cout<<31<<' '<<12<<' '<<4713<<' '<<"BC"<<endl;
		}
		if(k>365&&k<=1721423)
		{
			x=k/1451;
			if(x==0) 
			{
				xx=k/365;
				yy=k-xx*365;
				zz=yy/29;
				if(zz==1) cout<<yy+1<<' '<<1<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==2) cout<<yy-31<<' '<<2<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==3) cout<<yy-59<<' '<<3<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==4) cout<<yy-90<<' '<<4<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==5) cout<<yy-121<<' '<<5<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==6) cout<<yy-151<<' '<<6<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==7) cout<<yy-182<<' '<<7<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==8) cout<<yy-213<<' '<<8<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==9) cout<<yy-243<<' '<<9<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==10) cout<<yy-274<<' '<<10<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==11) cout<<yy-304<<' '<<11<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==12) cout<<yy-335<<' '<<12<<' '<<4713-xx<<' '<<"BC"<<endl;
			}
			if(x!=0)
			{
				xx=4*x+(k-1451*x)/365;
				yy=k-1451*x-(xx-4*x)*365;
				zz=yy/29;
				if(zz==1) cout<<yy+1<<' '<<1<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==2) cout<<yy-31<<' '<<2<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==3) cout<<yy-59<<' '<<3<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==4) cout<<yy-90<<' '<<4<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==5) cout<<yy-121<<' '<<5<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==6) cout<<yy-151<<' '<<6<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==7) cout<<yy-182<<' '<<7<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==8) cout<<yy-213<<' '<<8<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==9) cout<<yy-243<<' '<<9<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==10) cout<<yy-274<<' '<<10<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==11) cout<<yy-304<<' '<<11<<' '<<4713-xx<<' '<<"BC"<<endl;
				if(zz==12) cout<<yy-335<<' '<<12<<' '<<4713-xx<<' '<<"BC"<<endl;
			}
		}
		if(k>1721423)
		{
			k=k-1721423;
			x=k/1451;
			xx=4*x+(k-1451*x)/365;
			yy=k-1451*x-(xx-4*x)*365;
			zz=yy/29;
			if(zz==1) cout<<yy+1<<' '<<1<<' '<<1+xx<<endl;
			if(zz==2) cout<<yy-31<<' '<<2<<' '<<1+xx<<endl;
			if(zz==3) cout<<yy-59<<' '<<3<<' '<<1+xx<<endl;
			if(zz==4) cout<<yy-90<<' '<<4<<' '<<1+xx<<endl;
			if(zz==5) cout<<yy-121<<' '<<5<<' '<<1+xx<<endl;
			if(zz==6) cout<<yy-151<<' '<<6<<' '<<1+xx<<endl;
			if(zz==7) cout<<yy-182<<' '<<7<<' '<<1+xx<<endl;
			if(zz==8) cout<<yy-213<<' '<<8<<' '<<1+xx<<endl;
			if(zz==9) cout<<yy-243<<' '<<9<<' '<<1+xx<<endl;
			if(zz==10) cout<<yy-274<<' '<<10<<' '<<1+xx<<endl;
			if(zz==11) cout<<yy-304<<' '<<11<<' '<<1+xx<<endl;
			if(zz==12) cout<<yy-335<<' '<<12<<' '<<1+xx<<endl;
		}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int  n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
	}
	for(int i=0;i<n;i++)
	{
		work(a[i]);
	}
	return 0;
}
