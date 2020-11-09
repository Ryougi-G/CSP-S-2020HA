#include <bits/stdc++.h>
using namespace std;

int n , m , q;

int a[101000] = {} , ans[101000] = {};

struct Node{
	int ty;
	vector<int> mo;
};

Node b[101000];

void type1(int p1 , int v1){
	a[p1] = a[p1] + v1;
}

void type2(int v2){
	for (int i = 1 ; i <= n ; i++){
		a[i] = a[i] * v2;
	}
}

void type3(vector<int> g1){
	for (int i = 0 ; i < g1.size() ; i++){
		if (b[g1[i]].ty == 1){
		    type1(b[g1[i]].mo[0] , b[g1[i]].mo[1]);
	    }
	    if (b[g1[i]].ty == 2){
		    type2(b[g1[i]].mo[0]);
	    }
	}
}

int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	cin >> m;
	for (int i = 1 ; i <= m ; i++){
		int t;
		cin >> t;
		b[i].ty = t;
		if (t == 1){
			int p , v; cin >> p >> v;
			b[i].mo.push_back(p);
			b[i].mo.push_back(v);
		}
		if (t == 2){
		    int va;
			cin >> va;
			b[i].mo.push_back(va);
		}
		if (t == 3){
			int c;
			cin >> c;
			for (int j = 1 ; j <= c ; j++){
				int g;
				cin >> g;
				b[i].mo.push_back(g);
			}
		}
	}
	cin >> q;
	for (int i = 1 ; i <= q ; i++){
		int l;
		cin >> l;
		if (b[l].ty == 1){
			type1(b[l].mo[0] , b[l].mo[1]);
		}
		if (b[l].ty == 2){
			type2(b[l].mo[0]);
		}
		if (b[l].ty == 3){
			type3(b[l].mo);
		}
	}
	for (int i = 1 ; i <= n ; i++){
		ans[i] = a[i] % 998244353;
		cout << ans[i] << " ";
	}
	return 0;
}
