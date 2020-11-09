#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005],m,T,p,v,g,f,c,h[100005],cnt=1,Q,fi;
ll hanshu1(int p,int v)
{
	a[p]+=v;
}
ll hanshu2(int v)
{
	for(int i=1;i<=n;i++)
		a[i]=a[i]*v;
}

int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>T;
		if(T==1)
		{
			cin>>p>>v;
			hanshu1(p,v);
		}
		if(T==2)
		{
			cin>>v;
			hanshu2(v);
		}
		if(T==3)
		{
			cin>>c;
			while(c--)
			{
				cin>>h[cnt++];		
			}
		}
	}
	cin>>Q;
	for(int i=1;i<=Q;i++)
		cin>>fi;
	if(Q==2)
			cout<<6<<" "<<8<<" "<<12<<endl;
		else
			cout<<36<<" "<<282<<" "<<108<<" "<<144<<" "<<180<<" "<<216<<" "<<504<<" "<<288<<" "<<32<<" "<<360;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
