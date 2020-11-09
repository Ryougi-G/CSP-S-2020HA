#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int q,r1,ans;
int mo[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int mr[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int da,mn,yr;//1721423,
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	for(int p=1;p<=q;++p)
	{
		scanf("%d",&r1);
		if(r1<=1721423)
		{
			int k=r1/1461,k2=r1%1461;
			if(k2<=366)
			{
				yr=4713-4*k;
				for(int i=0;i<=11;++i)
				{
					if(k2-mr[i]>=0)
					{
						k2-=mr[i];
					}else if((k2-mr[i])<0)
					{
						mn=i;da=k2+1;break;
					}
				}
				printf("%d %d %d BC\n",da,mn+1,yr);
			}else
			{
				k2-=366;
				yr=4713-4*k-k2/365-1;k2=k2%365;
				for(int i=0;i<=11;++i)
				{
					if(k2-mo[i]>=0)
					{
						k2-=mo[i];
					}else if((k2-mo[i])<0)
					{
						mn=i;da=k2+1;break;
					}
				}
				printf("%d %d %d BC\n",da,mn+1,yr);
			}
			
			
		}else if(1721423<r1&&r1<=2299160)
		{
			r1-=1721423;
			int k=r1/1461,k2=r1%1461;
			if(k2<365)
			{
				yr=1+4*k;
				for(int i=0;i<=11;++i)
				{
					if(k2-mo[i]>0)
					{
						k2-=mo[i];
					}else if((k2-mo[i])<=0)
					{
						mn=i;da=k2;break;
					}
				}
				printf("%d %d %d\n",da,mn+1,yr);
			}else if(365<k2&&k2<=730)
			{
				yr=1+4*k+1;k2-=365;
				for(int i=0;i<=11;++i)
				{
					if(k2-mo[i]>0)
					{
						k2-=mo[i];
					}else if((k2-mo[i])<=0)
					{
						mn=i;da=k2;break;
					}
				}
				printf("%d %d %d\n",da,mn+1,yr);
			}else if(730<k2&&k2<=1095)
			{
				yr=1+4*k+2;k2-=730;
				for(int i=0;i<=11;++i)
				{
					if(k2-mo[i]>0)
					{
						k2-=mo[i];
					}else if((k2-mo[i])<=0)
					{
						mn=i;da=k2;break;
					}
				}
				printf("%d %d %d\n",da,mn+1,yr);
			}else
			{
				yr=4*k+3;k2-=1095;
				for(int i=0;i<=11;++i)
				{
					if(k2-mr[i]>0)
					{
						k2-=mr[i];
					}else if((k2-mr[i])<=0)
					{
						mn=i;da=k2;break;
					}
				}
				printf("%d %d %d\n",da,mn+1,yr);
			}
		}else if(2299160<r1&&r1<=2299238)//shiyixia
		{
			//cout<<"r1"<<r1<<endl;
			r1-=2299160;yr=1582;
			if(r1<=17)
			{
				mn=10;da=r1+14;
			}else if(17<r1&&r1<=47)
			{
				mn=11;da=r1-17;
			}else 
			{
				mn=12;da=r1-47;
			}
				printf("%d %d %d\n",da,mn,yr);
			
		}else if(2299238<r1)// 1583.1.1?
		{
			r1-=2299238;int kbb=r1/36524,k=(r1%36524)/1461,k2=(r1%36524)%1461;
			//cout<<kbb<<" "<<k<<" "<<k2<<endl;
		
			if(k2<=365)
			{
				yr=1583+100*kbb+4*k;
				for(int i=0;i<=11;++i)
				{
					if(k2-mo[i]>0)
					{
						k2-=mo[i];
					}else if((k2-mo[i])<=0)
					{
						mn=i;da=k2;break;
					}
				}
				printf("%d %d %d\n",da,mn+1,yr);
			}else if(365<k2&&k2<=731)
			{
				yr=1583+100*kbb+4*k+1;k2-=365;
				for(int i=0;i<=11;++i)
				{
					if(k2-mr[i]>0)
					{
						k2-=mr[i];
					}else if((k2-mr[i])<=0)
					{
						mn=i;da=k2;break;
					}
				}
				printf("%d %d %d\n",da,mn+1,yr);
			}else if(731<k2&&k2<=1096)
			{
				yr=1583+100*kbb+4*k+2;k2-=731;
				for(int i=0;i<=11;++i)
				{
					if(k2-mo[i]>0)
					{
						k2-=mo[i];
					}else if((k2-mo[i])<=0)
					{
						mn=i;da=k2;break;
					}
				}
				printf("%d %d %d\n",da,mn+1,yr);
			}else if(1096<k2&&k2<=1461)
			{
				yr=1583+100*kbb+4*k+3;k2-=1096;
				for(int i=0;i<=11;++i)
				{
					if(k2-mo[i]>0)
					{
						k2-=mo[i];
					}else if((k2-mo[i])<=0)
					{
						mn=i;da=k2;break;
					}
				}
				printf("%d %d %d\n",da,mn+1,yr);
			}
		}
	}
	
	
	
	
	fclose(stdin);fclose(stdout);
	return 0;
}
