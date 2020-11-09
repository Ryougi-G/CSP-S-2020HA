#include<bits/stdc++.h>
using namespace std;
const int Q=998244353;
int n,m,q;
int T[100010],P[100010],V[100010],g[1000010];
unsigned long long a[100010];
int C[100010][5];
inline unsigned long long szread(){
	unsigned long long res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
return res*f;}
void han1(int f){
	a[P[f]]%=Q;
	a[P[f]]+=V[f];
	a[P[f]]%=Q;
}
void han2(int f){
	for(int i=1;i<=n;++i) a[i]%=Q,a[i]=a[i]*V[f],a[i]%=Q;
}
void han3(int f){
	for(int i=C[f][1];i<=C[f][2];++i){
		if(T[g[i]]==1) han1(g[i]);
		if(T[g[i]]==2) han2(g[i]);
		if(T[g[i]]==3) han3(g[i]);
	}
}
int main(){
	freopen("call.in","r",stdin);freopen("call.out","w",stdout);
	n=szread();
	for(int i=1;i<=n;++i) a[i]=szread(),a[i]%=Q;
	m=szread();int kkk=1;
	for(int i=1;i<=m;++i){
		T[i]=szread();
		if(T[i]==1){
			P[i]=szread();V[i]=szread();
		}
		else if(T[i]==2){
			V[i]=szread();
		}
		else if(T[i]==3){
			C[i][0]=szread();C[i][1]=kkk;kkk=kkk+C[i][0];C[i][2]=kkk-1;
			for(int j=C[i][1];j<=C[i][2];++j){
				g[j]=szread();
			}
		}
	}
	q=szread();
	for(int i=1;i<=q;++i){
		int f=szread();
		if(T[f]==1) han1(f);
		if(T[f]==2) han2(f);
		if(T[f]==3) han3(f);
	}
	for(int i=1;i<=n;++i) printf("%llu ",a[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}
