	#include<bits/stdc++.h>	
	#define ll long long
	using namespace std;
	const int maxn=1e5+5;
	ll yu,sta=-4713,sta2=1583,p1,q1,flagf;
	int mon[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int mon2[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	
	void mtod(int x){
	int mo;
	for(int i=1;i<=12;i++){
	if(x<mon[i]) {mo=i;break;}
	else x-=mon[i];}
	cout<<x+1<<' '<<mo<<' ';}
	
	void mtod_r(int x){
	int mo;
	for(int i=1;i<=12;i++){
	if(x<mon2[i]) {mo=i;break;}
	else x-=mon2[i];}
	cout<<x+1<<' '<<mo<<' ';}
	
	void sub1(int x){
	if(x<=17){cout<<x+14<<' '<<10<<' '<<1582;return;}
	x-=17;
	if(x<=30){cout<<x<<' '<<11<<' '<<1582;return;}
	x-=30;
	cout<<x<<' '<<12<<' '<<1582;return;}
	
	void init(){
	yu=flagf=0;
	}
	//2299160
	int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int T,n,p,q;
	cin>>T;
	while(T--){
	cin>>n;
	init();
	if(n<=2299160){
	p=n%1461,q=n/1461;
	if(p>=366)++yu,p-=366;
	if(p>=365)++yu,p-=365;
	if(p>=365)++yu,p-=365;
	if(yu==0)mtod_r(p);
	else mtod(p);
	if(sta+q*4+yu<0) 
	cout<<-(sta+q*4+yu)<<' '<<"BC"<<endl;
	else cout<<sta+q*4+yu+1<<endl;}
	else{//1582-1600
	n-=2299160;
	if(n<=78) {sub1(n);continue;}
	n-=78;
	if(n<=6286-78+365+1){//2305446
	p=n%1461,q=n/1461;
	if(p>=365)++yu,p-=365;
	if(p>=366)++yu,p-=366,flagf=1;
	if(p>=365&&flagf==1)++yu,p-=365;	
	if(yu==1)mtod_r(p);
	else mtod(p);
	cout<<sta2+q*4+yu<<' '<<endl;}
	else{//1601-n
	//p=n%146097,q=n/146097;
	p1=n%1461,q1=n/1461;//2445036
	if(p1>=365)++yu,p1-=365;
	if(p1>=365)++yu,p1-=365;
	if(p1>=365)++yu,p1-=365;
	ll yu2=(1+q1*4+yu)/100,yu3=(1+q1*4+yu)%100,yu4=(1+q1*4+yu)%400,yu5=(1+q1*4+yu)/400;
	if(yu==3&&(yu3!=0||yu4==0))mtod_r(p1-yu2+yu5);
	else mtod(p1-yu2+yu5);
	cout<<1601+q1*4+yu<<' '<<endl;
	}
	}
}
	return 0;
	}
