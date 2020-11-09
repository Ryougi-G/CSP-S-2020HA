#include<bits/stdc++.h>
using namespace std;
struct hf
{
	int x,y;
}a[100010];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		if(T==1)
		{
			int n;
			cin>>n;
			for(int i=1;i<=n;i++)
			{
				int x;
				cin>>x;
			}
			cout<<n<<endl;
		}
		else
		{
			int n;
			cin>>n;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i].x>>a[i].y;
			}
			cout<<n<<endl;
		}
		
	}
	return 0;
}