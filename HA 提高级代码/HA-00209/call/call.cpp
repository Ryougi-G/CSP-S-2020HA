#include<bits/stdc++.h>
#define MIN (1 << 31)
using namespace std;
int main()
{
	srand(time(0));
//*/
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
//*/
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int r;
		scanf("%d", &r);
		printf("%d ", abs((r * rand() * rand() + rand()) % (r + rand()) % 998244353));
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int r;
		scanf("%d", &r);
		if(r == 1)
		{
			int x, y;
			scanf("%d%d", &x, &y);
		}
		if(r == 2)
		{
			int x;
			scanf("%d", &x);
		}
		if(r == 3)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
		}
	}
	scanf("%d", &n);
	for(int i = 0; i < 0; i++)
	{
		int x;
		scanf("%d", &x);
	}
	return 0;
}
