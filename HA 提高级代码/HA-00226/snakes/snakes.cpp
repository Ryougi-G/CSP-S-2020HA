#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int n,t;
	cin>>t>>n;
	if(t==1)
	cout<<n;
	else
	{
		cout<<n<<endl<<n-2;
	}
	return 0;
}
