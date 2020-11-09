#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
long long int ri[101],q; //ri 儒略日 q 表示询问组数 
int year=0,cnt=1,run=0,sum=0;
int m1=31,m2[2]={28,29},m3=31,m4=30,m5=31,m6=30,m7=31,m8=31,m9=30,m10=31,m11=30,m12=31;
int si_y,si_m,si_d; //si_y si_m si_d 表示年月日 
string BC="";
int main(){
freopen("julian.in","r",stdin);
freopen("julian.out","w",stdout);

//1.输入数据 
cin >> q;
for(int i=0;i<q;i++){
	cin >> ri[i];
}
//2.计算模块
//公元前4713年1月1日正午12点到此后某一时刻间所经过的天数
for(int i=0;i<q;i++){
	if(ri[i]>=365){
		sum=ri[i];
		for(int j=0;j<99999;j++){
		if(cnt%4==0 && cnt%100!=0 || cnt%400==0 && sum>=366){
		sum-=366;
		year++;
		cnt++;
		}else{
		sum-=365;
		year++;
		cnt++;
		}
		if(sum<366 && cnt%4==0 && cnt%100!=0 || cnt%400==0) break;
		else if(sum<365) break;
		}
	}else sum=ri[i];
	if(year<4713){
	si_y=4713-year;
	BC="BC";
	}
	if(year>=4713){
	si_y=year-4712;
	BC="";
	}
	if(cnt%4==0 && cnt%100!=0 || cnt%400==0 && sum>=366) run=1;
	if(sum<=m1&&sum>=0){
		si_m=1;
		si_d=sum+1;
	}
	if(sum-m1<=m2[run]&&sum-m1>=0){
		si_m=2;
		si_d=sum-m1;
	}
	if(sum-m1-m2[run]<=m3&&sum-m1-m2[run]>=0){
		si_m=3;
		si_d=sum-m1-m2[run];
	}
	if(sum-m1-m2[run]-m3<=m4&&sum-m1-m2[run]-m3>=0){
		si_m=4;
		si_d=sum-m1-m2[run]-m3;
	}
	if(sum-m1-m2[run]-m3-m4<=m5&&sum-m1-m2[run]-m3-m4>=0){
		si_m=5;
		si_d=sum-m1-m2[run]-m3-m4;
	}
	if(sum-m1-m2[run]-m3-m4-m5<=m6&&sum-m1-m2[run]-m3-m4-m5>=0){
		si_m=6;
		si_d=sum-m1-m2[run]-m3-m4-m5;
	}
	if(sum-m1-m2[run]-m3-m4-m5-m6<=m7&&sum-m1-m2[run]-m3-m4-m5-m6>=0){
		si_m=7;
		si_d=sum-m1-m2[run]-m3-m4-m5-m6;
	}
	if(sum-m1-m2[run]-m3-m4-m5-m6-m7<=m8&&sum-m1-m2[run]-m3-m4-m5-m6-m7>=0){
		si_m=8;
		si_d=sum-m1-m2[run]-m3-m4-m5-m6-m7;
	}
	if(sum-m1-m2[run]-m3-m4-m5-m6-m7-m8<=m9&&sum-m1-m2[run]-m3-m4-m5-m6-m7-m8>=0){
		si_m=9;
		si_d=sum-m1-m2[run]-m3-m4-m5-m6-m7-m8;
	}
	if(sum-m1-m2[run]-m3-m4-m5-m6-m7-m8-m9<=m10&&sum-m1-m2[run]-m3-m4-m5-m6-m7-m8-m9>=0){
		si_m=10;
		si_d=sum-m1-m2[run]-m3-m4-m5-m6-m7-m8-m9;
	}
	if(sum-m1-m2[run]-m3-m4-m5-m6-m7-m8-m9-m10<=m11&&sum-m1-m2[run]-m3-m4-m5-m6-m7-m8-m9-m10>=0){
		si_m=11;
		si_d=sum-m1-m2[run]-m3-m4-m5-m6-m7-m8-m9-m10;
	}
	if(sum-m1-m2[run]-m3-m4-m5-m6-m7-m8-m9-m10-m11<=m12&&sum-m1-m2[run]-m3-m4-m5-m6-m7-m8-m9-m10-m11>=0){
		si_m=12;
		si_d=sum-m1-m2[run]-m3-m4-m5-m6-m7-m8-m9-m10-m11;
	}
	cout <<si_d<<" "<<si_m<<" "<<si_y<<" "<<BC<<endl;
	year=0; cnt=1; run=0;
	si_y=0; si_m=0; si_d=0;
	BC=""; sum=0;
}

fclose(stdin);
fclose(stdout);
return 0;
}

