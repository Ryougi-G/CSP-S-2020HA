#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q,r,i,y,m,d;
	bool run,k;
	cin>>q;
	for(i=1;i<=q;i++){
		cin>>r;
		y=-4713; m=1; d=1;
		k=true;
		if(r>=500000000&&k){
			k=false;
			r-=500000000;
			y=1364241; m=5; d=27;
		}
		if(r>=300000000&&k){
			k=false;
			r-=300000000;
			y=816660; m=1; d=1;
		}
		if(r>=100000000&&k){
			k=false;
			r-=100000000;
			y=269078; m=8; d=7;
		}
		if(r>=50000000&&k){
			k=false;
			r-=50000000;
			y=132183; m=4; d=1;
		}
		if(r>=30000000&&k){
			k=false;
			r-=30000000;
			y=77425; m=2; d=9;
		}
		if(r>=10000000&&k){
			k=false;
			r-=10000000;
			y=22666; m=12; d=20;
		}
		if(r>=5000000&&k){
			k=false;
			r-=5000000;
			y=8977; m=6; d=7;
		}
		if(r>=3000000&&k){
			k=false;
			r-=3000000;
			y=3501; m=8; d=15;
		}
		if(r>=1000000&&k){
			k=false;
			r-=1000000;
			y=-1976; m=11; d=7;
		}
		if(r>=500000&&k){
			k=false;
			r-=500000;
			y=-3345; m=12; d=4;
		}
		if(r>=100000&&k){
			k=false;
			r-=100000;
			y=-4440; m=10; d=14;
		}
		run=true;
		while(r!=0){
			d++; r--;
			if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d==32){d=1; m++;}
			if((m==4||m==6||m==9||m==11)&&d==31){d=1; m++;}
			if(d==30&&m==2){d=1; m++;}
			if(d==29&&m==2&&!run){d=1; m++;}
			if(y==1582&&m==10&&d==5) d=15;
			if(m==13){
				m=1; y++;
				run=false;
				if(y<=1582){
					if(y<0&&y%4==-1) run=true;
					if(y>0&&y%4==0) run=true;
				}
				else if(y%400==0||(y%100!=0&&y%4==0)) run=true;
			}
			if(y==0) y++;
		}
		cout<<d<<" "<<m<<" ";
		if(y<0) cout<<0-y<<" BC"<<endl;
		else cout<<y<<endl;
	}
	return 0;
}
