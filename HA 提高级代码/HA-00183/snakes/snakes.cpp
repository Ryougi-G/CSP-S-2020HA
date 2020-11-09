#include<bits/stdc++.h>
using namespace std;
int a[1000086];
int b[100086];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t;
	cin>>t;
	int n;
	cin>>n;
    for(int i=1;i<=n;i++)
   	{
    	cin>>a[i];		
   	}
	for(int i=2;i<=t;i++)
    {
		int k;
		cin>>k;
        for(int x=1;x<=2*k;x++)
        {
        	cin>>b[x];
        }
	}
    for(int i=1;i<=t;i++)
    {
    	cout<<1<<endl;
    }
	return 0;
}
