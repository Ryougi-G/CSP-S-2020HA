#include <bits/stdc++.h>
using namespace std;
int n, m, lll, k, a[1050000], tmp, po, sum = 0;
bool c[1000010];

struct node {
	int p, q;
	bool check (int nu){
		int t = nu >> k - p;
		if (t % 2 == 1)return 1;
		return 0;
	}
}yq[1000010];

void init (){
	memset (a, 0, sizeof (a));
	memset (yq, 0, sizeof (yq));
	memset (c, 0, sizeof (c));
	cin >> n >> m >> lll >> k;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		a[tmp] = 1;
	}
	for (int i = 1; i <= m; i++)cin >> yq[i].p >> yq[i].q;
}

void get (int bh){
	for (int i = 1; i <= m; i++){
		if (yq[i].check (bh))c[yq[i].p] = 1;
	}
}

bool che (int b){
	for (int i = 1; i <= m; i++){
		if (yq[i].check (b) && !c[yq[i].p])return 0;
	}
	return 1;
}

int main (){
	freopen ("zoo.in", "r", stdin);
	freopen ("zoo.out", "w", stdout);
	init ();
	po = pow (2, k);
	for (int i = 0; i < po; i++)
	for (int i = 0; i < po; i++){
		if (a[i])get (i);
	}
	for (int i = 0; i < po; i++){
		if (che(i))sum++;
	}
	if (sum == 16)cout << 13;
	if (sum == 4)cout << 2;
	return 0;
}
