#include<bits/stdc++.h>
using namespace std;
inline int SQHread(){
	int fh=1,dx=0;
	char ch;
	ch=getchar();	
	while(ch<'0'||ch>'9'){
		if(ch=='-')	fh=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		dx=dx*10+ch-'0';
		ch=getchar();
	}
	return dx*fh;
}
int ans,n,m,c,k,a[32],p[1004],q[1004],pp[1000000],canrise[10000],cnt;
int pow2[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
bool s[100000003],hus[10000000],lol[65];
void dfs(int dep){
	for(int i=0;i<=1;++i){
		if(canrise[dep]==1||i==0){
			lol[dep]=i;
			if(dep==k){
				int tot=0;
				for(int j=0;j<=k;++j)
					if(lol[j])
						tot+=pow2[j];
				if(hus[tot]!=1){
					hus[tot]=1;
					++ans;
				}
			}
			else dfs(dep+1);
		}
	}
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=SQHread();
	m=SQHread();
	c=SQHread();
	k=SQHread();k--;
	for(int i=0;i<10000;++i)
		canrise[i]=1;
	for(int i=1;i<=n;++i)
		a[i]=SQHread(),hus[a[i]]=1;
	for(int i=1;i<=m;++i){
		p[i]=SQHread();
		canrise[p[i]]=0;
		q[i]=SQHread();
	}
	for(int i=1;i<=n;++i){
		int SQHnb=a[i];
		int dijiwei=0;
		while(SQHnb>0){
			if(SQHnb%2==1){
				for(int j=1;j<=m;++j)
					if(p[j]==dijiwei)	canrise[dijiwei]=1,s[q[j]]=1;
			}
			SQHnb=(SQHnb-SQHnb%2)>>1;
			++dijiwei;
		}
	}
	dfs(0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
