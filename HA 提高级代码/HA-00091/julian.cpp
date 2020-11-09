#include<bits/stdc++.h>
using namespace std;
bool rn(int r){
	if(r%4==0) return 1;
	else return 0;
}
int r[100001];
struct{
	int nian,yue,ri;
}rq[100001]={4713,1,1};
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q,c;
	cin>>q;
	for(int i=1;i<=q;i++) cin>>r[i];
	for(int i=1;i<=q;i++){
		rq[i].nian=4317;rq[i].ri=1;rq[i].yue=1;
		rq[i].ri+=r[i];
		while(rq[i].ri>31){
	if(rq[i].yue==1||rq[i].yue==3||rq[i].yue==5||rq[i].yue==7||rq[i].yue==8||rq[i].yue==10||rq[i].yue==12){
		rq[i].yue++;rq[i].ri-=31;
	}
	if(rq[i].yue==4||rq[i].yue==6||rq[i].yue==9||rq[i].yue==11){
		rq[i].yue++;rq[i].ri-=30;
	}
	else if(rn(rq[i].nian)){ rq[i].yue++;rq[i].ri-=29;
	}
	else {
	rq[i].yue++;rq[i].ri-=28;} 
	if(rq[i].yue>12) rq[i].nian--;rq[i].yue=1;
			}}
	for(int i=1;i<=q;i++) cout<<rq[i].ri<<" "<<rq[i].yue<<" "<<rq[i].nian<<" "<<"BC"<<endl;
	return 0;
}
