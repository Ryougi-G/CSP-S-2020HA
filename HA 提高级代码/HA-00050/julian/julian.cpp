#include<bits/stdc++.h>
using namespace std;
int q,bb=1,kk=0;
int r;
int m=0,y=0,d=0,h=0;
void yyy()
{
	int x;
	if(kk<366)
	{
		bb=1;
		x=0;
	}
	if(kk>365&&kk<732)
	{
		bb=0;
		x=2;
		kk=kk-365;
	}
	if(kk>731)
	{
		bb=1;
		x=(kk-731)/365+2;
		kk=kk-731-(x-2)*365;
	}
	h=x;
}
void yy()
{
	int x;
	if(kk<367)
	{
		x=0;
		bb=0;
	}
	if(kk>366)
	{
		bb=1;
		x=(kk-366)/365+1;
		kk=(kk-366)-365*(x-1);
		if(kk==0)
		kk=365;
	}
	h=x;
}
void mm()
{
	int x;
	if(bb==0)
	{
		if(kk<32)
		{x=1;}
		if(kk>31&&kk<61)
		{x=2;kk=kk-31;}
		if(kk>60&&kk<92)
		{x=3;kk=kk-60;}
		if(kk>91&&kk<122)
		{x=4;kk=kk-91;}
		if(kk>121&&kk<153)
		{x=5;kk=kk-121;}
		if(kk>152&&kk<183)
		{x=6;kk=kk-152;}
		if(kk>182&&kk<214)
		{x=7;kk=kk-182;}
		if(kk>213&&kk<245)
		{x=8;kk=kk-213;}
		if(kk>244&&kk<275)
		{x=9;kk=kk-244;}
		if(kk>274&&kk<306)
		{x=10;kk=kk-274;}
		if(kk>305&&kk<336)
		{x=11;kk=kk-305;}
		if(kk>335)
		{x=12;kk=kk-335;}
	}
	if(bb==1)
	{
		if(kk<32)
		x=1;
		if(kk>31&&kk<60)
		{x=22;kk=kk-31;}
		if(kk>59&&kk<91)
		{x=3;kk=kk-59;}
		if(kk>90&&kk<121)
		{x=4;kk=kk-90;}
		if(kk>120&&kk<152)
		{x=5;kk=kk-120;}
		if(kk>151&&kk<182)
		{x=6;kk=kk-151;}
		if(kk>181&&kk<213)
		{x=7;kk=kk-181;}
		if(kk>212&&kk<244)
		{x=8;kk=kk-212;}
		if(kk>243&&kk<274)
		{x=9;kk=kk-243;}
		if(kk>273&&kk<305)
		{x=10;kk=kk-273;}
		if(kk>304&&kk<335)
		{x=11;kk=kk-304;}
		if(kk>334)
		{x=12;kk=kk-334;}
	}
	m=x;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	while(q--)
	{
		m=0;y=0;d=0;h=0;
		cin>>r;
		if(r<1721424)
		{
			if(r/1461==0)
			{
				kk=r+1;
				yy();
				y=4713-h;
				mm();
				d=kk;
				cout<<d<<' '<<m<<' '<<y<<' '<<"BC"<<endl;
			}
			else
			{
				int aa=0;
				aa=r/1461;
				kk=r-aa*1461+1;
				yy();
				y=4713-aa*4-h;
				mm();
				d=kk;
				cout<<d<<' '<<m<<' '<<y<<' '<<"BC"<<endl;
			}
		}
		else if(r>1721423&&r<2299161)
		{
			int aa=0;
				aa=r/1461;
				kk=r-aa*1461+1;
				yy();
				y=aa*4+1+h-4713;
				mm();
				d=kk;
				cout<<d<<' '<<m<<' '<<y<<endl;
		}
		else if(r>2299238)
		{
			int aa=0,cc=0;
				cc=r-2299238;
				aa=cc/1461;
				kk=cc-aa*1461;
				yy();
				y=aa*4+h+1582+1;
				mm();
				d=kk;
				cout<<d<<' '<<m<<' '<<y<<endl;
		}
	}
	return 0;
}
