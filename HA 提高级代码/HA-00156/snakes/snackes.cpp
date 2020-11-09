#include<bits/stdc++.h>
using namespace std;
long long ans=0,t,n,ans1=0;
int main()
{
	int num=0;
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t>>n;
	int a[t],b1[n],b[n];
	for(int i=0;i<t;i++)
	{
	    if(i==0)
		{
			for(int j=0;j<n;j++)
			{
			cin>>a[j];
		    ans=ans+a[j];
			}
		for(int c=0;c<n;c++)
		{
			if(a[i]<ans-a[i])
			ans1++;
			else
			{
			num=num+1;
			break;
			}
		}
		if(num==1)
		{
			cout<<"1"<<endl;
			break;
		}
		else
		{
			cout<<ans1<<endl;
		}
		} 
		else 
		{
			for(int j=0;j<n;j++)
			{
			cin>>b1[j]>>a[j];
		    ans=ans+a[j];
			}
		for(int c=0;c<n;c++)
		{
			if(a[c]<ans-a[c])
			ans1++;
			else if(a[c]>ans-a[c])
			{
			num=num+1;
			break;
			}
		}
		if(num==1)
		{
			cout<<"1"<<endl;
			break;
		}
		else
		{
			cout<<ans1<<endl;
		}
		}
		ans1=0;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
