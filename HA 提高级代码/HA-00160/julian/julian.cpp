#include<bits/stdc++.h>
using namespace std;
const int N=203312;
int T;
long long n,mi;
int mo[135]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int run[153]={0,31,29,31,30,31,30,31,31,30,31,30,31};
inline long long read()
{
	long long num=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {num=(num<<1)+(num<<3)+ch-'0'; ch=getchar();}
	return num*f;
}
long long st=0,th=0,la=0,xun=0,Bit=0;
long long bf[N],mid[N],en[N],ad[N];
inline int check(int i)
{
	if((i%4==0&&i%100!=0)||i%400==0) return 1;
	return 0;
}
inline void prepare()
{
	bf[4714]=-1;
	for(int i=4713;i>=1;--i)
	{
		if((i-1)%4==0) st+=366,bf[i]=bf[i+1]+366;
		else st+=365,bf[i]=bf[i+1]+365;
	}
	st--;//公元前总天数 
	// 1-1582
	for(int i=1;i<=1581;i++) i%4==0?th+=366:th+=365;
	th+=31+28+31+30+31+30+31+31+30+4;//1582.10.4
	for(int i=1;i<=4;i++) 
	{
		i%4==0?mi+=366:mi+=365;
		mid[i]=mi;
	}
	Bit+=17+30+31;//1582.12.31 now 
	for(int i=1583;i<=1600;i++)
	{
		if(check(i)) la+=366,en[i]=en[i-1]+366;
		else la+=365,en[i]=en[i-1]+365;
	}
	for(int i=1;i<=400;i++)
	{
		if(check(i)) xun+=366,ad[i]=ad[i-1]+366;
		else xun+=365,ad[i]=ad[i-1]+365;
	}
}
inline int find_bf(long long x)
{
	int r=4714,l=1,ans=0;
	while(l<=r)
	{
		int tt=(l+r)>>1;
		if(bf[tt]<=x) {ans=tt; r=tt-1;}
		else l=tt+1;
	}
	return ans;
}
inline int find_la(long long x)
{
	int l=1582,r=1600,ans=0;
	while(l<=r)
	{
		int tt=(l+r)>>1;
		if(en[tt]<=x) {ans=tt; l=tt+1;}
		else r=tt-1;
	}
	return ans;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	T=read();
	prepare();
	while(T--)
	{
		n=read(); 
		if(n<=st)// - 
		{
			int nian=find_bf(n),mou=0,dd=0; 
			if(n==bf[nian]) {printf("31 12 %d BC\n",nian); continue;}
			else
			{
				n-=bf[nian]; nian--;
				if((nian-1)%4==0) 
				{
					for(int i=1;i<=12;i++)
					{
						dd+=run[i];
						if(dd>=n) {mou=i; break;}
					}
					
					dd-=run[mou];
					n-=dd;
					cout<<n<<" "<<mou<<" "<<nian<<" BC"; puts("");
//					printf("%d %d %d BC\n",n,mou,nian);
					continue;
				}
				else
				{
					for(int i=1;i<=12;i++)
					{
						dd+=mo[i];
						if(dd>=n) {mou=i; break;}
					}
					dd-=mo[mou];
					n-=dd;
					cout<<n<<" "<<mou<<" "<<nian<<" BC"; puts("");
//					printf("%d %d %d BC\n",n,mou,nian);
					continue;
				}
			}
		}
		else
		{
			n-=st;
			if(n<=th) //<= 1582.10.4
			{
				int nian=4*((int)n/mi),mou=0,dd=0;// check!!!!!!
				if(nian*mi==4*n) 
				{
					printf("31 12 %d\n",nian);
					continue;
				}
				else
				{
					n-=(nian/4)*mi; 
					int t=0;
					while(n>=mid[t]) t++;
					nian+=t; n-=mid[t-1];
					if(nian%4==0) 
					{
						for(int i=1;i<=12;i++)
						{
							dd+=run[i];
							if(dd>=n) {mou=i; break;}
						}
						dd-=run[mou];
						n-=dd;
						cout<<n<<" "<<mou<<" "<<nian; 
//						printf("%d %d %d\n",n,mou,nian);
						continue;
					}
					else
					{
						for(int i=1;i<=12;i++)
						{
							dd+=mo[i];
							if(dd>=n) {mou=i; break;}
						}
						dd-=mo[mou];
						n-=dd;
						cout<<n<<" "<<mou<<" "<<nian; puts("");
//						printf("%d %d %d\n",n,mou,nian);
						continue;
					}
				}
			}
			n-=th;
			if(n<=Bit)
			{
				if(n<=17)
				{
					printf("%d 10 1582\n",14+n);
					continue;
				}
				n-=17;
				if(n<=30)
				{
					printf("%d 11 1582\n",n);
					continue;
				}
				n-=30;
				if(n<=31)
				{
					printf("%d 12 1582\n",n);
					continue;
				}
			}
			n-=Bit;
			if(n<=la)//1583.1.1-1600.12.31
			{
				int nian=find_la(n),mou=0,dd=0;
				n-=en[nian];
				if(!n)//data: 365
				{
					printf("31 12 %d\n",nian);
					continue;
				}
				else
				{
					nian++;
					if(check(nian)) 
					{
						for(int i=1;i<=12;i++)
						{
							dd+=run[i];
							if(dd>=n) {mou=i; break;}
						}
						dd-=run[mou];
						n-=dd;
						cout<<n<<" "<<mou<<" "<<nian; puts("");
						continue;
					}
					else
					{
						for(int i=1;i<=12;i++)
						{
							dd+=mo[i];
							if(dd>=n) {mou=i; break;}
						}
						dd-=mo[mou];
						n-=dd;
						cout<<n<<" "<<mou<<" "<<nian; puts("");
						continue;
					}
				}
			}
			n-=la;
			int nian=400*((int)n/xun),mou=0,dd=0;
			if(nian*xun==400*n) 
			{
				nian+=1600;
				printf("31 12 %d\n",nian);
				continue;
			}
			else
			{
				n-=(nian/400)*xun; 
				int t=0;
				while(n>=ad[t]) t++;
				nian+=t; n-=ad[t-1]; nian+=1600;
				if(check(nian)) 
				{
					for(int i=1;i<=12;i++)
					{
						dd+=run[i];
						if(dd>=n) {mou=i; break;}
					}
					dd-=run[mou];
					n-=dd;
					cout<<n<<" "<<mou<<" "<<nian; puts("");
			//		printf("%d %d %d\n",n,mou,nian);
					continue;
				}
				else
				{
					for(int i=1;i<=12;i++)
					{
						dd+=mo[i];
						if(dd>=n) {mou=i; break;}
					}
					dd-=mo[mou];
					n-=dd;
					cout<<n<<" "<<mou<<" "<<nian; puts("");
			//		printf("%d %d %d\n",n,mou,nian);
					continue;
				}
			}
		}		
	}
	return 0;
}
