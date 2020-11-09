#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int book[N];

int main()
{
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	
	long long n, m, c, k;
	int a[N], p[N], q[N];
	cin >> n >> m >> c >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> p[i] >> q[i];
		
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			long long b = j;
			b >>= p[i];
			if(b & 1)
				book[q[i]] = 1;
		}
	}
	
	int cnt = 0;
	for(int i = 0; i < c; i++)
	{
		if(book[q[i]])
		{
			for(int j = 0; j < pow(2, k) - 1; j++)
			{
				long long b = a[j];
				b >>= p[i];
				if(b & 1)
					cnt++;
			}
		}
	}
	cnt -= n;
	cout << cnt;
	return 0;
}
