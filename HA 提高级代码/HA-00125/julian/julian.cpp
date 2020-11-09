#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("julian.in");
ofstream fout("julian.out");
int Q,r,ye,mo,da,o;
int a[]={31,59,90,120,151,181,212,243,273,304,334,365};
int b[]={31,60,91,121,152,182,213,244,274,305,335,366};
bool fr(int n)
{
	if(n<0)
	{
		if((-ye)%4==1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(n<=1582)
	{
		if(n%4==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(n%4==0&&n%100!=0||n%400==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int main()
{
	fin>>Q;
	for(int i=1;i<=Q;i++)
	{
		fin>>r;
		ye=(r/1461)*4+((r%1461)/365)-4713;
		o=r-((ye+4713)*365+(ye+4713)/4);
		if(ye>=0)
			ye++; 
		mo=1;
		for(int j=0;j<12;j++)
		{
			if(fr(ye))
			{
				if(o-b[j]>=0)
				{
				mo=j+2;
				}
				else
				{
					if(ye==-4713)
					da=o-b[j-1]+1;
					else
					da=o-b[j-1];
					break;
				}
			}
			else
			{
				if(o-a[j]>=0)
				{
				mo=j+2;
				}
				else
				{
					if(ye==-4713)
					da=o-a[j-1]+1;
					else
					da=o-a[j-1];
					break;
				}
			}
		}
		if(ye>0)
			fout<<da<<" "<<mo<<" "<<ye<<endl;
		else
			fout<<da<<" "<<mo<<" "<<ye*(-1)<<" "<<"BC"<<endl;
	}
	return 0;	
}
