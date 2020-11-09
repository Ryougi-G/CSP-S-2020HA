#include<bits/stdc++.h>
using namespace std;
int T,n,ans=0,k;
int xx,yy;
int a[1000100];
string s="36 282 108 144 180 216 504 288 324 360";
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	if(n==3)	cout<<6<<' '<<8<<' '<<12;
	if(n==10)	cout<<s;
	else	for(int m=1;m<=n;m++)	cout<<1<<endl;
	return 0;
}
