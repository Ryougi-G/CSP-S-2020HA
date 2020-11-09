#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
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
const int MAX_N=1.1e6;
int N,A[MAX_N];
int tmp[MAX_N];
int solve()
{
	if(N<=2)return 1;
	memcpy(tmp,A,sizeof(A));
	int i=1,mx=N;
Label:
	if(tmp[mx]-tmp[i]>=tmp[i+1]){
		tmp[mx]-=tmp[i];
		i++;
		if(mx>=i&&tmp[mx-1]>tmp[mx])mx=mx-1;
		if(tmp[N]>=tmp[mx])mx=N;
		goto Label;
	}
	if(N==2)i++;
	return N-i+1;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	
	int T=readint();
	N=readint();
	for(int i=1;i<=N;i++)
		A[i]=readint();
	printf("%d\n",solve());
	while(--T)
	{
		int k=readint();
		while(k--)
		{
			int k=readint(),x=readint();
			A[k]=x;
		}
		printf("%d\n",solve());
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
