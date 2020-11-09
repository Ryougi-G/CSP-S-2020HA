#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1000010;
int T,temp,n,sn[MAXN];

void threesort(){
	if (sn[3] > sn[2]) {
		swap(sn[3],sn[2]);
		if (sn[2] > sn[1]) swap(sn[1],sn[2]);
	}
	else {
		if (sn[2]>sn[1]) swap(sn[2],sn[1]);
	}
	if (sn[1] > sn[2] + sn[3] ) printf("1\n");
	else printf("3\n");
}

int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&T);
	T -=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&sn[i]);
	threesort();
	for (int i=0;i<T;i++){
		scanf("%d",&n);
		for(int j=0;j<n;j++){
			scanf("%d",&temp);
			scanf("%d",&sn[temp]);
		}	
		threesort();
	}
	return 0;
}
