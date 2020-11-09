#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull e;
int mon[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int rmon[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
ull k, q, l, p;
ull year, month, day;
ull rw, kw, qw, lw, pw, yearw, monthw, dayw;
ull r;
ull aa, ab, ac, ad, ae, af, ag, ayear, amonth, aday, ah, ai;
int mo (int m, bool run){
	if (run){
		if (m < rmon[1])return 1;
		if (m >= rmon[1] && m < rmon[2])return 2;
		if (m >= rmon[2] && m < rmon[3])return 3;
		if (m >= rmon[3] && m < rmon[4])return 4;
		if (m >= rmon[4] && m < rmon[5])return 5;
		if (m >= rmon[5] && m < rmon[6])return 6;
		if (m >= rmon[6] && m < rmon[7])return 7;
		if (m >= rmon[7] && m < rmon[8])return 8;
		if (m >= rmon[8] && m < rmon[9])return 9;
		if (m >= rmon[9] && m < rmon[10])return 10;
		if (m >= rmon[10] && m < rmon[11])return 11;
		if (m >= rmon[11] && m < rmon[12])return 12;
	}
	else {
		if (m < mon[1])return 1;
		if (m >= mon[1] && m < mon[2])return 2;
		if (m >= mon[2] && m < mon[3])return 3;
		if (m >= mon[3] && m < mon[4])return 4;
		if (m >= mon[4] && m < mon[5])return 5;
		if (m >= mon[5] && m < mon[6])return 6;
		if (m >= mon[6] && m < mon[7])return 7;
		if (m >= mon[7] && m < mon[8])return 8;
		if (m >= mon[8] && m < mon[9])return 9;
		if (m >= mon[9] && m < mon[10])return 10;
		if (m >= mon[10] && m < mon[11])return 11;
		if (m >= mon[11] && m < mon[12])return 12;
	}
}
int main (){
	freopen ("julian.in", "r", stdin);
	freopen ("julian.out", "w", stdout);
	cin >> e;
	for (int i = 0; i < e; i++){
		cin >> r;
		if (r < 1721424){
			k = r / 1461;
			q = r % 1461;
			if (q <= 365){
				l = 0;
				p = q;
				month = mo (p, 1);
				day = p - rmon[month - 1] + 1;
			}
			else {
				l = (q - 366) / 365 + 1;
				p = (q - 366) % 365;
				month = mo (p, 0);
				day = p - mon[month - 1] + 1;
			}
			year = 4713 - k * 4 - l;
			cout << day << " " << month << " " << year << " BC" << endl;
		}
		if (r >= 1721424 && r < 2298796){
			rw = r - 1721424;
			kw = rw / 1461;
			qw = rw % 1461;
			if (qw >= 1095){
				lw = 3;
				pw = qw - 1095;
				monthw = mo (pw, 0);
				dayw = pw - rmon[monthw - 1] + 1;
			}
			else {
				lw = qw / 365;
				pw = qw % 365;
				monthw = mo (pw, 1);
				dayw = pw - mon[monthw - 1] + 1;
			}
			yearw = kw * 4 + lw + 1;
			cout << dayw << " " << monthw << " " << yearw << endl;
		}
		if (r >= 2298796){
			aa = r - 1721426;
			ab = aa / 146097;
			ac = aa % 146097;
			ad = ac / 36524;
			ae = ac % 36524;
			af = ae / 1461;
			ag = ae % 1461;
			if (ag >= 1095){
				ai = 3;
				ah = ag - 1095;
				amonth = mo (ah, 0);
				aday = ah - rmon[amonth - 1] + 1;
			}
			else {
				ai = ag / 365;
				ah = ag % 365;
				amonth = mo (ah, 1);
				aday = ah - mon[amonth - 1] + 1;
			}
			ayear = ab * 400 + ad * 100 + af * 4 + ai + 1;
			cout << aday << " " << amonth << " " << ayear << endl;
		}
	}
	return 0;
}
