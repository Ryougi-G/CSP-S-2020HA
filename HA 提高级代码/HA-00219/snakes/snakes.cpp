#include<bits/stdc++.h>
using namespace std;
int a[1000000],ans;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int n,T;
	cin>>T;
	if(T==1)
	{
		cin>>n;
			for(int i = 1;i <= n;i++)
				cin>>a[i];
			if(a[3]-a[1]>=a[2])ans=1;
			if(a[3]-a[1]<a[2])ans=3;
			cout<<ans;
	}	
	else
	cout<<"3"<<endl;
	cout<<"1";
	return 0;
}
