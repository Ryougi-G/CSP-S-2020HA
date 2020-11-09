#include<iostream>
#include<fstream>
using namespace std;
int a[1000001],p[1000001],q[1000001];
ifstream fin("zoo.in");
ofstream fout("zoo.out");
int main()
{
	int n,m,c,k;
	fin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)
	{
		fin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		fin>>p[i]>>q[i];		
	}
	for(int i=1;i<=c;i++)
	{
		if(a[i]==1) 
			c+=a[i];
	}
	for(int i=0;i<=k-1;i++)
	{
			if(a[i]==1) a[i]++;
			else a[i]+=a[i];
	}
	fout<<n+c+k<<endl;
	return 0;
}
