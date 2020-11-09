#include <bits/stdc++.h>

using namespace std;

long long n, num, day = 1, mon = 1, yar = 4713;
bool cen = true, key = true;

inline int read()
{
	int xig = 0; bool fl = 0; char ch = getchar();
	while (!isdigit(ch)) fl |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) xig = (xig << 3) + (xig << 1) + (ch ^ 48), ch = getchar();
	return fl ? -xig : xig;
}

void print()
{
	printf ("%lld %lld %lld ", day, mon, yar);
	
	if (cen) printf ("BC");
	
	return ;
}

int main()
{
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	
	n = read();
	
	for (register int i = 1; i <= n; ++ i)
	{
		num = read();
		
		for (register int j = 1; j <= num; ++ j)
		{
			if (cen && key)
			{
				++ day;
				
				if ( (yar == 1582) && (mon == 10) && (day == 5) ) { day = 14; key = false; goto next;}
				
				if ( (day == 28) && (mon == 2) && ( (yar - 1) % 4 != 0 ) ) { day = 0; ++ mon; }
				else if ( (day == 29) && (mon == 2) && ( (yar - 1 != 0) && ( (yar - 1) % 4 == 0 ) ) ) { day = 0; ++ mon; }
				else if (day == 30){
					if (mon == 4) { day = 0; ++ mon; }
					if (mon == 6) { day = 0; ++ mon; }
					if (mon == 9) { day = 0; ++ mon; }
					if (mon == 11) { day = 0; ++ mon; }
				}
				else if (day == 31){
					if (mon == 1) { day = 0; ++ mon; }
					if (mon == 3) { day = 0; ++ mon; }
					if (mon == 5) { day = 0; ++ mon; }
					if (mon == 7) { day = 0; ++ mon; }
					if (mon == 8) { day = 0; ++ mon; }
					if (mon == 10) { day = 0; ++ mon; }
					if (mon == 12) { day = 0; mon = 1; yar --; }
				}
			}
			
			next:
			
			if (cen && !key)
			{
				++ day;
				
				if ( (yar == 1582) && (mon == 10) && (day == 5) ) day = 15;
				
				if ( (day == 28) && (mon == 2) && (yar % 4 != 0) ) { day = 0; ++ mon; }
				else if ( (day == 29) && (mon == 2) && ( ( (yar % 100 != 0) && (yar % 4 == 0) ) || (yar % 400 == 0) ) ) { day = 0; ++ mon; }
				else if (day == 30){
					if (mon == 4) { day = 0; ++ mon; }
					if (mon == 6) { day = 0; ++ mon; }
					if (mon == 9) { day = 0; ++ mon; }
					if (mon == 11) { day = 0; ++ mon; }
				}
				else if (day == 31){
					if (mon == 1) { day = 0; ++ mon; }
					if (mon == 3) { day = 0; ++ mon; }
					if (mon == 5) { day = 0; ++ mon; }
					if (mon == 7) { day = 0; ++ mon; }
					if (mon == 8) { day = 0; ++ mon; }
					if (mon == 10) { day = 0; ++ mon; }
					if (mon == 12) { day = 0; mon = 1; yar --; }
				}
				
				if (yar == 0) { cen = false; }
			}
			
			if (!cen)
			{
				++ day;
				
				if ( (day == 28) && (mon == 2) && (yar % 4 != 0) ) { day = 0; ++ mon; }
				else if ( (day == 29) && (mon == 2) && ( ( (yar % 100 != 0) && (yar % 4 == 0) ) || (yar % 400 == 0) ) ) { day = 0; ++ mon; }
				else if (day == 30){
					if (mon == 4) { day = 0; ++ mon; }
					if (mon == 6) { day = 0; ++ mon; }
					if (mon == 9) { day = 0; ++ mon; }
					if (mon == 11) { day = 0; ++ mon; }
				}
				else if (day == 31){
					if (mon == 1) { day = 0; ++ mon; }
					if (mon == 3) { day = 0; ++ mon; }
					if (mon == 5) { day = 0; ++ mon; }
					if (mon == 7) { day = 0; ++ mon; }
					if (mon == 8) { day = 0; ++ mon; }
					if (mon == 10) { day = 0; ++ mon;}
					if (mon == 12) { day = 0; mon = 1; ++ yar; }
				}
			}
		}
		
		print();
	}
	
	return 0;
}


