#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int r;
		cin >> r;
		//1721424 = ¹«Ôª
		if(r == 1721424)
		{
			cout << "0 1 1" << endl;
		}
		else if(r > 1721424)
		{
			r-= 1721424;
			int y = r / 1.0 / (365*4+1);
			int yy = r - y * (365*4+1);
			int m = 1;
			int mm = yy;
			yy /= 365;
			y *= 4;
			y += yy;
			while(mm > mon[m+1])
			{
				mm -= mon[m+1];
				m++;
			}
			cout << mm << ' ' << m << ' ' << y << endl;
		}
		else
		{
			cout << "0 1 1 BC" << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
