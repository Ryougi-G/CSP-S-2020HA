#include<bits/stdc++.h>
using namespace std;
long long a[1000000],b[1000000],c[10000000],m[1000000];
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=q;i++)
	{
//		if(a[i]>1461)
//		{
			b[i]=a[i]/1461;
			c[i]=a[i]-b[i]*1461;
			if(c[i]<=365)
			{
				b[i]=b[i]*4+1-4714;
				if(c[i]<=30){
					m[i]=1;
					c[i]=c[i]+1;
				}
				if(c[i]>=31&&c[i]<=60)
				{
					m[i]=2;c[i]=c[i]-30;
				}
				if(c[i]>60&&c[i]<=91)
				{
					m[i]=3;c[i]=c[i]-60+1;
				}
				if(c[i]>91&&c[i]<=121)
				{
					m[i]=4;c[i]=c[i]-91+1;
				}
				if(c[i]>121&&c[i]<=152)
				{
					m[i]=5;c[i]=c[i]-121+1;
				}
				if(c[i]>152&&c[i]<=182)
				{
					m[i]=6;c[i]=c[i]-152+1;
				}
				if(c[i]>182&&c[i]<=213)
				{
					m[i]=7;c[i]=c[i]-182+1;
				}
					if(c[i]>213&&c[i]<=244)
				{
					m[i]=8;c[i]=c[i]-213+1;
				}
					if(c[i]>244&&c[i]<=274)
				{
					m[i]=9;c[i]=c[i]-244+1;
				}
					if(c[i]>274&&c[i]<=305)
				{
					m[i]=10;c[i]=c[i]-274+1;
				}
					if(c[i]>305&&c[i]<=335)
				{
					m[i]=11;c[i]=c[i]-305+1;
				}
					if(c[i]>335&&c[i]<=366)
				{
					m[i]=12;c[i]=c[i]-335+1;
				}
				
			}
			if(c[i]>365){
				c[i]=c[i]-365;
				for(int l=0;;l++)
				{
					c[i]=c[i]-365*l;
					if(c[i]>0&&c[i]<365)
					{
						b[i]=b[i]+1+l-4713;
						if(c[i]<31)
						{
							m[i]=1;c[i]=c[i];
						}
						if(c[i]>=31&&c[i]<59)
						{
							m[i]=2;c[i]=c[i]-31;
						}
						if(c[i]>=59&&c[i]<90)
						{
							m[i]=3;c[i]=c[i]-59;
						}
						if(c[i]>=90&&c[i]<120)
						{
							m[i]=4;c[i]=c[i]-90;
						}
						if(c[i]>=120&&c[i]<151)
						{
							m[i]=5;c[i]=c[i]-120;
						}
						if(c[i]>=151&&c[i]<181)
						{
							m[i]=6;c[i]=c[i]-151;
						}
						if(c[i]>=181&&c[i]<212)
						{
							m[i]=7;c[i]=c[i]-181;
						}
							if(c[i]>=212&&c[i]<243)
						{
							m[i]=8;c[i]=c[i]-212;
						}
							if(c[i]>=243&&c[i]<273)
						{
							m[i]=9;c[i]=c[i]-243;
						}
							if(c[i]>=273&&c[i]<304)
						{
							m[i]=10;c[i]=c[i]-274;
						}
							if(c[i]>=304&&c[i]<334)
						{
							m[i]=11;c[i]=c[i]-304;
						}
							if(c[i]>=334&&c[i]<365)
						{
							m[i]=12;c[i]=c[i]-334;
						}
						
						break;
					}
				}
				
			}
//		}
//		if(a[i]<1461)
//		{
//			
	}
	for(int i=1;i<=q;i++)
	{
		cout<<c[i]<<' '<<m[i]<<' ';
		if(b[i]<0) cout<<-b[i]<<' '<<"BC"<<endl;
		if(b[i]>=0) cout<<b[i]+1;
		
	}
	return 0;
	
}
