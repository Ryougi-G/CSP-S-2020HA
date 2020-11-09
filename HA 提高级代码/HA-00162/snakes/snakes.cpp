	#include<bits/stdc++.h>
	#define ll long long
	using namespace std;
	const int maxn=1e6+5;
	struct qw{
	int b,num;}a[maxn];
	int b[maxn];
	bool cmp(qw q,qw w){
	if(q.num==w.num) return q.b<w.b;
	else return q.num<w.num;
	}
	int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int n,T,k,q,w,flag=-1;
	cin>>T>>n;	
	for(int i=1;i<=n;i++)cin>>a[i].num,a[i].b=i;
	while(T--){++flag;
	if(flag>0){cin>>k;
	for(int i=1;i<=n;i++)a[i].num=b[i];
	for(int i=1;i<=k;i++)cin>>q>>w,a[q].num=w;}
	for(int i=1;i<=n;i++)b[i]=a[i].num;
	sort(a+1,a+1+3,cmp);
	if(a[3].num>=a[2].num+a[1].num)	{
	if(a[3].num==a[2].num+a[1].num&&(a[3].b<a[1].b||a[3].b<a[2].b))
	cout<<3<<endl;
	else cout<<1<<endl;}
	else cout<<3<<endl;
	}
	return 0;
	}
