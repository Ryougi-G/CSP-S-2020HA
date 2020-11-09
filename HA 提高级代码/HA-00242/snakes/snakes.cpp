#include<bits/stdc++.h>
using namespace std;
int T,n,a[1000010],k;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
       if(i==1)
       {
       	 cin>>n;
       	 for(int j=1;j<=n;j++)
       	   cin>>a[j];
       }
	   else
	   {
	   	  cin>>k;
	   	  int x1,y1;
	   	  for(int j=1;j<=2*k;j++)
	   	  {
	   	  	 cin>>x1>>y1;
	   	  	 a[x1]=y1;
	   	  }
	   }
	   int r=n,l=1;
	   while(a[r]-a[l]>a[l+1])
	   {
	   	 a[r]-=a[i]
	   }
	}
	return 0;
}
