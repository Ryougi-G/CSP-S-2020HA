#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll q,r,y,m,d,cnt=0;
ll mon1[12]= {31,59,90,120,151,181,212,243,273,304,334,365};
ll mon2[12]= {31,60,91,121,152,182,213,244,274,305,335,366};
ll mon3[3]= {31,30,31};
ll bcr[4]= {366,365,365,365},adr[4]= {365,365,365,366},sb[4]={365,366,365,365};
bool nr(int x){
	if((x%4==0&&x%100!=0)||x%400==0){
		return false;
	}
	else{
		return true;
	}
}
int main() {
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%lld",&q);
	while(q--) {
		cnt++;
		scanf("%lld",&r);
		r++;
		if(r<=1721424) {
			y=4713-(r/1461)*4;
			r%=1461;
			ll loop=0;
			if(r!=0) {
				loop++;
				for(ll i=0; i<4; i++) {
					if(r-bcr[i]>0) {
						r-=bcr[i];
						loop++;
					}
					else {
						break;
					}
				}
			}
			y-=loop-1;
			if(loop%4!=1) {
				for(ll i=0; i<12; i++) {
					if(r<=mon1[i]) {
						m=i+1;
						r-=mon1[i-1];
						break;
					}
				}
			}
			else {
				for(ll i=0; i<12; i++) {
					if(r<=mon2[i]) {
						m=i+1;
						r-=mon2[i-1];
						break;
					}
				}
			}
			d=r;
			cout<<d<<' '<<m<<' '<<y<<" BC"<<endl;
		}
		else if(r<=2299161) {
			r-=1721424;
			y=(r/1461)*4+1;
			r%=1461;
			ll loop=0;
			if(r!=0) {
				loop++;
				for(ll i=0; i<4; i++) {
					if(r-adr[i]>0) {
						r-=adr[i];
						loop++;
					}
					else {
						break;
					}
				}
			}
			y+=loop-1;
			if(loop%4!=0) {
				for(ll i=0; i<12; i++) {
					if(r<=mon1[i]) {
						m=i+1;
						r-=mon1[i-1];
						break;
					}
				}
			}
			else {
				for(ll i=0; i<12; i++) {
					if(r<=mon2[i]) {
						m=i+1;
						r-=mon2[i-1];
						break;
					}
				}
			}
			d=r;
			cout<<d<<' '<<m<<' '<<y<<endl;
		}
		else {
			r-=2299161;
			if(r<=78) {
				r+=14;
				y=1582;
				m=10;
				d=14;
				for(ll i=0; i<3; i++) {
					if(r-mon3[i]>0) {
						r-=mon3[i];
						m++;
					} else {
						break;
					}
				}
				r-=14;
				d+=r;
				cout<<d<<' '<<m<<' '<<y<<endl;
			}
			else {
				r-=78;
				y=1583;
				y+=(r/146097)*400;
				r%=146097;
				y+=(r/36524)*100;
				r%=36524;
				y+=(r/1461)*4;
				r%=1461;
				ll loop=0;
				if(r!=0) {
					loop++;
					for(ll i=0; i<4; i++) {
						if(r-sb[i]>0) {
							r-=sb[i];
							loop++;
						}
						else {
							break;
						}
					}
				}
				y+=loop-1;
				if(nr(y)) {
					for(ll i=0; i<12; i++) {
						if(r<=mon1[i]) {
							m=i+1;
							r-=mon1[i-1];
							break;
						}
					}
				}
				else {
					for(ll i=0; i<12; i++) {
						if(r<=mon2[i]) {
							m=i+1;
							r-=mon2[i-1];
							break;
						}
					}
				}
				d=r;
				cout<<d<<' '<<m<<' '<<y<<endl;
			}
		}
	}
	return 0;
}
