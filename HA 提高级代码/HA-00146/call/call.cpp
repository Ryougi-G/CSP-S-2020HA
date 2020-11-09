#include<bits/stdc++.h>
#define rint register int
using namespace std;
int p[400005],tot,q[400005],a[100005],l,x;
int n,m,t[100005],c[100005],u[100005],v[100005],w[100005];
int h[100005],nxt[1000005],go[1000005];
int s[400005];
void ad(int k,int l,int r,int v)
{
	p[k]+=v;
	s[k]=s[k]+v*(r-l+1);
}
void xd(int k,int l,int r,int v)
{
	p[k]=p[k]*v;
	q[k]=q[k]*v;
	s[k]=s[k]*v;
}
void pushdown(int k,int l,int r)
{
	if(q[k]!=1)
	{
		int mid=l+r>>1;
		xd(k*2,l,mid,q[k]);
		xd(k*2+1,mid+1,r,q[k]);
	}
	q[k]=1;
	if(p[k])
	{
		int mid=l+r>>1;
		ad(k*2,l,mid,p[k]);
		ad(k*2+1,mid+1,r,p[k]);
	}
	p[k]=0;
}
void jia(int k,int l,int r,int xx,int yy,int v)
{
	if(l>=xx&&r<=yy) 
	{
		p[k]+=v;s[k]=s[k]+(r-l+1)*v;//cout<<l<<" "<<r;
		return;
	}
	int mid=l+r>>1;
	//cout<<mid;
	pushdown(k,l,r);
	if(mid>=xx) jia(k*2,l,mid,xx,yy,v);
	if(mid<yy) jia(k*2+1,mid+1,r,xx,yy,v);
	s[k]=s[k*2]+s[k*2+1];
}
void cheng(int k,int l,int r,int xx,int yy,int v)
{
	if(l>=xx&&r<=yy) 
	{
		q[k]*=v;s[k]=s[k]*v;
	}
}
void se(int k)
{
	for(rint j=h[k];j;j=nxt[j])
	{
		rint y=go[j];
		if(t[y]==3) se(y);
		else if(t[y]==1) jia(1,1,n,u[y],u[y],v[y]);
		else cheng(1,1,n,1,n,c[y]);
	//	cout<<y<<' ';
	}
}
int sum(int k,int l,int r,int xx,int yy)
{
	if(l>yy||r<xx) return 0;
	if(l>=xx&&r<=yy) return s[k];
	int mid=l+r>>1;
	pushdown(k,l,r);
	int res=0;
	if(mid>=xx) res+=sum(k*2,l,mid,xx,yy);
	if(mid<yy) res+=sum(k*2+1,mid+1,r,xx,yy);
	return res; 
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(rint i=1;i<=n;i++)
	q[i]=1;
	for(int i=1;i<=n;i++)
	{
	scanf("%d",&a[i]);
	//cout<<i<<" "<<a[i];
	jia(1,1,n,i,i,a[i]);
	}
	//cout<<s[1];
	cin>>m;
	for(rint i=1;i<=m;i++)
	{
		scanf("%d",&t[i]);
		if(t[i]==1)
		{
			scanf("%d%d",&u[i],&v[i]);
		}
		else if(t[i]==2)
		{
			scanf("%d",&c[i]);
		}
		else
		{
			scanf("%d",&c[i]);
			for(rint j=1;j<=c[i];j++)
			scanf("%d",&w[j]);
			for(rint j=c[i];j>=1;j--)
			{
				nxt[++tot]=h[i];h[i]=tot;go[tot]=w[j];
			}
		}
	}
	cin>>l;
	for(rint i=1;i<=l;i++)
	{
		scanf("%d",&x);
		if(t[x]==1) 
		{
			jia(1,1,n,u[x],u[x],v[x]);
		}
		else if(t[x]==2)
		{
			cheng(1,1,n,1,n,c[x]);
		}
		else
		{
			se(x);
		}
	}
	for(rint i=1;i<=n;i++)
	cout<<sum(1,1,n,i,i)<<" ";
	return 0;
}
