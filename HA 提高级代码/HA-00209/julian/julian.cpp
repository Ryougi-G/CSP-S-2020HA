#include<bits/stdc++.h>
using namespace std;
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool g(int n)
{
	if((n > 1582 && ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)) || n <= 1582)
		return true;
	else
		return false;
}
int main()
{
//*/
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
//*/
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		long long r;
		int n = -4712, m = 1, d = 1;
		scanf("%lld", &r);
		if(r > (1582 + 4712) * 365)
			r += 10;
		while(r > 1ll * 365)
		{
			r -= 1ll * 365;
			if(n % 4 == 0 && g(n) == true)
				r--;
			n++;
		}
		if(r == 365 && n % 4 != 0)
		{
			r = 0;
			n++;
		}
		if(r != 0)
		{
			bool temp = false;
			if(n % 4 == 0 && g(n))
			{
				temp = true;
			}
			for(int j = 0; j < 12 && r > month[j]; j++)
			{
				r -= 1ll * month[j];
				m++;
				if(j == 1 && temp == true)
				{
					if(r == 0)
					{
						m--;
						r += 28;
						break;
					}
					else
						r--;
				}
			}
			d += r;
		}
		if(n > 0)
		printf("%d %d %d", d, m, n);
		if(n <= 0)
		printf("%d %d %d BC", d, m, -n + 1);
		if(i < q - 1)
			printf("\n");
	}
	return 0;
}
