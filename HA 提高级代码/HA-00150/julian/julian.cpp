#include<bits/stdc++.h>

using namespace std;

#define re register

const int maxn = 1e6 + 1;
const int INF = 1e9 + 7;

int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int read()
{
	re int x = 0, f = 1, ch = getchar();
	while(!isdigit(ch)){ if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

int n;

int main()
{
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);	
	n = read();
	for(int i = 1; i <= n; i ++)
	{
		int Q = read(), ans_y = 0, ans_m = 0, ans_d = 0;
		if(Q < 1721424) {
			int S_year = Q / 1461;
			int Y = Q % 1461;
			ans_y = 4713 - S_year * 4;
			for(int k = 1; k <= 4; k ++)
			{
				if(Y - 365 - (k == 1) >= 0) {
					Y = Y - 365 - (k == 1);
					ans_y --;
					continue;
				}
				for(int j = 1; j <= 12; j ++)
				{
					if(Y - a[j] - (k == 1 && j == 2) < 0) { ans_m = j; break; }
					Y -= a[j]; Y -= (k == 1 && j == 2);
				}
				ans_d = Y + 1;
				printf("%d %d %d BC\n", ans_d, ans_m, ans_y);
				break;
			}
			continue;
		}
		Q -= 1721424;
		if(Q <= 577460) {
			int S_year = Q / 1461;
			int Y = Q % 1461;
			ans_y = S_year * 4 + 1;
			for(int k = 1; k <= 4; k ++)
			{
				if(Y - 365 - (k == 4) >= 0) {
					Y = Y - 365 - (k == 4);
					ans_y ++;
					continue;
				}
				for(int j = 1; j <= 12; j ++)
				{
					if(Y - a[j] - (k == 4 && j == 2) < 0) { ans_m = j; break; }
					Y -= a[j]; Y -= (k == 4 && j == 2);
				}
				ans_d = Y + 1;
				printf("%d %d %d\n", ans_d, ans_m, ans_y);
				break;
			}
			continue;		
		}
		if(Q - 577460 < 355) {
			Q -= 577460;
			for(int j = 1; j <= 12; j ++)
			{
				if(j == 10) {
					if(Q - 21 < 0) { ans_m = j; break; }
					Q -= 21; continue;
				}
				if(Q - a[j] < 0) { ans_m = j; break; }
				Q -= a[j];
			}
			ans_d = Q + 1;
			printf("%d %d 1582\n", ans_d, ans_m);
			continue;
		}
	}
	return 0;
}
