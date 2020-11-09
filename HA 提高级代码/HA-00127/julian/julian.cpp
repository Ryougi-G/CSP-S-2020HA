#include <bits/stdc++.h>
using namespace std;
int mth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int a[10000005]={0},b[10000005]={0},c[10000005]={0};
int main(){
	freopen ("julian.in","r",stdin);
	freopen ("julian.out","w",stdout);
	int d=1,m=1,y=-4713;
	int gy=1,ok=1;
	for (int j=1;j<=10000000;j++){
		d++;
		int jl=0;
		if (ok==1&&(y+gy)%4==0)jl=1;
		if (ok==1&&d==mth[m]+1&&(jl==0||m!=2)){
			d=1;m++;
		}
		if (ok==1&&jl==1&&m==2&&d==30){
			d=1;m++;
		}
		int rn=0;
		if (ok==0&&(y%4==0&&y%100!=0)||(y%400==0))rn=1;
		if (ok==0&&(rn==0||m!=2)&&d==mth[m]+1){
			d=1;m++;
		}
		if (ok==0&&rn==1&&m==2&&d==30){
			d=1;m++;
		}
		if (m==13){
			m=1;y++;
		}
		if (y==0){
			y++;gy=0;
		}
		if (y==1582&&m==10&&d==4){
			d=14;ok=0;
		}
		a[j]=d;b[j]=m;c[j]=y;
	}
	int q;
	cin>>q;
	for (int i=1;i<=q;i++){
		int r;cin>>r;
		if (c[r]<0){
			cout<<a[r]<<" "<<b[r]<<" "<<-c[r]<<" BC"<<endl;
		}
		else{
			cout<<a[r]<<" "<<b[r]<<" "<<c[r]<<endl;
		}
	}
	return 0;
}
