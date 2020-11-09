#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>t;
	srand(time(NULL));
	for(int i=1;i<=t;i++)
	{
		cout<<rand()%(i+100)<<endl;
	}
	return 0;
}
