#include <bits/stdc++.h>
using namespace std;

int data[1000005];
int f[10005][10005];
void solve()
{
	for(int i=1;i<=n;i++){
		
	}
}

int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int n,t;
	int g1,g2;
	int k;
	cin>>t;
	for(int j=1;j<=t;j++){
		if(t==1){
			cin>>n;
			for(int i=1;i<=n;i++)
			scanf("%d",&data[i]);
			solve();
		}
		else{
			scanf("%d",&k);
			for(int i=i;i<=k;i++);
			{
				scanf("%d%d",&g1,&g2);
				data[g1]=g2;
			}
			solve();
		}
		
	}
	for(int i=1;i<=t;i++ )	
		cout<<data[t]%10;
	
	return 0;
}

