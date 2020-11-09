#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int main() {
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int sls[10001],ans=0,a[10001],index=1,alimao[100001],aejz,ejz=1,n,m,c,k,p[10001],q[10001];
	cin >> n >> m >> c >> k;
	for(int i=0;i<n;i++) {
		scanf("%d",&alimao[i]);
		a[i]=alimao[i];
	}
	for(int i=0;i<m;i++) {
		scanf("%d%d",&p[i],&q[i]);
	}
	for(int i=0;i<n;i++) {
		while(alimao[i]>0){
			aejz+=alimao[i]%2*ejz;
			ejz*=10;
			alimao[i]/=2;
		}
		for(int j=0;j<m;j++) {
			for(int g=p[i];j>0;j--) {
				index*=10;
			}
			if(aejz/(index/10)-aejz/index*index==q[i]) sls[q[i]]=1;
		}
		index=1;
		ejz=1;
		aejz=0;
	}
	int num=0,cnt=2,ej=0,ii;
	for(int i=0;i<k;i++) {
		num+=cnt;
		cnt*=2;
	}
	for(int i=0;i<num;i++) {
		ii=i;
		while(ii>0){
			ej+=ii%2*ejz;
			ejz*=10;
			ii/=2;
		}
		for(int j=0;j<m;j++) {
			for(int g=p[i];j>0;j--) {
				index*=10;
			}
			if(ej/(index/10)-ej/index*index==q[i]) {
				if(sls[q[i]]==1 && i!=a[i]) ans++;
			}
		}
		index=1;
		ejz=1;
		ej=0;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

