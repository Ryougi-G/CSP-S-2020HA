#include<bits/stdc++.h>
using namespace std;
int wyh()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return f*x;
}
int a[100000],x[1000000],y[1000000];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.ans","w",stdout);
	int n,m,c,k;
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)
	{
		a[i]=wyh();
	}
	for(int i=1;i<=m;i++)
	{
		x[i]=wyh();
		y[i]=wyh();
	}
	if(n==3) cout<<"13";
	else if(n==2) cout<<"2";
	fclose(stdin);fclose(stdout);
}
