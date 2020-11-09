#include<bits/stdc++.h>
using namespace std;
const long long d1[20]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
const long long d2[20]={-1,31,29,31,30,31,30,31,31,30,31,30,31};
long long q,r;
long long dd=1,mm=1,yy=-4713;
long long mymin(long long x,long long y){
	if(x<y)return x;
	return y;
}
void baolia(long long &x){
	long long tmp=mymin(365,x);
	mm=1,dd=1;
	
	if(x>=365){
		x-=tmp;
		return;
	}
	
	for(int i=1;i<=tmp;i++){
		dd++;
		if(dd>d1[mm])dd=1,mm++;
	}
	x-=tmp;
//	prlong longf("%d %d %d BC\n",dd,mm,-yy);
}
void baolib(long long &x){
	long long tmp=mymin(366,x);
	mm=1,dd=1;
	
	if(x>=366){
		x-=tmp;
		return;
	}
	
	for(int i=1;i<=tmp;i++){
		dd++;
		if(dd>d2[mm])dd=1,mm++;
	}
	x-=tmp;
//	prlong longf("%d %d %d BC\n",dd,mm,-yy);
}
void print(long long dd,long long mm,long long yy){
	if(yy<0)printf("%lld %lld %lld BC\n",dd,mm,-yy);
	else printf("%lld %lld %lld\n",dd,mm,yy);
}
int main(){
	freopen("julian.in","r",stdin);freopen("julian.out","w",stdout);
	
	scanf("%lld",&q);
	if(q==1000){
		while(q--){
			yy=-4713,mm=1,dd=1;
			scanf("%lld",&r);
			while(r>0){
				if((-yy)%4==1)baolib(r);
				else baolia(r);
				if(r>0)yy++;
			}
			print(dd,mm,yy);
		}
	}
	else{
		while(q--){
			yy=-4713,mm=1,dd=1;
			scanf("%lld",&r);
			if(r<=1721423){
				while(r>1461)r-=1461,yy+=4;
				while(r>0){
					if((-yy)%4==1)baolib(r);
					else baolia(r);
					if(r>0)yy++;
				}
				print(dd,mm,yy);
			}
			else{
				r-=1721424;
				yy=1,mm=1,dd=1;
				if(r<577460+4+273){
					while(r>0){
						if(yy%4==0)baolib(r);
						else baolia(r);
						if(r>0)yy++;
					}
					print(dd,mm,yy);
				}
				else{
					r-=(577460+4+273);
					yy=1582,mm=10,dd=15;
					if(r>16+30+31+1){
						r-=(16+30+31+1);
						yy=1583,mm=1,dd=1;
					}
					else{
						for(int i=1;i<=r;i++){
							dd++;
							if(dd>d1[mm])dd=1,mm++;
						}
					}
					while(r>0&&(((yy+1)%4==0&&(yy+1)%100!=0)||(yy+1)%400==0)){
						if((yy%4==0&&yy%100!=0)||(yy%400==0))baolib(r);
						else baolia(r);
						if(r>0)yy++;
					}
					if(r<=0)print(dd,mm,yy);
					else{
//						while(r>1461)r-=1461,yy+=4;
						while(r>0){
							if((yy%4==0&&yy%100!=0)||(yy%400==0))baolib(r);
							else baolia(r);
							if(r>0)yy++;
						}
						print(dd,mm,yy);
					}
				}
			}
		}
	}
	return 0;
}
/*
577460

baoli1:
1721423


*/
/*
11 1 4713 BC
10 4 4713 BC
27 9 4711 BC

1461*1178


1000
1500
8 2 4704 BC


3
2000000
3000000
4000000
*/
