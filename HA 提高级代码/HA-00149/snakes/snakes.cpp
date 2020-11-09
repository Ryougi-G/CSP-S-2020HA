#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int a[2100],sum;bool bol=1;	int q,n;
void fight(){
	while(bol==1){
		int min=0x3f,max=0,posmin=0,posmax=0;
		for(int i=1;i<=n;i++){
			if(a[i]<min||a[i]!=0){min=a[i];posmin=i;}
			if(a[i]>max){max=a[i];posmax=i;}
		}
		if(posmax==posmin)break;
		a[posmax]=a[posmax]-min;
		a[posmin]=0;
		int min1=0x3f;
		for(int i=1;i<=n;i++){
			if(a[i]<min||a[i]!=0){min1=a[i];}
		}
		if(a[posmax]<=min1){
			a[posmax]=max;
			a[posmin]=min;
			break;
		}
	}
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);

	cin>>q>>n;
	q--;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	fight();
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>0)ans++;
	}
	cout<<ans;
	for(int i=1;i<=q;i++){
		int n1;
		cin>>n1;
		for(int j=1;j<=n1;j++){
			int i1,a1;
			cin>>i1>>a1;
			a[i1]=a1;
		}
		fight();
		int ans=0;
		for(int j=1;j<=n;j++){
			if(a[j]>0)ans++;
		}
		cout<<ans;
	}
}
//priority_queue<int, vector<int>,greater<int> >p;
//cout<<fixed<<setprecision();
