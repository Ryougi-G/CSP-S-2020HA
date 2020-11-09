#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int qr(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int hip[1000005],n[1000005],ans[1000005],hop[1000005];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t=qr();
	for(int i=1;i<=t;++i){
		n[i]=qr();
		if(i == 1){
			for(int j=1;j<=n[1];++j){
				hip[j]=qr();
			}
		}
		else{
			for(int j=1;j<=n[i];++j){
				int x=qr(),y=qr();
				hip[x]=y;
			}
		}
		for(int j = 1;j <= n[i]; ++j){
			hop[j]=hip[j];
		}
		sort(hop+1,hop+1+n[i]);
		for(int j=n[i];j>=(n[i]+1)/2;--j){
			if(hop[j]-hop[n[i]-j+1]<=hop[j-1]-hop[n[i]-j+2]&&j-1!=n[i]-j+2){
				ans[i]=n[i];
				break;
			}
			else if(hop[j]-hop[n[i]-j+1]<=hop[j-1]&&j-1==n[i]-j+2){
				ans[i]=n[i];
				break;
			}
			ans[i]=(n[i]+1)/2;
		}
	}
	for(int i=1;i<=t;++i){
		printf("%d\n",ans[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
