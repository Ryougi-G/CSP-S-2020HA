#include<bits/stdc++.h>
using namespace std;
long long animal, rule;
long long a[1000];
int main()
{
//*/
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
//*/
	int n, m, c, k;
	long long ans = 0;
	scanf("%d%d%d%d", &n, &m, &c, &k);
	for(int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		animal = animal | a[i];
	}
	sort(a, a + n);
	for(int i = 0; i < m; i++)
	{
		long long r, p;
		scanf("%lld%lld", &r, &p);
		rule = rule | (1 << r);
	}
	if(k < 20)
	{
		long long temp = animal & rule;
		temp = rule ^ temp;
		int e = 0;
		for(long long i = 0; i < (1 << k); i++)
		{
			if(i == a[e])
			{
				e++;
				continue;
			}
			if(!(temp & i))
				ans++;
		}
		printf("%lld", ans);
		return 0;
	}
	long long temp = animal & rule;
	temp = rule ^ temp;
	int numa = 0;
	for(int i = 0 ; i <= k; i++)
	{
		if(temp & (1 << i))
			numa++;
	}
	printf("%d", (1 << k - numa) - n);
	return 0;
}
