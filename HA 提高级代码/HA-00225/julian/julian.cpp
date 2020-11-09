#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define rg register
using namespace std;

int q,r;
int a[13] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline int readint();
void prin(int dy, int mo ,int ye)
{
	if (ye < 0)
		printf("%d %d %d BC\n",dy,mo,abs(ye));
	else printf("%d %d %d\n",dy,mo,ye);
}

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q = readint();
	for (rg int k = 1; k <= q; ++k)
	{
		int ye = -4713, mo = 1, dy = 1;
		r = readint();
		int num = 1;
		while (r > 0)
		{	
			if (num == 13) num = 1;
			if (mo == 13) mo = 1, ye += 1;
			if (ye == 0) ye = 1;
			//printf("::%d %d %d %d %d\n",r,num,dy,mo,ye);
			if (ye < 1582)
			{
				if(((ye < 0 && (abs(ye)-1) % 4 == 0) || (ye > 0 && ye % 4 ==0)) && r > 366)
				{r -= 366; ++ye; continue;}
				else if(((ye < 0 && (abs(ye)-1) % 4 == 0) || (ye > 0 && ye % 4 ==0)) && r > 365)
				{r -= 365; ++ye; continue;} 
				if (r < a[num])
				{
					dy += r; r = 0;
					prin(dy,mo,ye);
					break;
				}
				else if (r >= a[num])
				{
					if (((ye < 0 && (abs(ye)-1) % 4 == 0) || (ye > 0 && ye % 4 ==0)) && mo == 2)
					{
						if (r != 29)
						{
							mo++; r -= a[0]; ++num;
						}
						else if(r == 29)
						{
							prin(1,3,ye); r = 0;
							break;
						}
					}
					else {mo++; r -= a[num]; ++num;}
				}
			}
			else if (ye == 1582)
			{
				//printf("::%d %d %d %d %d\n",r,num,dy,mo,ye);
				if (r < a[num])
				{
					if(mo == 10)
					{
						if ((dy + r) < 5 || (dy + r) > 14)
						{
							dy += r; r = 0;
							prin(dy,mo,ye);
							break;
						}
						else 
						{
							dy += (14 + (r - 3));
							if (dy <= a[num])
							{
								r = 0;
								prin(dy,mo,ye);
								break;
							}
							else
							{
								mo++; dy -= a[num];
								r = 0; prin(dy,mo,ye); break;
							}
						}
					}
				}
				else if (mo == 10 && (r >= (a[num]-10)))
					{
						mo++; r -= (a[num]-10); ++num;
					}
				else if (mo != 10 && r >= a[num])
				{
					mo++; r -= a[num]; ++num;
				}
			}
			else if(ye > 1582)
			{
				//printf("::%d %d %d %d %d\n",r,dy,mo,ye);
				if((((ye % 4) == 0 && (ye % 100) != 0) || ye % 400 == 0) && r > 366)
				{r -= 366; ++ye; continue;}
				else if( (ye % 4 != 0 || (ye % 4 == 0 && ye % 100 == 0) || ye % 400 !=0) && r > 365)
				{r -= 365; ++ye; continue;}
				if (r < a[num])
				{
					dy += r; r = 0;
					prin(dy,mo,ye);
					break;
				}
				else if (r >= a[num])
				{
					if ((((ye % 4) == 0 && (ye % 100) != 0) || ye % 400 == 0) && mo == 2)
					{
						if (r != 29)
						{
							mo++; r -= a[0]; ++num;
						}
						else if(r == 29)
						{
							prin(1,3,ye); r = 0;
							break;
						}
					}
					else {mo++; r -= a[num]; ++num;}
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
inline int readint()
{
	int x = 0, f = 1;char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
	return f * x;
}
