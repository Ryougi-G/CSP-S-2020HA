#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline void read(T&x) {
	x = 0; bool w = 1; char c = getchar();
	while(!isdigit(c)) { if(c=='-')w=0; c = getchar(); }
	while(isdigit(c)) { x = x*10+c-'0'; c = getchar(); }
	x = w ? x : -x;
}

int Month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int n, t, mon, yea;

inline bool ren(int y, int o) {
	if(o == 1) return (y-1)%4==0; 
	if(o == 0) return y%4==0;
}

inline void init() {
	n++, mon = 1, yea = 4713; 
}

inline void work() {
	read(n); init(); 
	while(((n>366)||(n>365&&!ren(yea,1))) && yea > 0) {
		if(ren(yea, 1)) n--; 
		n -= 365; yea--;
	}
	if(yea) {
		if(ren(yea, 1)) Month[1]++; 
		for(mon = 1; mon <= 12; mon++) {
			if(n <= Month[mon-1]) break;
			n -= Month[mon-1]; 
		}
		if(ren(yea, 1)) Month[1]--;
		printf("%d %d %d BC\n", n, mon, yea);
	}
	else {
		yea = 1;
		while((n>365&&!ren(yea, 0))||n>366) {
			if(ren(yea, 0)) n--; 
			n -= 365; yea++;
		}
		if(ren(yea, 0)) Month[1]++; 
		for(mon = 1; mon <= 12; mon++) {
			if(n <= Month[mon-1]) break;
			n -= Month[mon-1]; 
		}
		if(ren(yea, 0)) Month[1]--;
		printf("%d %d %d\n", n, mon, yea);
	}
}

signed main() {
	freopen("julian.in","r",stdin); 
	freopen("julian.out","w",stdout);  
	read(t);
	while(t--) work();
	return 0; 
}
