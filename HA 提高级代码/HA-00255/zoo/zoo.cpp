#include <bits/stdc++.h>

using namespace std;

//  2   4   4   2   3    1  1
// ti mian tai nai dong le ba 

int n, m, c, k;

int main() {
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	
	scanf("%d %d %d %d", &n, &m, &c, &k);
	printf("%lld\n", (1LL << k) - n);
	return 0;
}

