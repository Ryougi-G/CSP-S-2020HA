#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll q,r,da,mo,ye,mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
ll read(){
	ll w=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		w=(w<<3)+(w<<1)+(c^48);
		c=getchar();
	}
	return w*f;
}
bool rlrn(ll year){
	if(year%4==0)return 1;
	else return 0;
}
bool rn(ll year){
	if(year%400==0||(year%4==0&&year%100!=0))return 1;
	return 0;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q=read();
	for(int i=1;i<=q;i++){
		r=read();
		if(r<=1721422){
			ye=4713;
	    	mo=1;
		    da=1;
			while(1){
				if(r<365)break;
				if(rlrn(ye)){
					if(r==365)r=0;
					else r-=366;
					ye--;
					if(r<365)break;
				}
				else{
					r-=365;
					ye--;
					if(r<365)break;
				}
			}
			while(1){
				if(r<28)break;
				if(mo==2&&rlrn(-ye))r++;
				if(r<mon[mo])break;
				r-=mon[mo];
				mo%=12;
				mo++;
			}
			da+=r;
			printf("%lld %lld %lld BC\n",da,mo,ye);
		}
		else{
			r-=1721423;
			ye=1;
			mo=1;
			da=-6;
			if(r>577813)r+=4;
			while(1){
				if(r<365)break;
				if(rn(ye)){
					if(r==365)r=0;
					else r-=366;
					ye++;
					if(r<365)break;
				}
				else{
					r-=365;
					ye++;
					if(r<365)break;
				}
			}
			while(1){
				if(r<28)break;
				if(mo==2&&rlrn(-ye))r++;
				if(r<mon[mo])break;
				r-=mon[mo];
				mo%=12;
				mo++;
			}
			da+=r;
			printf("%lld %lld %lld\n",da,mo,ye);
		}
	}
	return 0;
}
