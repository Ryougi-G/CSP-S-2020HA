#include <bits/stdc++.h>
using namespace std;
int q,m=1,y,n;
int gcd(int x,int y)
{
	return y^=x^=y^=x%=y;
}
bool run1(int a)
{
	if(gcd(a,400)==0||(gcd(a,4)==0&&gcd(a,100)!=0))
		return true;
	return false;
}
bool run2(int a)
{
	if(gcd(a,4)==0)
		return true;
	return false;
}
void print()
{
	if(n==0)n=1;
	if(y<4713)
	{
		y=4713-y;
		n++;
		printf("%d %d %d BC\n",n,m,y);
		//cout<<n<<" "<<m<<" "<<y<<" "<<"BC"<<endl;
		return;
	}else
	{
		y-=4712;
		n++;
		printf("%d %d %d\n",n,m,y);
		//cout<<n<<" "<<m<<" "<<y<<endl;
		return;
	}
}
void work()
{
	m=1,y=0;
		while((n>=31&&(m==1||m==3|m==5||m==7||m==8||m==10||m==12))||(n>=30&&(m==4||m==6||m==9||m==11))||(m==2&&n>=28))
		{
			if(y<6293)
			{
				if(m==1||m==3|m==5||m==7||m==8||m==10||m==12)
				{
					n-=31;
					++m;
					if(m==13){m=1;++y;}
				}else if(m==2)
				{
					if(run2(y))
					{
						n-=29;++m;if(m==13){m=1;++y;}
					}else {
						n-=28;++m;if(m==13){m=1;m++;}
					}
				}else{
					n-=30;
					++m;
					if(m==13){m=1;++y;}
				}
			}else{
				if(m==1||m==3|m==5||m==7||m==8||m==10||m==12)
				{
					n-=31;
					++m;
					if(m==13){m=1;++y;}
				}else if(m==2)
				{
					if(run1(y))
					{
						n-=29;++m;if(m==13){m=1;++y;}
					}else {
						n-=28;++m;if(m==13){m=1;m++;}
					}
				}else{
					n-=30;
					++m;
					if(m==13){m=1;++y;}
				}
			}		
		}
	print();
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;++i)
	{
		scanf("%d",&n);
		if(n>2298518)n+=10;
		work();
	}
	return 0;
}
