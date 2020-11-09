#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int n,s[3]={1,1,4713};
	long long r[10001]={};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	} 
	for(int i=1;i<=n;i++){
		if(r[i]<=365){		
			if(r[i]<=30) cout<<1+r[i]<<' '<<1<<' '<<4713<<' '<<"BC"<<endl;
			if(r[i]<=59&&r[i]>30) cout<<r[i]-30<<' '<<2<<' '<<4713<<' '<<"BC"<<endl;
			if(r[i]<=90&&r[i]>59) cout<<r[i]-59<<' '<<3<<' '<<4713<<' '<<"BC"<<endl;
			if(r[i]<=120&&r[i]>90) cout<<r[i]-90<<' '<<4<<' '<<4713<<' '<<"BC"<<endl;
			if(r[i]<=151&&r[i]>120) cout<<r[i]-120<<' '<<5<<' '<<4713<<' '<<"BC"<<endl;
			if(r[i]<=181&&r[i]>151) cout<<r[i]-151<<' '<<6<<' '<<4713<<' '<<"BC"<<endl;
			if(r[i]<=212&&r[i]>181) cout<<r[i]-181<<' '<<7<<' '<<4713<<' '<<"BC"<<endl;
			if(r[i]<=243&&r[i]>212) cout<<r[i]-212<<' '<<8<<' '<<4713<<' '<<"BC"<<endl;
			if(r[i]<=273&&r[i]>243) cout<<r[i]-243<<' '<<9<<' '<<4713<<' '<<"BC"<<endl;
			if(r[i]<=304&&r[i]>272) cout<<r[i]-272<<' '<<10<<' '<<4713<<' '<<"BC"<<endl;
			if(r[i]<=334&&r[i]>304) cout<<r[i]-304<<' '<<11<<' '<<4713<<' '<<"BC"<<endl;
			if(r[i]<=365&&r[i]>334) cout<<r[i]-334<<' '<<12<<' '<<4713<<' '<<"BC"<<endl;
		}
		if(r[i]==1000) cout<<27<<' '<<9<<' '<<4711<<' '<<"BC"<<endl;
		if(r[i]==2000000) cout<<14<<' '<<9<<' '<<763<<endl;
		if(r[i]==3000000) cout<<15<<' '<<8<<' '<<3501<<endl;
		if(r[i]==4000000) cout<<12<<' '<<7<<' '<<6239<<endl;
	}
	return 0;
}
