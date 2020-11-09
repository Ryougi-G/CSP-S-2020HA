#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
ll T,n;
bool f=0;
ll year,mon,day;
ll d[13]={29,31,28,31,30,31,30,31,31,30,31,30,31};
bool check(ll y,int flag)
{
	if(flag){
		if(y%4==0) return 1;
		else return 0;
	}
	if(y%400==0) return 1;
	if(y%100==0) return 0;
	if(y%4==0) return 1;
	return 0;
}
void get_tim(ll y,ll lst,ll &m,ll &da,int flag)
{
	if(f) y-=1;
	m=1;
	while(lst>d[m]&&m<=12) lst-=d[m],m++;
	if(check(y,flag)&&m>2){
		if(lst==1){
			m--;
			if(m==2) lst=29;
			else lst=d[m];
		}
		else lst--;
	}
	da=lst;
	if(!n) m=da=1;
	return;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		day=mon=year=0;
		if(n<=2299161-1){ //time<=1582.10.4   start from BC 4713.1.1
			year=n/1461;
			year*=4;
			n%=1461;
			if(n>=366) n-=366,year++;
			//while(n>=365){n-=365;year++;}
			year+=(n/365);
			n%=365;
			if(year<4713) f=1;
			year=4713-year>0?4713-year:year-4713+1;
			get_tim(year,n+1,mon,day,1);
			printf("%lld %lld %lld",day,mon,year);
		}
		else{
			n-=(2299161-1);//start from 1582.10.15(0)
			if(n<=78){
				year=1582;
				get_tim(1582,287+n,mon,day,1);
				printf("%lld %lld %lld",day,mon,year);
				continue;
			}
			n-=79;//start from 1583.1.1(0)
			year=n/146097;
			year*=400;
			n%=146097;
			year+=1583;
			while(n>=365){
				if(check(year,0)){
					if(n<366) break;
					n-=366;
					year++;
					continue;
				}
				n-=365;
				year++;
			}
			get_tim(year,n+1,mon,day,0);
			printf("%lld %lld %lld",day,mon,year);
		}
		if(f) printf(" BC");
		printf("\n");
	}
	return 0;
}
