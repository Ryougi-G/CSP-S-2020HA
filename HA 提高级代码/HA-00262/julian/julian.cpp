#include <cstdio>
const int Month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int RD = 2298883 + 263;

int read()
{
	int ch, f = 1;
	while ((ch = getchar()) < '0' || ch > '9')
		f = (ch == '-' ? -1 : 1);
	int ret = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9')
		ret = ret * 10 + ch - '0';
	return ret * f;
}

void work(int d)
{
	if (d <= RD)
	{
		int year = -4713;
		while (d >= 365)
		{
			if ((year < 0 && year % 4 == -1) || (year % 4 == 0 && year > 0))
			{
				if (d < 366)
					break;
				else
					d -= 366, year = (year == -1 ? 1 : year + 1);
			}	
			else
				d -= 365, year = (year == -1 ? 1 : year + 1);
		}
		int month = 1;
		for (int i = 1; i <= 12; i++)
		{
			int t = (i == 2 && ((year < 0 && year % 4 == -1) || (year % 4 == 0 && year > 0)) ? 29 : Month[i]);
			if (d < t)
				break;
			else
				d -= t, month++; 
		}
		int day = 1 + d;
		if (year < 0)
			printf("%d %d %d BC\n", day, month, -year);
		else
			printf("%d %d %d\n", day, month, year);
	}
	else
	{
		d -= RD;
		d--;
		int year = 1582;
		while (d >= 365)
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			{
				if (d < 366)
					break;
				else
					d -= 366, year++;
			}	
			else
				d -= 365, year++;
		}
		int month = 10;
		for (int i = 10; i <= 12; i++)
		{
			int t = (i == 2 && ((year < 0 && year % 4 == -1) || (year % 4 == 0 && year > 0)) ? 29 : Month[i]);
			if (d < t)
				break;
			else
				d -= t, month++; 
		}
		 
		if (month > 12)
		{
			year++, month -= 12;
			for (int i = 1; i <= 12; i++)
			{
				int t = (i == 2 && ((year < 0 && year % 4 == -1) || (year % 4 == 0 && year > 0)) ? 29 : Month[i]);
				if (d < t)
					break;
				else
					d -= t, month++; 
			}
		}
		int day = 1 + d;
		if (day > (month == 2 && ((year < 0 && year % 4 == -1) || (year % 4 == 0 && year > 0)) ? 29 : Month[month]))
			month++, day -= month == 2 && ((year < 0 && year % 4 == -1) || (year % 4 == 0 && year > 0)) ? 29 : Month[month];
		if (month > 12)
			year++, month -= 12;
		printf("%d %d %d\n", day, month, year);
	}
}

int main()
{
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	int q = read();
	while (q--)
	{
		int r = read();
		work(r);
	}
	return 0;
}
