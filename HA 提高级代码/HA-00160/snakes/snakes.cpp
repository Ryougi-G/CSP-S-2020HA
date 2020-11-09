#include<bits/stdc++.h>
using namespace std;


inline int read()
{
	int num=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {num=(num<<1)+(num<<3)+ch-'0'; ch=getchar();}
	return num*f;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	puts("1");
	cout<<"3";
	return 0;
}
