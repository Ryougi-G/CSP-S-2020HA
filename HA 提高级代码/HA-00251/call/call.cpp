#include<bits/stdc++.h>
using namespace std;
int n,m,c[100010];
inline int readint()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return f*x;
}
int h[100010];
struct node{
	int x,y;
}f1[100010];
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=readint();
	for(int i=1;i<=n;++i) c[i]=readint();
	m=readint();
	for(int i=1;i<=m;++i)
	{
		int tot=readint();
		if(tot==1) {
			int q=readint();
		}
		if(tot==2) {
			int q=readint();
		}
	}
	for(int i=1;i<=n;++i) cout<<i;
	fclose(stdin);fclose(stdout);
	return 0;
}
