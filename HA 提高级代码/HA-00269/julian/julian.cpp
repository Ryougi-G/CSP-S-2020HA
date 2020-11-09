#include<bits/stdc++.h>
using namespace std;

int n,nian=-1,yue;
int a[120000];

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		nian=-1;
		if(a[i]<2299158)
		{
			if(a[i]<=1721424)
			{
				while(1)
				{
					nian++;
					a[i]-=366;
					if(a[i]<0) 
					{
						a[i]+=366;
						
						while(1)
						{
							a[i]-=31;
							if(a[i]<0)
							{
							a[i]+=31;
							yue=1;
							cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
							break;
							}
							a[i]-=29;
							if(a[i]<0)
							{
								a[i]+=29;
								yue=2;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=3;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=4;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=5;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=6;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=7;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=8;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=9;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=10;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=11;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=12;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
						}
						break;
					}
					nian++;
					a[i]-=365;
					if(a[i]<0) 
					{
						a[i]+=365;
						while(1)
						{
							a[i]-=31;
							if(a[i]<0)
							{
							a[i]+=31;
							yue=1;
							cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
							break;
							}
							a[i]-=28;
							if(a[i]<0)
							{
								a[i]+=28;
								yue=2;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=3;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=4;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=5;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=6;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=7;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=8;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=9;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=10;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=11;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=12;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
						}
						break;
					}
					nian++;
					a[i]-=365;
					if(a[i]<0) 
					{
						a[i]+=365;
						while(1)
						{
							a[i]-=31;
							if(a[i]<0)
							{
							a[i]+=31;
							yue=1;
							cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
							break;
							}
							a[i]-=28;
							if(a[i]<0)
							{
								a[i]+=28;
								yue=2;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=3;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=4;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=5;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=6;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=7;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=8;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=9;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=10;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=11;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=12;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
						}
						break;
					}
					nian++;
					a[i]-=365;
					if(a[i]<0) 
					{
						a[i]+=365;
						while(1)
						{
							a[i]-=31;
							if(a[i]<0)
							{
							a[i]+=31;
							yue=1;
							cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
							break;
							}
							a[i]-=28;
							if(a[i]<0)
							{
								a[i]+=28;
								yue=2;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=3;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=4;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=5;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=6;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=7;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=8;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=9;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=10;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=30;
							if(a[i]<0)
							{
								a[i]+=30;
								yue=11;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
							a[i]-=31;
							if(a[i]<0)
							{
								a[i]+=31;
								yue=12;
								cout<<a[i]+1<<' '<<yue<<' '<<4713-nian<<' '<<"BC"<<endl;
								break;
							}
						}
						break;
					}
				}	
			}		
		}	
	}
	return 0;
}
