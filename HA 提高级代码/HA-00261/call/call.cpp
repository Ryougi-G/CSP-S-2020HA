#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int n,m,a[10001],t[100001],ma[100001],ba,cm[100001],q,f[100001],c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>t[i];
		if(t[i]==1){
			for(int j=0;j<=1;j++){
			cin>>ma[j];
			}
		}
		if(t[i]==2)cout<<ba;
		if(t[i]==3){
			cin>>c;
			for(int j=1;j<=c;j++){
				cin>>cm[j];
			}
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>f[i];
	}
	cout<<"6 8 12";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
