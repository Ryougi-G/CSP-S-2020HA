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
int n,m,c,k;//��������,ָ������,��������,���������λ�� 
unsigned long long a[maxn];//������ 
int p[maxn],q[maxn];
int cnt[66];//jΪ1�Ķ����ж��ٸ��� 
int o[66],xu[66];//��jλ�Ƿ���������,��jλ�Ƿ���Ҫ������ 
ull ans;
ull ps;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=qr();m=qr();c=qr();k=qr();
	for(reg int i=1;i<=n;i++){//nlogn Ԥ���� 
		a[i]=qr();
		for(reg int j=0;j<64;j++){//64λ�ϲ�����1 
			if(a[i]&((ull)1<<j)){
				cnt[j]++;
			}
		}
	}
	for(reg int i=1;i<=m;i++){
		p[i]=qr();q[i]=qr();//piλΪ1��Ҫ��qiλ������|
		xu[p[i]]=1; 
		if(cnt[p[i]]){
			o[p[i]]=1;//����ж���piλΪ1,�Ƕ�����һ������ 
		}
	}
	for(reg int j=0;j<64;j++){
		if(o[j]){//��һλ��������� 
			ps+=(ull)1<<j;
		}
	}
	if(k<=20){//o(2^k*20),�������еĶ���,����������Ҫ�Ƿ�������,40pts 
		int maxx=1<<k;
		int flag=0;
		for(reg int i=0;i<maxx;i++){ 
			for(reg int j=0;j<20;j++){
				 if(i&(1<<j)){
					if(xu[j]){//�����һλ����Ҫ���ϵ������������	
					if(!o[j]) flag=1;//��Ҫ����ȴû���� 
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
