#include<bits/stdc++.h>
using namespace std;
#define re register int
struct xxx{
	int sum,name;
}a[1000005];
int b[1000005];
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
bool cmp(xxx x,xxx y){
	if(x.sum==y.sum){
		return x.name>y.name;
	}
	else
		return x.sum>y.sum;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t;
	t=read();
	int n;
	n=read();
	int ans=n;
	for(re i=1;i<=n;i++){
		b[i]=read();
		a[i].name=i;
	}
	for(re i=1;i<=n;i++)
		a[i].sum=b[i];
	if(ans==2){
		for(re i=1;i<=t;i++){
			cout<<1<<endl;
		}
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	//for(int i=1;i<=n;i++)
	//	cout<<a[i].sum<<" ";
	while((a[1].sum-a[ans].sum)>a[ans-1].sum){
			b[a[ans].name]=0;
			a[ans].sum=0;
			ans--;
			if(ans==2)
				break;
		}
	if(ans==2)
	ans=1;
	cout<<ans<<endl;
	t--;
	while(t--){
		int num;
		cin>>num;
		for(re i=1;i<=num;i++){
			int x,y;
			x=read();
			y=read();
			b[x]=y;
		}
		if(ans==2){
			cout<<1<<endl;
			continue;
		}
		for(re i=1;i<=n;i++){
			a[i].name=i;
			a[i].sum=b[i];
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(b[i]>0)
				ans++;
		}
		sort(a+1,a+1+n,cmp);
		//	for(int i=1;i<=n;i++)
		//cout<<a[i].sum<<" ";
		while((a[1].sum-a[ans].sum)>a[ans-1].sum){
			b[a[ans].name]=0;
			a[ans].sum=0;
			ans--;
			if(ans==2)
				break;
		}
		if(ans==2){
			cout<<1<<endl;
			continue;
		}
		cout<<ans<<endl;
	}
}
