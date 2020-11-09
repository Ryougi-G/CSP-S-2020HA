#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const int maxN = 1e5 + 100;

struct DAYth;
int moth(DAYth x);

struct DAYth{
	int year, month, day;
	bool is_BC;
	void print(){
		if (is_BC == false && year >= 1582){
			if (year == 1582 && month == 10 && day > 4)
				day += 10;
			else
				day += 10;
		}
		if (day > moth(*this)){
			day -= moth(*this);
			month ++;
		}
		if (month > 12){
			month -= 12;
			if (is_BC){
				if (year == 1)
					is_BC = false;
				else
					year --;
			}
			else{
				year ++;
			}
		}
		if (is_BC)
			printf("%d %d %d BC\n", day, month, year);
		else
			printf("%d %d %d\n", day, month, year);
	}
}ans[maxN], now;

void search(int x);

int Q, n, cnt = 1;
int mothh[13] = {28, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
pair <int, int> sorts[maxN];
int main(void){
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	scanf("%d", &Q);
	for (int i = 1; i <= Q; i ++){
		scanf("%d", &n);
		sorts[i].first = n;
		sorts[i].second = i;
	}
	sort(sorts + 1, sorts + Q);
	now.day = 1, now.month = 1, now.year = 4713;
	now.is_BC = true;
	for (cnt = 1; cnt <= Q; cnt ++){
		search(sorts[cnt].first - sorts[cnt - 1].first);
	}
	for (int i = 1; i <= Q; i ++){
		ans[i].print();
	}
	return 0;
}

bool run_year(DAYth x){
	if (x.year > 1582 && !x.is_BC)
		return (x.year % 400 == 0) || ((x.year % 4 == 0) && (x.year % 100 != 0));
	else if (!x.is_BC)
		return (x.year % 4 == 0);
	else
		return (x.year % 4 == 1);
}

int moth(DAYth x){
	if (x.month == 2)
		if (run_year(x))
			return 29;
		else
			return 28;
	else
		return mothh[x.month];
}

int yearth(DAYth x){
	if (run_year(x))
		return 366;
	else
		return 365;
}

void search(int x){
	if (now.day > 1){
		x += (now.day - 1);
		now.day = 1;
	}
	while (now.month != 1){
		now.month --;
		x += (moth(now));
	}
	for (; ; ){
		if (x > yearth(now)){
			x -= yearth(now);
			if (now.is_BC){
				if (now.year == 1)
					now.is_BC = false;
				else
					now.year --;
			}
			else{
				now.year ++;
			}
		}
		else if (x > moth(now)){
			x -= moth(now);
			now.month ++;
		}
		else if (x > 0){
			now.day += x;
			ans[sorts[cnt].second] = now;
			return;
		}
		else{
			ans[sorts[cnt].second] = now;
			return;
		}
	}
}
