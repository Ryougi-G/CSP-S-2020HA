#include <bits/stdc++.h>
using namespace std;
int n, a[100010], m, q, cz, tmp;

struct node {
	int kind;
	int xb, zhi;
	int czhi;
	int fcts;
	vector<int> ty;
}fct[100010];


void work (int x){
	if (fct[x].kind == 1)a[fct[x].xb] += fct[x].zhi;
	if (fct[x].kind == 2){
		for (int i = 1; i <= n; i++)a[i] *= fct[x].czhi;
	}
	if (fct[x].kind == 3){
		for (int i = 0; i < fct[x].fcts; i++)work (fct[x].ty[i]);	
	}
}
	
void init (){
	memset (a, 0, sizeof (a));
	memset (fct, 0, sizeof (fct));
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++){
		cin >> fct[i].kind;
		if (fct[i].kind == 1)cin >> fct[i].xb >> fct[i].zhi;
		if (fct[i].kind == 2)cin >> fct[i].czhi;
		if (fct[i].kind == 3){
			cin >> fct[i].fcts;
			for (int j = 0; j < fct[i].fcts; j++){
				cin >> tmp;
				fct[i].ty.push_back (tmp);
			}
		}
	}
	cin >> q;
}

int main (){
	freopen ("call.in", "r", stdin);
	freopen ("call.out", "w", stdout);
	init ();
	for (int i = 0; i < q; i++){
		cin >> cz;
		work (cz);
	}
	for (int i = 1; i <= n; i++)cout << a[i] << " ";
	return 0;
}
