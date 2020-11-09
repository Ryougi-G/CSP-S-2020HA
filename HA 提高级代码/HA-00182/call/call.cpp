#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n,q,f,num[100001],m,hxs[100001][3],t,num3[1001][101],cnt=3;
void dy(int index) {
	if(hxs[index][0]==1) {
		num[hxs[index][1]-1]+=hxs[index][2];
	} else if(hxs[index][0]==2) {
		for(int i=0;i<n;i++) {
			num[i]*=hxs[index][1];
		}
	} else if(hxs[index][0]==3) {
		for(int j=1;j<=num3[hxs[index][1]][0];j++) {
			dy(num3[hxs[index][1]][j]-1);
		}
	}
}
int main() {
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++) {
		scanf("%d",&num[i]);
	}
	cin >> m;
	for(int i=0;i<m;i++) {
		scanf("%d",&hxs[i][0]);
		if(hxs[i][0]==1) {
			scanf("%d%d",&hxs[i][1],&hxs[i][2]);
		} else if(hxs[i][0]==2) {
			scanf("%d",&hxs[i][1]);
		} else {
			hxs[i][1]=cnt;
			scanf("%d",&num3[cnt][0]);
			for(int j=1;j<=num3[cnt][0];j++) {
				scanf("%d",&num3[cnt][j]);
			}
			cnt++;
		}
	}
	cin >> q;
	for(int i=0;i<q;i++) {
		scanf("%d",&f);
		dy(f-1);
	}
	for(int i=0;i<n;i++) {
		printf("%d ",num[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

