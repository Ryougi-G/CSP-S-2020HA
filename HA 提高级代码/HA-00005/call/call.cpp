#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int MAXN = 1e5 + 10;
struct node {
	int sum ,l ,r ,plz ,mlz;
	node () {
		l = r = sum = plz = 0;
		mlz = 1;
	}
}tree[MAXN << 2];
int n ,m ,a[MAXN] ,c[20004][101];
void pushup (int i) {
	tree[i].sum = (tree[i << 1].sum + tree[i << 1 | 1].sum) % mod;
	return ;
}
void pushdown (int i) {
	if (tree[i].plz != 0 || tree[i].mlz != 1) {
		tree[i << 1].sum = (tree[i << 1].sum * tree[i].mlz % mod + (tree[i << 1].r - tree[i << 1].l + 1) * tree[i].plz % mod) % mod;
		tree[i << 1 | 1].sum = (tree[i << 1 | 1].sum * tree[i].mlz % mod + (tree[i << 1 | 1].r - tree[i << 1 | 1].l + 1) * tree[i].plz % mod) % mod;
		tree[i << 1].mlz = (tree[i << 1].mlz * tree[i].mlz) % mod;
		tree[i << 1 | 1].mlz = (tree[i << 1 | 1].mlz * tree[i].mlz) % mod;
		tree[i << 1].plz = (tree[i << 1].plz * tree[i].mlz + tree[i].plz) % mod;
		tree[i << 1 | 1].plz = (tree[i << 1 | 1].plz * tree[i].mlz + tree[i].plz) % mod;
		tree[i].plz = 0;
		tree[i].mlz = 1;
	}
	return ;
}
void build (int i ,int l ,int r) {
	tree[i].l = l ,tree[i].r = r;
	if (l == r) {
		tree[i].sum = a[l] % mod;
		return ;
	}
	int mid = (l + r) >> 1;
	build (i << 1 ,l ,mid);
	build (i << 1 | 1 ,mid + 1 ,r);
	pushup (i);
	return ;
}
void add (int i ,int l ,int r ,int d ,int k) {
	if (tree[i].l == tree[i].r) {
		tree[i].sum = (tree[i].sum + (tree[i << 1].r - tree[i << 1].l + 1) * k % mod) % mod;
		return ;
	}
	pushdown (i);
	if (tree[i << 1].r >= d) add (i << 1 ,l ,r ,d ,k);
	else add (i << 1 | 1 ,l ,r ,d ,k);
	pushup (i);
	return ;
}
void mul (int i ,int l ,int r ,int k) {
	if (tree[i].l >= l && tree[i].r <= r) {
		tree[i].mlz = (tree[i].mlz * k) % mod;
		tree[i].plz = (tree[i].plz * k) % mod;
		tree[i].sum = (tree[i].sum * k) % mod;
		return ;
	}
	if (tree[i].l > r || tree[i].r < l) return ;
	pushdown (i);
	if (tree[i << 1].r >= l) mul (i << 1 ,l ,r ,k);
	if (tree[i << 1 | 1].l <= r) mul  (i << 1 | 1 ,l ,r ,k);
	pushup (i);
	return ;
}
ll query (int i ,int l ,int r) {
	if (tree[i].l >= l && tree[i].r <= r) {
		return tree[i].sum % mod;
	}
	if (tree[i].l > r || tree[i].r < l) return 0;
	pushdown (i);
	ll s = 0;
	if (tree[i << 1].r >= l) s = (s + query (i << 1 ,l ,r)) % mod;
	if (tree[i << 1 | 1].l <= r) s = (s + query (i << 1 | 1 ,l ,r)) % mod;
	return s % mod;
}
int Q;
void do_ (int r) {
	if (c[r][0] == -1) {
		add (1 ,1 ,n ,c[r][1] ,c[r][2]);
		return ;
	}
	else if (c[r][1] == -2) {
		mul (1 ,1 ,n ,c[r][1]);
		return ;
	}
	else {
		for (int q = 1;q <= c[r][0];++ q) {
			do_ (c[r][q]);
		}
	}
	return ;
}
ll qq (int i ,int l ,int r ,int d) {
	if (tree[i].l == tree[i].r) {
		return tree[i].sum % mod;
	}
	pushdown (i);
	if (tree[i << 1].r >= d) return qq (i << 1 ,l ,r ,d);
	else return qq (i << 1 | 1 ,l ,r ,d);
}
int main () {
	freopen ("call.in","r",stdin);
	freopen ("call.out","w",stdout);
	scanf ("%d",&n);
	for (int q = 1;q <= n;++ q) {
		scanf ("%d",&a[q]);
	}
	build (1 ,1 ,n);
	scanf ("%d",&m);
	for (int q = 1 ,opt;q <= n;++ q) {
		scanf ("%d",&opt);
		if (opt == 1) {
			scanf ("%d%d",&c[q][1] ,&c[q][2]);
			c[q][0] = -1;
		}
		else if (opt == 2) {
			scanf ("%d",&c[q][1]);
			c[q][0] = -2;
		}
		else {
			scanf ("%d",&c[q][0]);
			for (int w = 1;w <= c[q][0];++ w) {
				scanf ("%d",&c[q][w]);
			}
		}
	}
	scanf ("%d",&Q);
	int ed_;
	while (Q --) {
		scanf ("%d",&ed_);
		do_ (ed_);
	}
	for (int q = 1;q <= n;++ q) {
		printf ("%d ",qq (1 ,1 ,n ,q));
	}
	printf ("\n");
	return 0;
}

