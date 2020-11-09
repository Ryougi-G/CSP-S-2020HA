#include<bits/stdc++.h>
using namespace std;
int a[13]={31,0,31,30,31,30,31,31,30,31,30,31},b[13];
int q,y,m,d,ri;
bool grn(int n){
	if(n%400==0||(n%4==0&&n%100!=0))return true;
	return false;
}
bool rrn(int n){
	if(n%4==0)return true;
	return false;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	while(q--){
		cin>>ri;
		bool j=1;
		for(int i=0;i<12;i++)b[i]=a[i];
		y=-4713,m=1,d=1;
		while(ri>=365){
			if(y==0){y=1;}
			if(y<=1582){
            	if(y<0){
				if(rrn(y+1)){y++;ri-=366;}
				else {y++;ri-=365;}
			}
			   if(y<=1582&&y>0){
				if(rrn(y)){y++;ri-=366;}
				else {y++;ri-=365;}
			}
        }
			if(y>1582){
				if(j&&y>1582){ri=ri+10;j=0;}
				if(grn(y)){y++;ri-=366;}
				else {y++;ri-=365;}
			} 
		}
		if(y<0){if(rrn(y+1))b[1]=29;else b[1]=28;}
		if(y>0&&y<1582){if(rrn(y))b[1]=29;else b[1]=28;}
		if(y==1582){b[9]=21;}
		if(y>1582){if(grn(y))b[1]=29;else b[1]=28;}
		int i=0;
		while(ri>=31){ri-=b[i];m++;i++;}
		if(ri>=b[i+1]&&(i!=11)){ri-=b[i+1];m++;}
		d+=ri;
		if(y<0)cout<<d<<" "<<m<<" "<<abs(y)<<" "<<"BC"<<endl;
		else cout<<d<<" "<<m<<" "<<y<<endl;
	}
	return 0;
}
