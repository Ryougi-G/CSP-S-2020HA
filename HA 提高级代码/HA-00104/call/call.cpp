#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[100090],head[100090],m,t;
struct dian{
	int u,v,nxt;
}e[100900];
struct shu{
	int wei,zhi,lei;
}s[400090];
int cnt=0;
int init[400090];
void add(int u,int v){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int cnt1,cnt2;
void zhixing(int i){
		if(s[i].lei==1){
			a[s[i].wei]=a[s[i].wei]+s[i].zhi;
		}
		if(s[i].lei==2){
			for(int j=1;j<=n;j++) a[j]*=s[i].zhi;
		}
		else{
			for(int j=head[i];j;j=e[j].nxt){
				zhixing(e[j].v);
			}  
		}
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>t;
		if(t==1){
			s[i].lei=1;
			cin>>s[i].wei>>s[i].zhi;
		}
		if(t==2){
			s[i].lei=2;
			cin>>s[i].zhi;
		}
		if(t==3){
			s[i].lei=3;
			int j,tj; cin>>j;
			for(int p=1;p<=j;p++){
				cin>>tj;
				add(i,tj);
			} 
		}
	}
	int q;int tq;
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>tq;
		zhixing(tq);
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
}

