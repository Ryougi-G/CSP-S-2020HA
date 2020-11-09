#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

inline int rd(){
	int ret = 0;
	char ch = getchar();
	while(ch > '9' || ch < '0') ch= getchar();
	while(ch <= '9' && ch >= '0'){
		ret = ret*10 + ch - '0', ch = getchar();
	}
	return ret;
}

int T;
int n;
int a[N];
int l[N], r[N];

signed main(){
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out","w", stdout);
	T = rd();
	for(int i = 1; i <= T; i++){
		if(i == 1){
			n = rd();
			for(int i = 1; i <= n; i++){
				a[i] = rd();
			}
		}
		else{
			int k = 0;
			k = rd();
			for(int i = 1; i <= k; i++){
				a[rd()] = rd();
			}
		}
		
		a[0] = 0x3f3f3f, a[n+1] = -0x3f3f3f;
		for(int i = 1; i <= n; i++) l[i] = i-1, r[i] = i+1;
		r[n] = n+1;
		
		int left = 1, right = n;
		int cnt = n;
		
		while(cnt >= 1){
			if(a[right] - a[left] > a[r[left]]){
				int val = a[right] - a[left];
				right = l[right], left = r[left];
				
				a[l[left]] = val, cnt--;
				
				for(int i = left; i; i = r[i])
					if(a[i] <= val && a[r[i]] >= val){
						r[i] = l[left], l[l[left]] = i;
						r[l[left]] = r[i], l[r[i]] = l[left];
						break;
				}
				
			}
			else break;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
