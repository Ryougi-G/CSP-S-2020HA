#include<bits/stdc++.h>
using namespace std;
#define MAXN 999999999
int a[1000000],a2[1000000],p[100000000],q[100000000],n,m,k,ans=0; 
bool arry[100000000];                      //小B要买的饲料种类 
long long c;
bool y(int i){
	for(int j=0;j<n;j++)
		if(a2[j]==i)
			return true;
	return false;
}

int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	for(int i=0;i<=100000000;i++){
		p[i]=MAXN;
		q[i]=MAXN;
		arry[i]=false;
	}
	cin>>n>>m>>c>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a2[i]=a[i];
	}
	for(int i=0;i<m;i++){
		cin>>p[i]>>q[i];
	}
	for(int i=0;i<n;i++){
		int flag=0;
		while(a[i]!=0){
			if(a[i]%2==1){
				for(int j=0;j<m;j++){
					if(flag==p[j]){
						arry[p[j]]=true;
					}
				}
			}
			flag++; a[i]/=2;
		}
	}
	for(int i=0;i<=10;i++){
		cout<<arry[i];
	}
	int temp=1;
	for(int i=1;i<=k;i++){
		temp*=2;
	}
	for(int i=0;i<temp;i++){
		if(y(i)) continue;
		int flag=0,t=i;
		while(t!=0){
			if(t%2==1&&arry[flag]==false){
				flag=MAXN;
				break;
			}
			flag++; t/=2;
		}
		if(flag!=MAXN){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
