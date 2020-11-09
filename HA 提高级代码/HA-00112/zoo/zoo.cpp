#include<bits/stdc++.h>
using namespace std;
#define ri register int
long long m,n,c,k,tot,sum;
long long a[50005],cre[65][3],cc[50005],vis[50005];
const long long M=50001;
inline long long read()
{
	long long x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void lsh()
{
	
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(),c=read(),k=read();
	for(ri i=1;i<=n;i++)
	a[i]=read();
	while(m--)
	{
		long long x=read(),y=read();
		y=y%M;
		if(cre[x][1]==1)
		cc[y]=cc[cre[x][2]];
		cre[x][1]=1;
		cre[x][2]=y;
		for(ri i=1;i<=n;i++)
		{
			if((a[i]>>x)&1)
			{
				cc[y]=1;
				vis[i]=1;
			}
		}
		if(!cc[y])
		tot++;
	}
	for(ri i=1;i<=n;i++)
	if(vis[i]) sum++;
	//cout<<sum<<endl;
	cout<<(1<<(k-tot))-n;
	return 0;
}
