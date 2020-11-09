#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,m,n,ani[100001];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>a>>b>>c>>d;
	bool kind[d+1];
	int sw[c+1];
	memset(sw,0,sizeof(sw));
	memset(kind,0,sizeof(kind));
	vector<int> tu[d];
	for(int i=1;i<=a;i++){
		cin>>ani[i];
		int ok=ani[i],p=0;
		while(ok!=0){
			if(ok&1==1) sw[p]=true;
			p++;
			ok=ok>>1;
		}
	} 
	for(int i=1;i<=b;i++){
		int nu,sinu;
		cin>>nu>>sinu;
		if(sw[nu]==0) sw[nu]=2;
	}
	int ans=(1<<d);
	for(int i=0;i<=(1<<d)-1;i++){
		int num=i;
		int n=0;
		while(num!=0){
			int laswei=num&1;
			if(laswei==1){
				if(sw[n]==2){
					ans--;
					break;
				}
			}
			n++;
			num=num>>1;
		}
	}
	cout<<ans-a<<endl;
	return 0;
}
