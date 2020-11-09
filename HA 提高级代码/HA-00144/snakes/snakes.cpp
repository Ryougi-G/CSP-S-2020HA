#include<bits/stdc++.h>
using namespace std;
inline int SQHread(){
	int fh=1,dx=0;
	char ch;
	ch=getchar();	
	while(ch<'0'||ch>'9'){
		if(ch=='-')	fh=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		dx=dx*10+ch-'0';
		ch=getchar();
	}
	return dx*fh;
}
int T,n,a[3000004],beifen[3000004];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	T=SQHread();
	--T;
	n=SQHread();
	int ans;
	for(int i=1;i<=n;++i)
		a[i]=SQHread(),beifen[i]=a[i];
	for(int TT=1;TT<=T;++TT){
		sort(a+1,a+n+1);
		ans=n;
		while(a[ans]-a[1]>=a[n-1]){
			sort(a+1,a+n+1);
			a[1]=999999999;
			a[n]-=a[1];
			--ans;
			sort(a+1,a+n+1);
		}
		int m=SQHread();
		for(int i=1;i<=n;++i)
			a[i]=beifen[i];
		for(int i=1;i<=m;++i){
			int rr=SQHread();
			int rrr=SQHread();
			a[rr]=rrr;
		}
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
