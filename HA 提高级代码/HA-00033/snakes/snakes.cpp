#include<iostream>
using namespace std;
long long a1[1000001],a2[1000001];
int arry[11];
void ans(int num,int i){
	if(num==2&&a2[2]>=a2[1]){
		arry[i]=1;
		return;
	}else if(a2[num]-a2[1]<a2[2]&&num>2){
		arry[i]=num;
		return;
	}else if(a2[num]-a2[1]>=a2[2]){
		a2[1]=a2[num]-a2[1];
		for(int j=1;j<num;j++){
			if(a2[j]>a2[j+1]){
				swap(a2[j],a2[j+1]);
			}
		}
		ans(--num,i);
	}
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T,n,k;
	cin>>T;
	for(int i=1;i<=T;i++){
		if(i==1){
			cin>>n;
			for(int j=1;j<=n;j++){
				cin>>a1[j];
				a2[j]=a1[j];
			}
			ans(n,i);
		}else{
			cin>>k;
			for(int j=1;j<=k;j++){
				int x;
				cin>>x;
				cin>>a1[x];
			}
			for(int j=1;j<=n;j++){
				a2[j]=a1[j];
			}
			ans(n,i);
		}
	}
	for(int i=1;i<=T;i++){
		cout<<arry[i]<<endl;
	}
	return 0;
}
