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
	int p;long long v;//t==1ʱp��ʾԪ���±�v��ʾ����,t==2ʱ��v��ʾ�˻���t==3ʱv��ʾ���ú����ĸ��� 
	//p��ʾ����1�ຯ���ĸ���,v֮���ʾ���ж��ຯ�������ϳ˻�
	int len;
	std::vector<int>c;//��ʾ���ú����ı�� 
	std::vector<std::pair<int,int> >d;//��ʾһ���ײ�������� 
}c[maxn];//���еĺ���
long long muls;//�������ĳ˻��ۼ��˶��� 
int tag[maxn];//��¼ÿ��Ԫ���ۼ��˶��� 
void dfs(int cnt){
	int len=c[cnt].len;//���õĺ����ĸ��� 
	for(reg int i=0;i<len;i++){//ö�����е��õĺ���,���ദ�� 
		int pos=c[cnt].c[i];
//		printf("��� %d\n",pos);
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
			if(!c[pos].p){//���û�б����Ϲ�,��ȥ���� 
				c[pos].v=1;
				dfs(pos);
			}
			for(reg int j=0;j<c[pos].p;j++){
				c[cnt].p++;
				c[cnt].d.push_back(std::make_pair(c[pos].d[j].first,c[pos].d[j].second));
			}//ת�� 
//			c[cnt].v=(c[cnt].v*c[pos].v)%mod;//ת�� 
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
				c[i].c.push_back(k);//���뺯����� 
			}
		}
	}
	for(reg int i=1;i<=m;i++){//�����е����ຯ���黯Ϊ1,2�ຯ�������� 
		if(c[i].t==3){
			if(!c[i].p){//���������û�б����Ϲ� 
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
//			printf("�˻� %d\n",muls);
			for(reg int z=1;z<=n;z++){
			a[z]=(a[z]*c[f[i]].v)%mod;
			}
//			muls=(muls*c[f[i]].v)%mod;
//			printf("�˻� %d\n",muls);
		}
		else if(c[f[i]].t==3){//���Ե����������� 
//			printf("�ۼӺ����� %d\n",c[f[i]].p);
			int k=c[f[i]].p;
			for(reg int j=0;j<k;j++){	
				if(c[f[i]].d[j].first){
				a[c[f[i]].d[j].first]=(a[c[f[i]].d[j].first]+c[f[i]].d[j].second)%mod;	
				}
//				printf("�ۼӵ�ֵ %d\n",tag[c[f[i]].d[j].first]);
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
//		a[i]=((a[i]*muls)%mod+tag[i])%mod;//tag��muls���Ⱥ�˳�򡣡��� 
		printf("%d ",a[i]);
	}
	return 0;
}
