#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#define DEBUG(N,S) cerr<<N<<": "<<S<<endl;
#define TEST cerr<<"test"<<endl;
#define ull unsigned long long
using namespace std;
const int cbeginyear=4713,cdicyear=1582;
ull Q,q;
ull ansyear,ansmonth,ansday;
unsigned int monthly[2][13]={0,31,28,31,30,31,30,31,31,30,31,30,31,0,31,29,31,30,31,30,31,31,30,31,30,31};
int yearly[2]={365,366}; //0 is normal 1 is run 
ull allruluebc=1721424;
ull allrulueac=2299161;
ull allbeforeclear=2299239;


void calc_md(int isrun){
	for(int i=1;i<=12;++i){
		if(q<monthly[isrun][i]){
			ansmonth=i;
			break;
		}
		q-=monthly[isrun][i];
	}
	ansday=q+1;
	return;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>Q;
	while(Q--){
		scanf("%lld",&q);
		if(q<allruluebc){
			ansyear=cbeginyear;
			int tmp1=1000*365+250;
			while(q>=tmp1){
				ansyear-=1000;
				q-=tmp1;
			}
			int tmp2=100*365+25;
			while(q>=tmp2){
				ansyear-=100;
				q-=tmp2;
			}
			int tmp3=4*365+1;
			while(q>=tmp3){
				ansyear-=4;
				q-=tmp3;
			}
			int isr=1;
			while((isr==0 && q>=365)||(isr==1 && q>=366)){
				q-=365;
				if(isr==1)--q;
				--ansyear;
				isr=((ansyear-1)%4==0)?1:0;
			}
			calc_md(isr);
			cout<<ansday<<' '<<ansmonth<<' '<<ansyear<<" BC"<<endl;
		}else if(q<allrulueac){
			q-=allruluebc;
			ansyear=1;
			int tmp1=1000*365+250;
			while(q>=tmp1){
				ansyear+=1000;
				q-=tmp1;
			}
			int tmp2=100*365+25;
			while(q>=tmp2){
				ansyear+=100;
				q-=tmp2;
			}
			int tmp3=4*365+1;
			while(q>=tmp3){
				ansyear+=4;
				q-=tmp3;
			}
			int isr=0;
			while((isr==0 && q>=365)||(isr==1 && q>=366)){
				q-=365;
				if(isr==1)--q;
				++ansyear;
				isr=(ansyear%4==0)?1:0;
			}
			calc_md(isr);
			cout<<ansday<<' '<<ansmonth<<' '<<ansyear<<endl;
		}else if(q<allbeforeclear){
			q-=allrulueac;
			ansyear=1582;
			ansmonth=10;
			ansday=15;
			if(q<17){
				ansday+=q;
			}else{
				q-=17;
				for(int i=11;i<=12;++i){
					if(q<monthly[0][i]){
						ansmonth=i;
						ansday=q+1;
						break;
					}
					q-=monthly[0][i];
				}
			}
			cout<<ansday<<' '<<ansmonth<<' '<<ansyear<<endl;
		}else{
			q-=allbeforeclear;
			ansyear=1583;
			ull tmp5=2560000*365+620800;
			while(q>=tmp5){
				ansyear+=2560000;
				q-=tmp5;
			}
			
			ull tmp4=25600*365+6208;
			while(q>=tmp5){
				ansyear+=25600;
				q-=tmp4;
			}
			int tmp1=1600*365+388;
			while(q>=tmp1){
				ansyear+=1600;
				q-=tmp1;
			}
			int tmp2=400*365+97;
			while(q>=tmp2){
				ansyear+=400;
				q-=tmp2;
			}
			int isr=0;
			while((isr==0 && q>=365)||(isr==1 && q>=366)){
				q-=365;
				if(isr==1)--q;
				++ansyear;
				isr=((ansyear%4==0 && ansyear%100!=0) || ansyear%400==0)?1:0;
			}
			calc_md(isr);
			cout<<ansday<<' '<<ansmonth<<' '<<ansyear<<endl;
		}
		ansyear=ansday=ansmonth=0;
	}
	return 0;
}
