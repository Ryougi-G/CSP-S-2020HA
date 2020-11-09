#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define ull long long
inline ull read()
{
	ull x=0;
	char c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
const int maxn=1,maxm=1000007;
int n,m,c,k,p[71],q,s[maxm],b[maxm],v[maxm],t[maxm];
int hup;
unsigned long long su,h;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read();
	m=read();
	c=read();
	k=read();
	for(rint i=1;i<=n;i++)
	{
		su=read();
		q=0;
		while(su)
		{
			if(su&1)
			p[q]=1;
			su=su>>1;
			q++;
		}
	}
	for(rint i=1;i<=m;i++)
	{
		s[i]=read();
		b[i]=read();
		t[i]=b[i];
	}
	sort(t+1,t+m+1);
	int nn=unique(t+1,t+m+1)-t-1;
	for(rint i=1;i<=m;i++)
	{
		b[i]=lower_bound(t+1,t+nn+1,b[i])-t;
		if(p[s[i]])
		v[b[i]]=1;
	}
	for(rint i=1;i<=m;i++)
	{
		if(!v[b[i]])
		p[s[i]]=-1;
	}
	h=1;
	for(rint i=0;i<k;i++)
	{
		if(p[i]!=-1)
		h=h*2;
	}
	h=h-n;
	cout<<h;
	return 0;
}
