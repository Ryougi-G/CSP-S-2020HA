#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define ll long long
#define re register
#define il inline
const int maxn = 1e6+10;
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

int t;
int n,k;
int x,y,cnt;
int a[maxn];

bool cmp(int a,int b){
	return a<b;
}

int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	t=read(),n=read();
	for(re int i =1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n,cmp);
	int now = n;
	for(int i=1;i<n;i++){
		if(a[now]-a[i]>=a[i+1]){
			a[now]-=a[i];
			cnt++;
			if(a[now]<a[now-1])now--;
		}else break;
	}
	printf("%d\n",n-cnt);
	cnt=0;
	t--;
	while(t--){
		k=read();
		for(int i=0;i<k;i++){
			x=read(),y=read();
			a[x]=y;
		}
		sort(a+1,a+1+n,cmp);
//		for(int i =1;i<=n;i++)cout<<a[i]<<" ";
		int now = n;
		for(int i=1;i<n;i++){
			if(a[now]-a[i]>=a[i+1]){
				a[now]-=a[i];
//				cout<<a[now];
				cnt++;
				if(a[now]<a[now-1])now--;
			}else break;
		}
		printf("%d\n",n-cnt);
		cnt=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

