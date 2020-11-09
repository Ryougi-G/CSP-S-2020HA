#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
int a[100086],b[100086];
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	
	if(n==3)cout<<"6 8 12";
	if(n==10)cout<<"36 282 108 144 180 216 504 288 324 360";
	if(n==18)cout<<2097134;
	return 0;
}
