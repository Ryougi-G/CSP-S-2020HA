#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define D 1000005
int a[D],b[D];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return x*f;
}void q_sort(int l,int r,int *q){
	int i=l,j=r,p;
	int mid=q[(r+l-1)/2];
	while(i<=j){
		while(q[i]>mid)	++i;
		while(q[j]<mid)	--j;
		if(i<=j){
			p=q[i];
			q[i]=q[j];
			q[j]=p;
			i++;
			--j;
		}
	}
	if(j>l)	q_sort(l,j,q);
	if(i<r)	q_sort(i,r,q);
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t=read(),n,q,p,x,y,m;
	bool	f=1;
	while(t--){
		if(f){
			f=0;
			m=n=read();
			for(int i=1;i<=n;++i)
				b[i]=a[i]=read();
			q_sort(1,n,b);
			while(((n>2)&&((b[1]-b[n])>=b[n-1])) || ((n==2)&&(b[1]>=b[2]))){
				b[1]=b[1]-b[n];
				n--; 
				if(n==1)	break;
				q_sort(1,n,b);
			}
			printf("%d\n",n);
		}
		else{
			n=read();
			for(int i=1;i<=n;++i){
				x=read(),y=read();
				a[x]=y;
			}
			n=m;
			for(int i=1;i<=n;++i)
				b[i]=a[i];
			q_sort(1,n,b);
			while(((n>2)&&((b[1]-b[n])>=b[n-1])) || ((n==2)&&(b[1]>=b[2]))){
				b[1]=b[1]-b[n];
				n--; 
				q_sort(1,n,b);
			}
			printf("%d\n",n);
		}
	}
	return 0;
}
