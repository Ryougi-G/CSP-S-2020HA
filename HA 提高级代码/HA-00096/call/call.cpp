#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
inline int lread()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	
	
	fclose(stdin);fclose(stdout);
	return 0;
}
