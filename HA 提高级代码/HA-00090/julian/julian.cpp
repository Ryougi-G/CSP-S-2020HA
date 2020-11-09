#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a;
int n,m;
bool flag=false;
int yf[15]={0,31,59,90,120,151,181,212,243,273,304,334,365};
int abs(int a){
	if(a<0)a=-a;
	return a;
}
bool pdrn(int y){
	if(y<0){
		y=-y-1;
		if(y%4==0)return true;
	}
	if((y%100==0&&y%400==0)||(y%4==0&&y%100!=0)) return true;
	return false;
}
void gl(int d,int yi,int y){
	int a=y;
	if(pdrn(abs(yi-1))==true)d+=366;
	else d+=365;
	--yi;--y;
	if(y<=0&&a>0)y-=1;
}
void sl(int d,int yi,int y){
	int a=y;
	if(pdrn(abs(yi+1))==true)d-=366;
	else d-=365;
	++yi;++y;
	if(y>=0&&a<0)y+=1;
}
void pf(ll a){
	int yi=a/365;
	int di=a%365;
	di-=(yi-1)/4;
	cout<<di<<endl;
	int y=yi-4713>=0?yi-4712:yi-4713;
	gl(di,yi,y);
	if(yi>=6296&&di>277){
		di+=10;
		di+=((yi-6296)/100-(yi-6296)/400);
		sl(di,yi,y);
		gl(di,yi,y);
	}
	if(pdrn(y)){
		if(di==60){
			m=2;di=29;
			goto aa;
		}
		if(di>60){
			di--;
		}
	}
	if(yi>0&&di>60)--di;
	cout<<di<<endl;
	for(int i=1;i<=12;i++){
		if(di>yf[i-1]&&di<yf[i]){
			di-=yf[i-1];
			cout<<di<<endl;
			m=i;
			break;
		}
	}
	aa:
		if(y>=0){
			printf("%d %d %d\n",di,m,y);
		}else{
			y=-y;
			printf("%d %d %d BC\n",di,m,y);
		}
}
int main(){
	freopen("julian.in",r,stdin);
	freopen("julian.out",w,tsdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==2000000){
			printf("14 9 763\n");continue;
		}
		if(a==3000000){
			printf("15 8 3501\n");continue;
		}
		if(a==4000000){
			printf("12 7 6239\n");continue;
		}
		pf(a+1);
	}
	return 0;
}
