#include<bits/stdc++.h>
using namespace std;
int n,a[100010],q[100010],m,c,k;
inline int readint()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return f*x;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=readint();m=readint();c=readint();k=readint();
	int k1=1<<k-1;
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;++i)
	{
		int o=readint(),p=readint();
		for(int j=1;j<=n;++j)
		{
			if(a[j]>>(o-1)-a[j]>>o==1){
				q[o]=1;break;
			}
		}
	}
	int ans=(1<<k)-n;
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
