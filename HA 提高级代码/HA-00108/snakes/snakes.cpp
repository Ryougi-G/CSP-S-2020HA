#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x)
{
	int f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}x*=f;
}
const int N=5e4+10;
int T,n,k,a[N],b[N],ans;

int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	read(T);
	for(int t=1;t<=T;t++)
	{
		if(t==1){read(n);for(int i=1;i<=n;i++) read(a[i]),b[i]=a[i];}
		else{read(k);for(int i=1;i<=n;i++) a[i]=b[i];
		for(int i=1,x,y;i<=k;i++) read(x),read(y),a[x]=y;}
		ans=n;
		while(1)
		{
			if(ans==2){ans--;break;}
			if(a[ans]-a[1]>=a[2])
			{
				ans--;a[ans]=a[ans+1]-a[1];
				for(int i=1;i<ans;i++) a[i]=a[i+1];
				sort(a+1,a+ans+1);
				continue;
			}
			break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
