#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int w=1,s=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')
			w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
int b[20005];
struct xxx{
	int mode,x,y,c[4005];
}a[5005];
int sum[200005];
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		b[i]=read();
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int m1,a1,a2;
		cin>>m1;
		if(m1==1){
			cin>>a1>>a2;
			a[i].mode=1;
			a[i].x=a1;
			a[i].y=a2;
		}
		else if(m1==2){
			cin>>a1;
			a[i].mode=2;
			a[i].x=a1;
		}
		else if(m1==3){
			int l;
			cin>>l;
			a[i].x=l;
			for(int j=1;j<=l;j++)
				cin>>a[i].c[j];
		}
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		int Q;
		cin>>Q;
		if(a[Q].mode==1){
			b[a[Q].x]+=a[Q].y;
		}
		else if(a[Q].mode==2){
			for(int j=1;j<=n;j++)
				b[j]*=a[Q].x;
		}
		else{
			//cout<<1<<endl;
			for(int j=1;j<=a[Q].x;j++){
				int N=a[j].c[j];
				//cout<<N<<" ";
				if(a[N].mode==1){
					b[a[N].x]+=a[N].y;
				}
				else if(a[N].mode==2){
				for(int k=1;k<=n;k++)
					b[k]*=a[N].x;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";
}
