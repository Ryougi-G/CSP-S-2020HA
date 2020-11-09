#include<bits/stdc++.h>
using namespace std;
#define MAXN 20005
long long n,m,q,t;
struct t3{
	int cnt;
	int cmd[MAXN+100];
}t3[MAXN];
int t2[MAXN];
struct t1{
	int a,b;
}t1[MAXN];
long long a[MAXN]={0};
short kind[MAXN]={0};
void Do(int f){
	if(kind[f]==1){
			a[t1[f].a]+=t1[f].b;
			//cout<<"111";
	}
	if(kind[f]==2){
		for(int i=1;i<=n;i++){
			a[i]*=t2[f];
		}
		//cout<<"222";
	}
	if(kind[f]==3){
		int kk=1;
		//cout<<t3[f].cmd.front();
		while(kk<=t3[f].cnt){
		//cout<<"333";
			Do(t3[f].cmd[kk]);
			kk++;
		}
		
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]%998244353<<" ";
//	}
//	cout<<endl;
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	//cout<<"please cin aftm";
	for(int i=1;i<=m;i++){
		cin>>t;
		if(t==1){
			kind[i]=1;
			int a,b;
			cin>>a>>b;
			t1[i].a=a;
			t1[i].b=b;
		}
		if(t==2){
			kind[i]=2;
			cin>>t2[i];
		}
		if(t==3){
			kind[i]=3;
			int count,fun;
			cin>>count;
			for(int j=1;j<=count;j++){
				cin>>fun;
				t3[i].cmd[j]=fun;
				t3[i].cnt=count;
				//cout<<"you pushed"<<fun<<"into"<<i;
			}
		}
	}
	
	cin>>q;
	int f;
	for(int i=1;i<=q;i++){
		cin>>f;
		Do(f);
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
