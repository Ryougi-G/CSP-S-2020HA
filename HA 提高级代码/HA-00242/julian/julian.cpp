#include<bits/stdc++.h>
using namespace std;
#define inf 100009
int q,rq[inf],mont,yer,daay;
int tp(int x)
{
	if(mont==1)
	return 31;
	if(mont==2)
	return 28;
	if(mont==3)
	return 31;
	if(mont==4)
	return 30;
	if(mont==5)
	return 31;
	if(mont==6)
	return 30;
	if(mont==7)
	return 31;
	if(mont==8)
	return 31;
	if(mont==9)
	return 30;
	if(mont==10)
	return 31;
	if(mont==11)
	return 30;
	if(mont==12)
	return 31;
}
int ry(int y)
{
	if(mont==1)
	return y;
	if(mont==2)
	return y-32;
	if(mont==3)
	return y-59;
	if(mont==4)
	return y-91;
	if(mont==5)
	return y-121;
	if(mont==6)
	return y-152;
	if(mont==7)
	return y-182;
	if(mont==8)
	return y-213;
	if(mont==9)
	return y-244;
	if(mont==10)
	return y-274;
	if(mont==11)
	return y-305;
	if(mont==12)
	return y-335;
}
int fp(int x)
{
	if(x<=31)
	return 1;
	else
	if(x<=59)
	return 2;
	else
	if(x<=90)
	return 3;
	else
	if(x<=120)
	return 4;
	else
	if(x<=151)
	return 5;
	else
	if(x<=181)
	return 6;
	else
	if(x<=212)
	return 7;
	else
	if(x<=243)
	return 8;
	else
	if(x<=273)
	return 9;
	else
	if(x<=304)
	return 10;
	else
	if(x<=334)
	return 11;
	else
	if(x<=365)
	return 12;
}
int main()
{
    freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++)
		cin>>rq[i];
	for(int i=1;i<=q;i++)
	{
		if(rq[i]==365)
		{
			cout<<1<<" "<<1<<" "<<4712<<" "<<"BC"<<endl;
			continue;
		}
		int dd=rq[i]+1;
		mont=fp(dd);
		daay=ry(dd);
		if(daay==0) 
		{
			mont--;
			daay=tp(mont);
		}
		cout<<daay<<" "<<mont<<" "<<4713<<" "<<"BC"<<endl;
	}
	return 0;
}
