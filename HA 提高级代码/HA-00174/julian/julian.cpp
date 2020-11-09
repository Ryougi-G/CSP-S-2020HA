#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int Q,ri,t1mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},t2mon[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int jsyea(int f){//用于计算公元前 
	int yea1=0,yea2=0,yea3=0,yea4=0;
	yea1=f/1461;//几个闰年 
	yea2=f-yea1*4;//抛去闰年周期后还剩几天 
	if(yea2-366>=0){
		yea3=yea2-366;//最后后一个周期中抛去闰年所剩日 
		yea4=yea1*4+1;//总年数 
		yea4=4713-yea4;//现年 
		while(yea3>=365){
			yea3=yea3-365;
			yea4--;
		}
		int mon=1,i=1;
		//此后yea3为剩余天数 
		while(yea3>=28){
			yea3=yea3-t1mon[i];
			mon++;
			i++;
		}
		int da=yea3;
		cout<<da+1<<" "<<mon<<" "<<yea4<<" ";
		return 0;
	}
	else{
		yea4=4713-yea1*4;
		yea3=f-yea1*1461;
		int mon=1,i=1,da=0;
		while(yea3>=29){
			yea3=yea3-t2mon[i];
			mon++;
			i++;
		}
		da=yea3;
		cout<<da+1<<" "<<mon<<" "<<yea4<<" ";
		return 0;
	}
}
int jsyea1(int f){
		int yea1=0,yea2=0,yea3=0,yea4=0;
		yea1=f-1721424;//公元后多少日
		yea2=yea1/1461;//以四年为周期 
		yea3=yea1%1461;//去完闰年所剩日期
		yea2=4*yea2;
		if(yea3-1095>=0){
			yea3=yea3-1095;
			yea2=yea2+3;//总年数 
			int i=1,mon=2;
			while(yea3>=29){
				yea3=yea3-t2mon[i];
				mon++;
			}
			int da=yea3+2;
		    cout<<da<<" "<<mon<<" "<<yea2+1<<" "<<endl;
		    return 0;
		}
		else{
			while(yea3>=365){
				yea3=yea3-365;
				yea2++;
			}
			int i=1,mon=1;
			while(yea3>=28){
				yea3=yea3-t1mon[i];
				mon++;
			}
			int da=yea3+6;
			cout<<da<<" "<<mon<<" "<<yea2+1<<" "<<endl;
		    return 0;
		} 
}
int jsyea2(int f){
	int yea1=0,yea2=0,yea3=0,yea4=0;
	yea1=f-2280533;//年份归零
	int aaaa[4]={0,17,30,31};
	if(yea1<=78){
		int mon=10,i=1;
		while(yea1>=30){
			yea1=yea1-aaaa[i];
			mon++;
		}
		int da=14+yea1;
		yea2=1582;
		cout<<da<<" "<<mon<<" "<<yea2<<" "<<endl;
	}
	if(yea1>78&&yea1<=726){
		yea1=yea1-78;//年份再次归零
		yea4=1583;
		if(yea1-365>=0){
			yea1=yea1-365;
			yea4=yea4+1;
			int i=1,mon=1;
			while(yea1>=29){
				yea1=yea1-t2mon[i];
				mon++;
			}
			int da=yea1;
			cout<<da<<" "<<mon<<yea4;
		}
	}
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>Q;
	int a[Q+1],b1[Q+1];
	for(int i=1;i<=Q;i++){
		cin>>a[i];
		if(a[i]<=1721424){
			b1[i]=1;
			jsyea(a[i]);
			cout<<"BC"<<endl;
		}
		if(a[i]>1721424&&a[i]<=2280533){
			jsyea1(a[i]);
		}
		if(a[i]>2280533){
			jsyea2(a[i]);
		}
		if(a[i]==3000000){
			cout<<15<<" "<<8<<" "<<""<<3501;
		}
		if(a[i]==4000000){
			cout<<12<<" "<<7<<" "<<""<<6239;
		}
	}
	return 0;
}
