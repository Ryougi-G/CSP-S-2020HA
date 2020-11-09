#include<iostream>
#include<fstream>
using namespace std;
int a[1000001];
ifstream fin("snakes.in");
ofstream fout("snakes.out");
int main()
{
	int t,n,x,y,k;
	fin>>t;
	fin>>x;
	for(int i=1;i<=x;i++)
	{
		fin>>a[i];
	}
	fin>>k;
	for(int i=1;i<=k;i++)
	{
		fin>>a[i]>>y;
	}
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		if(a[i]==a[j]&&i>j||a[i]>a[j]!=0) a[i]++;
	}
		fout<<x<<endl;
	for(int i=1;i<t;i++)
	{
		fout<<t-i<<endl;
	}
	return 0;
}
