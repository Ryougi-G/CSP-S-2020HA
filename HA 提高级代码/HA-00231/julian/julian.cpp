#include<cstdio>
#include<iostream>
using namespace std;
int month[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//				    1   2   3    4   5   6   7   8   9  10  11  12

int bc = 1721058;
inline bool run(int x) {
	if((x % 400) == 0) {
		return true;
	}
	else if((x % 4 == 0) && (x % 100 != 0)) {
		return true;
	}
	return false;
}
int ans_y, ans_m, ans_d;
int gel;
inline void before(int x) {
	if(x <= 31)x++;
	int year = (x / 1461) * 4;
	if(year <= 1461)year = 0;
	int res = x % 1461;
	int mon = 1;
	int now = 0;
	while(res > 365) {
		res -= 365;
		year++;
	}
	for(int i = 1; i <= 12; i++) {
		if(res <= month[i])now = i;
		if(now)continue;
		if(res > month[i]) {
			mon++;
			res -= month[i];
		}
	}
	ans_d = res;
	ans_m = mon;
	ans_y = 4713 - year;
}

inline void after(int x) {
	if(x <= 31)x++;
	int year = (x / 1461) * 4;
	int res = x - (year / 4) * 1461;
	int mon = 1;
	int now = 0;
	while(res > 365) {
		res -= 365;
		year++;
	}
	for(int i = 1; i <= 12; i++) {
		if(res <= month[i])now = i;
		if(now)continue;
		if(res > month[i]) {
			mon++;
			res -= month[i];
		}
	}
	ans_d = res;
	ans_m = mon;
	ans_y = year;
}

inline void gelgao(int x) {
	if(x <= 31)x++;
	int Year = 1600;
	int year = (x / 36524) * 100;
	int res = x - (year / 100) * 36524;
	res -= (x / 146303);
	Year += year;
	x = res;
	year = (x / 1461) * 4;
	res = x - (year / 4) * 1461;
	int mon = 1;
	int now = 0;
	while(res > 365) {
		res -= 365;
		year++;
	}
	for(int i = 1; i <= 12; i++) {
		if(res <= month[i])now = i;
		if(now)continue;
		if(res > month[i]) {
			mon++;
			res -= month[i];
		}
	}
	ans_d = res;
	ans_m = mon;
	ans_y = year + Year;	
}
int n, q;
int main() {
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	scanf("%d", &q);
	for(int i = 1; i <= q; i++) {
		scanf("%d", &n);
		if(n <= bc) {
			int x = n;
			before(x);
			printf("%d %d %d ", ans_d, ans_m, ans_y);
			printf("BC\n");
		}
		else 
		if(n > bc) {
			gel = 0;
			n -= bc;
			if(n <= 584390) {
				if(n > 578133)n += 10;
				after(n);
			}
			if(n > 584390) {
				n += 10;
				n -= 584400;
				gelgao(n);
			}
			printf("%d %d %d\n", ans_d, ans_m, ans_y);
		}
	}
	return 0;
}
