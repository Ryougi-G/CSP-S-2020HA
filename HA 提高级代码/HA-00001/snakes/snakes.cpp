#include<bits/stdc++.h>
using namespace std;
long long t,n,b[1000],c[1000],l,p=0,m,h=0;
int main(){
freopen("snakes.in","r",stdin);
freopen("snakes.out","w",stdout);
cin>>t;
for(int q=1;q<=t;q++)
{
	scanf("%lld",&n);
	for(int w=1;w<=n;w++)
	{
		h==0;
		if(q==1)
		{
			m=n;
			cin>>b[w];
			p=p+b[w];
		}else
		{
			cin>>l;int k=b[l];
			cin>>b[l];
			p=p-k+b[l];
		}
		for(int w=1;w<=m;w++)
		{
			if(b[w]>0.5*p)
			{
				cout<<"1"<<endl;h++; 
			}
		}
		if(h==0)
		{
			cout<<"3"<<endl;
		}
	}
	
}
return 0;
}
