#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int mod = 998244353;

struct point{
	int op, p, v;
} p[N];
int idx;

typedef pair<int ,int> use;

int n, m;
int a[N], mu;
int add[N];
int st[N], top;
int ti[N];


inline void build(int x){
	if(x == 1){
		int pos = 0, val = 0;
		scanf("%d%d", &pos, &val);
		p[++idx].op = 1, p[idx].p = pos, p[idx].v = val;
	}
	if(x == 2){
		int val = 0;
		scanf("%d", &val);
		p[++idx].op = 2, p[idx].v = val;
	}
	if(x == 3){
		int num = 0;
		p[++idx].op = 3; scanf("%d", &num);
		
		for(int i = 1; i <= num; i++){
			int tmp = 0;
			scanf("%d", &tmp);
			
			if(st[top] == tmp) ti[top]++;
			else {
				st[++top] = tmp;
				ti[top] = 1;
			}
		}
		
		for(int i = 1; i <= top; i++){
			use pa;
			pa.first = st[i], pa.second = ti[i];
			q[idx].push_back(pa);
		}
	}
	return;
}


inline void add(){
	int p = 0, v = 0;
	scanf("%d%d", &p, &v);
	a[p] += v;
	return;
}

inline void muti(){
	int tmp = 1;
	scanf("%d", &tmp);
	mu *= tmp;
	return;
}

inline void inst(){
	
}

int step[N];

signed main(){
	scanf("%d", &n);
	for(int i =  1; i <= n; i++){
		scanf("%d", &a[i]);
		add[i] = a[i];
	}
	
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		int T = 0;
		scanf("%d", &T);
		if(T == 1) build(1);
		if(T == 2) build(2);
		else {
			st[i] = 3; 
			build(3);
		}	
	}
	
	scanf("%d", &Q);
	for(int i = 1; i <= Q; i++){
		scanf("%d", step[i]);
		
	}
	return 0;
}
