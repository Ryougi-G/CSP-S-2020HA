#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll q,r,nian,yue,ri,bc;
int yu[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
inline ll mod(int x,int y)
{
	while(x-y>0)
	x-=y;
	return x;
}
inline void yue1(int da)
{
	if(da<=31) yue=1,ri=da;
	else if(da<=60) yue=2,ri=da-31;
	else if(da<=91) yue=3,ri=da-60;
	else if(da<=121) yue=4,ri=da-91;
	else if(da<=152) yue=5,ri=da-121;
	else if(da<=182) yue=6,ri=da-152;
	else if(da<=213) yue=7,ri=da-182;
	else if(da<=244) yue=8,ri=da-213;
	else if(da<=274) yue=9,ri=da-244;
	else if(da<=305) yue=10,ri=da-274;
	else if(da<=335) yue=11,ri=da-305;
	else if(da<=366) yue=12,ri=da-335;
}
inline void yue2(int da)
{
	if(da<=31) yue=1,ri=da;
	else if(da<=59) yue=2,ri=da-31;
	else if(da<=90) yue=3,ri=da-59;
	else if(da<=120) yue=4,ri=da-90;
	else if(da<=151) yue=5,ri=da-120;
	else if(da<=181) yue=6,ri=da-151;
	else if(da<=212) yue=7,ri=da-181;
	else if(da<=243) yue=8,ri=da-212;
	else if(da<=273) yue=9,ri=da-243;
	else if(da<=304) yue=10,ri=da-273;
	else if(da<=334) yue=11,ri=da-304;
	else if(da<=365) yue=12,ri=da-334;
}
inline void dis(int k)
{
	if(ri>k){ri-=k;}
	else
	{
		for(int i=1;i<=k;i++)
		{
			ri--;
			if(!ri)
			{
				if(yue!=3)
				yue--,ri=yu[yue];
				else
				{
					if(nian%100==0&&nian%8==0)
					{ri=29;continue;}
					if(nian%100!=0&&nian%4==0)
					{ri=29;continue;}
					ri=28;
				}
			}
		}
	}
}
inline void print()
{
	if(nian>=1700&&!bc)
	{
		int k=nian-1700;
		if(!nian%100)
		if(yue>2){dis(k+1);print();return;}
		dis(floor(k/100));
	}
	cout<<ri<<" "<<yue<<" "<<nian;
	if(bc)
	cout<<" BC";
	cout<<endl;
}
inline void work()
{
	ll r=read();
	ll da=(mod(r,1461))+1,ye=floor(r/1461);
	if(ye<1178)
	{
		bc=1;
		if(da<366)
		{
			nian=4713-4*ye;
			yue1(da);
			print();
			return;
		}
		nian=4713-4*ye-floor((da-1)/365);
		da=mod(da-1,365);
		yue2(da);
		print();
		return;
	}
	else 
	{
		r-=1721424;
		ll da=mod(r,1461)+1,ye=floor(r/1461);
		if(ye<=395)
		{
			if(da<=1095)
			{
				nian=ye*4+1+floor((da-1)/365);
				da=mod(da,365);
				yue2(da);
				print();
				return;
			}
			else
			{
				nian=ye*4+3;
				da-=1094;
				yue1(da);
				print();
				return;
			}
		}
		if(ye==396)
		{
			if(da<=652)
			{
				nian=ye*4+1+floor((da-1)/365);
				da=mod(da,365);
				yue2(da);
				print();
				return;
			}
			da+=10;
			if(da<=1095)
			{
				nian=ye*4+1+floor((da-1)/365);
				da=mod(da,365);
				yue2(da);
				print();
				return;
			}
			else
			{
				nian=ye*4+3;
				da-=1094;
				yue1(da);
				print();
				return;
			}
		}
		if(ye>396)
		{
			if(da<=1095)
			{
				nian=ye*4+1+floor((da-1)/365);
				da=mod(da,365);
				yue2(da);
				print();
				return;
			}
			else
			{
				nian=ye*4+3;
				da-=1094;
				yue1(da);
				print();
				return;
			}
		}
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q=read();
	for(register int i=1;i<=q;i++)
	work();
	return 0;
}
