#include<bits/stdc++.h>
#define rint register int
using namespace std;
long long n,a,b,c,d,m,s,k,e,f;
long long nian,yue,ri;
long long p[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
long long r[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
void pyr(int u)
{
	int j=1;yue=1;ri=1;
	while(u>=p[j]&&j<12)
	{
		yue++;u=u-p[j];
		j++;
	}
	ri=ri+u;
}
void ryr(int u)
{
	int j=1;yue=1;ri=1;
	while(u>=r[j]&&j<12)
	{
		yue++;u=u-r[j];
		j++;
	}
	ri=ri+u;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	b=365*3+366;c=366*(25*4-3)+365*(400-25*4+3);
	d=(1580/4)*b+365+p[1]+p[2]+p[3]+p[4]+p[5]+p[6]+p[7]+p[8]+p[9]+3;
	e=17+p[11]+p[12];f=366*(25-1)+355*(100-25+1);
//	cout<<c<<" ";
	for(rint i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		nian=4713;yue=1;ri=1;
		if(k>(4713-1)/4*b+365)
		{
			nian=1;
			k=k-(4713-1)/4*b-366;
			if(k>d)
			{
				nian=1582,ri=15,yue=10;
				k=k-d-1;
				if(k>=e)
				{
					k=k-e;
					nian=1583,ri=1,yue=1;
					if(k>=365) 
					{
						nian++;k=k-365;
						if(k>=366)
						{
							nian++;k=k-366;
							if(k>=4*b)
							{
							k=k-4*b;nian=1601;
							nian=nian+(k/c)*400;
							k=k%c;
							cout<<k<<" ";
							nian=nian+(k/f)*100;
							k=k%f;
							//cout<<nian<<" ";
							nian=nian+(k/b)*4;
							k=k%b;
							//cout<<nian<<" ";
							nian=nian+(k/365);
							if(k>=365*3)
							nian=nian+3,k=k%365,ryr(k);
							else 
							nian=nian+(k/365),k=k%365,pyr(k);
							}
							else
							{
							nian=nian+(k/b)*4;
							k=k%b;
							//cout<<nian<<" ";
							nian=nian+(k/365);
							if(k>=365*3)
							nian=nian+3,k=k%365,ryr(k);
							else 
							nian=nian+(k/365),k=k%365,pyr(k);
							}
						}
						else ryr(k);
					}
					else pyr(k);
				}
				else
				{
					k=d-3+14+k;
					pyr(k);
				}
			}
			else
			{
				nian=nian+(k/b)*4;
				k=k%b;
				//nian=nian+(k/365);
				if(k>=365*3)
				nian=nian+3,k=k%365,ryr(k);
				else
				nian=nian+(k/365),k=k%365,pyr(k);
			}
			cout<<ri<<" "<<yue<<" "<<nian<<endl;
		}
		else
		{
			c=k/b;nian=nian-c*4;k=k-c*b;
			if(k<366)
			{
				ryr(k);
			}
			else
			{
				nian--;
				k=k-366;
				while(k>=365)
				{
					nian--;k=k-365;
				}
				pyr(k);
			}
			cout<<ri<<" "<<yue<<" "<<nian<<" BC"<<endl;
		}	
	}
	return 0;
}
