#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll r;

namespace task1 {
	int y = -4713, m = 1, d = 1, tot = 0;
	const int H[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool isEnd() {
		return y == 1582 && m == 10 && d == 4;
	}
	
	const int N = 3e6 + 9;
	
	int toy[N], tom[N], tod[N];
	
	void init() {
		while (true) {
	//		if (y % 1000 == 0 && d == 1 && m == 1)
	//			system("pause");
	//		
			toy[tot] = y;
			tom[tot] = m;
			tod[tot] = d;
			tot++;
			
			if (isEnd())
				break;
			d++;
			if (m == 2) {
				int t = 28;
				if ((y < 0 && (y + 1) % 4 == 0) || (y > 0 && y % 4 == 0)) 
					t = 29;
				if (d > t) {
					d = 1;
					m += 1;
				}
			} else {
				if (d > H[m]) {
					d = 1;
					m += 1;
				}
			}
			if (m > 12) {
				y += 1;
				m -= 12;
				if (y == 0)
					y++;
				}
				
	//		if (y % 100 == 0 && d == 1 && m == 1)
	//			 cout << y << " " << m << " " << d << endl;
		}
		
	//	cout << toy[10] << " " << tom[10] << " " << tod[10] << endl;
	//	cout << toy[100] << " " << tom[100] << " " << tod[100] << endl;
	//	cout << toy[1000] << " " << tom[1000] << " " << tod[1000] << endl;
	//	cout << toy[2000000] << " " << tom[2000000] << " " << tod[2000000] << endl;
	//
	//	cout << tot << endl;
		return ;
	}
	pair<pair<int, int>, int > Query(ll r) {
		return make_pair(make_pair(toy[r], tom[r]), tod[r]);
	}
}

void solve(ll r) {
	const int T = 2299161;
	
	if (r <= T) {
		// if date is in Julian calendar
		// 4713 1 1 BC to 1582 10 4
		pair<pair<int, int>, int > q = task1::Query(r);
		int y = q.first.first, m = q.first.second, d = q.second;
		if (y < 0)
			printf("%d %d %d BC\n", d, m, -y);
		else 
			printf("%d %d %d\n", d, m, y);
	} else {
		// if date is in Gregorian calendar£©£¬
		// from 1582 10 15 to ...
		r -= T;
		int y = 1461, m = 10, d = 5;
		
	}
}

int main() {
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	task1::init();
	for (scanf("%d", &n); n; n--) {
		scanf("%lld", &r);
		solve(r);
	}
	return 0;
}
