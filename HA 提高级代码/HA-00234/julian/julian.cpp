#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <string>
#define pb push_back
#define mp make_pair
#define pll pair<long long,long long>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int DMAX=100000+5;
const int INF=1000000007;
const int MOD=998244353;
inline void read(ll &x){
	x=0;
	ll f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+int(ch-'0');
		ch=getchar();
	}
	x*=f;
}
ll n;
ll dat;
ll pre;
ll x;
ll y,m,d;
ll qr[14];
ll pol;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	read(n);
	dat=365*3+366; //1461
//	cout<<dat<<endl;
	pre=(dat*1178);
	pol=dat*395;
	pol+=365;
	pol+=276;
	pre+=366; //1721424
//	cout<<pol+pre<<endl;
	qr[1]=qr[3]=qr[5]=qr[7]=qr[8]=qr[10]=qr[12]=31;
	qr[4]=qr[6]=qr[9]=qr[11]=30;
	while(n--){
		read(x);
		if(x<pre){
			ll qas=x/dat;
			ll lef=x%dat;
			y=4713-qas*4,m=1,d=1;
			for(int i=1;i<=lef;i++){
				if(m==2){
					if(y%4==1){
						if(d==29){
							m++;
							d=1;
							continue;
						}
					}
					else{
						if(d==28){
							m++;
							d=1;
							continue;
						}
					}
				}
				if(m!=2 && d==qr[m]){
					if(m!=12){
						m++;
						d=1;
					}
					else{
						y--;
						m=1,d=1;
					}
					continue;
				}
				d++;
			}
			printf("%lld %lld %lld BC\n",d,m,y);
			continue;
		}
		x-=pre;
		if(x<=pol){
			ll qas=x/dat;
			ll lef=x%dat;
//			cout<<qas<<" "<<lef<<endl;
			ll y=1+qas*4,m=1,d=1;
			for(int i=1;i<=lef;i++){
				if(m==2){
					if(y%4==0){
						if(d==29){
							m++;
							d=1;
							continue;
						}
					}
					else{
						if(d==28){
							m++;
							d=1;
							continue;
						}
					}
				}
				if(m!=2 && d==qr[m]){
					if(m!=12){
						m++;
						d=1;
					}
					else{
						y++;
						m=1,d=1;
					}
					continue;
				}
				d++;
			}
			printf("%lld %lld %lld\n",d,m,y);
			continue;
		}
		x-=pol;
		if(x<=79){
			y=1582,m=10,d=14;
			for(int i=1;i<=x;i++){
				if(m==2){
					if(y%4==0){
						if(d==29){
							m++;
							d=1;
							continue;
						}
					}
					else{
						if(d==28){
							m++;
							d=1;
							continue;
						}
					}
				}
				if(m!=2 && d==qr[m]){
					if(m!=12){
						m++;
						d=1;
					}
					else{
						y++;
						m=1,d=1;
					}
					continue;
				}
				d++;
			}
			printf("%lld %lld %lld\n",d,m,y);
			continue;
		}
		x-=79;
//		ll y=1583,m=1,d=1;
//		for(int i=1;i<=x;i++){
//				if(m==2){
//					if(y%400==0 || (y%4==0 && y%100!=0)){
//						if(d==29){
//							m++;
//							d=1;
//							continue;
//						}
//					}
//					else{
//						if(d==28){
//							m++;
//							d=1;
//							continue;
//						}
//					}
//				}
//				if(m!=2 && d==qr[m]){
//					if(m!=12){
//						m++;
//						d=1;
//					}
//					else{
//						y++;
//						m=1,d=1;
//					}
//					continue;
//				}
//				d++;
//			}
//		printf("%lld %lld %lld\n",d,m,y);
		ll y=1583,m=1,d=1;
		while(x>0){
			ll qas=x/dat;
			ll lef=x%dat;
			ll asdf=y;
			y=y+qas*4;
				for(int i=1;i<=lef;i++){
					if(m==2){
						if(y%4==0){
							if(d==29){
								m++;
								d=1;
								continue;
							}
						}
						else{
							if(d==28){
								m++;
								d=1;
								continue;
							}
						}
					}
					if(m!=2 && d==qr[m]){
						if(m!=12){
							m++;
							d=1;
						}
						else{
							y++;
							m=1,d=1;
						}
						continue;
					}
					d++;
				}
			ll poly;
			ll qwert;
			if(asdf%100==0){
				if(m<=2 && d<=28){
					qwert=asdf/100;
				}
				else{
					qwert=(asdf+1)/100;
				}
			}
			else{
				qwert=asdf/100;
			}
			if(y%100==0){
				if(m<=2 && d<=28){
					poly=(y-1)/100;
				}
			}
			else{
				poly=y/100;
			}
			ll dist=(poly-qwert+1);
			ll erd=poly/4-qwert/4+1;
			x=dist-erd;
		}
		
		printf("%lld %lld %lld\n",d,m,y);
	}
	return 0;
}
