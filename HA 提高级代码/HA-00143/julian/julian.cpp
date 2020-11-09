#include <bits/stdc++.h>
using namespace std;
int d=0;
bool runnian1(long long a)
{
	if(a%4==0&&a%100!=0||a%400==0)
	{
		return true;
	}
	return false;
}

bool runnian2(long long a)
{
	if(a%4==0||a==0)
	{
		return true;
	}
	return false;
}

int yuefen(int a)
{
	d=0;
	if(a<=31)
	{
		if(a!=0)
		{
			d=32-a;
		}
		else
		{
			d=31;
		}
		return 12;
	}
	else if(a>31&&a<=61)
	{
		d=31-(a-31);
		return 11;
	}
	else if(a>61&&a<=92||a>61&&a<=82)
	{
		if(a>61&&a<=82)
		{
			
		d=22-(a-61);
		}
		else
		{
			d=32-(a-61);
		}
		return 10;
	}
	else if(a>92&&a<=122||a>82&&a<=112)
	{
		if(a>92&&a<=122)
		{
		
		d=31-(a-92);	
		}
		else
		{
			d=31-(a-82);
		}
		return 9;
	}
	else if(a>122&&a<=153||a>112&&a<=143)
	{
		if(a>122&&a<=153)
		{
			d=32-(a-122);
		}
		else
		{
			d=32-(a-112);
		}
		return 8;
	}
	else if(a>153&&a<=184||a>143&&a<=174)
	{
		if(a>153&&a<=184)
		{
			d=32-(a-153);
		}
		else
		{
			d=32-(a-143);
		}
		return 7;
	}
		else if(a>184&&a<=214||a>174&&a<=204)
	{
		if(a>184&&a<=214)
		{
			d=31-(a-184);
		}
		else
		{
			d=31-(a-174);	
		}
		return 6;
	}
		else if(a>214&&a<=245||a>204&&a<=235)
	{
		if(a>214&&a<=245)
		{
			d=32-(a-214);
		}
		else
		{
			d=32-(a-204);
		}
		return 5;
	}
		else if(a>245&&a<=275||a>235&&a<=265)
	{
		if(a>245&&a<=275)
		{
			d=31-(a-245);
		}
		else
		{
			d=31-(a-235);
		}
		return 4;
	}
		else if(a>275&&a<=306||a>265&&a<=296)
	{
		if(a>275&&a<=306)
		{
			d=32-(a-275);
		}
		else
		{
			d=32-(a-265);
		}
		return 3;
	}
		else if(a>306&&a<=334||a>306&&a<=335||a>296&&a<=324||a>296&&a<=326)
	{
		if(a>306&&a<=334)
		{
			d=29-(a-306);
		}
		else if(a>296&&a<=324)
		{
			d=29-(a-296);
		}
		else if(a>296&&a<=326)
		{
			d=30-(a-296);
		}
		else
		{
			d=30-(a-306);
		}
		return 2;
	}
		else if(a>334&&a<=365||a>335&&a<=366||a>324&&a<=355||a>325&&a<=356)
	{
		if(a>334&&a<=365)
		{
			d=32-(a-334);
		}
		else if(a>324&&a<=355)
		{
			d=32-(a-324);
		}
		else if(a>325&&a<=356)
		{
			d=32-(a-325);
		}
		else
		{
			d=32-(a-335);
		}
		return 1;
	}
	
}

//vector<unsigned long long>r;
unsigned long long r[1000000];
int main(void)
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	long long Q ,year=-4713;
	unsigned long long ri,temp=366;
	int day,month;
	cin>>Q;
	for(int i=0;i<Q;i++)
	{
		cin>>r[i];
	}
	for(int i=0;i<Q;i++)
	{
		year=-4713;
		temp=366;
		if(r[i]>31)
		{
			if(r[i]>temp)
			{
				while(1)
				{
					year+=1;
					if(year<1582)
					{
						if(runnian2(year+1)&&year<0)
						{
							temp+=366;
							if(r[i]<=temp)
							{
								break;
							}
						}
						else if(runnian2(year)&&year>0)
						{
							temp+=366;
							if(r[i]<=temp)
							{
								break;
							}
						}
						else if(year!=0)
						{
							temp+=365;
								if(r[i]<=temp)
							{
								break;
							}
						}
					}
					else if(year==1582)
					{
						temp+=345;
						if(r[i]<=temp)
						{
							break;
						}
					}
					else
					{
					if(runnian1(year))
						{
							temp+=366;
							if(r[i]<=temp)
							{
								break;
							}
						}
						else
						{
							temp+=365;
								if(r[i]<=temp)
							{
								break;
							}
						}
						
					}
				}
				month=yuefen(temp-r[i]);
				 day=d;
				if(year==1582)
				{
					if(month==10&&day>4)
					{
						day+=10;
					}
				}
				 if(year>1582)
				 {
				 		//month=yuefen(temp-r[i]-10);
				 day=d-10;
				 }
			}
			else
			{
				 month=yuefen(temp-r[i]);
				 day=d;
			}
		}
		else
		{
				 month=1;
				 day=r[i]+1;
		}
		if(year>0)
	{
	cout<<day<<" "<<month<<" "<<year<<endl;
		
	}
	else
	{
		
	cout<<day<<" "<<month<<" "<<-year<<" "<<"BC"<<endl;
	}
	}

	return 0;
}
