#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int nc1 = 2299160;
int Q;
int yue_[13] = {0 ,31 ,60 ,91 ,121 ,152 ,182 ,213 ,244 ,274 ,305 ,335 ,366} ,yue[13] = {0 ,31 ,59 ,90 ,120 ,151 ,181 ,212 ,243 ,273 ,304 ,334 ,365};
ll x;
int main () {
	freopen ("julian.in","r",stdin);
	freopen ("julian.out","w",stdout);
	scanf ("%d",&Q);
	
	while (Q --) {
		scanf ("%lld",&x);
		if (x <= nc1) {
			int Y5 = x / 1461;
			
			int Y_ = Y5 * 4 ,D_ = 0 ,M_ = 0;
			int d = x % 1461;
			int d1 = d - 1;
			d1 /= 365;
			Y_ += d1;
			bool run = true;
			if (d1 > 0) {
				d %= 365;
				run = false;
			}
			if (run) {
				for (int q = 1;q <= 12;++ q) {
					if (d < yue_[q]) {
						M_ = q;
						d = d - yue_[q - 1];
						break;
					}
				}
			}
			else {
				for (int q = 1;q <= 12;++ q) {
					if (d < yue[q]) {
						M_ = q;
						d = d - yue_[q - 1];
						break;
					}
				}
			}
			D_ = d + 1;
			Y_ -= 4713;
			if (Y_ < 0) {
				Y_ = -Y_;
				printf ("%d %d %d BC\n",D_ ,M_ ,Y_);
			}
			else {
				Y_ ++;
				printf ("%d %d %d\n",D_ ,M_ ,Y_);
			}
		}
		else {
			int Y_ = 1582 ,M_ = 10 ,D_ = 5;
			x = x - nc1 + 9;
			if (x <= 16) {
				D_ += x;
				printf ("%d %d %d\n",D_ ,M_ ,Y_);
			}
			else  {
				x -= 16 ,M_ ++;
				if (x > 30) {
					x -= 30;
					M_ ++;
					if (x > 31) {
						x -= 31;
					}
					else printf ("%d %d %d\n",x ,M_ ,Y_);
				}
				else printf ("%d %d %d\n",x ,M_ ,Y_);
			}
			
		}
	}
	return 0;
}

