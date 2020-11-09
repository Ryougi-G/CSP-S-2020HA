#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int q;
int r[100010],yy,mm,dd;
struct node
{
	int y;
	int m;
	int d;
}ans[100010];
int lread()
{
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}

void jl(int a)
{
	while(a!=0)
	{
			while(yy%4==1&&a!=0)
		{
			while(mm==1&&a!=0)
			{
				while(dd<31&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==31) ++mm;
			}
			while(mm==2&&a!=0)
			{
				while(dd<29&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==29) ++mm;
			}
			while(mm==3&&a!=0)
			{
				while(dd<31&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==31) ++mm;
			}
			while(mm==4&&a!=0)
			{
				while(dd<30&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==30) ++mm;
			}
			while(mm==5&&a!=0)
			{
				while(dd<31&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==31) ++mm;
			}
			while(mm==6&&a!=0)
			{
					while(dd<30&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==30) ++mm;
			}
			while(mm==7&&a!=0)
			{
				while(dd<31&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==31) ++mm;
			}
			while(mm==8&&a!=0)
			{
				while(dd<31&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==31) ++mm;
			}
			while(mm==9&&a!=0)
			{
					while(dd<30&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==30) ++mm;
			}
			while(mm==10&&a!=0)
			{
				while(dd<31&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==31) ++mm;
			}
			while(mm==11&&a!=0)
			{
					while(dd<30&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==30) ++mm;
			}
			while(mm==12&&a!=0)
			{
				while(dd<31&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==31) ++yy;
			}
		}
		while(yy%4!=1&&a!=0)
		{
			while(mm==1&&a!=0)
			{
				while(dd<31&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==31) ++mm;
			}
			while(mm==2&&a!=0)
			{
				while(dd<28&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==28) ++mm;
			}
			while(mm==3&&a!=0)
			{
				while(dd<31&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==31) ++mm;
			}
			while(mm==4&&a!=0)
			{
				while(dd<30&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==30) ++mm;
			}
			while(mm==5&&a!=0)
			{
				while(dd<31&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==31) ++mm;
			}
			while(mm==6&&a!=0)
			{
					while(dd<30&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==30) ++mm;
			}
			while(mm==7&&a!=0)
			{
				while(dd<31&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==31) ++mm;
			}
			while(mm==8&&a!=0)
			{
				while(dd<31&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==31) ++mm;
			}
			while(mm==9&&a!=0)
			{
					while(dd<30&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==30) ++mm;
			}
			while(mm==10&&a!=0)
			{
				while(dd<31&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==31) ++mm;
			}
			while(mm==11&&a!=0)
			{
					while(dd<30&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==30) ++mm;
			}
			while(mm==12&&a!=0)
			{
				while(dd<31&&a!=0)
				{
					--a;
					++dd;
				}
				if(dd==31) ++yy;
			}
		}
	}
	
	return;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	
	q=lread();
	for(int i=1;i<=q;++i)
	{
		r[i]=lread();
		yy=-4713;
		mm=1;
		dd=1;
		jl(r[i]);
		ans[i].y=yy;
		ans[i].m=mm;
		ans[i].d=dd;
	}
	for(int i=1;i<=q;++i)
	{
		int k=abs(ans[i].y);
		printf("%d %d %d BC\n",ans[i].d,ans[i].m,k);
	}
	
	
	fclose(stdin);fclose(stdout);
	return 0;
}
