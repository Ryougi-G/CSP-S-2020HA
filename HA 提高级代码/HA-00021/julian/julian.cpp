#include<bits/stdc++.h>
using namespace std;
int n,q,ye,mo,da,bj,g,r,zf,u;
int pan(int x)
{
	if(x%100==0)
	{
		if(x%400==0) return 1;
		else return 0;
	}
	else
	{
		if(x%4==0) return 1;
		else return 0;
	}
}
void tp()
{
	if(q>0&&q<=30) da+=q;
    if(q>30&&q<=58) mo=2,da+=(q-31);
	if(q>58&&q<=89) mo=3,da+=(q-59);
	if(q>89&&q<=119) mo=4,da+=(q-90);
	if(q>119&&q<=150) mo=5,da+=(q-120);
	if(q>150&&q<=180) mo=6,da+=(q-151);
	if(q>180&&q<=211) mo=7,da+=(q-181);
	if(q>211&&q<=242) mo=8,da+=(q-212);
	if(q>242&&q<=272) mo=9,da+=(q-243);
	if(q>272&&q<=293) 
	{
	mo=10;
	da+=(q-273);
	if(q-272>=5) da+=10;
	}
	if(q>293&&q<=323) mo=11,da+=(q-294);
	if(q>323&&q<=354) mo=12,da+=(q-324);	
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		ye=-4713,mo=1,da=1,bj=-1,zf=-1;
		g=366,r=1;
		scanf("%d",&q);
		while(q)
		{
			if(q>=g) 
			{
			q-=g,ye++;
			if(ye==0)
			{
			ye=1,zf=1,g=365,r=0;
			continue;
			}
			if(ye==1582)
			{
			g=355,r=0,bj=1;
			continue;
			} 
			if(bj==-1) {
			u=ye;
			if(zf==-1) u=-1*ye-1;
			if(u%4==0) r=1,g=366;else r=0,g=365;
			}
		    else {if(pan(ye)) r=1,g=366;else r=0,g=365;}
			}
			else
			{
			if(ye==1582) 
			{
			tp();
			q=0;
			continue;
			}
			if(r)
			{
			if(q>0&&q<=30) da+=q;
			if(q>30&&q<=59) mo=2,da+=(q-31);
			if(q>59&&q<=90) mo=3,da+=(q-60);
			if(q>90&&q<=120) mo=4,da+=(q-91);
			if(q>120&&q<=151) mo=5,da+=(q-121);
			if(q>151&&q<=181) mo=6,da+=(q-152);
			if(q>181&&q<=212) mo=7,da+=(q-182);
			if(q>212&&q<=243) mo=8,da+=(q-213);
			if(q>243&&q<=273) mo=9,da+=(q-244);
			if(q>273&&q<=304) mo=10,da+=(q-274);
			if(q>304&&q<=334) mo=11,da+=(q-305);
			if(q>334&&q<=365) mo=12,da+=(q-335);
			}
			else
			{
			if(q>0&&q<=30) da+=q;
			if(q>30&&q<=58) mo=2,da+=(q-31);
			if(q>58&&q<=89) mo=3,da+=(q-59);
			if(q>89&&q<=119) mo=4,da+=(q-90);
			if(q>119&&q<=150) mo=5,da+=(q-120);
			if(q>150&&q<=180) mo=6,da+=(q-151);
			if(q>180&&q<=211) mo=7,da+=(q-181);
			if(q>211&&q<=242) mo=8,da+=(q-212);
			if(q>242&&q<=272) mo=9,da+=(q-243);
			if(q>272&&q<=303) mo=10,da+=(q-273);
			if(q>303&&q<=333) mo=11,da+=(q-304);
			if(q>333&&q<=364) mo=12,da+=(q-334);	
			}
			q=0;
			}
		}
		if(zf==-1) printf("%d %d %d BC\n",da,mo,-1*ye);
		else printf("%d %d %d\n",da,mo,ye);
	}
	return 0;
}
