#include<bits/stdc++.h>
using namespace std;
int hp[50010];
int sum;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t;
	cin>>t;
	int a,b,n;
	for(int tt=0;tt<t;++tt)
	{
		cin>>n;
		if(tt==0)
		{
			sum=n;
			int tot=sum;
			for(int i=0;i<n;++i)
			{
				cin>>hp[i];
			}
		}
		if(tt!=0)
		{
			int tot=sum;
			for(int i=0;i<n;++i)
			{
				cin>>a>>b;
				hp[a-1]=b;
			}
		}
		if(hp[0]>hp[1]+hp[2]||hp[1]-hp[0]>hp[2]||hp[2]>=hp[1]+hp[0]||hp[1]-hp[2]>=hp[0])
		{
			cout<<"1\n";
			continue;
		}
		cout<<"3\n";
	}
	
	return 0;
}
