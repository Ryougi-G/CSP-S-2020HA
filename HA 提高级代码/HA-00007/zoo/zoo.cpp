#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 10; 
int n, m, c, k, a[N];
int fla[100];
vector<int> v[100];
inline int read() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			f = 1;
		c = getchar();
	}
	while (c <= '9' && c >= '0') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	if (f)
		return ~(x - 1);
	return x;
}
int main() {
	freopen ("zoo.in", "r", stdin);
	freopen ("zoo.out", "w", stdout);
	n = read();
	m = read();
	c = read();
	k = read();
	for (register int i = 1; i <= n; i++)
		a[i] = read();
	for (register int i = 1; i <= m; i++) {
		int p = read(), q = read();
		v[p].push_back(q);
	}
	for (register int i = 0; i < k; i++)//��iλ 
		if (v[i].size()) {//�Ե�iλ��Լ����� 
			for (register int j = 1; j <= n; j++)
				if ((a[j] >> i) & 1)//��Ҫ���iλ������
					fla[i] = 1;//��iλֻ��Ϊ1
			if (fla[i] != 1)
				fla[i] = 2;//��iλ������ 
		}
	int k1 = k;
	for (register int i = 0; i < k; i++)
		if (fla[i] == 2)
			k1--;
	printf("%lld\n", (LL)((1 << k1) - n));
	return 0;
}

