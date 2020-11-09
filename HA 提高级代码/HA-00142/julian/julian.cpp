#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<iostream>

#define MAXN 100005
#define int long long

using namespace std;

inline int read(){
	int w=0,f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch>='9'){
		w=(w<<1)+(w<<3)+(ch-48);
	}
	return w*f;
}

int q;
int r;
int m[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int s[15];

void modif(){
	m[2]++;
	for(int i=2;i<=12;i++)s[i]++;
}

void modifback(){
	m[2]--;
	for(int i=2;i<=12;i++)s[i]--;
}

const int year4=1461;

struct Node{
	int a,b,c;
	Node(int aa,int bb,int cc):a(aa),b(bb),c(cc){}
	Node(){}
};

Node Chtolly(int x){
	if(x<year4){
		if(x<=365){
			modif();
			int p=upper_bound(s+1,s+13,x)-s-1;
			if(p<0)p=0;
			x-=s[p];
			x++;
			modifback();
			return Node(x,p+1,-4713);
		}
		else{
			int y=x/365;
			x-=y*365;
			int p=lower_bound(s+1,s+13,x)-s-1;
			if(p<0)p=0;
			x-=s[p];
			return Node(x,p+1,-4713+y);
		}
	}
	else{
		int yy=x/year4;
		if(x<=1721058){
			x-=yy*year4;
			if(x<=365){
				modif();
				int p=lower_bound(s+1,s+13,x)-s-1;
				if(p<0)p=0;
				x-=s[p];
				x++;
				modifback();
				return Node(x,p+1,-4713+(yy)*4);
			}
			else{
				int y=x/365;
				x-=y*365;
				int p=lower_bound(s+1,s+13,x)-s-1;
				if(p<0)p=0;
				x-=s[p];
				return Node(x,p+1,-4713+y+(yy)*4);
			}
		}
		else{
			x-=1721058;
			if(x<=365*3){
				int y=(x-1)/365;
				x-=y*365;
				int p=lower_bound(s+1,s+13,x)-s-1;
				if(p<0)p=0;
				x-=s[p];
				return Node(x,p+1,y+1);
			}
			else if(x<=year4){
				modif();
				x-=365*3;
				int p=lower_bound(s+1,s+13,x)-s-1;
				if(p<0)p=0;
				x-=s[p];
				modifback();
				return Node(x,p+1,4);
			}
			else{
				int yy=x/year4;
				x-=yy*year4;
				if(x<=365*3){
					int y=(x-1)/365;
					x-=y*365;
					int p=lower_bound(s+1,s+13,x)-s-1;
					if(p<0)p=0;
					x-=s[p];
					return Node(x,p+1,y+yy*4+1);
				}
				else if(x<=year4){
					modif();
					x-=365*3;
					int p=lower_bound(s+1,s+13,x)-s-1;
					if(p<0)p=0;
					x-=s[p];
					x++;
					modifback();
					return Node(x,p+1,3+yy*4);
				}
			}
		}
	}
}

signed main(void){
	
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	
	for(int i=1;i<=12;i++){
		s[i]=s[i-1]+m[i];
		//printf("%d ",s[i]);
	}
	
	scanf("%lld",&q);
	while(q--){
		scanf("%lld",&r);
		Node ans=Chtolly(r);
		printf("%lld %lld %lld",ans.a,ans.b,abs(ans.c));
		if(ans.c<=0)printf(" BC\n");
		else printf("\n");
	}

	return 0;
}
