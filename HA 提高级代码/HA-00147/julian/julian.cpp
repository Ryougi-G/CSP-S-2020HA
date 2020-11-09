#include<bits/stdc++.h>
using namespace std;
int q,a[100020],n,y,n1,y1,r,b[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++) cin>>a[i];
	for(int i=2;i<=12;i++) b[i]+=b[i-1];
	for(int i=1;i<=q;i++)
	{
	
		n=a[i]/365;
		y=a[i]%365;
		if(y>b[2])
		for(int j=4713;j>=4713-n;j-=4) y--;
		if(abs(y)>=365)
		if((y-1)/4==0) 
		{
			n+=y/366;
			y+=366*(y/366);
		}
		else
		{
			n+=y1/365;
			y-=365*(y/365);
		}
		for(int j=1;j<=12;j++)
		{
			if(y<=b[j])
			{
				r=y-b[j-1]+1;
				y=j;
				break;
			} 
		}
		if(n<4713-1582)
		{
			cout<<r<<" "<<y<<" "<<4713-n<<" BC"<<endl;
		}
		else
		{
			if(4713-n>0)
			{
				n-=4713-1582;
				for(int j=1582;j>=1582-n;j-=4) if((j-1)%4==0&&(j-1)%100!=0||(j-1)%400==0) y--;
				y+=11;
				if(y>=365) 
				if(((n+1)%4==0&&(n+1)%100!=4||(n+1)%400==0)&&y>365) 
				{
					n+=y/366;
					y+=366*(y/366);
				}
				else
				{
					n+=y/365;
					y-=365*(y/365);
				}
				for(int j=1;j<=12;j++)
				{
					if(y<=b[j])
					{
						r=y-b[j-1]+1;
						y=j;
						break;
					} 
				}
				cout<<r<<" "<<y<<" "<<4713-n<<" BC"<<endl;
			}
			else
			{
				n=(4713-1582)/365;
				y=(4713-1582)%365;
				if(y>b[2])
				for(int j=4713;j>=4713-1582;j-=4) y--;
				if(abs(y)>=365)
				if((y-1)/4==0) 
				{
					n+=y/366;
					y+=366*(y/366);
				}
				else
				{
					n+=y/365;
					y-=365*(y/365);
				}
				for(int j=1;j<=12;j++)
				{
					if(y<=b[j])
					{
						r=y-b[j-1]+1;
						y=j;
						break;
					} 
				}
				n1=1582/365;
				p=1582%365;
				for(int j=1582;j>=1;j-=4) if((j-1)%4==0&&(j-1)%100!=0||(j-1)%400==0) p--;
				p+=11;
				if(abs(p)>=365) 
				if(((n1+1)%4==0&&(n1+1)%100!=4||(n1+1)%400==0)&&p>365) 
				{
					n1+=p/366;
					p+=366*(p/366);
				}
				else
				{
					n1+=p/365;
					p-=365*(p/365);
				}
				for(int j=1;j<=12;j++)
				{
					if(p<=b[j])
					{
						r1=p-b[j-1]+1;
						p=j;
						break;
					} 
				}
				n2=(a[i]-4713)/365;
				y2=(a[i]-4713)%365;
				for(int j=n2*365;j>=1;j--) if(j%4==0&&j%100!=0||j%400==0) y2--;
				if(abs(y2)>=365) 
				if(((n2+1)%4==0&&(n2+1)%100!=4||(n2+1)%400==0)&&y2>365) 
				{
					n2+=y2/366;
					y2+=366*(y2/366);
				}
				else
				{
					n2+=y2/365;
					y2-=365*(y2/365);
				}
				for(int j=1;j<=12;j++)
				{
					if(y2<=b[j])
					{
						r2=y-b[j-1];
						y2=j;
						break;
					} 
				}
				n3=n+n1+n2;
				y3=y+p+y2;
				r3=r+r1+r2;
				for(int j=1;j<=12;j++)
				{ 
					if(r3<=b[j])
					{
						r3=r3-b[j-1];
						y3+=j;
						break;
					} 
				}
				if(y3>=12) 
				{
					n3+=y3/12;
					y3-=(y3/12)*12;
				}
				cout<<r3<<" "<<y3<<" "<<n3<<endl;
			}
		}
	}
	return 0;
}
