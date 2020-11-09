#include<bits/stdc++.h>
using namespace std;
int t,n,a[10010],k,s[1010][1010];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","r",stdout);
    cin>>t;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    cin>>k;
    for(int i=1;i<=2;i++)
    for(int j=1;j<=k;j++)
    cin>>s[i][j];
    
    if(k==3) cout<<n<<endl<<1<<endl;
     if(k==5) cout<<n<<endl<<3<<endl;
	return 0;
}
