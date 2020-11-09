#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int a[1001];
int q=0;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
    cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>a[i];
		if(a[i]<=30)
		{
			cout<<1+a[i]<<" 1 "<<"4713 "<<"BC";
		}
		else if(a[i]>30&&a[i]<=58)
		{
		    cout<<1+a[i]-30<<" 2 "<<"4713 "<<"BC";
		}
		else if(a[i]>58&&a[i]<=89)
		{
			cout<<1+a[i]-58<<" 3 "<<"4731 "<<"BC";
		}
		else if(a[i]>89&&a[i]<=119)
		{
			cout<<1+a[i]-89<<" 4 "<<"4731 "<<"BC";
		}
		else if(a[i]>119&&a[i]<=150)
		{
			cout<<1+a[i]-119<<" 5 "<<"4731 "<<"BC";
		}
		else if(a[i]>150&&a[i]<=180)
		{
			cout<<1+a[i]-150<<" 6 "<<"4731 "<<"BC";
		}
		else if(a[i]>180&&a[i]<=211)
		{
			cout<<1+a[i]-180<<" 7 "<<"4731 "<<"BC";
		}
		else if(a[i]>211&&a[i]<=241)
		{
			cout<<1+a[i]-211<<" 8 "<<"4731 "<<"BC";
		}
		else if(a[i]>241&&a[i]<=271)
		{
			cout<<1+a[i]-241<<" 9 "<<"4731 "<<"BC";
		}
		else if(a[i]>271&&a[i]<=302)
		{
			cout<<1+a[i]-271<<" 10 "<<"4731 "<<"BC";
		}
		else if(a[i]>302&&a[i]<=332)
		{
			cout<<1+a[i]-302<<" 11 "<<"4731 "<<"BC";
		}
		else if(a[i]>332&&a[i]<=363)
		{
			cout<<1+a[i]-332<<" 12 "<<"4731 "<<"BC";
		}
		else if(a[i]>363&&a[i]<=394)
		{
			cout<<1+a[i]-363<<" 1 "<<"4730 "<<"BC";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
