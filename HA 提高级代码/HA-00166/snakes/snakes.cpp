#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e6+7;
int k,n,x,y,tot;
int b[N];
struct s{
	int x,power,ert;
}; s f[N];

inline bool cmp(s x,s y){
	if(x.ert==y.ert) return x.x>y.x;
	return x.ert>y.ert;
}

inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch<='9'&&ch>='0'){ x=x*10+ch-'0'; ch=getchar();}
	return x;
}
inline void pai(int l,int r,int x){
	for(int i=r+1;i>l;i--) swap(f[i],f[i-1]);
	swap(f[x],f[l]);
}
inline void work(){
	int l=1,r=tot,ans=tot;
	while(1){
		if(l>=r) break;
		int p=f[l].ert-f[r].ert;
		int x=f[l].x,y=f[r].x;
		if(p>=f[l+1].ert){
			r--; ans--; continue;
		}
		else if(p>=f[r-1].ert){
			if(p==f[r-1].ert){
				if(x<f[r-1].x) break;
				else r--,ans--;
			}
			else{
				r--,ans--;
			}
		}
		f[l].ert=p,l++;
		for(int i=l+1;i<=r;i++){
			if(p>=f[i].ert){
				if(p==f[i].ert){
					if(x>f[i].x){
						pai(i,r,l-1);
						break;
					}
					else{
						continue;
					}
				}
				else{
					pai(i,r,l-1);
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
    n=read();
	for(int i=1;i<=n;++i){
    	cin>>k; memset(b,0,sizeof(b));
    	if(i==1){ tot=k;
    		for(int j=1;j<=k;j++){
    			f[j].x=j;
    			f[j].ert=f[j].power=read();
    		}
    	}
    	else{
    		for(int j=1;j<=k;j++){
    			x=read(),y=read();
    			f[x].ert=y; b[x]=1;
    		}
    	}
    	for(int j=1;j<=tot;j++) if(b[j]==0) f[j].ert=f[j].power;
    	sort(f+1,f+1+tot,cmp);
    	work();
    }
	return 0;
}
