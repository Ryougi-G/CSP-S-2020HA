#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
ifstream fin("julian.in");
ofstream fout("julian.out");
int main()
{
	int q,r,x=0,y=0;
		fin>>q;
	for(int i=1;i<=q;i++)
	{
		fin>>r;
		if(r<30&&r>1)
		{
			int a=1,b=1,c=4713;
			fout<<a+r<<" "<<1<<" "<<4713<<" "<<"BC"<<endl;
		}
		if(r>30&&r<365)
		{
			int a=1,b=1,c=4713;	
			b+=r/30;
			a=r%30;
			fout<<a<<" "<<b<<" "<<4713<<" "<<"BC"<<endl;
		}
		if(r>365)
		{
			int a=1,b=1,c=4713;
			c-=r/365;
			x=r%365;
			a=x/10;
			b=x/30;
			fout<<a<<" "<<b<<" "<<c<<" "<<"BC"<<endl;
		}
	}	
	return 0;
}
