#include <bits/stdc++.h>
typedef long long i64;
int s0[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int s1[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool F(int x) 
{ 
	if(x < 0) return (-x-1)%4 == 0;
	return x <= 1582?x%4 == 0:((x%4 == 0&&x%100 != 0)||x%400 == 0); 
} 
int G(int x, int y, int z) { return F(x)?s1[y-1]+z:s0[y-1]+z; }
i64 S(int x, int y, int z)
{
	if(x < 0) return (4712/4-(-x-1)/4)+(4713+x)*365ll+G(x, y, z)-1;
	if(x <= 1581||(x == 1582&&y < 10)) return S(-1, 12, 31)+(x-1)/4+(x-1)*365ll+G(x, y, z);
	if(x == 1582&&y == 10&&z <= 4) return S(-1, 12, 31)+(x-1)/4+(x-1)*365ll+G(x, y, z);
	if(x == 1582) return S(-1, 12, 31)+(x-1)/4+(x-1)*365ll+G(x, y, z)-10;
	return S(1582, 12, 31)+((x-1)/4-1582/4)+((x-1)/400-1582/400)-
		((x-1)/100-1582/100)+((x-1)-1582)*365ll+G(x, y, z);
}
int q; i64 v;
int main()
{
	freopen("julian.in", "r", stdin), freopen("julian.out", "w", stdout);
	for(int i = 1; i <= 12; ++i) s0[i] += s0[i-1], s1[i] += s1[i-1];
	scanf("%d", &q);
	for(int l, r, x, A, B, C; q--; )
	{
		scanf("%lld", &v);	
		if(v <= S(-1, 12, 31))
		{
			l = -4713, r = -1;
			while(l <= r) x = (l+r)>>1, S(x, 1, 1) <= v?(A = x, l = x+1):(r = x-1);
			l = 1, r = 12;
			while(l <= r) x = (l+r)>>1, S(A, x, 1) <= v?(B = x, l = x+1):(r = x-1);
			l = 1, r = F(A)?s1[B]-s1[B-1]:s0[B]-s0[B-1];
			while(l <= r) x = (l+r)>>1, S(A, B, x) <= v?(C = x, l = x+1):(r = x-1);			
		}
		else if(v <= S(1582, 10, 4))
		{
			l = 1, r = 1582;	
			while(l <= r) x = (l+r)>>1, S(x, 1, 1) <= v?(A = x, l = x+1):(r = x-1);
			l = 1, r = 12;
			while(l <= r) x = (l+r)>>1, S(A, x, 1) <= v?(B = x, l = x+1):(r = x-1);
			l = 1, r = F(A)?s1[B]-s1[B-1]:s0[B]-s0[B-1];
			while(l <= r) x = (l+r)>>1, S(A, B, x) <= v?(C = x, l = x+1):(r = x-1);			
		}
		else 
		{
			l = 1582, r = 1e9;	
			while(l <= r) x = (l+r)>>1, S(x, 1, 1) <= v?(A = x, l = x+1):(r = x-1);
			l = 1, r = 12; if(A == 1582) l = 10;
			while(l <= r) x = (l+r)>>1, S(A, x, 1) <= v?(B = x, l = x+1):(r = x-1);
			l = 1, r = F(A)?s1[B]-s1[B-1]:s0[B]-s0[B-1]; if(A == 1582&&B == 10) l = 15;
			while(l <= r) x = (l+r)>>1, S(A, B, x) <= v?(C = x, l = x+1):(r = x-1);			
		}
		if(A < 0) printf("%d %d %d BC\n", C, B, -A);
		else printf("%d %d %d\n", C, B, A);
	}
	return 0;	
}
