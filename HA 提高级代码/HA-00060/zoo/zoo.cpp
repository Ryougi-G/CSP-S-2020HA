#include<bits/stdc++.h>
#define reg register 
typedef unsigned long long ull;
inline unsigned long long qr(){
	unsigned long long x=0,f=0;char ch=0;
	while(!isdigit(ch)){f|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return f?-x:x;
}
const int maxn=1e6+100;
int n,m,c,k;//动物数量,指令数量,饲料种数,动物二进制位数 
unsigned long long a[maxn];//动物编号 
int p[maxn],q[maxn];
int cnt[66];//j为1的动物有多少个。 
int o[66],xu[66];//第j位是否买了饲料,第j位是否需要买饲料 
ull ans;
ull ps;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=qr();m=qr();c=qr();k=qr();
	for(reg int i=1;i<=n;i++){//nlogn 预处理 
		a[i]=qr();
		for(reg int j=0;j<64;j++){//64位上不会有1 
			if(a[i]&((ull)1<<j)){
				cnt[j]++;
			}
		}
	}
	for(reg int i=1;i<=m;i++){
		p[i]=qr();q[i]=qr();//pi位为1的要买qi位的饲料|
		xu[p[i]]=1; 
		if(cnt[p[i]]){
			o[p[i]]=1;//如果有动物pi位为1,那多买了一种饲料 
		}
	}
	for(reg int j=0;j<64;j++){
		if(o[j]){//这一位买过了饲料 
			ps+=(ull)1<<j;
		}
	}
	if(k<=20){//o(2^k*20),遍历所有的动物,看看它的需要是否被满足了,40pts 
		int maxx=1<<k;
		int flag=0;
		for(reg int i=0;i<maxx;i++){ 
			for(reg int j=0;j<20;j++){
				 if(i&(1<<j)){
					if(xu[j]){//如果这一位是需要饲料的且买过了饲料	
					if(!o[j]) flag=1;//需要饲料却没有买 
					}
				}
			}
			if(!flag) ans++;
		}
		ans-=n;
		printf("%d",ans);
		return 0;
	}
	
	return 0;
}
