#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,m,a[1000],s=1;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	
	int maxx=a[n];
	
	while(maxx-a[s]>=a[n-1]){
		
		maxx=maxx-a[s];
		s++;
	}
	cout<<n-s+1<<endl;
    for(int i=2;i<=t;i++)
	{
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			int x,y;
			cin>>x>>y;
			a[x]=y;
		}
		maxx=a[n];
		s=1;
		while(maxx-a[s]>a[n-1]){
			maxx=maxx-a[s];
			s++;
		}
		cout<<n-s+1<<endl;
	}
	return 0;
}
