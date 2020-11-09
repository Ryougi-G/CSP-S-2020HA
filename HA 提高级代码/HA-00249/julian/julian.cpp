#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,a,day,month,year;
int b[13]={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%lld",&a);
		if(a<1721424)
		{
			int k=0;
			year=4713;
			while(a>0)
			{
				if(year%4!=1)
				{
					a-=365;
					if(a>0)	year--;
					else if(a==0){k=1;cout<<1<<" "<<1<<" "<<year-1<<" "<<" BC"<<endl;break;}
					else if(a<0){
						int t=0;
						a+=365;
						b[1]=28;
						do
						{
							a-=b[t];
							t++;	
						}while(a>=0);
						month=t;
						day=a+b[t-1]+1;
						break;
					}
				}
				else{
					a-=366;
					if(a>0)	year--;
					else if(a==0){cout<<1<<" "<<1<<" "<<year-1<<" "<<" BC"<<endl;k=1;break;}
					else if(a<0){
						int t=0;
						a+=366;
						b[1]=29;
						do
						{
							a-=b[t];
							t++;	
						}while(a>=0);
						month=t;
						day=a+b[t-1]+1;
					}
				}
			}
			if(!k)cout<<day<<" "<<month<<" "<<year<<" "<<"BC"<<endl;
		}
		else if(a>1721424&&a<2298430)
		{
			a-=1721424;
			int k=0;
			year=1;
			while(a>0)
			{
				if(year%4!=0)
				{
					a-=365;
					if(a>0)	year++;
					else if(a==0){k=1;cout<<1<<" "<<1<<" "<<year+1<<endl;break;}
					else if(a<0){
						int t=0;
						a+=365;
						b[1]=28;
						do
						{
							a-=b[t];
							t++;	
						}while(a>=0);
						month=t;
						day=a+b[t-1]+1;
						break;
					}
				}
				else{
					a-=366;
					if(a>0)	year++;
					else if(a==0){cout<<1<<" "<<1<<" "<<year+1<<endl;k=1;break;}
					else if(a<0){
						int t=0;
						a+=366;
						b[1]=29;
						do
						{
							a-=b[t];
							t++;	
						}while(a>=0);
						month=t;
						day=a+b[t-1]+1;
					}
				}
			}
			if(!k)cout<<day<<" "<<month<<" "<<year<<endl;
		}
		else if(a>2298430&&a<=2298431+69)
		{
			a-=2298430-10;
			int t=10;
			do
			{
				a-=b[t];
				t++;	
			}while(a>=0);
			month=t;
			day=a+b[t-1]+1;
			cout<<day<<" "<<month<<" "<<1582<<endl;
		}
		else if(a>2298500&&a<=2298500+6575)
		{
			a-=2298500;
			int k=0;
			year=1583;
			while(a>0)
			{
				if(year%4!=0)
				{
					a-=365;
					if(a>0)	year++;
					else if(a==0){k=1;cout<<1<<" "<<1<<" "<<year+1<<endl;break;}
					else if(a<0){
						int t=0;
						a+=365;
						b[1]=28;
						do
						{
							a-=b[t];
							t++;	
						}while(a>=0);
						month=t;
						day=a+b[t-1]+1;
						break;
					}
				}
				else{
					a-=366;
					if(a>0)	year++;
					else if(a==0){cout<<1<<" "<<1<<" "<<year+1<<endl;k=1;break;}
					else if(a<0){
						int t=0;
						a+=366;
						b[1]=29;
						do
						{
							a-=b[t];
							t++;	
						}while(a>=0);
						month=t;
						day=a+b[t-1]+1;
					}
				}
			}
			if(!k)cout<<day<<" "<<month<<" "<<year<<endl;
		}
		else if(a>2298500+6575)
		{
			a-=2298500+6575+6;
			year=1601;
			int k=0;
			while(a>0)
			{
				a-=146097;
				year+=400;
			}
			a+=146097,year-=400;
			while(a>0)
			{
				if(year%4!=0&&year%400!=0)
				{
					a-=365;
					if(a>0)	year++;
					else if(a==0){k=1;cout<<1<<" "<<1<<" "<<year-1<<endl;break;}
					else if(a<0){
						int t=0;
						a+=365;
						b[1]=28;
						do
						{
							a-=b[t];
							t++;	
						}while(a>=0);
						month=t;
						day=a+b[t-1]+1;
						break;
					}
				}
				else{
					a-=366;
					if(a>0)	year++;
					else if(a==0){cout<<1<<" "<<1<<" "<<year-1<<endl;k=1;break;}
					else if(a<0){
						int t=0;
						a+=366;
						b[1]=29;
						do
						{
							a-=b[t];
							t++;	
						}while(a>=0);
						month=t;
						day=a+b[t-1]+1;
					}
				}
			}
			if(!k)cout<<day<<" "<<month<<" "<<year-2<<endl;
		}
	}
	return 0;
}
