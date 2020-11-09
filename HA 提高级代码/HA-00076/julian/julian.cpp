#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int sum=0,Q,r;
int day,month,year;
int y_bc[5001];
int ju[100000];//1582
int a[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
int ar[13]={0,0,31,60,91,121,152,182,213,244,274,305,335};
int search(int x)
{
	int left=1,right=4713;
	int mid=(left+right)/2;
	while(left<mid)
	{
		if(x>y_bc[mid])
		{
			right=mid;
		}
		else
		{
			left=mid;
		}
		mid=(left+right)/2;
	}
	return left;
}
int search1(int x)
{
	int left=1,right=1852;
		int mid=(left+right)/2;

	while(left<mid)
	{
		if(x<ju[mid])
		{
			right=mid;
		}
		else
		{
			left=mid;
		}
		mid=(left+right)/2;
	}
	return left;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	y_bc[4713]=-1;
	for(int i=4712;i>=1;i--)
	{
		if(i%4==0)
		{
			y_bc[i]=y_bc[i+1]+366;
		}
		else
		{
			y_bc[i]=y_bc[i+1]+365;
		}
		//cout<<y_bc[i]<<endl;
	}
	ju[1]=0;
	for(int i=2;i<=1582;i++)
	{
		if((i-1)%4==0)
		{
			ju[i]=ju[i-1]+366;
		}
		else 
		{
			ju[i]=ju[i-1]+365;
		}
	}
	cin>>Q;
	ju[1583]=ju[1582]+355;
	/*for(int i=1584;i<=10000;i++)
	{
		if(((i-1)%4==0&&(i-1)%100!=0)||(i-1)%400==0)
		{
			ju[i]=ju[i-1]+366;
		}	
		else
		{
			ju[i]=ju[i-1]+365;
		}
	} */
	while(Q--)
	{
		cin>>r;
		if(r<=1721423)
		{
			year=search(r);
			while(r<y_bc[year])
			{
				year++;
			}
			r-=y_bc[year];
			if((year-1)%4==0)
			{
				for(int i=12;i>=1;i--)
				{
					if(r-ar[i]>0)
					{
						day=r-ar[i];
						month=i;
						break;
					}
				}
			}
			else
			{
				for(int i=12;i>=1;i--)
				{
					if(r-a[i]>0)
					{
						day=r-a[i];
						month=i;
						break;
					}
				}
			}
			printf("%d %d %d BC\n",day,month,year);
		}
		else if(r<=22999238)
		{
			r-=y_bc[1]+366; 
			year=search1(r);
			while(r>ju[year])
			{
				year++;
			}
			while(r<ju[year])
			{
				year--;
			}
			r-=ju[year];
			
			
			if(year==1582)
			{
				if(r>277)
				{
					r+=10;
				}
			}
			
			if(year%4==0)
			{
				for(int i=12;i>=1;i--)
				{
					if(r-ar[i]>0)
					{
						day=r-ar[i];
						month=i;
						break;
					}
				}
			}
			else
			{
				for(int i=12;i>=1;i--)
				{
					if(r-a[i]>0)
					{
						day=r-a[i];
						month=i;
						break;
					}
				}
			}
			printf("%d %d %d\n",day,month,year);
		}
	}
	
	return 0;
}
