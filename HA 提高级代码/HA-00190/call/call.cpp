#include<bits/stdc++.h>
using namespace std;
int wyh()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return f*x;
}
int n,m,t[110000],q;
int x[110000],y[110000],z[110000],c[1100000];
int a[110000],f[1100000],zhi[110000];
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.ans","w",stdout);
	n=wyh();
	for(int i=1;i<=n;i++){a[i]=wyh();}
	m=wyh();
	for(int i=1;i<=m;i++)
	{
		t[i]=wyh();
		if(t[i]==1){x[i]=wyh();y[i]=wyh();}
		if(t[i]==2){z[i]=wyh();}
		if(t[i]==3){c[i]=wyh();for(int j=1;j<=c[i];j++){f[j]=wyh();}}	
	}
	q=wyh();
	for(int i=1;i<=q;i++){zhi[i]=wyh();}
	for(int ii=1;ii<=q;ii++)
	{
		for(int i=1;i<=m;i++)
		{
			if(t[zhi[ii]]==1)
			{
				for(int j=1;j<=n;j++)
				{
					a[x[zhi[ii]]]=(a[x[zhi[ii]]]+y[zhi[ii]])%998244353;break;
				}
			}
			if(t[zhi[ii]]==2)
			{
				for(int j=1;j<=n;j++)
				{
					a[j]=a[j]*z[zhi[ii]]%998244353;
				}
			}
			if(t[zhi[ii]]==3)
			{
				for(int j=1;j<=c[zhi[ii]];j++)
				{
					if(t[f[j]]==1)
					{
						for(int jj=1;jj<=n;jj++)
				        {
					        a[x[f[j]]]=(a[x[f[j]]]+y[f[j]])%998244353;break;
				        }
					}
					if(t[f[j]]==2)
					{
						for(int jj=1;jj<=n;jj++)
				        {
					        a[jj]=a[jj]*z[f[j]]%998244353;
				        }
					}
				}
			}
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]%998244353);
	}
	fclose(stdin);fclose(stdout);
}
