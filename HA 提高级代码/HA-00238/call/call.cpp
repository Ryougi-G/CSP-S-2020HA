#include <iostream>
#include <cstdio>
#include <vector>
#define uLL unsigned long long
using namespace std;
const int maxN = 1e5 + 100;
const int mod = 998244353;

void readin();
void func1(int x, int y);
void func2(int x);
void func3(int f);

int n, m, Q;
int a[maxN];
vector <int> func[maxN];
int main(void){
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	readin();
	scanf("%d", &Q);
	for (int i = 1; i <= Q; i ++){
		int f;
		scanf("%d", &f);
		if (func[f][0] == 1)
			func1(func[f][1], func[f][2]);
		else if (func[f][0] == 2)
			func2(func[f][1]);
		else
			func3(f);
	}
	for (int i = 1; i <= n; i ++){
		printf("%d ", a[i]);
	}
	return 0;
}

void func1(int x, int y){
	a[x] = (((long long)a[x] + (long long)(y % mod)) % mod);
}

void func2(int x){
	for (int i = 1; i <= n; i ++)
		a[i] = ((((uLL)a[i]) * (uLL)x) % mod);
}

void func3(int f){
	for (int i = 1; i < func[f].size(); i ++)
		if (func[func[f][i]][0] == 1)
			func1(func[func[f][i]][1], func[func[f][i]][2]);
		else if (func[func[f][i]][0] == 2)
			func2(func[func[f][i]][1]);
		else
			func3(func[f][i]);
}

void readin(){
	for (int i = 1; i <= m; i ++){
		int T;
		scanf("%d", &T);
		if (T == 1){
			func[i].push_back(1);
			int p, v;
			scanf("%d%d", &p, &v);
			func[i].push_back(p);
			func[i].push_back(v);
		}
		else if (T == 2){
			int v;
			scanf("%d", &v);
			func[i].push_back(2);
			func[i].push_back(v);
		}
		else{
			func[i].push_back(3);
			int G, g;
			scanf("%d", &G);
			for (int j = 1; j <= G; j ++){
				scanf("%d", &g);
				func[i].push_back(g);
			}
		}
	}
}
