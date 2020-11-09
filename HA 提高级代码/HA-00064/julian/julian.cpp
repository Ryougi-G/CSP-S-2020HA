#include<bits/stdc++.h>
using namespace std;
long long n, m1, d, m, y = 4713, flag = 0;
string cen;
void pd() {
	if (m == 1) if (d > 31) d = 1, m ++;
	if (m == 2) if (d > 28) d = 1, m ++;
	if (m == 3) if (d > 31) d = 1, m ++;
	if (m == 4) if (d > 30) d = 1, m ++;
	if (m == 5) if (d > 31) d = 1, m ++;
	if (m == 6) if (d > 30) d = 1, m ++;
	if (m == 7) if (d > 31) d = 1, m ++;
	if (m == 8) if (d > 31) d = 1, m ++;
	if (m == 9) if (d > 30) d = 1, m ++;
	if (m == 10) if (d > 31) d = 1, m ++;
	if (m == 11) if (d > 30) d = 1, m ++;
	if (m == 12) if (d > 31) d = 1, m ++;
}
void pdr() {
	if (m == 1) if (d > 31) d = 1, m ++;
	if (m == 2) if (d > 29) d = 1, m ++;
	if (m == 3) if (d > 31) d = 1, m ++;
	if (m == 4) if (d > 30) d = 1, m ++;
	if (m == 5) if (d > 31) d = 1, m ++;
	if (m == 6) if (d > 30) d = 1, m ++;
	if (m == 7) if (d > 31) d = 1, m ++;
	if (m == 8) if (d > 31) d = 1, m ++;
	if (m == 9) if (d > 30) d = 1, m ++;
	if (m == 10) if (d > 31) d = 1, m ++;
	if (m == 11) if (d > 30) d = 1, m ++;
	if (m == 12) if (d > 31) d = 1, m ++;
}
int main() {
	freopen("julian3.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin >> m1;
	cen = "BC";
	while (m1 --) {
		y = 4713, flag = 0, m = 1, d = 1;
		cin >> n;
		while (n--) {
			if (y == 0) {
				flag = 1;
				y = 1;
			}
			if (!flag) {
				d ++;
				if ((y - 1) % 4 == 0) {
					pdr();
					if (m == 13) {
						y --;
						m = 1;
					}
					
				} else {
					pd();
					if (m == 13) {
						y --;
						m = 1;
					}
					
				}
			} else {
				d ++;
				if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
					pdr();
					if (m == 13) {
						y ++;
						m = 1;
					}
					
				} else {
					pd();
					if (m == 13) {
						y ++;
						m = 1;
					}
					
				}
				
			}
		}
		if (!flag) {
			cout << d << ' ' << m << ' ' << y << ' ' << cen << endl;
		} else cout << d << ' ' << m << ' ' << y << endl;
	}

	return 0;
}
