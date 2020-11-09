#include<bits/stdc++.h>
using namespace std;
long long n,m,c,k,a[1919810],p[1919810],q[1919810],sl[1919810],sum,ans=0;
int main() {
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	memset(sl,0x3f,sizeof(sl));
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) 
	  {
	   cin>>p[i]>>q[i];
	   sl[p[i]]+=1<<q[i];
		}
	for(int i=1;i<=n;i++)
	  {
	  	int t=a[i];
	  	int num=0;
	  	while(t)
	  	  {
	  	    if(t&1)
	  	      {
	  	      	sum|=sl[num];
	  	      }
	  	    num++;
	  	    t>>=1;
	  	  }
	  }
	for(int i=0;i<=1<<k-1;i++)
	  {
	  	int t=i,num=0;
	  	bool st=true;
	  	while(t)
	  	 {
	  	   if(t&1)
	  	   	if((sum|sl[num])!=sum) 
	  	     	{
	  	     		st=false;
	  	     		t=0;
	  	     	}
	  	    t>>=1;
	  	    num++;
	  	 }
	  	 if(st==true) ans++;
	  }
	cout<<ans-n-1;
	return 0;
}
