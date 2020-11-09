#include<bits/stdc++.h>
using namespace std;
int T,n,k;
inline int szread(){
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}	
return res*f;}
struct node{
	int t,b;
}a[10000010];
int cmp1(node l,node c){
	return l.t>c.t;
}
int cmp2(node l,node c){
	return l.b<c.b;
}
int main(){
	freopen("snakes.in","r",stdin);freopen("snakes.out","w",stdout);
	T=szread();
	n=szread();
	for(int i=1;i<=n;++i){
		a[i].t=szread();a[i].b=i;
	}
	sort(a+1,a+n+1,cmp1);
	if(n==2) cout<<"1"<<endl;
	else if(n>2){
		int ll=n;
		while(1){
			if(a[1].t-a[ll].t>a[2].t||(a[1].t-a[ll].t==a[2].t&&a[1].b>=a[2].b))
				a[1].t-=a[ll].t,--ll;
			else if(a[1].t-a[ll].t>a[ll-1].t||(a[1].t-a[ll].t==a[ll-1].t&&a[1].b>=a[ll-1].b))
				a[1].t-=a[ll].t,--ll;
			else break;
			sort(a+1,a+ll+1,cmp1);
		}
		printf("%d\n",ll);
	}
	sort(a+1,a+n+1,cmp2);
	for(int ttt=1;ttt<T;++ttt){
		k=szread();
		for(int i=1;i<=k;++i){
			int aa=szread(),bb=szread();
			a[aa].t=bb;
		}
		sort(a+1,a+n+1,cmp1);
		if(n==2) cout<<"1"<<endl;
		else if(n>2){
		int ll=n;
		while(1){
			if(a[1].t-a[ll].t>a[2].t||(a[1].t-a[ll].t==a[2].t&&a[1].b>=a[2].b))
				a[1].t-=a[ll].t,--ll;
			else if(a[1].t-a[ll].t>a[ll-1].t||(a[1].t-a[ll].t==a[ll-1].t&&a[1].b>=a[ll-1].b))
				a[1].t-=a[ll].t,--ll;
			else break;
			sort(a+1,a+ll+1,cmp1);
		}
		printf("%d\n",ll);
		}
		sort(a+1,a+n+1,cmp2);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
