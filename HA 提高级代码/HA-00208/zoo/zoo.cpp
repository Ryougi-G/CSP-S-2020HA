#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
int readint()
{
	bool neg=false;
	int x=0;
	char c=getchar();
	while(c<'-')c=getchar();
	if(c=='-'){neg=true;c=getchar();}
	for(;c>='0'&&c<='9';c=getchar())
		x=x*10+c-'0';
	return neg?-x:x;
}
ll dpow_1[65];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	
	dpow_1[0]=0;
	for(int i=1;i<=64;i++)dpow_1[i]=(dpow_1[i-1]<<1)+1;
	int n=readint(),m=readint(),c=readint();
	int k=readint();
	ll A=0,P=0;
	for(int i=0;i<n;i++)A|=readint();
	while(m--)
	{
		P|=1<<readint();
		readint();
	}
	ll can=dpow_1[k]^P|A;
	for(int i=k-1;i>=0;i--)
		if(!(can>>i&1))k--;
	printf("%llu",dpow_1[k]-n+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
