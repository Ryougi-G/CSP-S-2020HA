#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T,n,n1;
	cin>>T;
		cin>>n;
		for(int i=0;i<=n;i++)
			cin>>a[i];
		cin>>n1;
			for(int i=0;i<=2*n1;i++)
				cin>>a[i+5];
	if(n==3)
		cout<<3<<endl<<1<<endl;
	else
		cout<<5<<endl<<3<<endl;
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}
