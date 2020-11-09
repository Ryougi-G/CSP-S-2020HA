#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}
int n,a;
signed main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.our","w",stdout);
	int t=read();int now=t;
	time(0);
	while(t){
		a=rand();
		if(t==now)n=read(); t--;
		printf("%d\n",max(a%n,1));
	}
	return 0;
}
