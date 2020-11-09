#include<bits/stdc++.h>
using namespace std;
long long p[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
long long ru[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	long long t,n,y,m,r,is;
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=1721423){
		    y=4713;m=1;r=1;
			y-=4*(n/1461);
			n-=(n/1461)*1461;
			if(n>=366){
				n-=365;
				m=12;r=31;}
			else{
				r+=n;
				while(r>ru[m]){
					r-=ru[m];
					m++;
				}
				cout<<r<<" "<<m<<" "<<y<<" BC"<<endl;
				continue;}
			while(n>=365){n-=365;y--;}
			r+=n;
			while(r>ru[m]){r-=p[m];m++;if(m==13){m=1;y--;}}
			cout<<r<<" "<<m<<" "<<y<<" BC"<<endl;
			continue;}
		else{
			n-=1721424;
			y=1;m=1;r=1;
			is=0;
			if(n<=577736){
				while(n>=365&&y%4==0||n>=366&&y%4!=0){
					if(y%4!=0){
						n-=365;
					}
					else{
						n-=366;
					}
					y++;
				}
				if(y%4==0){
				r+=n;
				while(r>ru[m]){
					r-=ru[m];m++;}
				cout<<r<<" "<<m<<" "<<y<<endl;
				continue;}
			    else{
				r+=n;
				while(r>ru[m]){
					r-=p[m];
					m++;}
				cout<<r<<" "<<m<<" "<<y<<endl;
				continue;}}
			else{
				n-=577737;
				y=1582;m=10;r=15;
			    while(n>=365&&is==0||n>=366&&is==1){
				    if(is==0){n-=365;y++;}
				    else{n-=366;y++;}
				    if(y%4==0&&y%100!=0){is=1;}
				    else if(y%400==0){is=1;}
				    else{is=0;}}
				r+=n;
				while(r>ru[m]){
					if(is==0){
						r-=p[m];
					}
					else{
						r-=ru[m];
					}
					m++;
					if(m==13){m=1;y++;}
					if(y%4==0&&y%100!=0){is=1;}
				    else if(y%400==0){is=1;}
				    else{is=0;}
					}
				cout<<r<<" "<<m<<" "<<y<<endl;
				continue;}}}
	return 0;
}
