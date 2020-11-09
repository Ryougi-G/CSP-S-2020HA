#include<iostream>
#include<cstdio>
using namespace std;
int q;
int date[1000004];
long long day[1000004],month[1000004],year[1000004];
int b[1000004];
long long days=0;
long long meet=0;
int time;
int num=0;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin >> q;
	for(int i=1;i<=q;i++)
	{
		meet=-1;
		num=0;
		cin >> date[i];
		if(date[i]<1721423)
		{
			b[i]=1;
		}
		else
		{
			b[i]=2;
		}
		if(date[i]<2299162)
		{
			for(int j=1;j<=6295;j++)
			{
				if((4713-j+1)%4==0||(j-4713)>0&&(j-4713)%4==0)
				{
					for(int k=1;k<=12;k++)
					{
						if(k==1) time=31;
						else if(k==2) time=29;
						else if(k==3) time=31;
						else if(k==4) time=30;
						else if(k==5) time=31;
						else if(k==6) time=30;
						else if(k==7) time=31;
						else if(k==8) time=31;
						else if(k==9) time=30;
						else if(k==10&&j==6295) time=5;
						else if(k==10) time=31;
						else if(k==11) time=30;
						else if(k==12) time=31;
						for(int o=1;o<=time;o++)
						{
							meet++;
							if(meet==date[i]&&b[i]==1)
							{
								day[i]=o,month[i]=k,year[i]=4713-j+1;
								num++;
								if(num==1)
								{
									break;
								}
							}
							else if(meet==date[i]&&b[i]==2)
							{
								day[i]=o,month[i]=k,year[i]=j-4713;
								num++;
								if(num==1)
								{
									break;
								}
							}
						}
						if(num==1)
						{
							break;
						}
					}
				}
				else
				{
					for(int k=1;k<=12;k++)
					{
						if(k==1) time=31;
						else if(k==2) time=28;
						else if(k==3) time=31;
						else if(k==4) time=30;
						else if(k==5) time=31;
						else if(k==6) time=30;
						else if(k==7) time=31;
						else if(k==8) time=31;
						else if(k==9) time=30;
						else if(k==10&&j==6295) time=5;
						else if(k==10) time=31;
						else if(k==11) time=30;
						else if(k==12) time=31;
						for(int o=1;o<=time;o++)
						{
							meet++;
							if(meet==date[i]&&b[i]==1)
							{
								day[i]=o,month[i]=k,year[i]=4713-j+1;
								num++;
								if(num==1)
								{
									break;
								}
							}
							else if(meet==date[i]&&b[i]==2)
							{
								day[i]=o,month[i]=k,year[i]=j-4713;
								num++;
								if(num==1)
								{
									break;
								}
							}
						}
						if(num==1)
						{
							break;
						}
					}
				}
				if(num==1)
				{
					break;
				}
			}
		}
		else	
		{
			int j1=6296;
			meet=2299170;
			while(1)
			{
				if((j1-4713)%400==0||(j1-4713)%4==0&&(j1-4713)%100!=0)
				{
					for(int k=1;k<=12;k++)
					{
						if(k==1) time=31;
						else if(k==2) time=29;
						else if(k==3) time=31;
						else if(k==4) time=30;
						else if(k==5) time=31;
						else if(k==6) time=30;
						else if(k==7) time=31;
						else if(k==8) time=31;
						else if(k==9) time=30;
						else if(k==10) time=31;
						else if(k==11) time=30;
						else if(k==12) time=31;
						for(int o=1;o<=time;o++)
						{
							meet++;
							if(meet==date[i])
							{
								day[i]=o,month[i]=k,year[i]=j1-4713;
								num++;
								if(num==1)
								{
									break;
								}
							}
						}
						if(num==1)
						{
							break;
						}
					}
				}
				else
				{
					for(int k=1;k<=12;k++)
					{
						if(k==1) time=31;
						else if(k==2) time=28;
						else if(k==3) time=31;
						else if(k==4) time=30;
						else if(k==5) time=31;
						else if(k==6) time=30;
						else if(k==7) time=31;
						else if(k==8) time=31;
						else if(k==9) time=30;
						else if(k==10) time=31;
						else if(k==11) time=30;
						else if(k==12) time=31;
						for(int o=1;o<=time;o++)
						{
							meet++;
							if(meet==date[i]&&b[i]==1)
							{
								day[i]=o,month[i]=k,year[i]=j1-4713;
								num++;
								if(num==1)
								{
									break;
								}
							}
						}
						if(num==1)
						{
							break;
						}
					}
				}
				if(num==1)
				{
					break;
				}
				j1++;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		if(b[i]==1)
		{
			cout << day[i] << " " << month[i] << " " << year[i] << " " << "BC" << endl;
		}
		else
		{
			cout << day[i] << " " << month[i] << " " << year[i] << endl;
		}
	}
	
	
	
	return 0;
}
