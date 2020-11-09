#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q; ll t,nian,mon; double day;
bool qian; int cnt=0; int run; int tmp;
const ll fen=2299248;
int yue[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>t;
		if(t<=fen){
			nian=t/365; mon=t%365+1; qian=0;
			if(nian==0&&mon<=59){
				if(mon>31) cout<<mon-31<<" "<<2<<" "<<4713<<" BC"<<endl;
				else cout<<mon<<" "<<1<<" "<<4713<<" BC"<<endl;
				continue;
			}
			run=nian/4+1; 
			if(nian%4==0){
				mon-=run; mon++;
				if(mon>59) mon--;
				mon+=run;
			}
			if(run>=365) nian=nian-run/365,run=run%365;
			mon-=run;
			if(mon<0) mon+=365;
			if(nian<4713) qian=1;
			else nian=nian-4713;
			cnt=0;
			while(mon>yue[++cnt]&&cnt<=12){
				mon=mon-yue[cnt];
			}
			day=mon; mon=cnt;
			if(day==0&&cnt==1){
				if(qian) cout<<31<<" "<<12<<" "<<4713-nian+1<<endl;
				else cout<<31<<" "<<12<<" "<<nian+1<<endl;
			} 
			else{
			if(qian){
				cout<<day<<" "<<mon<<" "<<4713-nian<<" BC"<<endl;
			}
			else cout<<day<<" "<<mon<<" "<<nian<<endl;
		}
		}
		else{
			nian=t/365; mon=t%365+1;
			run=nian/4+1;
			if(nian%4==0){
				mon-=run; mon++;
				if(mon>59) mon--;
				mon+=run;
			}
			run=run/100*99;
			if(run>=365) nian=nian-run/365,run=run%365;
			mon-=run; 
			if(run<0) run=0;
			cnt=0;
			while(mon>yue[++cnt]&&cnt<=12){
				mon=mon-yue[cnt];
			} 
			day=mon; mon=cnt;
			cout<<day<<" "<<mon<<" "<<nian<<endl;
		}
	}
} 
