#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll bo=2299160,nextrun=413;
ll q,r,t,m;
ll ye=-4712,mo=1,da=1;
ll yest;
bool BC;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		ye=-4712;mo=1;da=1;yest=0;
		cin>>r;
		if(r<=bo)
		{
			t=r%365;
			yest=r/365;
			m=yest/4;
			if(m*4<yest)m++;
			while(t<m)
			{
				yest--;
				t+=365;
				if((m-1)*4==yest)
				{
					m--;
					//t++;//?-
				}
			}
			t-=m;
			ye+=yest;
			while(t--)
			{
				da++;
				if(mo==1&&da==32)
				{
					mo++;da=1;
				}
				else if(mo==2&&da==29&&(ye%4!=0))
				{
					mo++;da=1;
				}
				else if(mo==2&&da==30)
				{
					mo++;da=1;
				}
				else if(mo==3&&da==32)
				{
					mo++;da=1;
				}
				else if(mo==4&&da==31)
				{
					mo++;da=1;
				}
				else if(mo==5&&da==32)
				{
					mo++;da=1;
				}
				else if(mo==6&&da==31)
				{
					mo++;da=1;
				}
				else if(mo==7&&da==32)
				{
					mo++;da=1;
				}
				else if(mo==8&&da==32)
				{
					mo++;da=1;
				}
				else if(mo==9&&da==31)
				{
					mo++;da=1;
				}
				else if(mo==10&&da==32)
				{
					mo++;da=1;
				}
				else if(mo==11&&da==31)
				{
					mo++;da=1;
				}
				else if(mo==12&&da==32)
				{
					mo=1;da=1;ye++;
				}
			}
			if(ye<=0)
			{
				cout<<da<<" "<<mo<<" "<<(-ye+1)<<" BC";
			}
			else cout<<da<<" "<<mo<<" "<<ye;
			cout<<"\n";
		}
		else
		{
			r-=bo;
			ye=1582;mo=10;da=15;
			if(r>=nextrun)
			{
				ye=1584;mo=1;da=1;r-=nextrun;
			}
			t=r%365;
			yest=r/365;
			m=yest/4;
			ll mm=yest/400,nn=yest/100;
			m-=(nn-mm);
			
			if(m*4<yest)m++;
			while(t<m)
			{
				yest--;
				t+=365;
				if((m-1)*4==yest)
				{
					m--;
					//t++;//?
				}
			}
			ye+=yest;
			t-=m;
			
			for(int i=1;i<=t;i++)
			{
				da++;
				if(mo==1&&da==32)
				{
					mo=2;da=1;
				}
				else if(mo==2&&da==29&&(ye%4!=0||(ye%4==0&&ye%100!=0)))
				{
					mo=3;da=1;
				}
				else if(mo==2&&da==30&&ye%4==0)
				{
					mo=3;da=1;
				}
				else if(mo==3&&da==32)
				{
					mo=4;da=1;
				}
				else if(mo==4&&da==31)
				{
					mo++;da=1;
				}
				else if(mo==5&&da==32)
				{
					mo++;da=1;
				}
				else if(mo==6&&da==31)
				{
					mo++;da=1;
				}
				else if(mo==7&&da==32)
				{
					mo++;da=1;
				}
				else if(mo==8&&da==32)
				{
					mo++;da=1;
				}
				else if(mo==9&&da==31)
				{
					mo++;da=1;
				}
				else if(mo==10&&da==32)
				{
					mo++;da=1;
				}
				else if(mo==11&&da==31)
				{
					mo++;da=1;
				}
				else if(mo==12&&da==32)
				{
					mo=1;da=1;ye++;
				}
			}
			cout<<da<<" "<<mo<<" "<<ye<<"\n";
		}
	}
	return 0;
}
