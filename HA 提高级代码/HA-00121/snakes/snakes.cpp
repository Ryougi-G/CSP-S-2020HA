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

int T,n,k,x,y,a[1000001];

int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	T = read(),n = read(),--T;
	for (int i = 1;i <= n;i++) a[i] = read();
	if (n == 3){
		if (a[3] >= a[1] + a[2]) printf("1\n");
		else printf("3\n");
	}else printf("%d\n",n);
	while (T--){
		k = read();
		for (int i = 1;i <= k;i++) x = read(),y = read(),a[x] = y;
		if (n == 3){
			if (a[3] >= a[1] + a[2]) printf("1\n");
			else printf("3\n");
		}else printf("%d\n",n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
