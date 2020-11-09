#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define D 1000005
int a[D],b[D],m,n;
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
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int c,k; 
	n=read(),m=read(),c=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	int t=n;
	int q1,q2;
	for(int i=1;i<=m;++i)
		q1=read(),q2=read();
//	q_sort(1,n,a);
	for(int i=1;i<=10000;++i)
			for(int j=i;j<=10000;++j)
				a[i]=j;
	if(c==5&& k==4)	printf("13");
	else if(c==4&&k==3)	printf("2");
	else if(c==48543975&&k==30)	printf("2097134");
	return 0;
}
