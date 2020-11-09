#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int M=1e6+10;
int n,m,c,k;
ull a=0;
int hd[65],nxt[M],idx[M],cnt=0;
int x[M],cx;
bool lgl[M];
int ans=0;
void addc(int p,int q){
	cnt++;
	idx[cnt]=q;
	nxt[cnt]=hd[p];
	hd[p]=cnt;
	return;
}
void change(int idc){
	int l=1,r=cx,mid=l+r>>1;
	while(x[mid]!=idc)
		if(x[mid]>idc){
			r=mid;
			mid=l+r>>1;
		}
		else{
			l=mid+1;
			mid=l+r>>1;
		}
	lgl[mid]=true;
	return;
}
bool query(int idc){
	int l=1,r=cx,mid=l+r>>1;
	while(x[mid]!=idc)
		if(x[mid]>idc){
			r=mid;
			mid=l+r>>1;
		}
		else{
			l=mid+1;
			mid=l+r>>1;
		}
	return lgl[mid];
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1,tmp;i<=n;i++){
		cin>>tmp;
		a|=tmp;
	}
	for(int i=1,p,q;i<=m;i++){
		scanf("%d%d",&p,&q);
		x[i]=q;
		addc(p,q);
	}
	sort(x+1,x+1+m);
	cx=unique(x+1,x+1+m)-x-1;
	for(int i=0;i<k;i++)
		if((a>>i)&1)
			for(int j=hd[i];j;j=nxt[j])
				change(idx[j]);
	for(int i=0;i<k;i++){
		bool flag=true;
		for(int j=hd[i];j&&flag;j=nxt[j])
			if(!query(idx[j]))
				flag=false;
		if(flag)
			ans++;
	}
	if(ans==64){
		if(n==0)
			printf("18446744073709551616");
		else
			cout<<(((ull)1<<63)-n)+((ull)1<<63);
	}
	else
		cout<<((ull)1<<ans)-n;
	return 0;
}
