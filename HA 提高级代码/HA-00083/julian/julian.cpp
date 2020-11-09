#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int shuru[100001],zushu,nian=-4713,yue=1,ri=1,a,b,c,d;
	cin>>zushu;
	for(int i=1;i<=zushu;i++)
	cin>>shuru[i];
	for(int i=1;i<=zushu;i++)
	{
		a=b=c=d=0;
	//	c=shuru[i]%1461;
	//	d=((shuru[i]-c)/1461)*4;//多少轮年 
		if(shuru[i]>=366)//无闰年 
		{
		nian=-4713;
		b=shuru[i];
		a=shuru[i]%365;
		nian+=((b-a)/365);//年份 
		nian-=(nian*2);
		//月份 
		a-=1;
				if(a<=30)//1
			{
			
			ri=1;
			yue=1;
			ri+=a;
		}
			if(a<=57&&a>30)//2
			{
			
			ri=1;
			yue=2;
			ri+=(a-31);
		}
			if(a<=88&&a>57)//3
			{
			
			ri=1;
			yue=3;
			ri+=(a-58);
		}
			if(a<=118&&a>88)//4
			{
			
			ri=1;
			yue=4;
			ri+=(a-89);
		}
			if(a<=149&&a>118)//5
			{
			
			ri=1;
			yue=5;
			ri+=(a-119);
		}
			if(a<=179&&a>149)//6
			{
			
			ri=1;
			yue=6;
			ri+=(a-150);
		}
			if(a<=211&&a>179)//7
			{
			
			ri=1;
			yue=7;
			ri+=(a-180);
		}
			if(a<=242&&a>211)//8
			{
			
			ri=1;
			yue=8;
			ri+=(a-212);
		}
			if(a<=272&&a>242)//9
			{
			
			ri=1;
			yue=9;
			ri+=(a-243);
		}
			if(a<=303&&a>272)//10
			{
			
			ri=1;
			yue=10;
			ri+=(a-273);
		}
			if(a<=333&&a>303)//11
			{
			
			ri=1;
			yue=11;
			ri+=(a-304);
		}
			if(a<=364&&a>323)//12
			{
			
			ri=1;
			yue=12;
			ri+=(a-334);
		}
		cout<<ri<<' '<<yue<<' '<<nian<<' '<<"BC"<<endl;
	}
	if(shuru[i]<366)//小于一年 
		{
		nian=-4713; 
		//月份 
		a=shuru[i];
			if(a<=30)//1
			{
			
			ri=1;
			yue=1;
			ri+=a;
		}
			if(a<=59&&a>30)//2
			{
			
			ri=1;
			yue=2;
			ri+=(a-31);
		}
			if(a<=90&&a>59)//3
			{
			
			ri=1;
			yue=3;
			ri+=(a-60);
		}
			if(a<=120&&a>90)//4
			{
			
			ri=1;
			yue=4;
			ri+=(a-91);
		}
			if(a<=151&&a>120)//5
			{
			
			ri=1;
			yue=5;
			ri+=(a-121);
		}
			if(a<=181&&a>151)//6
			{
			
			ri=1;
			yue=6;
			ri+=(a-152);
		}
			if(a<=212&&a>181)//7
			{
			
			ri=1;
			yue=7;
			ri+=(a-182);
		}
			if(a<=243&&a>212)//8
			{
			
			ri=1;
			yue=8;
			ri+=(a-213);
		}
			if(a<=273&&a>243)//9
			{
			
			ri=1;
			yue=9;
			ri+=(a-244);
		}
			if(a<=304&&a>273)//10
			{
			
			ri=1;
			yue=10;
			ri+=(a-274);
		}
			if(a<=335&&a>304)//11
			{
			
			ri=1;
			yue=11;
			ri+=(a-305);
		}
			if(a<=366&&a>335)//12
			{
			
			ri=1;
			yue=12;
			ri+=(a-336);
		}
		cout<<ri<<' '<<yue<<' '<<4713<<' '<<"BC"<<endl;
	}
}
return 0;
}


