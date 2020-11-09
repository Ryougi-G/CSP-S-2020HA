#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000010;

long long n, num, day = 1, mon = 1, yar = 4713;
bool cen = true;

inline int read()
{
	int xig = 0; bool fl = 0; char ch = getchar();
	while (!isdigit(ch)) fl |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) xig = (xig << 3) + (xig << 1) + (ch ^ 48), ch = getchar();
	return fl ? -xig : xig;
}



int mian()
{
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	
	return 0;
}
