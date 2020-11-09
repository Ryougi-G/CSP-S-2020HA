#include<bits/stdc++.h>
using namespace std;
long long julian;
int y,m,d,t,n;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>julian;
		y=julian;
		int ii=0;
		while(y>=0){
			if (ii%4==0&&ii>0) y-=366;
			else y-=365;
			ii++;
		}
		if ((ii-1)%4==0&&(ii-1>0)) y+=366;
		else y+=365;
		julian=y;
		if (julian>=0&&julian<=30) d=1,m=julian;
		if (julian>=31&&julian<=59) d=2,m=julian-31;
		if (julian>=60&&julian<=90) d=3,m=julian-60;
		if (julian>=91&&julian<=120) d=4,m=julian-91;
		if (julian>=121&&julian<=151) d=5,m=julian-121;
		if (julian>=152&&julian<=181) d=6,m=julian-152;
		if (julian>=182&&julian<=212) d=7,m=julian-182;
		if (julian>=213&&julian<=243) d=8,m=julian-213;
		if (julian>=244&&julian<=273) d=9,m=julian-244;
		if (julian>=274&&julian<=304) d=10,m=julian-274;
		if (julian>=305&&julian<=334) d=11,m=julian-305;
		if (julian>=335&&julian<=365) d=12,m=julian-335;
		if ((4713-ii+1)<0){
				cout<<m+1<<' '<<d<<' '<<abs(4713-ii)<<endl;
		}else{
				cout<<m+1<<' '<<d<<' '<<4713-ii+1<<' '<<"BC"<<endl;
		}
	}
	return 0;
}
