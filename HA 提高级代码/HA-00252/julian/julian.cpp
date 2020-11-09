#include <bits/stdc++.h>
#define deb if(debug)
#define int long long
const int debug =1;
#define fo(i,x) for(int i=1;i<=(x);++i)
#define fo_(i,b,x) for(int i = b;i<=x;++i)
#define re(i,b,x) for(int i = b;i>=x;--i)
#define N 100010
int run[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int ping[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
using namespace std;
int getm(int y,int m){
	if(y<=0){
		y = -y;
		if(y%4==0) {
			if(m==2) return 29;
			else return run[m];
		}else{
			if(m==2) return 28;
			else return ping[m];
		}
	}else{
		if(y<1582){
			if(y%4==0) {
				if(m==2) return 29;
				else return run[m];
			}else{
				if(m==2) return 28;
				else return ping[m];
			}
		}else if(y==1582){
			if(m==2) return 28;
			else if (m == 10) return 21;
			else return run[m];
		}else{
			if((y%4==0 && y%100!=0) || y%400==0) {
				if(m==2) return 29;
				else return run[m];
			}else{
				if(m==2) return 28;
				else return run[m];
			}
		}
	}
}
int gety(int y){
	if(y<=0){
		y = -y;
		if(y%4==0) {
			return 366;
		}else{
			return 365;
		}
	}else{
		if(y<1582){
			if(y%4==0) {
				return 366;
			}else{
				return 365;
			}
		}else if(y==1582){
			return 355;
		}else{
			if((y%4==0 && y%100!=0) || y%400==0) {
				return 366;
			}else{
				return 365;
			}
		}
	}
}
void solve(){
	int t;cin>>t;
	int yr = -4712,mm = 1,dd = 1;
	while(t-gety(yr)>0){
//			deb printf("Year %lld has %lld days \n",yr,gety(yr));
			t -= gety(yr);
			yr++;
	}
	while(t-getm(yr,mm)>0){
		
//		deb printf("Year %lld,%lld has %lld days \n",yr,mm,getm(yr,mm));
		t -= getm(yr,mm);
		mm++;
		
	}
	dd+= t;
	if(yr==1582 && mm == 10 && dd>=5) dd+= 10;
	if(yr<=0) printf("%lld %lld %lld BC\n",dd,mm,(-yr+1));
	else printf("%lld %lld %lld\n",dd,mm,yr);
	
}
signed main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int T;cin>>T;while(T--){
		solve();
	}
	return 0;
}
