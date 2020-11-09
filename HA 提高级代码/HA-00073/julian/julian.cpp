//就拿50分吧，太难了...... 
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
long long r[MAXN];
long long year=-4713,moon=1,day=1;
int every[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int Q;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		scanf("%lld",&r[i]);
		day+=r[i];
		long long hou=0;
		if(r[i]<1721423){
			year+=((day)/1461)*4;
			day%=1461;
			if(day>366)day-=366,year++;
			if(day>365)day-=365,year++;
			if(day>365)day-=365,year++;
			bool yes=0;
			if((year+1)%4==0)yes=1,every[2]++;
			for(int k=1;k<=12;k++){
				if(day<=every[k])break;
				day-=every[k];
				moon++;
			}
			if(yes)every[2]--;
			year=-year;
			printf("%lld %lld %lld BC\n",day,moon,year);
			day=1;moon=1;year=-4713;
		}
		else{
			day-=1721423;
			moon=1;year=1;
			//577737:1 1 1-4 10 1582
			if(day<=577737){
				year+=(day/1461)*4;
				day%=1461;
				if(day>365)day-=365,year++;
				if(day>365)day-=365,year++;
				if(day>365)day-=365,year++;
				bool yes=0;
				if((year+1)%4==0)yes=1,every[2]++;
				for(int k=1;k<=12;k++){
					if(day<=every[k])break;
					day-=every[k];
					moon++;
				}
				if(yes)every[2]--;
				printf("%lld %lld %lld\n",day,moon,year);
				day=1;moon=1;year=-4713;
			}
		}
	}
	return 0;
}
//2 1 4713 BC为第一天； 
//4 10 1582为猪掠历，判断闰年只需是4的倍数； 
//5 10 1582-14 10 1582（10天）不存在； 
//15 10 1582为现在的日历； 
//公元前（4n+1（n属于N））年为闰年； 
//没有公元0年； 
//平年365天，闰年366天； 
//公元前共有4713年； 
//公元前共有(1178*1461+365)即1721423天； 
//max(MAXN)为10^5，O(n^2)不可能； 
//max(r_i)为10^9，数学题...... 
