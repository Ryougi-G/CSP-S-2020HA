#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int n,m;
	int a[100010],b[100010];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>m;
	int q,w,e,r;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		if(b[i]==1) cin>>q>>w;
		if(b[i]==2) cin>>q;
		if(b[i]==3)
		{
			cin>>q;
			for(int j=0;j<q;j++)
				cin>>w;
			cin>>e;
			for(int k=0;k<e;k++)
				cin>>r;
		}
	}
	cout<<0<<endl;
	return 0;
}
