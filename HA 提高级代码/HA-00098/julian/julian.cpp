#include<bits/stdc++.h>
using namespace std;
int r,a,o,c,q;
int mt[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void find(int x)
{
	int mon=1;
	while(x)
	{
		if(x-mt[mon]<0) break;
		x-=mt[mon];
		mon++;
	}
	cout<<1+x<<" "<<mon<<" ";
}
int main()
{
//	freopen("julian.in","r",stdin);
//	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		//x=y=z=a=o=0;
		scanf("%d",&r);
		if(r<=2298795) 
		{
			a=r/365;c=a;
			o=r-365*a;//cout<<a<<" "<<o<<endl;
			if(c>=1||o>58) o--;
			if(c>=4) c/=4,o-=c;
			while(o<0) 
			{
				a--,o+=365;
				if(a%4==0) o++;
			}
			find(o);
			if(a-4713<0) cout<<4713-a<<" "<<"BC"<<endl;
			else cout<<a-4713+1<<endl;
		}
		else {
			r-=2298795;
			if(r<=16) 
			cout<<15+r<<" "<<10<<" "<<1582<<endl;
			else if(16<r&&r<=46) 
			cout<<r-16<<" "<<11<<" "<<1582<<endl;
			else if(46<r&&r<=77)
			cout<<r-46<<' '<<12<<' '<<1582<<endl;
			else 
			{
				r-=77;
				a=r/365;o=r-365*a;
				int x=a/4;
				int y=a/100;
				int z=a/400;
				o=o-x+y-z;
				while(o<0)
				{
					a--;o+=365;
			//		if((a%4==0&&a%100!=0)||(a%400==0)) 
					if(((a+1581)%4==0&&(a+1581)%100!=0)||(a+1581)%400==0) o++;
				}
				if(((a+1582)%4==0&&(a+1581)%100!=0)||(a+1581)%400==0) o++;
				find(o);
				cout<<a+1582<<endl;
			}
		}
	}
	return 0;
}
