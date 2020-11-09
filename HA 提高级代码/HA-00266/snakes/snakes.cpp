#include<bits/stdc++.h>
using namespace std;
int t,m;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t>>m;
	srand(time(NULL));
	for(int i=1;i<=t;i++)
	{
		cout<<rand()%(m+1)<<endl;
	}
	return 0;
}
