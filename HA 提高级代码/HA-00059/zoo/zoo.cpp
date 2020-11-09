#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
int t;
long long a[50];
int p,q;
long long Meet;
long long Pow[60],u[60],s[60];
void Math(int n)
{
	Pow[0]=1;
	for(int i=1;i<=n;i++)
	Pow[i]=Pow[i-1]*2;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);	
	cin>>n>>m>>c>>k;
	Math(k);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	long long ans=Pow[k];
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&p,&q);
		bool flag=0;
		for(int j=1;j<=n;j++)
		{
			if((p==0&&(a[j]&1==1))||a[j]>>p&1==1)
			{
				flag=1;
				if(u[q]==0)
				{
					u[q]=1;
					Meet++;
				}
				if(s[j]==0)
				{
					s[j]=1;		
					t++;		
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	ans-=Pow[k-i];
	cout<<ans;
	return 0;
}

