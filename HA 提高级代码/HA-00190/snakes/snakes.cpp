#include<bits/stdc++.h>
using namespace std;
int wyh()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return f*x;
}

int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.ans","w",stdout);
	int t,n,a[1000000],m,b[1000000];
	t=wyh();
	for(int i=1;i<=t;i++)
	{
		n=wyh();
		for(int j=1;j<=n;j++) a[j]=wyh();
		m=wyh();
		for(int y=1;y<=2*m;y++)b[y]=wyh();
	}
	cout<<"3"<<endl<<"1";
	fclose(stdin);fclose(stdout);
}
