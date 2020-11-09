#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int py=365*4+1;
int pan(int s){
	bool bol=1;
	int y=s/py;
	s=s-y*py;
	if(s/366==0){
		bol=0;
	}
	else{
		s=s-366;
		y=y*4;
		y=y+s/365+1;
		s=s%365;
	}
	                   
	s=s+1;
	if(s<=31){cout<<s<<" "<<1;return y;}s=s-31;
	if(bol==0){
		if(s<=29){cout<<s<<" "<<2;return y;}
		s=s-29;
	}
	else{
		if(s<=28){cout<<s<<" "<<2;return y;}
		s=s-28;
	}
	if(s<=31){cout<<s<<" "<<3;return y;}s=s-31;
	if(s<=30){cout<<s<<" "<<4;return y;}s=s-30;
	if(s<=31){cout<<s<<" "<<5;return y;}s=s-31;//5
	if(s<=30){cout<<s<<" "<<6;return y;}s=s-30;
	if(s<=31){cout<<s<<" "<<7;return y;}s=s-31;
	if(s<=31){cout<<s<<" "<<8;return y;}s=s-31;
	if(s<=30){cout<<s<<" "<<9;return y;}s=s-30;
	if(s<=31){cout<<s<<" "<<10;return y;}s=s-31;
	if(s<=30){cout<<s<<" "<<11;return y;}s=s-30;
	cout<<s<<" "<<12;return y;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		int x;
		cin>>x;
		int y=pan(x);
		int ans=4713-y;
		if(ans>=1){
			cout<<" "<<ans<<" BC"<<endl;
		}
		else cout<<" "<<-1*ans+1<<endl;
	}
	
}
//priority_queue<int, vector<int>,greater<int> >p;
//cout<<fixed<<setprecision();
