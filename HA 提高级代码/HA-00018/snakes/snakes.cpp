#include<bits/stdc++.h>
using namespace std;
long long snakes[100000000];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T;
	cin>>T;
	for(int s=1;s<=T;++s)
	{
		long long n,x,y,max,min,m;
		long long i=1,j=1,k=1;
    	cin>>n;
    	for (long long i=1;i<=n;++i)
	      cin>>snakes[i];
    	for (long long i=1;i<=n;++i)
    	  if(snakes[i]>snakes[i+1])
       	      max=snakes[i];
     	  if(snakes[i]==snakes[i+1])
    	      max=snakes[i+1];
         for (long long j=1;j<=n;++j)
           if(snakes[j]<snakes[j+1])
    	      min=snakes[j];
      	 m=max-min;
      	 if (m<snakes[i])
      	   n=n;
      	 else
      	 {
      	   n--;	
      	   for (int k=1;k<=n;++k)
    	      if(m>=snakes[k])
     	        n--;
      	 }
    	 cout<<n<<endl;
	}
    return 0;
}
