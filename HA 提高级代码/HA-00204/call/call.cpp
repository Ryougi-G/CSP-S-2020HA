#include <bits/stdc++.h>
#include <cstdio>
#include <stdlib.h>
using namespace std;

int n,m,len;
int data[100005];
int turn[100005];
int han[100005];
int fun[10000][10000];

//void read()
//{
//	
//}

void zuo(int t){
		int i=han[t];
		if(i==1)
		{	
			data[fun[t][1]]+=fun[t][2];
		}
		else if(i==2)
		{
			int num=fun[t][1];
			for(int j=1;j<=n;j++)
			{
				data[j]*=num;
			}
		}
		else if(i==3){
			int num=fun[t][0];
			for(int j=1;j<=num;j++)
			{
				zuo(fun[t][j]);
			}
		}
}

int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
//	freopen("data.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&data[i]);
	}
	cin>>m;
	for(int j=1;j<=m;j++)
	{
		scanf("%d",&han[j]);
		if(han[j]==1)
		{	
			scanf("%d%d",&fun[j][1],&fun[j][2]);
			
		}
		else if(han[j]==2)
		{
			scanf("%d",&fun[j][1]);
		}
		else if(han[j]==3){
			scanf("%d",&fun[j][0]);
			for(int k=1;k<=fun[j][0];k++)
				scanf("%d",&fun[j][k]);
		}
	}
	cin>>len;
	for(int t=1;t<=len;t++){
		scanf("%d",&turn[t]);
		zuo(turn[t]);
	}

	

	for(int k=1;k<=n;k++)
	{
		cout<<data[k]<<" ";
	}
	return 0;
}

