#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned long long ll;

const int N = 1010;

bool run(ll a)
{
	if(a % 400 == 0)
		return true;
	if(a % 4 == 0 && a % 100 != 0)
		return true;
	
	return false;
}

void jl(ll a)
{
	int year = -4712; int month = 1;
	if(a < 1721058)//公元前 
	{
		ll b;
		b = a / 1461;
		year = year + b * 4;
		b = a % 1461;
		b += 1;
		if(b - 366 > 0)
		{
			b -= 366;
			year++;
		}
		while(b - 365 > 0)
		{
			b -= 365;
			year++;
		}
		year--;
		
		if((-year - 1) % 4 == 0)
		{
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//2
			}
			if(b - 29 > 0)
			{
				b -= 29;
				month++;//3
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//4
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//5
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//6
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//7
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//8
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//9
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//10
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//11
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//12
			}
			//year = -year;
			cout << b << ' ' << month << ' ' << year << ' ' << "DC" << endl;
			return;
		}
		else
		{
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//2
			}
			if(b - 28 > 0)
			{
				b -= 28;
				month++;//3
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//4
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//5
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//6
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//7
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//8
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//9
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//10
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//11
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//12
			}
			//year = -year;
			cout << b << ' ' << month << ' ' << year << ' ' << "DC" << endl;
			return;
		}
	}
	
	else if((a >= 1721058) && (a <= 2306694))//公元后儒略历
	{
		year = 1;
		ll b;
		a -= 1721057;
		b = a / 1461;
		year = year + b * 4;
		b = a % 1461;
		b += 1;
		for (int i = 1; i <= 3; i++)
		{
			if(b - 365 > 0)
			{
				b -= 365;
				year++;
			}
			else 
				break;
		}
		if(b - 366 > 0)
		{
			b -= 366;
			year++;
		}
		
		if(year % 4 == 0)
		{
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//2
			}
			if(b - 29 > 0)
			{
				b -= 29;
				month++;//3
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//4
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//5
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//6
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//7
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//8
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//9
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//10
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//11
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//12
			}
			cout << b << ' ' << month << ' ' << year << endl;
			return;
		}
		else
		{
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//2
			}
			if(b - 28 > 0)
			{
				b -= 28;
				month++;//3
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//4
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//5
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//6
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//7
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//8
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//9
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//10
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//11
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//12
			}
			cout << b << ' ' << month << ' ' << year << endl;
			return;
		}
	}
	
	else
	{
		year = 1582;
		int month = 1;
		a -= 2306694;
		if(a <= 77)
		{
			month = 10;
			if(a - 16 > 0)
			{
				a -= 16;
				month++;
			}
			if(a - 30 > 0)
			{
				a -= 30;
				month++;
			}
			cout << a << month << year << endl; 
			return;
		}
		
		a -= 77;
		year++;
		ll b;
		b = a / 1461;
		year = year + 4 * b;
		b = a % 1461;
		b += 1;
		for (int i = 1; i <= 3; i++)
		{
			if(b - 365 > 0)
			{
				b -= 365;
				year++;
			}
			else 
				break;
		}
		if(b - 366 > 0)
		{
			b -= 366;
			year++;
		}
		
		if(run(year))
		{
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//2
			}
			if(b - 29 > 0)
			{
				b -= 29;
				month++;//3
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//4
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//5
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//6
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//7
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//8
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//9
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//10
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//11
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//12
			}
			cout << b << ' ' << month << ' ' << year << endl;
			return;
		}
		else
		{
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//2
			}
			if(b - 28 > 0)
			{
				b -= 28;
				month++;//3
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//4
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//5
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//6
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//7
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//8
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//9
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//10
			}
			if(b - 31 > 0)
			{
				b -= 31;
				month++;//11
			}
			if(b - 30 > 0)
			{
				b -= 30;
				month++;//12
			}
			cout << b << ' ' << month << ' ' << year << endl;
			return;
		}
	}
}

int main()
{
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	
	int n;
	ll s[N];
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	
	for(int i = 1; i <= n; i++)
		jl(s[i]);
	return 0;
}
