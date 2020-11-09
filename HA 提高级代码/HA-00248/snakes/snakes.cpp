#include<bits/stdc++.h>
using namespace std;
int T,n,k,a[1000010],b[1000100];
inline int read()
{
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}
void calc()
{
	//for(int i=1;i<=n;i++)
//	cout<<a[i]<<' ';
//	cout<<endl;
	int L=1;
	while(L<n-2){
		if(a[n]>=a[n-1]){
			if(a[n]-a[L]>=a[n-2])a[n]-=a[L++];
			else break;
		}else{
			if(a[n-1]-a[L]>=a[n-2])a[n-1]-=a[L++];
			else break;
		}
	}
	if(L==n-2){
		if(a[n]>=a[n-1]){
			if(a[n]-a[L]>=a[n-1])printf("1\n");
			else printf("3\n");
		}else{
			if(a[n-1]-a[L]>a[n])printf("1\n");
			else printf("3\n");
		}
	}else printf("%d\n",n-L+1);
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	T=read()-1;
	n=read();
	for(int i=1;i<=n;i++)
	a[i]=b[i]=read();
	calc();
	while(T--){
		k=read();
		for(int i=1;i<=k;i++){
			int x=read(),y=read();
			b[x]=y;
		}
		for(int i=1;i<=n;i++)a[i]=b[i];
		calc();
	}
}
