#include<bits/stdc++.h>
using namespace std;
long long q,a[100010];
long long d=1,m=1,y=4713;
int p[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int r[20]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int y1582[20]={0,31,28,31,30,31,30,31,31,30,21,30,31};
int qh=-1;
void ryue(int x);
void pyue(int x);
void tyue(int x);
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=q;++i)
	{
		d=1,m=1,y=4713,qh=-1;
		while(a[i]>0)
		{
			if(y==4713&&qh==-1&&a[i]>=1721424)
			{
				a[i]=a[i]-1721424;
				y=1;
				qh=1;
			}
			if(y==1&&qh==1&&a[i]>=90580140)
			{
				a[i]=a[i]-90580140;
				y=250000;
			}
			if(y==1&&qh==1&&a[i]>=3562427)
			{
				a[i]=a[i]-3562427;
				y=10001;
			}
			if(y>=10000&&(y-1)%10000==0&&a[i]>=3652425)
			{
				a[i]=a[i]-3652425;
				y=y+10000;
			}
			if(a[i]>366)
			{
				if(qh==-1)
				{
					if((y-1)%4==0)
					{
						a[i]=a[i]-366;
						y--;
					}
					else
					{
						a[i]=a[i]-365;
						y--;
					}
				}
				if(qh==1)
				{
					if(y<1582)
					{
						if(y%4==0)
						{
							a[i]=a[i]-366;
							y++;
						}
						else
						{
							a[i]=a[i]-365;
							y++;
						}
					}
					else if(y==1582)
					{
						a[i]=a[i]-355;
						y++;
					}
					else if(y>1582)
					{
						if(y%400==0||(y%4==0&&y%100!=0))
						{
							a[i]=a[i]-366;
							y++;
						}
						else
						{
							a[i]=a[i]-365;
							y++;
						}
					}
				}
			}
			if(a[i]<=366&&a[i]>31)
			{
				
				if(qh==-1)
				{
					if((y-1)%4==0)
					{
						ryue(i);
					}
					else
					{
						pyue(i);
					}
				}
				if(qh==1)
				{
					if(y<1582)
					{
						if((y-1)%4==0)
						{
							ryue(i);
						}
						else
						{
							pyue(i);
						}
					}
					else if(y==1582)
					{
						tyue(i);
					}
					else if(y>1582)
					{
						if(y%400==0||(y%4==0&&y%100!=0))
						{
							ryue(i);
						}
						else
						{
							pyue(i);
						}
					}
				}
			}
			if(a[i]<=31&&a[i]>0)
			{
				d=d+a[i];
				a[i]=a[i]-a[i];
			}
		}
		printf("%lld %lld %lld ",d,m,y);
		if(qh==-1)
		{
			printf("BC");
		}
		printf("\n");
	}
	return 0;
}
void ryue(int x)
{
	for(int i=1;i<=12;++i)
	{
		if(a[x]<r[i])
		{
			m=i;
			break;
		}
		a[x]=a[x]-r[i];
	}
	return;
}
void pyue(int x)
{
	for(int i=1;i<=12;++i)
	{
		if(a[x]<p[i])
		{
			m=i;
			break;
		}
		a[x]=a[x]-p[i];
		
	}
	return;
}
void tyue(int x)
{
	for(int i=1;i<=12;++i)
	{
		if(a[x]<y1582[i])
		{
			m=i;
			break;
		}
		a[x]=a[x]-y1582[i];
	}
	return;
}
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
	3651694515(2001~10000000)365237(1001~2000)365250(1~1000)3652425002(1~10000000)1721424(-4713~-1)3562427(1~10000)3652425(10000Äê)
	long long sum=0;
	for(int i=2001;i<=10000000;++i)
	{
		if(i%400==0||(i%4==0&&i%100!=0))
		{
			sum++;
		}
		sum=sum+365;
	}
	for(int i=1001;i<=2000;++i)
	{
		if(i<1582)
		{
			if(i%4==0)
			{
				sum++;
			}
		}
		if(i==1582)
		{
			sum=sum-10;
		}
		if(i>1582)
		{
			if(i%400==0||(i%4==0&&i%100!=0))
			{
				sum++;
			}
		}
		sum=sum+365;
	}
	for(int i=1;i<=4713;++i)
	{
		if((i-1)%4==0)
		{
			sum++;
		}
		sum=sum+365;
	}
	for(int i=30001;i<=40000;++i)
	{
		if(i%400==0||(i%4==0&&i%100!=0))
		{
			sum++;
		}
		sum=sum+365;
	}
	for(int i=1;i<=10000;++i)
	{
		if(i<1582)
		{
			if(i%4==0)
			{
				sum++;
			}
		}
		if(i==1582)
		{
			sum=sum-10;
		}
		if(i>1582)
		{
			if(i%400==0||(i%4==0&&i%100!=0))
			{
				sum++;
			}
		}
		sum=sum+365;
	}
	for(int i=1;i<=1000;++i)
	{
		if(i%4==0)
		{
			sum++;
		}
		sum=sum+365;
	}
	sum=3651694515+365237+365250;
	cout<<sum;
	return 0;
}*/     
