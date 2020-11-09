#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 1000005;
int T;         
void copy(void);
struct node {
	int val,pos;
	node() {
		val = pos = 0;      
	}
	node(int val,int pos):val(val),pos(pos){}
	bool operator < (const node &x)const {
		return val < x.val||val == x.val&&pos < x.pos;
	}
}a[maxn],w[maxn];        
int maopao(int l) {
	for(int i = n;i > l;-- i) {
		if(w[i] < w[i - 1]) {
			swap(w[i] , w[i - 1]);
		}
		else return i;
	}
	return l;
}                  
void init(int _) {
	if(_ == 1) {
		scanf("%d",&n);
		for(int i = 1;i <= n;++ i) {
			scanf("%d",&a[i].val);
			a[i].pos = i;
		}
		copy();
	}
	else {
		int k;
		scanf("%d",&k);
		for(int i = 1;i <= k;++ i) {
			int x,y;
			scanf("%d%d",&x,&y);
			a[x].val = y;
		}
		copy();
	}
}
void copy() {
	for(int i = 1;i <= n;++ i) {
		w[i] = a[i];
	}
}
void work(int _) {
	init(_);                    
	int head = 1;
	while(head < n) {             
		w[n].val -= w[head ++].val;     
		int pos = maopao(head);    
		if(pos == head) {      
			break ;
		}                     
	}                          
	if(head == n) {
		puts("1");
		return ;
	}
	printf("%d\n",n - head + 2);
	return ;
}
int main() {
	freopen("snakes.in","r",stdin);                      
	freopen("snakes.out","w",stdout);
	scanf("%d",&T);
	for(int _ = 1;_ <= T;++ _) {
		work(_);
	}
	return 0;
}
