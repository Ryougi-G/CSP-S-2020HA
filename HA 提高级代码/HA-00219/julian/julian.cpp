#include<bits/stdc++.h>
using namespace std;
long long int a=4173;
long long int nian,yue,ri,r,num;
int tianshu[100]{0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	long long int n;
	int flag=0;
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>r;
		nian=0;
		yue=0;
		ri=0;
		flag=0;
		nian=-4713;
		if(r<=366)
		{
			tianshu[2]=29;
			for(int j = 1;j <= 12&&flag==0;j++)
			{
				
				r=r-tianshu[j];
				if(r<0)
				{
					yue=j;
					ri=tianshu[j]+r+1;
					cout<<ri<<" "<<yue<<" "<<abs(nian)<<" BC"<<endl;
					flag=1;
				}
			}
			continue;
		}
		if(nian<1582)
		{
			num=(r/1461)*4;
			if(r%1461==0)
			{
				nian=nian+num;
				yue=1;
				ri=1;
				cout<<ri<<" "<<yue<<" "<<abs(nian);
				if(nian<0)cout<<" BC";
				cout<<endl;
			}
			if(r%1461>0&&r%1461<=366)
			{
				nian=nian+num+1;
				for(int j = 1;j <= 12;j++)
				{
					r=r-tianshu[j];
					if(r<0)
					{
						yue=j;
						ri=tianshu[j]+r+1;
					}
				}
				cout<<ri<<" "<<yue<<" "<<abs(nian)<<" BC"<<endl;
			}
			if(r%1461>366&&r%1461<=731)
			{
				nian=nian+num+2;
				for(int j = 1;j <= 12;j++)
				{
					r=r-tianshu[j];
					if(r<0)
					{
						yue=j;
						ri=tianshu[j]+r+1;
					}
				}
				cout<<ri<<" "<<yue<<" "<<abs(nian)<<" BC"<<endl;
			}
			if(r%1461>731&&r%1461<=1096)
			{
				nian=nian+num+3;
				for(int j = 1;j <= 12;j++)
				{
					r=r-tianshu[j];
					if(r<0)
					{
						yue=j;
						ri=tianshu[j]+r+1;
					}
				}
				cout<<ri<<" "<<yue<<" "<<abs(nian)<<" BC"<<endl;
			}
			if(r%1461>1096&&r%1461<1461)
			{
				nian=nian+num+4;
				for(int j = 1;j <= 12;j++)
				{
					r=r-tianshu[j];
					if(r<0&&j<=2)
					{
						yue=j;
						ri=tianshu[j]+r+1;
					}
					if(r<0&&j>2)
					{
						yue=j;
						ri=tianshu[j]+r;
					}
				}
				cout<<ri<<" "<<yue<<" "<<abs(nian)<<" BC"<<endl;
			}
		}
	}
	return 0;
}
