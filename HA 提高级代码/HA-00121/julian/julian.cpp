#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

inline int read(){
	int t = 0,flag = 1;
	register char c = getchar();
	while (c < 48 || c > 57) {if (c == '-') flag = -1;c = getchar();}
	while (c >= 48 && c <= 57) t = (t << 1) + (t << 3) + (c ^ 48),c = getchar();
	return flag * t;
}

inline bool judge(int year){
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

const int point1 = 2299160,point2 = 146097,point3 = 1461,point4 = 78;
int Q,r,year,month,day,M[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	Q = read();
	while (Q--){
		year = -4713,month = 1,day = 1,r = read();
		if (r > point1){
			r -= point1 + 1,year = 1582,month = 10,day = 15;
			if (r >= point4) r -= point4,++year,month = 1,day = 1;
			year += 400 * (r / point2),r %= point2;
			int temp = judge(year) ? 366 : 365;
			while (r >= temp){
				r -= temp;
				++year;
				temp = judge(year) ? 366 : 365;
			}
			if (judge(year)) ++M[2];
			for (int i = month;i <= 12;i++){
				if (r >= M[i]) r -= M[i],++month;
				else break;
			}
			day += r;
			if (judge(year)) --M[2];
		}
		else if (r == point1){
			printf("4 10 1582\n");
			continue;
		}else{
			bool flag = 0;
			year += 4 * (r / point3),r %= point3;
			if (year >= 0) ++year,flag = 1;
			int temp;
			if (year < 0) temp = (-year - 1) % 4 ? 365 : 366;
			else temp = (year % 4) ? 365 : 366;
			while (r >= temp){
				r -= temp;
				++year;
				if (year >= 0 && !flag) ++year,flag = 1;
				if (year < 0) temp = (-year - 1) % 4 ? 365 : 366;
				else temp = (year % 4) ? 365 : 366;
			}
			if (temp == 366) ++M[2];
			for (int i = 1;i <= 12;i++){
				if (r >= M[i]) r -= M[i],++month;
				else break;
			}
			day += r;
			if (temp == 366) --M[2];
		}
		if (year < 0) printf("%d %d %d BC\n",day,month,-year);
		else printf("%d %d %d\n",day,month,year);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
