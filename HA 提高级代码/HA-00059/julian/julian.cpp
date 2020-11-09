#include<bits/stdc++.h>
using namespace std;
int month[15];
long long q,Day;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);	
	month[1]=31;month[2]=28;
	month[3]=31;month[4]=30;
	month[5]=31;month[6]=30;
	month[7]=31;month[8]=31;
	month[9]=30;month[10]=31;
	month[11]=30;month[12]=31;
	cin>>q;
	while(q--)
	{
		long long D=1,Y=0,M=1;
		scanf("%lld",&Day);
		if(Day/(365*4+1)*4<4713)
		{
			Y+=Day/(365*4+1)*4;
			Day=Day-(Day/(365*4+1))*(365*4+1);
			Y+=(Day-1)/365;
			if(Day/365==0)
			month[2]=29;
			else
			{
				Day=Day-(Day/365)*365-1;			
			}
			int cnt=0;
			for(int i=1;i<=12;i++)
			{
				if(cnt+month[i]<Day)
				{
					M++;
					cnt+=month[i];
				}
				else 
				{
					D+=Day-cnt;
					break;
				}
			}
			printf("%lld %lld %lld BC\n",D,M,4713-Y);
			month[2]=28;
		}
		else
		{
			Y=1;
			Day-=((4713-1)/4+1)*(365*4+1);
			Y+=Day/(400*365+(40)+1)*400;
			Day=Day-(Day/(400*365+24*4+1)*(400*365+24*4+1));
			Y+=Day/(100*365+24*100);
			Day=Day-(Day/(100*365+24)*(100*365+24));
			Y+=Day/(4*365+1)*4;
			Day=Day-(Day/(4*365+1)*(4*365+1));
			if(Day/365==1)
			month[2]=29;
			else 
			{
				Day=Day-(Day/365)*365-1;			
			}
			int cnt=0;
			for(int i=1;i<=12;i++)
			{
				if(cnt+month[i]<Day)
				{
					M++;
					cnt+=month[i];
				}
				else 
				{
					D+=Day-cnt;
					break;
				}
			}
			printf("%lld %lld %lld\n",D,M,Y);
			month[2]=28;
		}
	}
	return 0;
}
