#include<bits/stdc++.h>
using namespace std;
#define rint register int
const int maxn=100007;
int n;
long long r,y,m,d,t,fp=1721424,gp=577460;
long long pp=6575,rou=1461,qp=146097,ep;
int md[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int me[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int she[6]={365,366,365,365};
int sha[6]={366,365,365,365};
int hun[6]={36525,36524,36524,36524};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
/*	for(rint i=1;i<=1581;i++)
	for(rint j=1;j<=12;j++)
	{
		ep+=md[j];
		if(j==2)
		{
			if(i%4==0)
			ep=ep+1;
		}
	}
	cout<<ep;*/
	scanf("%d",&n);
	for(rint i=1;i<=n;i++)
	{
		scanf("%lld",&r);
		if(r<fp)
		{
			y=4713;
			m=1;
			d=1;
			t=r/rou;
			y=y-t*4;
			r=r-t*rou;
			while(r>she[y%4])
			{
				r-=she[y%4];
				y--;
			}
			for(rint j=1;j<=12;j++)
			{
				if(y%4==1)
				{
					if(r<me[j])
					break;
					r-=me[j];
					m=j+1;
				}
				else
				{
					if(r<md[j])
					break;
					r-=md[j];
					m=j+1;
				}
			}
			d=d+r;
			if(m>12)
			m=1,y--;
			printf("%lld %lld %lld BC\n",d,m,y);
		}
		else
		{
			r-=fp;
			y=1;
			m=1;
			d=1;
			if(r<gp)
			{
				t=r/rou;
				y=y+t*4;
				r=r-t*rou;
				while(r>sha[y%4])
				{
					r-=sha[y%4];
					y++;
				}
				for(rint j=1;j<=12;j++)
				{
					if(y%4==0)
					{
						if(r<me[j])
						break;
						r-=me[j];
						m=j+1;
					}
					else
					{
						if(r<md[j])
						break;
						r-=md[j];
						m=j+1;
					}
				}
				d=d+r;
				if(m>12)
				m=1,y++;
				printf("%lld %lld %lld\n",d,m,y);
			}
			else
			{
				r-=gp;
				y=1582;
				m=1;
				d=1;
				for(rint j=1;j<=9;j++)
				{
					if(y%4==0)
					{
						if(r<me[j])
						break;
						r-=me[j];
						m=j+1;
					}
					else
					{
						if(r<md[j])
						break;
						r-=md[j];
						m=j+1;
					}
				}
				if(r<4)
				{
					d=d+r;
					printf("%lld %lld %lld\n",d,m,y);
				}
				else
				{
					r=r-4;
					d=15;
					if(r<17)
					{
						d=d+r;
						printf("%lld %lld %lld\n",d,m,y);
					}
					else
					{
						r=r-17;
						d=1;
						m=11;
						for(rint j=11;j<=12;j++)
						{
							if(y%4==0)
							{
								if(r<me[j])
								break;
								r-=me[j];
								m=j+1;
							}
							else
							{
								if(r<md[j])
								break;
								r-=md[j];
								m=j+1;
							}
						}
						if(m>12)
						{
							m=1;
							y++;
						}
						if(m>10)
						{
							d=d+r;
							printf("%lld %lld %lld\n",d,m,y);
						}
						else
						{
							t=r/qp;
							y=y+400*t;
							r=r-t*qp;
							while(r>36524)
							{
							if(r>36525)
							{
								r-=36525;
								y+=100;
							}
							else
							break;
							if(r>36524)
							{
								r-=36524;
								y+=100;
							}
							else
							break;
							if(r>36524)
							{
								r-=36524;
								y+=100;
							}
							else
							break;
							if(r>36524)
							{
								r-=36524;
								y+=100;
							}
							else
							break;
							}
							while(r>365)
							{
								if((y%400==0)||(y%4==0&&y%100!=0))
								r-=366;
								else
								r-=365;
								y++;
							}
				for(rint j=1;j<=12;j++)
				{
					if((y%400==0)||(y%4==0&&y%100!=0))
					{
						if(r<me[j])
						break;
						r-=me[j];
						m=j+1;
					}
					else
					{
						if(r<md[j])
						break;
						r-=md[j];
						m=j+1;
					}
				}
				d=d+r;
				if(m>12)
				m=1,y++;
				printf("%lld %lld %lld\n",d,m,y);
/*							if(r<pp)
							{
								t=r/rou;
								y=y+t*4;
								r=r-t*rou;
								while(r>sha[y%4])
								{
									r-=sha[y%4];
									y++;
								}
								for(rint j=1;j<=12;j++)
								{
				if(y%4==0)
				{
				if(r<me[j])
				break;
				r-=me[j];
				m=j+1;
				}
				else
				{
				if(r<md[j])
				break;
				r-=md[j];
				m=j+1;
				}
								}
								d=d+r;
								if(m>12)
								m=1,y++;
								printf("%lld %lld %lld\n",d,m,y);
							}
							else
							{
								r-=pp;
								r+=367;
								y=1600;
								m=1;
								d=1;
								t=r/qp;
								y=y+400*t;
								r=r-t*qp;
								while(r>hun[y/100%4])
								{
									r-=hun[y/100%4];
									y=y+100;
								}
								while(r>sha[y%4])
								{
									r-=sha[y%4];
									y++;
								}
								for(rint j=1;j<=12;j++)
								{
				if(y%4==0)
				{
				if(r<me[j])
				break;
				r-=me[j];
				m=j+1;
				}
				else
				{
				if(r<md[j])
				break;
				r-=md[j];
				m=j+1;
				}
								}
								d=d+r;
								if(m>12)
								m=1,y++;
								printf("%lld %lld %lld\n",d,m,y);
							}*/
						}
					}
				}
			}
		}
	}
	return 0;
}
