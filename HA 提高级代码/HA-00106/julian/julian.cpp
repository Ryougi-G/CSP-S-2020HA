#include<bits/stdc++.h>
using namespace std;
#define int long long 
int fen1=1721424;//��԰ǰ 
int fen2=2299161; 
int fen3=2299238;
int t,r;
int yue[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int run[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int a[48]={31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int b[48]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
int c[400]={365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,365,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,365,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,365,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,
365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365};
signed main( )
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>r;
		if(r<fen1)
		{
			r=r+1;
			int nian=r/(365*3+366)*4;
			r=r%((365*3+366));
			int yue=0;
			for(int i=0;i<=47;i++)
			{
				yue++;
				if(r<=a[i])
				{
					cout<<r<<" "<<(yue-1)%12+1<<"��"<<4713-nian-(yue-1)/12<<" "<<"BC"<<endl; 
					break;	
				}
				r=r-a[i];
			}
		}
		else if(r<fen2)
		{
			r=r-fen1+1;
			int nian=r/(365*3+366)*4;
			r=r%(365*3+366);
			int yue=0;
			for(int i=0;i<=47;i++)
			{
				yue++;
				if(r<=b[i])
				{
					cout<<r<<" "<<(yue-1)%12+1<<" "<<nian+(yue-1)/12+1<<" "<<endl; 
					break;	
				}
				r=r-b[i];
			}
		}
		else if(r<=fen3)
		{
			r=r-fen2;
			r++;
			if(r<=17)cout<<15+r-1<<" "<<10<<" 1582 "<<endl; 
			else 
			{
				r=r-17;
				if(r<=30)cout<<r<<" "<<11<<" 1582 "<<endl;
				else cout<<r-30<<" "<<12<<" 1582 "<<endl;
			}
		}
		else 
		{ 
			int u=0;
			r=r-fen3;
			int lun=r/(365*303+366*97)*400;
			r=r%(365*303+366*97);
		//	cout<<r<<endl;
			for(int i=0;i<400;i++)
			{
				if(r<=c[i])
				{
					u=i;
					break;
				}
				r=r-c[i];
			}
		//	cout<<r<<endl;
			u=u+1582+1+lun;
			if(u%400==0)
			{
				for(int i=0;i<=11;i++)
				{
					if(r<=run[i])
					{
						cout<<r<<"��"<<i+1<<" "<<u<<endl; 
						break;
					}
					r=r-run[i];
				}
			}
			else if(u%4==0&&u%100!=0)
			{
				for(int i=0;i<=11;i++)
				{
					if(r<=run[i])
					{
						cout<<r<<"��"<<i+1<<" "<<u<<endl; 
						break;
					}
					r=r-run[i];
				}
			}
			else
			{
				for(int i=0;i<=11;i++)
				{
					if(r<=yue[i])
					{
						cout<<r<<"��"<<i+1<<" "<<u<<endl; 
						break;
					}
					r=r-yue[i];
				}
			} 
		}
	}
}
