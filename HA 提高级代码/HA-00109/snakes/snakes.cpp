#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;

int n, t, x, y, num;

deque <int> arr;

inline int read()
{
	int xig = 0; bool fl = 0; char ch = getchar();
	while (!isdigit(ch)) fl |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) xig = (xig << 3) + (xig << 1) + (ch ^ 48), ch = getchar();
	return fl ? -xig : xig;
}

bool comp(int a, int b) { return a < b; }

int mian()
{
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	
	n = read();
	num = t = read();
	for (register int i = 1; i <= t; ++ i) arr.push_back(read());
	
	while (arr.size() > 1)
	{
		if (arr[arr.size()] - arr.front() > arr[arr.size() - 1])
		{
			arr[arr.size()] -= arr.front();
			arr.pop_front();
		}
		else
		{
			break;
		}
	}
	
	printf ("%d", arr.size());
	puts("");
	
	for (register int i = 2; i <= n; ++ i)
	{
		t = read();
		
		for (register int i = 1; i <= t; ++ i)
		{
			x = read();
			y = read();
			
			arr[x] = y;
		}
		
		while (arr.size() > 1)
		{
			if (arr[arr.size()] - arr.front() > arr[arr.size() - 1])
			{
				arr[arr.size()] -= arr.front();
				arr.pop_front();
			}
			else
			{
				break;
			}
		}
	}
	
	printf ("%d", arr.size());
	puts("");
	
	return 0;
}
