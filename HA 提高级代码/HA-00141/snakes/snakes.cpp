#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10; 
int t,n,a[N];
int rd(){
	int f=1,x=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return f*x;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	t=rd();
	for(int i=1;i<=t;i++){
		if(i==1){
			n=rd();
			for(int i=1;i<=n;i++)
				a[i]=rd();
		}
		else{
			int k=rd(),x,y;
			while(k--){
				x=rd(),y=rd();
				a[x]=y;
			}
		}
		if(n==3){
			if((a[3]-a[1])>=a[2])
				printf("1\n");
			else
				printf("3\n");
		}
	}
	return 0;
}
