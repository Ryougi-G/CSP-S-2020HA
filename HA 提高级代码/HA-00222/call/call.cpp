#include"cstdio"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;
int n,m,a[1000001];
struct node{
	int pos,val,times;
	queue<int>q;
	inline void A(){
		a[pos]+=val;
	}
	inline void B(){
		for(int i=1;i<=n;i++)
			a[i]*=times;
	}
}call;
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	while(m--){
		int T;
		scanf("%d",&T);
		if(T==1){
			scanf("%d%d",&call.pos,&call.val);
		}
		if(T==2){
			scanf("%d",&call.times);
		}
		if(T==3){
			while(call.q.size())call.q.pop();
			int turn,x;
			scanf("%d",&turn);
			while(turn--){
				scanf("%d",&x);
				call.q.push(x);
			}
		}
	}
	int Q,T;
	scanf("%d",&Q);
	while(Q--){
		scanf("%d",&T);
		if(T==1){
			call.A();
		}
		if(T==2){
			call.B();
		}
		if(T==3){
			queue<int>tmp=call.q;
			while(tmp.size()){
				int now=tmp.front();
				tmp.pop();
				if(now==1)call.A();
				else call.B();
			}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
/*
3
1 2 3
3
1 1 1
2 2
3 2 1 2
2
2 3
*/
/*
10
1 2 3 4 5 6 7 8 9 10
8
3 2 2 3
3 2 4 5
3 2 5 8
2 2
3 2 6 7
1 2 5
1 7 6
2 3
3
1 2 3
*/
