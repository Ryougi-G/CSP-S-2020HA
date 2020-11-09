#include<bits/stdc++.h>
using namespace std;
long long t;
long long day;
int x1[5]={366,365,365,365},x2[15]={31,29,31,30,31,30,31,31,30,31,30,31};
int x3[15]={31,28,31,30,31,30,31,31,30,31,30,31};  //x1闰 x2平 
int yy[5]={365,365,365,366};
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>t;
	while(t){
		t--;
		cin>>day;
		//____________
		if(day>=0&&day<1721424){
			long long a=4713,b=1,c=1;   //a 年 b 月 c日 
			long long year4=day/1461; //算出能走过的闰年
			if(year4) day=day-1461*year4;  
			a-=4*year4;
			int k=3; 
			for(int i=0;i<4;i++){
			 if(day>=x1[i]) {
			 	k=i;
				day-=x1[i];
				a--;
				}
				else break;     
			}                 //年份判断完毕 
		//	cout<<day<<endl; 
				if(k==3){
				for(int i=0;i<12;i++){
					if(day>=x2[i]) {
						b++;
						day-=x2[i];
					}
					else {
					
						c+=day;
						cout<<c<<' '<<b<<' '<<a<<" BC"<<endl;
						break;
					}
				}
			}
			else{
			for(int i=0;i<12;i++){
					if(day>=x3[i]) {
						b++;
						day-=x3[i];
					}
					else {
						c+=day;
						cout<<c<<' '<<b<<' '<<a<<" BC"<<endl;
						break;
					}
				}
			}
		}             //40分到手 无意外的话   
		//-------------------------
		if(day>=1721424&&day<2299161) {
			long long a=1,b=1,c=1;
			day-=1721424;
		long long year4=day/1461; //算出能走过的闰年
			if(year4) day=day-1461*year4;  
			a+=4*year4;
			int k=0; 
			for(int i=0;i<4;i++){
			 if(day>=yy[i]) {
			 	k=i;
				day-=yy[i];
				a++;
				}
				else break;     
			}                 //年份判断完毕 
		//	cout<<day<<endl; 
				if(k==2){
				for(int i=0;i<12;i++){
					if(day>=x2[i]) {
						b++;
						day-=x2[i];
					}
					else {
						c+=day;
						cout<<c<<' '<<b<<' '<<a<<endl;
						break;
					}
				}
			}
			else{
			for(int i=0;i<12;i++){
					if(day>=x3[i]) {
						b++;
						day-=x3[i];
					}
					else {
						c+=day;
						cout<<c<<' '<<b<<' '<<a<<endl;
						break;
					}
				}
			}
		}        //公历前所有数据ok 10 4 可过 
			if(day>=2299161){
				long long a=1582,b=10,c=15;
				day-=2299161;
				if(day<=77){
					if (day<=16) {cout<<c+day<<' '<<b<<' '<<a<<endl; continue;}
					 if(day>16&&day<=46) {
					day-=16;
					c=0;
					b++;
					cout<<c+day<<' '<<b<<' '<<a<<endl;
					continue;	
					}
					if(day>46){
					day-=46;
					c=0;
					b=12;
					cout<<c+day<<' '<<b<<' '<<a<<endl;
					continue;
					}
				}
				if(day>=6651) {
					a=1601,b=1,c=1;
					day-=6652;
					if(day>=36524) {
						long long hyear=day/36524;
						if(hyear) day--;
						day=day-hyear*36524;   //可保证一定没有百年  不对 还有在百年的情况orz 
						a=a+hyear*100;
						hyear--;
						long long qwq=hyear/4;
						day-=qwq;
						long long year4=day/1461; //算出能走过的闰年
						if(year4) day=day-1461*year4;  
						a+=4*year4;
					} 
					else  {
						long long year4=day/1461; //算出能走过的闰年
						if(year4) day=day-1461*year4;  
						a+=4*year4;
					}
				}
				else if(day>=6341&&day<6651) {
					day-=6341;
					a=1600,b=3,c=1;
				}
			//	cout<<day<<endl; 
				long long k;
				if(a%4==0) k=3;
				if(a%4==1) k=0;
				if(a%4==2) k=1;
				if(a%4==3) k=2;
				int ans=4;  
				while(ans){
					ans--;
					 if(day>=yy[k]) {
				day-=yy[k];
				a++;
				
				}
				else break;     
					if(k==3) k=0;
					else k++;    //k 将要经历的 
				}
				if(k==3){
				for(int i=0;i<12;i++){
					if((i==1)&&(a%100==0)&&(a%400!=0)&&(day-28==0)){
						cout<<1<<' '<<3<<' '<<a<<endl;
						break;
					}
					if(day>=x2[i]) {
						b++;
						day-=x2[i];
					}
					else {
						if((i>=2)&&(a%100==0)&&(a%400!=0)) c++;
						c+=day;
						cout<<c<<' '<<b<<' '<<a<<endl;
						break;
					}
				}
			}
			else{
			for(int i=0;i<12;i++){
					if(day>=x3[i]) {
						b++;
						day-=x3[i];
					}
					else {
						c+=day;
						cout<<c<<' '<<b<<' '<<a<<endl;
						break;
					}
				}
			}
		}	
	}
	return 0;
}
