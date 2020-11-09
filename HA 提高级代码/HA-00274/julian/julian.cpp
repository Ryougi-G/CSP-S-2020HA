#include<bits/stdc++.h>
#define LL long long 
using namespace std;

int t;
LL k,da,mo,ye;
LL r;

inline int qr()
{
	int x=0,w=1;char a=0;
	while(a<'0'||a>'9'){if(w=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<3)+(x<<1)+(a^48);a=getchar();}
	return x*w;
}

inline LL qrl()
{
	LL x=0,w=1;char a=0;
	while(a<'0'||a>'9'){if(w=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<3)+(x<<1)+(a^48);a=getchar();}
	return x*w;
}

inline void work(int r)
{
	for(register int j=1;j<=r;j++)
	{
		da++;
		int ru=0;
		if(ye<0&&(ye+1)%4==0)
			ru=1;
		if(ye>0&&(ye)%4==0)
			ru=1;
		if(ye>1582&&ye%100==0)
			if(ye%400!=0)
				ru=0;
		if(mo==1||mo==3||mo==5||mo==7||mo==8||mo==10||mo==12)
		{
			if(da==32)
			{
				mo++;
				da=1;
				if(mo>12)
				{
					ye++;
					if(ye==0)
						ye++;
					mo=1;
				}
			}
			if(ye==1582&&mo==10&&da==5)
				da=15;
		}
		else
		{
			if(mo==4||mo==6||mo==9||mo==11)
			{
				if(da==31)
				{
					mo++;
					da=1;
				}
			}
			else
				if(mo==2)
				{
					if(ru)
					{
						if(da==30)
						{
							mo++;
							da=1;
						}
					}
					else
						if(da==29)
						{
							mo++;
							da=1;
						}
				}
		}	
	}
}

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	t=qr();
	for(register int ol=1;ol<=t;ol++)
	{
		r=qrl();
		if(r==0)
		{
			printf("1 1 4713 BC\n");
			continue;
		}
		da=1,mo=1;ye=-4713;
		if(r<2299160)
		{
			ye=ye+(r/1461)*4;
			r%=1461;
			if(r>=366)
			{
				ye++;
				r-=366;
				while(r>=365)
				{
					ye++;
					r-=365;
				}
				if(ye>=0)
					ye+=1;
				work(r);
				if(ye<0)
					printf("%lld %lld %lld BC\n",da,mo,-ye);
				else
					printf("%lld %lld %lld\n",da,mo,ye);
			}
			else
			{
				if(ye>=0)
					ye+=1;
				work(r);
				if(ye<0)
					printf("%lld %lld %lld BC\n",da,mo,-ye);
				else
					printf("%lld %lld %lld\n",da,mo,ye);
			}
			continue;
		}
		if(r==2299160)
		{
			printf("4 10 1582\n");
			continue;
		}
		if(r==2299161)
		{
			printf("15 10 1582\n");
			continue;
		}
		if(r>2299161)
		{
			r-=2299161;
			da=15;
			mo=10;
			ye=1582;
			ye=ye+(r/146097)*400;
			r%=146097;
			while(r>=366)
			{
				int ru=0;
				if((ye+1)%4==0)
					ru=1;
				if((ye+1)%100==0&&(ye+1)%400!=0)
					ru=0;
				ye++;
				ru==1?r-=366:r-=365;
			}
			work(r);
			printf("%lld %lld %lld\n",da,mo,ye);
		}
	}
	return 0;
}
//2299160
