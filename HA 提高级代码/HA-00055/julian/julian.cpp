#include <bits/stdc++.h>
using namespace std;
int dayr[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int dayp[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int ljr[]={0,31,60,91,121,152,182,213,244,274,305,335,366};
int ljp[]={0,31,59,90,120,151,181,212,243,273,304,334,365};
bool pd1(int x)
{
	if(x%4==0)
	{
		if(x%100==0)
		{
			if(x%400==0) return true;
			else return false;
		}
		else return true;
	}
	else return false;
}
bool pd2(int x)
{
	if(x%4==0) return true;
	else return false;
}
int q;
int r;
int rl=2299161;
int nf[10000000];
long long ljh[10000000];
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	nf[0]=ljh[0]=0;
	for(int i=1;i<=10000000;i++)
	{
		if(i<=4712)
		{
			if(pd2(4712-i)) nf[i]=366;
			else nf[i]=365; 
		}
		else if(i>4712&&i<=6294)
		{
			if(pd2(i-4712)) nf[i]=366;
			else nf[i]=365;
		}
		else if(i>6294)
		{
			if(pd1(i-4712)) nf[i]=366;
			else nf[i]=365;
		}
		nf[6294]=355;
		ljh[i]=ljh[i-1]+nf[i];
	}
	cin>>q;
	int nian,yue,ri,qh;
	while(q--)
	{
		ljh[0]=0;
		int rp;
		cin>>r;
		int tot=upper_bound(ljh+1,ljh+10000000,r)-ljh;
		tot--;
		if(tot<=4712) 
		{
			nian=4713-tot;
			qh=0;
		}
		else
		{
			nian=tot-4712;
			qh=1;
		}
		int r1=r-ljh[tot];
		
		if(tot<=6294)
		{
			if(pd2(tot)) rp=0;
			else rp=1;
		}
		else
		{
			if(pd1(tot)) rp=0;
			else rp=1;
		}
		if(rp==0) 
		{
			yue=upper_bound(ljr+1,ljr+13,r1)-ljr;
			ri=r1-ljr[yue-1]+1;
		}
		else 
		{
			yue=upper_bound(ljp+1,ljp+13,r1)-ljp;
			ri=r1-ljp[yue-1];
		}
		cout<<ri<<' '<<yue<<' '<<nian;
		if(qh==0) cout<<' '<<"BC";
		cout<<endl;
	}
	return 0;
}
