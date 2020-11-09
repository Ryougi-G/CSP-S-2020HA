#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,y=1;
	//scanf("%d",&x);return x;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=10*x+ch-'0';
		ch=getchar();
	}
	//cout<<x<<'K'<<endl;
	return x;
}
int n,m;
int cz[100000][3],G[3000000],ttg;
long long datt[100000];
inline void n1(int tt)
{
	
	datt[cz[tt][1]-1]=(datt[cz[tt][1]-1]+cz[tt][2]%998244353)%998244353;
	return;	
}
inline void n2(int tt)
{
	//long long vv=read()%998244353;
	for(int i=0;i<n;++i) datt[i]=(datt[i]*(cz[tt][1])%998244353)%998244353;
	return;	
}
inline void zx(int t)
{
	if(cz[t][0]==1)
	{
		n1(t);
	}
	if(cz[t][0]==2)
	{
		n2(t);
	}

	for(int i=cz[t][1];i<=cz[t][2];i+=3)
	{
		
		if(G[i]==1)
		{
			datt[G[i+1]-1]=(datt[G[i+1]-1]+G[i+2]%998244353)%998244353;
		}
		else
		{
			for(int pp=0;pp<n;++pp) datt[pp]=(datt[pp]*(G[i+1]%998244353))%998244353;
		}
	}
	return;
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(int i=0;i<n;++i) datt[i]=read();
	m=read();
	for(int i=0,o=0;i<m;++i) 
	{
		cz[i][0]=read();
		if(cz[i][0]==1)
		{
			cz[i][1]=read();
			cz[i][2]=read();
			continue;
		}
		if(cz[i][0]==2)
		{
			cz[i][1]=read();
			continue;
		}
		o=read();
		cz[i][1]=ttg;
		for(int jj=0;jj<o;++jj)
		{
			G[ttg]=read();
			if(G[ttg]==1)
			{
				G[++ttg]=read();
				G[++ttg]=read();
				ttg++;
			}
			else
			{
				G[++ttg]=read();
				//G[++ttg]=read();
				ttg+=2;
			}
			
		}
		cz[i][2]=ttg-1;
		
		
	}
	int osr=read();
	for(int i=0,sd=0;i<osr;++i)
	{
		sd=read();
		zx(sd);
	}
	for(int i=0;i<n;++i)
	{
		printf("%d ",datt[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
