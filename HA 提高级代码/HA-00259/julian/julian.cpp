#include<bits/stdc++.h>
using namespace std;
int q;
int r[111111111];
int d=1,m=1,y=-4713;
int sum=0;
void work(int ri)
{
	int t=ri;
	for(int i=1;i<=t;i++)
	{

			if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
			{
				if(d<31)
				{
					d++;
					ri--;
				}
				else
				{
					m++;
					d-=30;
				}
			
		
			}
			if(m==2)
			{
				if((y+1)%4==0)
				{
					if(d<29)
					{
						d++;
						ri--;
					}
					else
					{
						m++;
						d-=28;
					}
				}
				else
				{
					if(d<28)
					{
						d++;
						ri--;
					}
					else
				{
					m++;
					d-=27;
				}
				}
		
			}
			if(m==4||m==6||m==9||m==11)
			{
				if(d<30)
				{
					d++;
					ri--;
				}
				else
				{
					m++;
					d-=29;
				}

			}	
		if(m>12)
		{
			y++;
			m-=12;
			d++;
			ri--;
		}	
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++)
		cin>>r[i];
	work(r[1]);
	cout<<d<<' '<<m<<' '<<-y<<' '<<"BC";
	for(int i=2;i<=q;i++)
	{
		work(r[i]);
		cout<<endl<<d<<' '<<m<<' '<<-y<<' '<<"BC";
	}
 return 0;
}
