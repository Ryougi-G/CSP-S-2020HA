// T1
// DeP
#include <cstdio>
#include <cstdlib>
using namespace std;

const int Pin[] = {
	//  1   2   3   4   5   6   7   8   9  10  11  12
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
const int Run[] = {
	0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool isGre(int Y) {
	if (Y % 400 == 0) return true;
	if (Y % 4 == 0 && Y % 100 != 0) return true;
	return false;
}
bool isJul(int Y, int BC) {
	if (Y % 4 == BC) return true;
	return false;
}

struct Day {
	int Y, M, D; bool BC;

	Day() { }
	Day(int _Y, int _M, int _D, bool _B): Y(_Y), M(_M), D(_D), BC(_B) { }

	bool operator == (const Day& rhs) const {
		return Y == rhs.Y && M == rhs.M && D == rhs.D && BC == rhs.BC;
	}
	
	bool operator < (const Day& rhs) const {
		if (BC && !rhs.BC) return true;
		if (!BC && rhs.BC) return false;
		if (BC && rhs.BC) {
			if (Y != rhs.Y) return Y > rhs.Y;
			if (M != rhs.M) return M < rhs.M;
			return D < rhs.D;
		}
		if (!BC && !rhs.BC) {
			if (Y != rhs.Y) return Y < rhs.Y;
			if (M != rhs.M) return M < rhs.M;
			return D < rhs.D;
		}
		return false;
	}
	bool operator <= (const Day& rhs) const {
		return *this < rhs || *this == rhs;
	}
};

const Day D1 = Day(1582, 10, 4, false), D2 = Day(1582, 10, 15, false);

Day Pls(Day d) {
	if (d == D1) return D2;
	if (d.M == 2) {
		bool isr = (d <= D1)? isJul(d.Y, d.BC): isGre(d.Y);
		if (isr) {
			if (d.D == 29) d.D = 1, d.M = 3;
			else ++d.D;
		} else {
			if (d.D == 28) d.D = 1, d.M = 3;
			else ++d.D;
		}
	} else {
		if (d.D == Pin[d.M]) {
			d.D = 1;
			if (d.M == 12) {
				d.M = 1;
				if (d.BC) {
					if (d.Y == 1) d.Y = 1, d.BC = false;
					else --d.Y;
				} else ++d.Y;
			} else ++d.M;
		} else ++d.D;
	}
	return d;
}

void Add(Day d, int r) {
	// brute
	for (int i = 1; i <= r; ++i) d = Pls(d);

	printf("%d %d %d %s", d.D, d.M, d.Y, d.BC? "BC\n": "\n");
}

int q;

int main() {
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	
	scanf("%d", &q);
	while (q--) {
		static int r;
		scanf("%d", &r);
		Add(Day(4713, 1, 1, true), r);
	}
	return 0;
}
