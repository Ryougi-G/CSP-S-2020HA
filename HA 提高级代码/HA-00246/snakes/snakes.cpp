#include <bits/stdc++.h>
#define S 1000005
using namespace std;
int n;
int a[S];
int xx,dd;
int T;
int mt;
int sm;
int main(){
	freopen("snake.in","r",stdin);
	freopen("snake.out","w",stdout);
	scanf("%d",&T);
	scanf("%d",&n);
		int maxn=0;
		int ma=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]>=maxn){
				ma=i;
				maxn=a[i];
			}
			
		}
		
		int now=0;
		sm=0;
		for(int i=1;i<=n;++i){
			if(i!=ma){
				now+=a[i];
				if(a[i]>=sm)
				mt=i;
			}
		}
//		cout<<now<<" "<<maxn<<endl;
		if(now>maxn)cout<<3<<endl;
		if(now==maxn&&mt>ma)cout<<3<<endl;
		else cout<<1<<endl;
		T--;
		while(T--){
			maxn=0;
			ma=0;
			for(int i=1;i<=n;++i){
				scanf("%d %d",&xx,&dd);
				a[xx]=dd;
			}
			for(int i=1;i<=n;++i){
				if(a[i]>=maxn){
					ma=i;
					maxn=a[i];
				}
			}
			now=0;
			for(int i=1;i<=n;++i){
				if(i!=ma){
					now+=a[i];
					if(a[i]>=sm)
					mt=i;
				}
			}
//		cout<<now<<" "<<maxn<<endl;
//		cout<<mt<<endl;
			if(now>maxn)cout<<3<<endl;
			if(now==maxn&&mt>ma)cout<<3<<endl;
			else cout<<1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
