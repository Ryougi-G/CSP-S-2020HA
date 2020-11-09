#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,q,a[10001],t,b1[10001][10001];
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&t);
		if(t==1){
			b1[i][0]=1;
			scanf("%d%d",&b1[i][1],&b1[i][2]);
		}
		if(t==2){
			b1[i][0]=2;
			scanf("%d",&b1[i][1]);
		}
		if(t==3){
			int v;
			b1[i][0]=3;
			
			scanf("%d",&v);
			
			b1[i][1]=v;
			for(int j=2;j<=v+1;j++)
			scanf("%d",&b1[i][j]);
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int x;
		scanf("%d",&x);
		if(b1[x][0]==1){
			a[b1[x][1]]=a[b1[x][1]]+b1[x][2];
		}
		if(b1[x][0]==2){
			for(int j=1;j<=n;j++)
			{
			a[j]=a[j]*b1[x][1];	
	}

		}
		
		if(b1[x][0]==3){
			for(int j=2;j<=b1[x][1]+1;j++)
			{
				if(b1[b1[x][j]][0]==1){
			    a[b1[b1[x][j]][1]]=a[b1[b1[x][j]][1]]+b1[b1[x][j]][2];
		}
		   if(b1[b1[x][j]][0]==2){
			for(int z=1;z<=n;z++)
			a[z]=a[z]*b1[b1[x][j]][1];
		}
		    
			}
		}
	}
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	//return 0;
}
