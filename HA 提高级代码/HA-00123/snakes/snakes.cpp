#include<bits/stdc++.h>
using namespace std;
const int maxn=1005000;
int n,k;
int x,y;
int T;
int s[maxn];
struct sn{
	int tl;
	int num;
}a[maxn];
int head=1;

void so(){
	for(int i=n;i>head;i--){
		if( (a[i].tl>a[i-1].tl) || (a[i].tl==a[i-1].tl&&a[i].num>a[i-1].num) ) return;
		swap(a[i],a[i-1]);
	}
	return;
}

void et(int f,int l){
	if(head==n) return;
	int zh=a[l].tl-a[f].tl;
	if( ((zh<a[f+1].tl) || (zh==a[f+1].tl&&a[l].num<a[f+1].num))&&(head+1!=n)) return;
	
	a[l].tl=zh;
	head++;
	if(head==n) return;
	
	so();
	
	et(head,n);
	
	return ;
}

int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&T);
	T--;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		
		a[i].tl=s[i];
		a[i].num=i;
	}
		
	
	et(head,n);
	printf("%d\n",n-head+1);
	
	while(T--){
		head=1;
		scanf("%d",&k);
		
		for(int i=1;i<=k;i++){
			scanf("%d%d",&x,&y);
			s[x]=y;
		}
		
		for(int i=1;i<=n;i++){
			a[i].tl=s[i];
			a[i].num=i;
		}
		et(head,n);
		printf("%d\n",n-head+1);
	} 
	
	return 0;
}
