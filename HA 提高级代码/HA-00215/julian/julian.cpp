#include<bits/stdc++.h>
using namespace std;
int mo[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int mo2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int mo3[13]={0,31,28,31,30,31,30,31,31,30,21,30,31};
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q,a;
	cin>>q;
	for(int i=1;i<=q;i++){
	cin>>a;
	int d=1,m=1,y=-4713;
	while(a>365){
	if((y<=0&&abs(y+1)%4==0)||(y<1582&&y%4==0&&y>0))a-=366;
	else if(y<1582)a-=365;
	else if(y==1582)a-=355;
	else if(y%4==0&&y%100!=0||y%400==0)a-=366;
	else a-=365;
	y++;
	if(y==0)y=1;
	}
	if(y==1583&&a>=355){a-=355;y++;}
	int y1=y+1;
	if((y1%4!=0||y1%100==0)&&y1%400!=0&&a==365){a-=365;y++;}
	if(((y1<=0&&abs(y1+1)%4!=0)||(y1<1582&&y1%4!=0&&y1>0))&&a==365){a-=365;y++;}
	if(y==0)y++;
	while(a>=mo[m]&&((y%4!=0||y%100==0)&&y%400!=0&&y>1582||y<0&&abs(y1+1)%4!=0||(y<1582&&y%4!=0)&&y>0)){
		a-=mo[m];
		m++;	 
	}
	while(a>=mo2[m]&&((y%4==0&&y%100!=0||y%400==0)&&y>1582||(y<=0&&abs(y+1)%4==0)||(y<1582&&y%4==0&&y>0))){
		a-=mo2[m];
		m++;
	}
	if(y==1582&&a>=mo3[m]){
		a-=mo3[m];
		m++;
	}
	cout<<a+1<<' '<<m<<' '<<abs(y);
	if(y<0)cout<<" BC";
	cout<<endl;
}	
	return 0;
}
