#include<bits/stdc++.h>
using namespace std;
long long a,b1,b2;
bool d[64][2];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	long long n,m,c,k;
	long long e=0,f=1;
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		for(int j=0;j<=k-1;j++)if((a>>j)%2==1)d[j][0]=1;
	}
	for(int i=1;i<=m;i++){
		cin>>b1>>b2;
		if(d[b1][0]==0&&d[b1][1]==0){
		e++;	
		d[b1][1]=1;
		}
	}
	for(;k-e>0;e++){
		f*=2;
	}
	cout<<f-n<<endl;
	return 0;
}
