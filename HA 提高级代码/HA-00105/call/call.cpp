#incude<bits/stdc++.h
using namespace std;
int main (){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);	
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int m;
	cin>>m>>m1>>m2>>m3>>m4>>m5;
	if(m==1)
	{	
		a[m1]=a[m1]+m2;
	}
	if(m==2)
	{
		for(int t=0;t<n;t++)
		{	
			a[t]=a[t]*m1;
		}
	}
	if(m==3)
	{
		
	}
	return 0;
	}


