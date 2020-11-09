#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<iomanip>
#include<stack> 
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
bool b=false;
bool runnian(int nian,int yue,int ri) {
	if(nian<=-1) nian--;
	if(nian%4==0||(nian%4!=0&&nian%100==0)&&nian>1582) return true;
	else if(nian%4==0||(nian%4!=0&&nian%100==0)&&nian==1582&&yue>10) return true;
	else if(nian%4==0||(nian%4!=0&&nian%100==0)&&nian==1582&&yue==10&&ri>=15) return true;
	else if(nian<1582&&nian%4==0) return true;
	else if(nian==1582&&yue<10&&nian%4==0) return true;
	else if(nian==1582&&yue==10&&ri<4&&nian%4==0) return true;
	else if(nian==1582&&yue==10&&ri==4&&nian%4==0) return true;
	else return false;
}


long long yuefen[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};


int main() {
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		b=false;
		yuefen[2]=28;		
		long long ll,a;
		long long dangnian=-4713,dangyue=1,dangri=1;
		cin>>ll;
		dangri=dangri+ll;
		if(dangri>yuefen[dangyue]) {
			a=dangri/yuefen[dangyue];
			dangri=dangri%yuefen[dangyue];
			if(dangri==0) dangri=1;
			dangyue=dangyue+a;
			if(dangyue==0) dangyue=1;
		}
		if(dangyue>12) {
			a=dangyue/12;
			dangyue=dangyue%12;
			if(dangyue==0) dangyue=1;
			dangnian=dangnian+a;
			if(dangnian==0) dangnian==1;
			if(runnian(dangnian,dangyue,dangri)==true) {
				yuefen[2]=29;
			}
			else yuefen[2]=28;
		}
		if(dangnian==0) dangnian=1,yuefen[2]=28;
		if((dangnian>=1582&&dangyue>=10&&dangri>=5)||(dangnian>=1582&&dangyue>10)) { //如果这个年份不存在
			for(int i=5; i<=14; i++) {
				if(dangnian==1582&&dangyue==10&&dangri==i){
					dangri--;
					if(dangri==0) dangri=1;
					b=true;
				}
			}
			if(b==false&&dangri<=10&&dangyue==10){
				dangyue=dangyue-1;
				if(dangyue==0) dangyue=1;
				dangri=dangri+yuefen[dangyue]-10;
				if(dangri==0) dangri=1;
			}
			else if(b==false&&dangri>=11){
				dangri=dangri-10;
				if(dangri==0) dangri=1;
			}
		}
		if(dangnian>0){
			cout<<dangri<<" "<<dangyue<<" "<<dangnian<<endl;
		}
		else if(dangnian<0){
			cout<<dangri<<" "<<dangyue<<" "<<abs(dangnian)<<" "<<"BC"<<endl;
		}
	}
	return 0;
}
