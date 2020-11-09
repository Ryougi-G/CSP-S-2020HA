#include<bits/stdc++.h>
using namespace std;
long long q,n,ans,ans1;
int a[100],b[100];
int year=4713,month=1,day=1;
int main()
{
    int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int b[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=0;i<q;i++)
	{
	cin>>n;
	while(n<365)
	{
	if(year>1582)
	{
    	if(year%4!=0)
		{
		year=year-1;
		n=n-365;
		}
		else
		{
		year=year-1;
		n=n-366;	
		}
	}
	else if(year==1582)
	{
		year=year-1;
		n=n-355;
	}
	else
	{
		if(year%4==0&&year%100!=0||year%400==0)
		{
		year=year-1;
		n=n-366;	
		}
		else
		{
		year=year-1;
		n=n-365;
		}
	}
	}
	while(n>365)
	{
		if(year>1582)
		{
		if(year%4!=0)
			for(int i=0;i<12;i++)
		    {
		        if(n>a[i])
		        {
		    	n=n-a[i];
		    	}
		    	else
		    	{
				ans=i;
				ans1=n;
				}
		   }
		    else
		    for(int i=0;i<12;i++)
		    {
		        if(n>b[i])
		        {
		    	n=n-b[i];
		    	}
		    	else
		    	{
				ans=i;
				ans1=n;
				}
		   }
		   }
		else if(year==1582)
		{
		n=n+10;
		for(int i=0;i<12;i++)
		    {
		        if(n>a[i])
		        {
		    	n=n-a[i];
		    	}
		    	else
		    	{
				ans=i;
				ans1=n;
				}
		   }	
		}
		else 
		{
		if(year%4==0&&year%100!=0||year%400==0)
			for(int i=0;i<12;i++)
		    {
		        if(n>b[i])
		        {
		    	n=n-b[i];
		    	}
		    	else
		    	{
				ans=i;
				ans1=n;
				}
		   }
		else
		 for(int i=0;i<12;i++)
		    {
		        if(n>a[i])
		        {
		    	n=n-a[i];
		    	}
		    	else
		    	{
				ans=i;
				ans1=n;
				}
		   }
		} 
	}
	cout<<ans1<<" "<<ans<<" "<<year<<" "<<"BC";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}         
		            
