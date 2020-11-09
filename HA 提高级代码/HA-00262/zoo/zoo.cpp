#include <cstdio>
#include <vector>
using std::vector;
const int N = 1e6 + 10;

typedef unsigned long long ull;

int read()
{
	int ch, f = 1;
	while ((ch = getchar()) < '0' || ch > '9')
		f = (ch == '-' ? -1 : 1);
	int ret = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9')
		ret = ret * 10 + ch - '0';
	return ret * f;
}

ull a[N];
int mp[70];
int book[70], n, m, c, k;;

ull fast_pow(ull a, int b)
{
	ull ret = 1;
	while (b)
	{
		if (b & 1)
			ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}

inline ull work(int p)
{
	return (fast_pow(2, p) - 1) * fast_pow(2, k - p);
}

int main()
{
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	
	int cnt = 0, eid = 0;
	n = read(), m = read(), c = read(), k = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= m; i++)
	{
		int p = read(), q = read();
		if (mp[p] == 0)
			eid++;
		mp[p] = q;
	}
	
	for (int i = 1; i <= n; i++)
	{
		int tmp = a[i];
		for (int j = 0; j < k; j++)
		{
			if (tmp % 2 == 1 && book[j] == 0 && mp[j] != 0)
				book[j] = 1, cnt++;
			tmp = tmp / 2;	
		}
	}
	
	cnt = eid - cnt;
	printf("%llu", ((fast_pow(2, k - 1) - n) + fast_pow(2, k - 1)) - work(cnt));
	return 0;
}
