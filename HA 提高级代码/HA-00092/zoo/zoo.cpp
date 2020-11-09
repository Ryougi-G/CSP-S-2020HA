#include<iostream>
#include<cstdio>
using namespace std;
int lread()
{
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0')
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
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	

	
	fclose(stdin);fclose(stdout);
	return 0;
}
