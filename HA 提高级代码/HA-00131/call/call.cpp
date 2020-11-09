#include<cstdio>
using namespace std;
int i,ii,iii,n,s,a[100001],m,t[100001][3],all=0,f[100001],q;
int call1(int aa,int bb)
{a[aa]=(a[aa+]bb)%998244353;
};
int call2(int aa)
{
	for(iii=1;iii<=n;iii++)
	a[iii]=a[iii]*aa%998244353;
};
int call3(int s)
{
	for(ii=t[s][1];ii<=t[s][2];ii++)
      {	
      	if(t[f[ii]][0]==1)call1(t[f[ii]][1],t[f[ii]][2]);
      else if(t[f[ii]][0]==2)call2(t[f[ii]][1]);
      else if(t[f[ii]][0]==3)call3(f[ii]);
  };
};
int main()
{
	freopen("call.in","r",stdin);
    //freopen("call.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
      {
      scanf("%d",&t[i][0]);
      if(t[i][0]==1)scanf("%d%d",&t[i][1],&t[i][2]);
      else if(t[i][0]==2)scanf("%d",&t[i][1]);
      else if(t[i][0]==3)
	   {
       scanf("%d",&t[i][2]);
	   t[i][1]=all+1;
       all=t[i][2]+all;
       t[i][2]=all;
       for(ii=t[i][1];ii<=t[i][2];ii++)
       scanf("%d",&f[ii]);
	   };
	  };
	   scanf("%d",&q);	
	for(i=1;i<=q;i++)
	 {	 scanf("%d",&s);
	   if(t[s][0]==1)call1(t[s][1],t[s][2]);
      else if(t[s][0]==2)call2(t[s][1]);
      else if(t[s][0]==3)
      for(ii=t[s][1];ii<=t[s][2];ii++)
      {
      	if(t[f[ii]][0]==1)call1(t[f[ii]][1],t[f[ii]][2]);
      else if(t[f[ii]][0]==2)call2(t[f[ii]][1]);
     else if(t[f[ii]][0]==3)call3(f[ii]);
      };
	};
	  
for(i=1;i<=n;i++)
      printf("%d ",a[i]);	
    fclose(stdin);
    fclose(stdout);
	return 0;
};
