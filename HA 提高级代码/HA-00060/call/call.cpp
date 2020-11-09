#include<bits/stdc++.h>
#define reg register 
inline int qr(){
	int x=0,f=0;char ch=0;
	while(!isdigit(ch)){f|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return f?-x:x;
}
const int maxn=1e5+100;
const int mod=998244353;
int n,m,q;
long long  a[maxn];
int f[maxn];
struct hanshu{
	int t;
	int p;long long v;//t==1时p表示元素下标v表示增量,t==2时仅v表示乘积。t==3时v表示调用函数的个数 
	//p表示调用1类函数的个数,v之后表示所有二类函数的整合乘积
	int len;
	std::vector<int>c;//表示调用函数的编号 
	std::vector<std::pair<int,int> >d;//表示一个底层操作集合 
}c[maxn];//所有的函数
long long muls;//所有数的乘积累计了多少 
int tag[maxn];//记录每个元素累加了多少 
void dfs(int cnt){
	int len=c[cnt].len;//调用的函数的个数 
	for(reg int i=0;i<len;i++){//枚举所有调用的函数,分类处理 
		int pos=c[cnt].c[i];
//		printf("编号 %d\n",pos);
		if(c[pos].t==1){
		c[cnt].d.push_back(std::make_pair(c[pos].p,c[pos].v));
		c[cnt].p++;	
		}
		if(c[pos].t==2){
		c[cnt].v=(c[cnt].v*c[pos].v)%mod;
		c[cnt].d.push_back(std::make_pair(0,c[cnt].v));
		c[cnt].p++;
		}
		if(c[pos].t==3){
			if(!c[pos].p){//这个没有被整合过,下去整合 
				c[pos].v=1;
				dfs(pos);
			}
			for(reg int j=0;j<c[pos].p;j++){
				c[cnt].p++;
				c[cnt].d.push_back(std::make_pair(c[pos].d[j].first,c[pos].d[j].second));
			}//转移 
//			c[cnt].v=(c[cnt].v*c[pos].v)%mod;//转移 
		}
	}
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=qr();
	for(reg int i=1;i<=n;i++){
		a[i]=qr();
	}
	m=qr();
	for(reg int i=1;i<=m;i++){
		c[i].t=qr();
		if(c[i].t==1){
			c[i].p=qr();c[i].v=qr();
		}
		else if(c[i].t==2){
			c[i].v=qr();
		}
		else if(c[i].t==3){
			c[i].len=qr();
			for(reg int j=1;j<=c[i].len;j++){
				int k;k=qr();
				c[i].c.push_back(k);//放入函数编号 
			}
		}
	}
	for(reg int i=1;i<=m;i++){//将所有的三类函数归化为1,2类函数的整合 
		if(c[i].t==3){
			if(!c[i].p){//这个函数还没有被整合过 
				c[i].v=1;
				dfs(i);	
			}
		}
	}
	q=qr();muls=1;
	for(reg int i=1;i<=q;i++){
		f[i]=qr();
		if(c[f[i]].t==1){
			a[c[f[i]].p]=(a[c[f[i]].p]+c[f[i]].v)%mod;
		}
		if(c[f[i]].t==2){
//			printf("乘积 %d\n",muls);
			for(reg int z=1;z<=n;z++){
			a[z]=(a[z]*c[f[i]].v)%mod;
			}
//			muls=(muls*c[f[i]].v)%mod;
//			printf("乘积 %d\n",muls);
		}
		else if(c[f[i]].t==3){//可以调用其他函数 
//			printf("累加函数量 %d\n",c[f[i]].p);
			int k=c[f[i]].p;
			for(reg int j=0;j<k;j++){	
				if(c[f[i]].d[j].first){
				a[c[f[i]].d[j].first]=(a[c[f[i]].d[j].first]+c[f[i]].d[j].second)%mod;	
				}
//				printf("累加的值 %d\n",tag[c[f[i]].d[j].first]);
				else {
					for(reg int z=1;z<=n;z++){
						a[z]=(a[z]*c[f[i]].d[j].second)%mod;
					}
				}
			}
			/*if(c[f[i]].v!=1){
				muls=(muls*c[f[i]].v)%mod;
			}*/
		}
	}
	for(reg int i=1;i<=n;i++){
//		a[i]=((a[i]*muls)%mod+tag[i])%mod;//tag和muls有先后顺序。。。 
		printf("%d ",a[i]);
	}
	return 0;
}
