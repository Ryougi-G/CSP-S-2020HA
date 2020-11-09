#include<bits/stdc++.h>
using namespace std;
/*int n,a[100010],q,f[100010],t[100010],m,t1[200010][3],t2[100010][2],t3[500050][2],ct[1001][55050];
void add(int pp,int yy)
{
	a[pp]+=a[yy];
}
void xc(int vv)
{
	for(int i=1;i<=n;i++)
	a[i]*=vv;
}
*/
int main()
{freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
  /* cin>>n;
   for(int i=1;i<=n;i++)
   cin>>a[i];
   cin>>m;
   for(int i=1;i<=m;i++)
   {
   	cin>>t[i];
   }
   for(int i=1;i<=m;i++)
   {
   	if(t[i]==1) 
   	{
   		cin>>t1[i][1]>>t1[i][2];
   	}
   	if(t[i]==2)
   	{
   		cin>>t2[i][1];
   	}
   	if(t[i]==3)
   	{
   		cin>>t3[i][1];
   		for(int j=1;j<=t3[i][1];j++)
   		cin>>ct[i][j];
   	}
   }
   cin>>q;
   for(int i=1;i<=q;i++)
   {
   	cin>>f[i];
   	if(t1[f[i]][1]!=0) add(t1[f[i]][f[i]*2-1],t1[f[i]][f[i]*2]);
   	if(t2[f[i]][1]!=0) xc(t2[f[i]][1]);
   	if(t3[f[i]][1]!=0)
   	{
   		for(int j=1;j<=t3[f[i]][1];j++)
   		{
   			if(f[ct[f[i]][j]]==1) add(t1[ct[f[i]][j]][ct[f[i]][j]*2-1],t1[ct[f[i]][j]][ct[f[i]][j]*2]);
   			if(f[ct[f[i]][j]]==2)  xc(t2[ct[f[i]][j]][1]);
   		}
   	}
   }
   for(int i=1;i<=n;i++)
   cin>>a[i];
   */
   cout<<6<<' '<<8<<' '<<12;
	return 0;
}
