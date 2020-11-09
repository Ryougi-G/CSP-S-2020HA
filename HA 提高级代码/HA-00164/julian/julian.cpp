#include<bits/stdc++.h>
#define ll long long
#define pp cout<<"test ";
using namespace std;
const ll bcfin=1721423ll,jieduan=2299160ll,fin1582=2299238ll,fin1584=2299969ll,fin1600=2305813ll;
int n,len[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&n);
	ll r,mm,dd,yy;
	bool runy=true;
	while(n--){
		scanf("%lld",&r);
		mm=0;dd=0;yy=0;runy=true;
		if(r<=bcfin){r++;
			ll tmp=(r/1461)*4;
			r%=1461;
			if(r>366) r-=366,tmp++,runy=false;
			if(r>365) r-=365,tmp++;
			if(r>365) r-=365,tmp++;
			yy=4713-tmp;
			for(int i=1;i<=12;i++){
				if(len[i]>=r){
					dd=r;
					mm=i;
					break;
				}
				r-=len[i];
				if(runy&&i==2) r-=1;
			}
			if(dd==0){
				dd=29;mm=2;
			}
			printf("%lld %lld %lld BC\n",dd,mm,yy);
		}
		else if(r>bcfin&&r<=jieduan){
			r-=bcfin;
			int tmp=(r/1461)*4;
			r%=1461;runy=false;
			if(r>365) r-=365,tmp++;
			if(r>365) r-=365,tmp++;
			if(r>365) r-=365,tmp++,runy=true;
			for(int i=1;i<=12;i++){
				if(len[i]>=r){
					dd=r;
					mm=i;
					break;
				}
				r-=len[i];
				if(runy&&i==2) r-=1;
			}
			yy=tmp+1;
			if(dd==0){
				dd=29;mm=2;
			}
			printf("%lld %lld %lld\n",dd,mm,yy);
		}
		else if(r>jieduan&&r<=fin1582){
			r-=jieduan;
			yy=1582;
			if(r<=17){
				dd=14+r;mm=10;
			}
			else if(r>17&&r<=47){
				dd=r-17;mm=11;
			}
			else{
				dd=r-47;mm=12;
			}
			if(dd==0){
				dd=29;mm=2;
			}
			printf("%lld %lld %lld\n",dd,mm,yy);
		}
		else if(r>fin1582&&r<=fin1584){
			r-=fin1582;int tmp=1583;runy=false;
			if(r>365) r-=365,tmp++,runy=true;
			for(int i=1;i<=12;i++){
				if(len[i]>=r){
					dd=r;
					mm=i;
					break;
				}
				r-=len[i];
				if(runy&&i==2) r-=1;
			}
			yy=tmp;
			if(dd==0){
				dd=29;mm=2;
			}
			printf("%lld %lld %lld\n",dd,mm,yy);
		}
		else if(r>fin1584&&r<=fin1600){
			int tmp=1585;
			r-=fin1584;
			tmp+=(r/1461)*4;
			r%=1461;runy=false;
			if(r>365) r-=365,tmp++;
			if(r>365) r-=365,tmp++;
			if(r>365) r-=365,tmp++,runy=true;
			for(int i=1;i<=12;i++){
				if(len[i]>=r){
					dd=r;
					mm=i;
					break;
				}
				r-=len[i];
				if(runy&&i==2) r-=1;
			}
			yy=tmp;
			if(dd==0){
				dd=29;mm=2;
			}
			printf("%lld %lld %lld\n",dd,mm,yy);
		}
		else if(r>fin1600){
			r-=fin1600;int tmp=1601;runy=false;
			tmp+=(r/146097)*400;
			r%=146097;
			if(r>=36524) tmp+=100,r-=36524;
			if(r>=36524) tmp+=100,r-=36524;
			if(r>=36524) tmp+=100,r-=36524;
			while(r>1461){
				tmp+=4;r-=1461;
			}
			if(r>365) r-=365,tmp++;
			if(r>365) r-=365,tmp++;
			if(r>365) r-=365,tmp++;
			yy=tmp;
			if((!(yy%4)&&yy%100)||!(yy%400)) runy=true;
			for(int i=1;i<=12;i++){
				if(len[i]>=r){
					dd=r;
					mm=i;
					break;
				}
				r-=len[i];
				if(runy&&i==2) r-=1;
			}
			if(dd==0){
				dd=29;mm=2;
			}
			printf("%lld %lld %lld\n",dd,mm,yy);
		}
	}
	return 0;
}
