#include"cstdio"
#include"iostream"
#include"algorithm"
#include"cstdlib"
#include"cstring"
using namespace std;
int n,m,c,k,a[1000100],tot,tmp;
unsigned long long ans;
struct node{
	int p,q;
}s[1000100];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&s[i].p,&s[i].q);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if((a[j]>>s[i].p)&1){
				tot++;
				tmp+=(1<<s[i].p);
				break;
			}
		}
	}
	if(tot==m)printf("%llu",(unsigned long long)(1<<k)-n);
	else{
		for(unsigned long long i=1;i<=(1<<k);i<<=1)
			if((i&tmp))continue;
			else ans+=(1<<i);
		printf("%llu",ans);
	}
	return 0;
}
/*
3 3 5 4
1 4 6
0 3
2 4
2 5
*/
/*
2 2 4 3
1 2
1 3
2 4
*/
