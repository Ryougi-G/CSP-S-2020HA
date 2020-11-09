#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

inline long long read(){
	long long t = 0,flag = 1;
	register char c = getchar();
	while (c < 48 || c > 57) {if (c == '-') flag = -1;c = getchar();}
	while (c >= 48 && c <= 57) t = (t << 1) + (t << 3) + (c ^ 48),c = getchar();
	return flag * t;
}

inline void print(long long t){
	if (t < 0) putchar('-'),t = -t;
	if (t > 9) print(t / 10);
	putchar(t % 10 + 48);
}

int n,m,c,k,p[1000001],q[1000001],tot;
long long sum,a[1000001];
bool cantchoose[70];

int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n = read(),m = read(),c = read(),k = read();
	for (int i = 1;i <= n;i++) a[i] = read(),sum |= a[i];
	for (int i = 1;i <= m;i++){
		p[i] = read(),q[i] = read(),cantchoose[p[i]] = 1;
		if (sum >> p[i] & 1) cantchoose[p[i]] = 0;
	}
	for (int i = 0;i < k;i++){
		if (!cantchoose[i]) ++tot;
	}
	print((1 << (long long)tot) - n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
