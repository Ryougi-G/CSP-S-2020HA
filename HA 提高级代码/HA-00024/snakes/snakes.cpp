#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int t,s[N];
int read(){
	int w=0,f=1;
	char c=getchar();
	while (c>'9'||c<'0'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9'){
		w=(w<<3)+(w<<1)+(c^48);
		c=getchar();
	}
	return w*f;
}

int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	t=read();
	for (int cnt=1;cnt<=t;cnt++){
		int n=read();
		if (cnt==1){
			for (int i=1;i<=n;i++) s[i]=read();
			if (s[3]-s[1]>=s[2]) puts("1");
			else puts("3");
		}else{
			for (int i=1;i<=n;i++){
				int x=read(),w=read();
				s[x]=w;
			}
			if (s[3]-s[1]>=s[2]) puts("1");
			else puts("3");
		}
	}

	return 0;
}

