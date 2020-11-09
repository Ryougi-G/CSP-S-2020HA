#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int sb;
	cin>>sb;
	for(int s=1;s<=sb;s++){
		int n;
	cin>>n;
	int d=1,m=1,y=-4713;
	for(int i=1;i<=n;i++){
		if(y==0)y++;
		d++;
		if(y==1582&&m==10&&d==4){
			d+=10;i+=10;
			continue;
		}
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
			if(d>31)d%=31,m++;
		}else 
		if(m==2){
			if(y<1582){
//					if(y%4==0){
//						if(d>29)d%=29,m++;
//					}else 
//					if(d>28){
//						d%=28,m++;
//					}
					if(y%4==-1&&y<0){
						if(d>29)d%=29,m++; 
					}else if(d>28&&y<0){
						d%=28,m++;
					}
					if(y>0){
						if(y%4==0)if(d>29)d%=29,m++;
						else if(d>28)d%=28,m++;
					}
			}
			if(y>1582){
				if((y%4==0&&y%100!=0)||y%400==0){
					if(d>29)d%=29,m++;
				}else 
				if(d>28){
					d%=28,m++;
				}
			}
		}
		 else if(d>30)d%=30,m++;
		if(m>12)m%=12,y++;
	}
	cout<<d<<' '<<m<<' '<<abs(y);
	if(y<0)cout<<" BC"<<endl;
	else cout<<endl; 
	}
}
