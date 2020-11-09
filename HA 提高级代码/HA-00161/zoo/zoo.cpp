#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long 

const int N=1000100;

int n,m,vis[N],k;

ull lisan[N],a,ans=1,tot,zhong,jishu;

vector <unsigned long long> p[110];

ull read()
{
	ull ans=0;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		ans=(ans*10)+ch-'0';	
		ch=getchar();
	}
	return ans;
}

int query(ull x){
	return lower_bound(lisan+1,lisan+1+tot,x)-lisan;
}

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>zhong>>k;
	for(int i=1;i<=n;i++){
		ull x;
		x=read();
		a|=x;
	}
	for(int i=1;i<=m;i++){
		ull x,y;
		x=read();y=read();
		lisan[i]=y;
		p[x].push_back(y);	
	}
	sort(lisan+1,lisan+1+m);
	tot=m;
	int t=0;
	for(int j=0;j<k;j++){
		if((a>>j)&1){
			for(int i=0;i<p[j].size();i++){
				vis[query(p[j][i])]=1;
			}
			jishu++;
		}
	}
	for(int j=0;j<k;j++){
		bool book=true;
		if(((a>>j)&1)==0){
			for(int i=0;i<p[j].size();i++){
				if(vis[query(p[j][i])]==0) book=false;
			}
			if(book==true) jishu++;
		}
	}
	cout<<(ans<<jishu)-n;
	return 0;
}
