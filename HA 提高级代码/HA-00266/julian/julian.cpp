#include<bits/stdc++.h>
using namespace std;
int n,r=1;
int yue1[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int yue2[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
struct node
{
	int nian;
	int i;
	int n,y,d;
	bool f;
}a[1000086];
bool cmp(node x,node y)
{
	return x.nian<y.nian;
}
bool cmp1(node x,node y)
{
	return x.i<y.i;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].nian;
		a[i].i=i;
	}
	sort(a+1,a+1+n,cmp);
	int nian=4712,yue=1,ri=1,f=0,f2=0;
	for(int i=1;i<=a[n].nian;i++)
	{
		if(nian==0)
		{
			f=1;
			nian=0;
		}
		if(f==1)
		{
			if(f2==1)
			{
				if(nian%400==0||(nian%4==0&&nian%100!=0))
				{
					if(yue2[yue]==ri)
					{
						ri=1;
						if(yue==12)
						{
							nian++;
							yue=1;
						}
						else yue++;	
					}
					else ri++;
				}
				else
				{
					if(yue1[yue]==ri)
					{
						ri=1;
						if(yue==12)
						{
							nian++;
							yue=1;
						}
						else yue++;	
					}
					else ri++;
				}
				if(i==a[r].nian)
				{
					a[r].d=ri;
					a[r].y=yue;
					a[r].n=nian+1;
					a[r].f=1;
					r++;
				}
			}
			else
			{
				if(nian%4!=0&&f2==0)
				{
					if(yue1[yue]==ri)
					{
						ri=1;
						if(yue==12)
						{
							nian++;
							yue=1;
						}
						else yue++;	
					}
					else ri++;
					if(nian==1582&&yue==10&&ri==5)
					{
						ri=15;
						f2=1;
					}
				}
				else if(nian%4==0&&f2==0)
				{
					if(yue2[yue]==ri)
					{
						ri=1;
						if(yue==12)
						{
							nian++;
							yue=1;
						}
						else yue++;	
					}
					else ri++;
				}
				if(i==a[r].nian)
				{
					a[r].d=ri;
					a[r].y=yue;
					a[r].n=nian+1;
					a[r].f=1;
					r++;
				}
			}
		}
		else if(f!=1)
		{
			if(nian%4!=0)
			{
				if(yue1[yue]==ri)
				{
					ri=1;
					if(yue==12)
					{
						nian--;
						yue=1;
					}
					else yue++;	
				}
				else ri++;
			}
			else
			{
				if(yue2[yue]==ri)
				{
					ri=1;
					if(yue==12)
					{
						nian--;
						yue=1;
					}
					else yue++;	
				}
				else ri++;
			}
			if(i==a[r].nian)
			{
				a[r].d=ri;
				a[r].y=yue;
				a[r].n=nian+1;
				r++;
			}
		}
	}
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=n;i++)
	{
		if(a[i].f==0)
		printf("%d %d %d BC\n",a[i].d,a[i].y,a[i].n);
		else printf("%d %d %d\n",a[i].d,a[i].y,a[i].n-1);
	}
	return 0;
}
