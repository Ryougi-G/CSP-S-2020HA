#include<bits/stdc++.h>
using namespace std;
int month1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int month2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int main ()
{	
	freopen("julian.in","r",stdin);
	freopen("julian,out","w",stdout);
	int judge;
	judge=(1581+4713)*365+1581/4+4713/4+month1[0]+month1[1]+month1[2]+month1[3]+month1[4]+month1[5]+month1[6]+month1[7]+month1[8]+4;
	int sp,year,month,day;
	int Q,julian;
	cin>>Q;
	for(int t=1;t<=Q;t++)
	{
		cin>>julian;
		if(julian<judge){
			sp=(julian%(365*3+366)/365);
			year=julian/(365*3+366)*4-1-sp;
			if(year<=4713)
			{
				year=4713-year-1;
				int a,i,x=(julian%(365*3+366))%365;
				for (i=0;a<2;i++){day=x+1;
					x=x-month1[i];
					if(x>0) a=1;
					else a=2;//month is i+1 and day is x
					month=i+1;
					}
				cout<<day<<" "<<month<<" "<<year<<"BC"<<endl;
			}
			else
			{
				year=year-4713-1;
				int a,i,x=(julian%(365*3+366))%365;
					for (i=0;a<2;i++){day=x+1;
					x=x-month1[i];
					if(x>0) a=1;
					else a=2;//month is i+1 and day is x
					month=i+1;
					}
				cout<<day<<" "<<month<<" "<<year<<endl;
			}}
		else{
				int b;
				b=julian%(365*3+366)%365;
				if(b<=76){
					year=year-4713-1;
		int a,i,x=(julian%(365*3+366))%365;
					for (i=0;a<2;i++){day=x+1;
					x=x-month1[i];
					if(x>0) a=1;
					else a=2;//month is i+1 and day is x
					month=i+1;
					}
				}
				else{
					year=year-4713+1-1;
				int a,i,x=(julian%(365*3+366))%365;
					for (i=0;a<2;i++){day=x+1;
					x=x-month1[i];
					if(x>0) a=1;
					else a=2;//month is i+1 and day is x
					month=i+1;
					}
				}
			cout<<day<<" "<<month<<" "<<year<<endl;	
			}
    }
	return 0;
}
