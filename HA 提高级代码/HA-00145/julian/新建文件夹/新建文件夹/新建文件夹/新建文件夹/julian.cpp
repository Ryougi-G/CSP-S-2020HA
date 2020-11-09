#include<bits/stdc++.h>
using namespace std;
int i;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int n;
	cin>>n;
string a[2222];
	for( i=1;i<=n;i++)
       {
        	cin>>a[i];
        	 if(a[i]<365)
    {
    	int x=a/30;
    	int y=a%30;
    	cout<<1+y<<" "<<1+x<<" "<<4173;
    }
          }
    if(a[i]<365)
    {
    	int x=a/30;
    	int y=a%30;
    	cout<<1+y<<" "<<1+x<<" "<<4173;
    }
	return 0;
}
