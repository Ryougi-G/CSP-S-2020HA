#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a0;
	int a1;
	int a2;
	int a3;
	int a4;
	int a5;
	int a6;
}a[106];
int n,m,c,k,a1[100086],p,q,sum;
bool a2[100086];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	a[1].a0=1;
	a[1].a1=0;
	a[1].a2=0;
	a[1].a3=0;
	a[1].a4=0;
	a[1].a5=0;
	a[1].a6=0;
	
	a[2].a0=0;
	a[2].a1=1;
	a[2].a2=0;
	a[2].a3=0;
	a[2].a4=0;
	a[2].a5=0;
	a[2].a6=0;
	
	a[3].a0=1;
	a[3].a1=1;
	a[3].a2=0;
	a[3].a3=0;
	a[3].a4=0;
	a[3].a5=0;
	a[3].a6=0;
	
	a[4].a0=0;
	a[4].a1=0;
	a[4].a2=1;
	a[4].a3=0;
	a[4].a4=0;
	a[4].a5=0;
	a[4].a6=0;
	
	a[5].a0=1;
	a[5].a1=0;
	a[5].a2=1;
	a[5].a3=0;
	a[5].a4=0;
	a[5].a5=0;
	a[5].a6=0;
	
	a[6].a0=0;
	a[6].a1=1;
	a[6].a2=1;
	a[6].a3=0;
	a[6].a4=0;
	a[6].a5=0;
	a[6].a6=0;
	
	a[7].a0=1;
	a[7].a1=1;
	a[7].a2=1;
	a[7].a3=0;
	a[7].a4=0;
	a[7].a5=0;
	a[7].a6=0;
	
	a[8].a0=0;
	a[8].a1=0;
	a[8].a2=0;
	a[8].a3=1;
	a[8].a4=0;
	a[8].a5=0;
	a[8].a6=0;
	
	a[9].a0=1;
	a[9].a1=0;
	a[9].a2=0;
	a[9].a3=1;
	a[9].a4=0;
	a[9].a5=0;
	a[9].a6=0;
	
	a[10].a0=0;
	a[10].a1=1;
	a[10].a2=0;
	a[10].a3=1;
	a[10].a4=0;
	a[10].a5=0;
	a[10].a6=0;
	
	a[11].a0=1;
	a[11].a1=1;
	a[11].a2=0;
	a[11].a3=1;
	a[11].a4=0;
	a[11].a5=0;
	a[11].a6=0;
	
	a[12].a0=0;
	a[12].a1=0;
	a[12].a2=1;
	a[12].a3=1;
	a[12].a4=0;
	a[12].a5=0;
	a[12].a6=0;
	
	a[13].a0=1;
	a[13].a1=0;
	a[13].a2=1;
	a[13].a3=1;
	a[13].a4=0;
	a[13].a5=0;
	a[13].a6=0;
	
	a[14].a0=0;
	a[14].a1=1;
	a[14].a2=1;
	a[14].a3=1;
	a[14].a4=0;
	a[14].a5=0;
	a[14].a6=0;
	
	a[15].a0=1;
	a[15].a1=1;
	a[15].a2=1;
	a[15].a3=1;
	a[15].a4=0;
	a[15].a5=0;
	a[15].a6=0;
	
	a[16].a0=0;
	a[16].a1=0;
	a[16].a2=0;
	a[16].a3=0;
	a[16].a4=1;
	a[16].a5=0;
	a[16].a6=0;
	//
	a[17].a0=1;
	a[17].a1=0;
	a[17].a2=0;
	a[17].a3=0;
	a[17].a4=1;
	a[17].a5=0;
	a[17].a6=0;
	
	a[18].a0=0;
	a[18].a1=1;
	a[18].a2=0;
	a[18].a3=0;
	a[18].a4=1;
	a[18].a5=0;
	a[18].a6=0;
	
	a[19].a0=1;
	a[19].a1=1;
	a[19].a2=0;
	a[19].a3=0;
	a[19].a4=1;
	a[19].a5=0;
	a[19].a6=0;
	
	a[20].a0=0;
	a[20].a1=0;
	a[20].a2=1;
	a[20].a3=0;
	a[20].a4=1;
	a[20].a5=0;
	a[20].a6=0;
	
	a[21].a0=1;
	a[21].a1=0;
	a[21].a2=1;
	a[21].a3=0;
	a[21].a4=1;
	a[21].a5=0;
	a[21].a6=0;
	
	a[22].a0=0;
	a[22].a1=1;
	a[22].a2=1;
	a[22].a3=0;
	a[22].a4=1;
	a[22].a5=0;
	a[22].a6=0;
	
	a[23].a0=1;
	a[23].a1=1;
	a[23].a2=1;
	a[23].a3=0;
	a[23].a4=1;
	a[23].a5=0;
	a[23].a6=0;
	
	a[24].a0=0;
	a[24].a1=0;
	a[24].a2=0;
	a[24].a3=1;
	a[24].a4=1;
	a[24].a5=0;
	a[24].a6=0;
	
	a[25].a0=1;
	a[25].a1=0;
	a[25].a2=0;
	a[25].a3=1;
	a[25].a4=1;
	a[25].a5=0;
	a[25].a6=0;
	
	a[26].a0=0;
	a[26].a1=1;
	a[26].a2=0;
	a[26].a3=1;
	a[26].a4=1;
	a[26].a5=0;
	a[26].a6=0;
	
	a[27].a0=1;
	a[27].a1=1;
	a[27].a2=0;
	a[27].a3=1;
	a[27].a4=1;
	a[27].a5=0;
	a[27].a6=0;
	
	a[28].a0=0;
	a[28].a1=0;
	a[28].a2=1;
	a[28].a3=1;
	a[28].a4=1;
	a[28].a5=0;
	a[28].a6=0;
	
	a[29].a0=1;
	a[29].a1=0;
	a[29].a2=1;
	a[29].a3=1;
	a[29].a4=1;
	a[29].a5=0;
	a[29].a6=0;
	
	a[30].a0=0;
	a[30].a1=1;
	a[30].a2=1;
	a[30].a3=1;
	a[30].a4=1;
	a[30].a5=0;
	a[30].a6=0;
	
	a[31].a0=1;
	a[31].a1=1;
	a[31].a2=1;
	a[31].a3=1;
	a[31].a4=1;
	a[31].a5=0;
	a[31].a6=0;
	
	a[32].a0=0;
	a[32].a1=0;
	a[32].a2=0;
	a[32].a3=0;
	a[32].a4=0;
	a[32].a5=1;
	a[32].a6=0;
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i];
	}
	int kk=pow(2,k);
	for(int i=1;i<=m;i++)
	{
		cin>>p>>q;
		if(p==0)
		{
			for(int i=1;i<=kk;i++)
			{
				if(a[i].a0==1)
				{
					a2[i]=1;
				}
			}
		}
		if(p==1)
		{
			for(int i=1;i<=kk;i++)
			{
				if(a[i].a1==1)
				{
					a2[i]=1;
				}
			}
		}
		if(p==2)
		{
			for(int i=1;i<=kk;i++)
			{
				if(a[i].a2==1)
				{
					a2[i]=1;
				}
			}
		}
		if(p==3)
		{
			for(int i=1;i<=kk;i++)
			{
				if(a[i].a3==1)
				{
					a2[i]=1;
				}
			}
		}
		if(p==4)
		{
			for(int i=1;i<=kk;i++)
			{
				if(a[i].a4==1)
				{
					a2[i]=1;
				}
			}
		}
		if(p==5)
		{
			for(int i=1;i<=kk;i++)
			{
				if(a[i].a5==1)
				{
					a2[i]=1;
				}
			}
		}
		if(p==6)
		{
			for(int i=1;i<=kk;i++)
			{
				if(a[i].a6==1)
				{
					a2[i]=1;
				}
			}
		}
	}
	for(int i=1;i<=kk;i++)
	{
		if(a2[i]==1)
		sum++;
	}
	cout<<sum-n;
	return 0;
}
