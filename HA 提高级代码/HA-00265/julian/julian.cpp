#include<iostream>
#include<cstdio>
using namespace std;
const int yj4=1461,yg100=36524,yg400=146097,base=1721424,fir=4713,sec=1582,len=2299160,fd=2305459,
			mdcn[]={0,31,28,31,30,31,30,31,31,30,31,30,31},
			mdcs[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int yans,dans,mans;

void getans_bef1582(long long k){
	yans+=k/yj4*4;
	k%=yj4;
	if(k>366){
		yans++,k-=366;
		yans+=k/365;
		k%=365;
		for(int i=1;i<=12;++i){
			if(k<mdcn[i]){
				mans=i;
				dans=k+1;
				break;
			}
			k-=mdcn[i];
		}
	}else{
		for(int i=1;i<=12;++i){
			if(k<mdcs[i]){
				mans=i;
				dans=k+1;
				break;
			}
			k-=mdcs[i];
		}
	}
	if(yans>=fir)yans++;	
}

void getans_aft1582(long long k){
	k+=11;
	if(k>=fd){
		yans=1600+4712;
		k-=fd;
		yans+=k/yg400*400;
		k%=yg400;
		yans+=k/yg100*100;
		k%=yg100;
		if(yans%100==0&&yans%400!=0){
			yans+=k/365;
			k%=365;
			for(int i=1;i<=12;++i){
				if(k<mdcn[i]){
					mans=i;
					dans=k+1;
					break;
				}
				k-=mdcn[i];
			}
		}else getans_bef1582(k);
	}else getans_bef1582(k);
}

int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	long long dat;
	int t;
	cin>>t;
	while(t--){
		yans=dans=mans=0;
		cin>>dat;
		if(dat<=len)getans_bef1582(dat);
		else getans_aft1582(dat);
		cout<<dans<<" "<<mans<<" ";
		if(yans>fir)cout<<yans-fir<<endl;
		else cout<<fir-yans<<" BC"<<endl;
	}
}
