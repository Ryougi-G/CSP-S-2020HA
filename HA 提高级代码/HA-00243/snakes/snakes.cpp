#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001],m;
bool used[100001];
int tickmax=1,maix=-99,tickmin,minx=0x7f,x,y;
bool eat=true;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t;
	cin>>n;
	memset(used,true,sizeof(used));
	int uuu;int uu=n;
	uuu=uu;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int ww=1;ww<=t;ww++){
			
	for(int uuu=n;uuu>=1;uuu--){
	minx=0x7f7f;
	maix=-99;
		for(int i=1;i<=n;i++){
			if(a[i]>=maix&&used[i]!=false){
				tickmax=i;
				maix=a[i];
			}
			if(a[i]<=minx&&used[i]!=false){
				tickmin=i;
				minx=a[i];
			}
		}
		int y=tickmax,mo=tickmin;
		a[y]-=a[mo];

		for(int i=1;i<=n;i++){
			if(a[i]>=maix&&used[i]==true){
				tickmax=i;
				maix=a[i];
			}
			if(a[i]<minx&&used[i]==true){
				tickmin=i;
				minx=a[i];
			}
		}
		if(tickmax==y){
		n--;
		used[mo]=false;
		}
		if(tickmax!=y) break;
		if(n==1)break;
	}
	
	cout<<n<<endl;
	n=uu;
	if(ww!=t)
	{
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		a[x]=y;
		used[x]=true;
	}
	}

	}
	return 0;
}
//2
//5
//13 31 33 39 42
//5
//1 7 2 10 3 24 4 48 5 50
