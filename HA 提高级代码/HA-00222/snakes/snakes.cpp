#include"cstdio"
#include"iostream"
#include"cstring"
#include"cstdlib"
#include"algorithm"
#include"queue"
using namespace std;
int s[100010],eat[100010],T,n,ans;
inline void dfs(int now,int l,int r){
	if(now==0)return;
	if(eat[r]-eat[l]>eat[r-1])ans++,sort(eat+1,eat+1+n),dfs(now-1,l+1,r);
	else dfs(now-1,l,r);
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(T==1){
			for(int i=1;i<=n;i++){
				scanf("%d",&s[i]);
				eat[i]=s[i];
			}
		}
		else{
			for(int i=1,x,y;i<=n;i++){
				scanf("%d%d",&x,&y);
				s[x]=y;
			}
			for(int i=1;i<=n;i++){
				eat[i]=s[i];
			}
		}
		sort(eat+1,eat+1+n);
		dfs(n,1,n);
		printf("%d\n",n-ans);
		ans=0;
		memset(eat,0,sizeof eat);
	}
	return 0;
}
