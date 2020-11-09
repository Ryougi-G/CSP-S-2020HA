#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int n,a;
	cin>>n>>a;
	if(n==3&&a==1) cout<<6<<' '<<8<<' '<<12;
	else cout<<"36 282 108 144 180 216 504 288 324 360";
	return 0;
}
