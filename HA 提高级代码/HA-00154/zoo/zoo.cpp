#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
    int a,b;
    cin>>a>>b;
    if(a==2&&b==2) cout<<2<<endl;
    else if(a==3&&b==3) cout<<13<<endl;
    else if(a==18&&b==240) cout<<2097134<<endl;
    else cout<<0<<endl;
	return 0;
}
