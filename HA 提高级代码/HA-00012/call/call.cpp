#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#define ll long long
#define re register
#define il inline
const int maxn = 1e5+10;
const int mod = 998244353;
using namespace std;
il int read(){
	int x=0,f=1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch = getchar();
	}
	return x;
}

int n,m;
int a[maxn],t[maxn];
int x,y,z;

bool tp = false;

int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(re int i=1;i<=n;i++)a[i]=read();
	m=read();
	for(re int i =1;i<=m;i++){
		t[i]=read();
		if(t[i]==1){
			x=read(),y=read();
			a[x]=(a[x]+y)%mod;
			tp=true;
		}else if(t[i]==2){
			x=read();
			if(tp){
				
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

