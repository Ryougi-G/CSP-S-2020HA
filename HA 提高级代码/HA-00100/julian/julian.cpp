#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int q;
int ri;
bool flag=0;

signed main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q=read();
	while(q--){
		flag=0; int yue=0;
		ri=read();
		if(ri<=1721423-1){
			int now=4713;
			while(1){
				if((now-1)%4==0){
//					run
					if(ri<=366) break;
					ri-=366; now-=1;
				}
				else{
					if(ri<=365) break;
					ri-=365; now-=1;
				}
			}
			if((now-1)%4==0){
				if(ri>=1&&ri<=31) yue=1;
				if(ri>31&&ri<=60) ri-=31,yue=2;
				if(ri>60&&ri<=91) ri-=60,yue=3;
				if(ri>91&&ri<=121) ri-=91,yue=4;
				if(ri>121&&ri<=152) ri-=121,yue=5;
				if(ri>152&&ri<=182) ri-=152,yue=6;
				if(ri>182&&ri<=213) ri-=182,yue=7;
				if(ri>213&&ri<=244) ri-=213,yue=8;
				if(ri>244&&ri<=274) ri-=244,yue=9;
				if(ri>274&&ri<=305) ri-=274,yue=10;
				if(ri>305&&ri<=335) ri-=305,yue=11;
				if(ri>335&&ri<=366) ri-=335,yue=12;
			}
			else{
				if(ri>=1&&ri<=31) yue=1;
				if(ri>31&&ri<=59) ri-=31,yue=2;
				if(ri>59&&ri<=90) ri-=59,yue=3;
				if(ri>90&&ri<=120) ri-=90,yue=4;
				if(ri>120&&ri<=151) ri-=120,yue=5;
				if(ri>151&&ri<=181) ri-=151,yue=6;
				if(ri>181&&ri<=212) ri-=181,yue=7;
				if(ri>212&&ri<=243) ri-=212,yue=8;
				if(ri>243&&ri<=273) ri-=243,yue=9;
				if(ri>273&&ri<=304) ri-=273,yue=10;
				if(ri>304&&ri<=334) ri-=304,yue=11;
				if(ri>334&&ri<=365) ri-=334,yue=12;
			}
			printf("%lld %lld %lld BC\n",ri+1,yue,now);
		}
//		BCqian
		else if(ri>1721423-1&&ri<=2299160-1){
			ri-=1721422;
			int now=1;
			while(1){
				if((now-1)%4==0){
//					run
					if(ri<=366) break;
					ri-=366; now+=1;
				}
				else{
					if(ri<=365) break;
					ri-=365; now+=1;
				}
			}
			if((now-1)%4==0){
				if(ri>=1&&ri<=31) yue=1;
				if(ri>31&&ri<=60) ri-=31,yue=2;
				if(ri>60&&ri<=91) ri-=60,yue=3;
				if(ri>91&&ri<=121) ri-=91,yue=4;
				if(ri>121&&ri<=152) ri-=121,yue=5;
				if(ri>152&&ri<=182) ri-=152,yue=6;
				if(ri>182&&ri<=213) ri-=182,yue=7;
				if(ri>213&&ri<=244) ri-=213,yue=8;
				if(ri>244&&ri<=274) ri-=244,yue=9;
				if(ri>274&&ri<=305) ri-=274,yue=10;
				if(ri>305&&ri<=335) ri-=305,yue=11;
				if(ri>335&&ri<=366) ri-=335,yue=12;
			}
			else{
				if(ri>=1&&ri<=31) yue=1;
				if(ri>31&&ri<=59) ri-=31,yue=2;
				if(ri>59&&ri<=90) ri-=59,yue=3;
				if(ri>90&&ri<=120) ri-=90,yue=4;
				if(ri>120&&ri<=151) ri-=120,yue=5;
				if(ri>151&&ri<=181) ri-=151,yue=6;
				if(ri>181&&ri<=212) ri-=181,yue=7;
				if(ri>212&&ri<=243) ri-=212,yue=8;
				if(ri>243&&ri<=273) ri-=243,yue=9;
				if(ri>273&&ri<=304) ri-=273,yue=10;
				if(ri>304&&ri<=334) ri-=304,yue=11;
				if(ri>334&&ri<=365) ri-=334,yue=12;
			}
			printf("%lld %lld %lld\n",ri,yue,now);
		}
//		BC--1582.10.4
		else if(ri>2299160-1){
			ri-=2299160-1; ri+=10;
			int now=1582,yue=10,day=4;
			while(1){
				if(ri==0||(yue==12&&day==31)) break;
				if(yue==10||yue==12){
					day++; ri--;
					if(day>31){
						day=1,yue++;
					}
				}
				else{
					day++;ri--;
					if(day>30){
						day=1;
						yue++;
					}
				}
			}
			if(ri==0){
				printf("%lld %lld %lld\n",day,yue,now);
			}
			else{
				ri--;
				now=1583; yue=0;day=0;
			while(1){
				if((now)%400==0||((now)%4==0&&(now)%100!=0)){
//					run
					if(ri<=366) break;
					ri-=366; now++;
				}
				else{
					if(ri<=365) break;
					ri-=365; now++;
				}
			}
			if((now)%400==0||((now)%4==0&&(now)%100!=0)){
				if(ri>=1&&ri<=31) yue=1;
				if(ri>31&&ri<=60) ri-=31,yue=2;
				if(ri>60&&ri<=91) ri-=60,yue=3;
				if(ri>91&&ri<=121) ri-=91,yue=4;
				if(ri>121&&ri<=152) ri-=121,yue=5;
				if(ri>152&&ri<=182) ri-=152,yue=6;
				if(ri>182&&ri<=213) ri-=182,yue=7;
				if(ri>213&&ri<=244) ri-=213,yue=8;
				if(ri>244&&ri<=274) ri-=244,yue=9;
				if(ri>274&&ri<=305) ri-=274,yue=10;
				if(ri>305&&ri<=335) ri-=305,yue=11;
				if(ri>335&&ri<=366) ri-=335,yue=12;
			}
			else{
				if(ri>=1&&ri<=31) yue=1;
				if(ri>31&&ri<=59) ri-=31,yue=2;
				if(ri>59&&ri<=90) ri-=59,yue=3;
				if(ri>90&&ri<=120) ri-=90,yue=4;
				if(ri>120&&ri<=151) ri-=120,yue=5;
				if(ri>151&&ri<=181) ri-=151,yue=6;
				if(ri>181&&ri<=212) ri-=181,yue=7;
				if(ri>212&&ri<=243) ri-=212,yue=8;
				if(ri>243&&ri<=273) ri-=243,yue=9;
				if(ri>273&&ri<=304) ri-=273,yue=10;
				if(ri>304&&ri<=334) ri-=304,yue=11;
				if(ri>334&&ri<=365) ri-=334,yue=12;
			}
			printf("%lld %lld %lld\n",ri,yue,now);
			}
		}
//		1582.10.15--(rule as up)
	}
	return 0;
}
