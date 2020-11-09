#include<bits/stdc++.h>
using namespace std;
int n,a[100010],m,b[100010];
inline int readint()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return f*x;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	n=readint();m=readint();
	for(int i=1;i<=m;++i)
	a[i]=readint(),b[i]=a[i];
	int cnt=1;
	while(b[m]-b[cnt]>=b[m-1])
	{
		b[m]-=b[cnt];
		cnt++;
	}
	printf("%d\n",(m-cnt+1));
	for(int i=2;i<=n;++i)
	{
		int m1=readint();
		for(int i=1;i<=m1;++i)
		{
			int c=readint(),d=readint();
		    a[c]=d;
		}
		for(int i=1;i<=m;++i) {b[i]=a[i];cout<<b[i];}
		int cnt1=1;
	    while(b[m1]-b[cnt1]>=b[m1-1])
	    {
		    b[m1]-=b[cnt1];
		    cnt1++;
	    }
	    printf("%d\n",(m1-cnt1+1));
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
