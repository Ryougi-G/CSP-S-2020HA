#include <iostream>
#include <cstdio>
using namespace std;
int q, ay = -4713, am = 1, ad = 1, m[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, rn = 1;
int main()
{
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i)
	{
		int r;
		scanf("%d", &r);
		while(r > 365 + rn && ay <= -1)//公元前 
		{
			r -= (365 + rn);
			++ay;
			if(((ay > 0 ? ay : -ay) - 1) % 4 == 0)
				rn = 1;
			else rn = 0;
			if(ay == 0)
			{
				ay = 1;
				break;
			} 
		}
		if(ay == 1) rn = 0; 
		while(r > 365 + rn && ay >= 1 && ay <= 1581)//公元 
		{
			r -= (365 + rn);
			++ay;
			if(ay % 4 == 0)
				rn = 1;
			else rn = 0;
		}
		if(ay == 1582 && r > 308)
			r += 9;
		while(r > 365 + rn)//转换历法 
		{
			r -= (365 + rn);
			++ay;
			if((ay % 4 == 0 && ay % 100 != 0) || (ay % 400 == 0))
				rn = 1;
			else rn = 0;
		}
		while(r > (am == 2 ? m[am] + rn : m[am])) 
		{
			r -= m[am];
			if(am == 2) r -= rn;
			++am;
		}
		ad += r;
		printf("%d %d %d ", ad, am, (ay > 0 ? ay : -ay));
		if(ay <= -1) printf("BC ");
		printf("\n");
		ay = -4713;
		am = 1;
		ad = 1;
	}
	return 0;
}
