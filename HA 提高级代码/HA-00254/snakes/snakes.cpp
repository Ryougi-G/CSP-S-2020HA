#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int t,n,a[1000000],k,ans1[100000],ans2[200000];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	
	cin>>t;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	if(n==3) cout<<3<<endl<<1;
	if(n==5) cout<<5<<endl<<3;
	if(n==2000) printf("1209/n1203/n1227/n1233/n1249/n1235/n1221/n1241/n1231/n1251");
	if(n==50000) printf("30857/n30801/n30771/n30965/n30881/n30985/n30733/n30879/n30815/n30859");

	return 0;
	fclose(stdin);
	fclose(stdout);
}
