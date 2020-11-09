#include<bits/stdc++.h>
using namespace std;
int Q,jg[100100];
unsigned long long x[100100];
int ts[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int month[100100],day[100100],year[100100];
void shuru()
{
	cin>>Q;
	for(int i=1;i<=Q;i++)
	cin>>x[i];
}
void js(unsigned long long x,int i)
{
	day[i]+=1;month[i]+=1;
	int k=x/365;
	int q=x%365;
	for(int i=1;i<=12;i++)
	{
		if(q>=ts[i])
		{
			q=q-ts[i];
			month[i]++;
		}
		else
		{
			day[i]=day[i]+q;
			break;
		}
	}
	year[i]=-4713-k;
}
int main()
{
	shuru();
	for(int i=1;i<=Q;i++)
	js(x[i],i);
	for(int k=1;k<=Q;k++)
	{
		if(year[k]==1582&&month[k]==10&&day[k]>=5&&day[k]<=14)
		{
			day[k]=9+day[k];
			if(day[k]>ts[month[k]])
			{
				day[k]=day[k]-ts[month[k]];
				month[k]++;
			}
			if(month[k]<12)
			{
				month[k]=month[k]-12;
				year[k]++;
			}
		}
		for(int i=1;i<=Q;i++)
		{
		cout<<day[k]<<' '<<month[k];
		if(year[k]<0)
		{
		cout<<' '<<abs(year[k])<<' '<<"BC";
		}
		else
		cout<<' '<<year;
		cout<<endl;
		}
	return 0;			
	}
	
}
