#include <bits/stdc++.h>
using namespace std;
int Q, r;
int ansd, ansm, ansy;
int mon1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int mon2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline int read() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			f = 1;
		c = getchar();
	}
	while (c <= '9' && c >= '0') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	if (f)
		return ~(x - 1);
	return x;
}
inline bool work(int r) {
	if (r < 366) {//若该日期在前4713年 
		ansy = 4713;
		for (register int i = 1; i <= 12; i++) {
			if (r - mon2[i] > 0)
				r -= mon2[i];
			else if (r - mon2[i] == 0) {
				ansm = i + 1;
				ansd = 1;
				return 1;
			}
			else if (r - mon2[i] < 0) {
				ansm = i;
				ansd = r + 1;
				return 1;
			}
		}
	}
	else if (r <= 1721424) {//该日期在前4713年之后，在公元前1年（含）之前 
		while (r >= 0) {
			ansy++;
			if (ansy % 4 == 1)
				r -= 366;
			else
				r -= 365;
		}
		if (ansy % 4 == 1)
			r += 366;
		else
			r += 365;
		ansy--;
		ansy = -ansy + 4713;
		if (ansy % 4 == 1) {
			for (register int i = 1; i <= 12; i++) {
				if (r - mon2[i] > 0)
					r -= mon2[i];
				else if (r - mon2[i] == 0) {
					ansm = i + 1;
					ansd = 1;
					return 1;
				}
				else if (r - mon2[i] < 0) {
					ansm = i;
					ansd = r + 1;
					return 1;
				}
			}
		}
		else {
			for (register int i = 1; i <= 12; i++) {
				if (r - mon1[i] > 0)
					r -= mon1[i];
				else if (r - mon1[i] == 0) {
					ansm = i + 1;
					ansd = 1;
					return 1;
				}
				else if (r - mon1[i] < 0) {
					ansm = i;
					ansd = r + 1;
					return 1;
				}
			}
		}
	}
	else if (r - 1721424 <= 578102) {//该日期在公元1年到1582年10月4日 
		r -= 1721424;
		while (r >= 0) {
			ansy++;
			if (ansy % 4 == 0)
				r -= 366;
			else
				r -= 365;
		}
		if (ansy % 4 == 0)
			r += 366;
		else
			r += 365;
		if (ansy % 4 == 0) {
			for (register int i = 1; i <= 12; i++) {
				if (r - mon2[i] > 0)
					r -= mon2[i];
				else if (r - mon2[i] == 0) {
					ansm = i + 1;
					ansd = 1;
					return 0;
				}
				else if (r - mon2[i] < 0) {
					ansm = i;
					ansd = r + 1;
					return 0;
				}
			}
		}
		else {
			for (register int i = 1; i <= 12; i++) {
				if (r - mon1[i] > 0)
					r -= mon1[i];
				else if (r - mon1[i] == 0) {
					ansm = i + 1;
					ansd = 1;
					return 0;
				}
				else if (r - mon1[i] < 0) {
					ansm = i;
					ansd = r + 1;
					return 0;
				}
			}
		}
	}
	else {//该日期为1582年10月15日至今 
		r += 10;
		r -= 1721424;
		r -= 578102;
		if (r <= 16) {
			r -= 10;
			ansy = 1582;
			ansm = 10;
			ansd = 15 + r;
			return 0;
		}
		else if (r - 16 <= 61) {
			r -= 10;
			r -= 16;
			ansy = 1582;
			for (register int i = 11; i <= 12; i++) {
				if (r - mon1[i] > 0)
					r -= mon1[i];
				else if (r - mon1[i] == 0) {
					ansm = i + 1;
					ansd = 1;
					return 0;
				}
				else if (r - mon1[i] < 0) {
					ansm = i;
					ansd = r + 1;
					return 0;
				}
			}
		}
		else {
			r -= 16;
			r -= 61;
			r -= 11;
			for (register int i = 1584; ; i++) {
				if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
					r -= 366;
				else
					r -= 365;
				if (r == 0) {
					ansy = i + 1;
					ansm = 1;
					ansd = 1;
					return 0;
				}
				else if (r < 0) {
					ansy = i;
					if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
						r += 366;
					else
						r += 365;
					break;
				}
			}
			if ((ansy % 4 == 0 && ansy % 100 != 0) || (ansy % 400 == 0)) {
				for (register int i = 1; i <= 12; i++) {
					if (r - mon2[i] > 0)
						r -= mon2[i];
					else if (r - mon2[i] == 0) {
						ansm = i + 1;
						ansd = 1;
						return 0;
					}
					else if (r - mon2[i] < 0) {
						ansm = i;
						ansd = r + 1;
						return 0;
					}
				}
			}
			else {
				for (register int i = 1; i <= 12; i++) {
					if (r - mon1[i] > 0)
						r -= mon1[i];
					else if (r - mon1[i] == 0) {
						ansm = i + 1;
						ansd = 1;
						return 0;
					}
					else if (r - mon1[i] < 0) {
						ansm = i;
						ansd = r + 1;
						return 0;
					}
				}
			}
		}
	}
}
int main() {
	freopen ("julian.in", "r", stdin);
	freopen ("julian.out", "w", stdout);
	Q = read();
	while (Q--) {
		r = read();
		ansd = 0;
		ansm = 0;
		ansy = 0;
		if (work(r))
			printf("%d %d %d BC\n", ansd, ansm, ansy);
		else
			printf("%d %d %d\n", ansd, ansm, ansy);
	}
	return 0;
}

