#include <cstdio>
#include <vector>
using std::vector;
const int N = 1e5, MOD = 998244353;
int h[N], tag[N];

struct function{
	int t;
	vector<int> v;
};

inline void pushdown(int k, int l, int r, int mid)
{
	if (tag[k] > 1)
	{
		h[k << 1] = ((long long)h[k << 1] * tag[k]) % MOD;
		h[k << 1 | 1] = ((long long)h[k << 1 | 1] * tag[k]) % MOD;
		tag[k << 1] = ((long long)tag[k << 1] * tag[k]) % MOD;
		tag[k << 1 | 1] = ((long long)tag[k << 1 | 1] * tag[k]) % MOD;
		tag[k] = 1;
	}
}

inline void pushup(int k)
{
	h[k] = h[k << 1] + h[k << 1 | 1];
}

int a[N];
void build(int k, int l, int r)
{
	tag[k] = 1;
	if (l == r)
	{
		h[k] = a[l];
		return ;
	}
	int mid = l + r >> 1;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
	pushup(k);
}

void change1(int k, int l, int r, int u, int v)
{
	if (l == r)
	{
		h[k] += v;
		return ;
	}
	int mid = l + r >> 1;
	pushdown(k, l, r, mid);
	if (u <= mid)
		change1(k << 1, l, mid, u, v);
	else
		change1(k << 1 | 1, mid + 1, r, u, v);
	pushup(k);
}

void change2(int k, int l, int r, int a, int b, int v)
{
	if (a <= l && b >= r)
	{
		h[k] = ((long long)h[k] * v) % MOD;
		tag[k] = ((long long)tag[k] * v) % MOD;
		return ;
	}
	int mid = l + r >> 1;
	pushdown(k, l, r, mid);
	if (a <= mid)
		change2(k << 1, l, mid, a, b, v);
	if (b > mid)
		change2(k << 1 | 1, mid + 1, r, a, b, v);
	pushup(k);
}

int query(int k, int l, int r, int a, int b)
{
	if (a <= l && b >= r)
		return h[k] % MOD;
	int mid = l + r >> 1, ret = 0;
	pushdown(k, l, r, mid);
	if (a <= mid)
		ret = ((long long)ret + query(k << 1, l, mid, a, b)) % MOD;
	if (b > mid)
		ret = ((long long)ret + query(k << 1 | 1, mid + 1, r, a, b)) % MOD;
	return ret % MOD;
}

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

function f[N];
int n;

void call(int F)
{
	for (int j = 0; j < f[F].v.size(); j++)
	{
		if (f[f[F].v[j]].t == 1)
			change1(1, 1, n, f[f[F].v[j]].v[0], f[f[F].v[j]].v[1]);
		else if (f[f[F].v[j]].t == 2)	
			change2(1, 1, n, 1, n, f[f[F].v[j]].v[0]);
		else
			call(f[F].v[j]);
	}
}

int main()
{
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
	
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	build(1, 1, n);
	int m = read(), t, c, p;
	for (int i = 1; i <= m; i++)
	{
		f[i].t = read();
		if (f[i].t == 3)
		{
			c = read();
			for (int j = 1; j <= c; j++)
				f[i].v.push_back(read());	
		}
		else if (f[i].t == 2)
		{
			c = read();
			f[i].v.push_back(c);
		}
		else
		{
			p = read(), c = read();
			f[i].v.push_back(p);
			f[i].v.push_back(c);
		}
	}
	
	int q = read(), F;
	for (int i = 1; i <= q; i++)
	{
		F = read();
		if (f[F].t == 1)
			change1(1, 1, n, f[F].v[0], f[F].v[1]);
		else if(f[F].t == 2)
			change2(1, 1, n, 1, n, f[F].v[0]);
		else
			call(F);
	}
	
	for (int i = 1; i <= n; i++)
		printf("%d ", query(1, 1, n, i, i) % MOD);
	return 0;
}
