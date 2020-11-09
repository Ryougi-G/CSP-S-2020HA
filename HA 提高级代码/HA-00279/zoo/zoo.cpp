#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 100010;
int n,k,ans,trasha,trashb;

int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&trasha);
	scanf("%d",&trashb);
	scanf("%d",&k);
	ans=1;
	for(int i=1;i<=k;i++) ans *= 2;
	ans=ans-n;
	printf("%d",ans);
	return 0;
}
