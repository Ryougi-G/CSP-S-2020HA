#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("julain","r",stdin);
	freopen("julain","w",stdout);
	long long i,m,n,y,r;
		cin>>m;
	for(i=1;i<=m;i++)
	{
	if(1<=m<365)
	{
		n=4713;
		y=(m/30)+1;
		r=(m%30)+1;
	}
	
	else
	{
		break;
	} 	
	if(365<=m<10000000)
	{
		n=4713-(m/365);
		y=((m%365)/30 )+1;
		r=((m%365)%30)+1;
	}
    }
    	cout<<r<<" "<<y<<" "<<n<<" "<<"BC";
		cout<<endl;
	return 0;
}
