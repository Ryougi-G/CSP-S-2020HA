#include<bits/stdc++.h>
using namespace std;
long long ans;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	long long n,r;
	int nian,yue,ri;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r;
		nian=-4713;
		yue=1;
		ri=1;
		for(long long j=1;j<=r;j++)
		{
			ri++;
			if(nian<1582)
			{
				if(nian==0)
				{
					nian++;
				}
				else if(nian<0)
				{
				 if(abs(nian+1)%4==0)
				 {
					if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)
					{
						if(ri==32)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==4||yue==6||yue==9||yue==11)
					{
						if(ri==31)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==2)
					{
						if(ri==30)
						{
							ri=1;
							yue++;
						}
					}
					if(yue==13)
					{
						nian++;
						yue=1;
						ri=1;
					}
				 }
				 else
				 {
					if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)
					{
						if(ri==32)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==4||yue==6||yue==9||yue==11)
					{
						if(ri==31)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==2)
					{
						if(ri==29)
						{
							ri=1;
							yue++;
						}
					}
					if(yue==13)
					{
						nian++;
						yue=1;
						ri=1;
					}
				 }
			    }
			    else if(nian>0)
			    {
			    	if(nian%4==0)
				 {
					if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)
					{
						if(ri==32)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==4||yue==6||yue==9||yue==11)
					{
						if(ri==31)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==2)
					{
						if(ri==30)
						{
							ri=1;
							yue++;
						}
					}
					if(yue==13)
					{
						nian++;
						yue=1;
						ri=1;
					}
				 }
				 else
				 {
					if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)
					{
						if(ri==32)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==4||yue==6||yue==9||yue==11)
					{
						if(ri==31)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==2)
					{
						if(ri==29)
						{
							ri=1;
							yue++;
						}
					}
					if(yue==13)
					{
						nian++;
						yue=1;
						ri=1;
					}
				 }
			    }
			}
			else if(nian==1582&&yue<10)
			{
				if(nian%4==0)
				{
					if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)
					{
						if(ri==32)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==4||yue==6||yue==9||yue==11)
					{
						if(ri==31)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==2)
					{
						if(ri==30)
						{
							ri=1;
							yue++;
						}
					}
					if(yue==13)
					{
						nian++;
						yue=1;
						ri=1;
					}
				}
				else
				{
					if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)
					{
						if(ri==32)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==4||yue==6||yue==9||yue==11)
					{
						if(ri==31)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==2)
					{
						if(ri==29)
						{
							ri=1;
							yue++;
						}
					}
					if(yue==13)
					{
						nian++;
						yue=1;
						ri=1;
					}
				}
			}
			else if(nian==1582&&yue==10)
			{
				if(ri==5)
				{
					ri+=10;
				}
				else if(ri==32)
				{
					ri=1;
					yue=11;
				}
			}
			else if(nian==1582&&yue==11)
			{
				if(ri==31)
				{
					yue=12;
					ri=1;
				}
			}
			else if(nian==1582&&yue==12)
			{
				if(ri==32)
				{
					yue=1;
					ri=1;
					nian++;
				}
			}
			else if(nian>1582)
			{
				if(nian%400==0||(nian%4==0&&nian%100!=0))
				{
					if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)
					{
						if(ri==32)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==4||yue==6||yue==9||yue==11)
					{
						if(ri==31)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==2)
					{
						if(ri==30)
						{
							ri=1;
							yue++;
						}
					}
					if(yue==13)
					{
						nian++;
						yue=1;
						ri=1;
					}
				}
				else
				{
					if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)
					{
						if(ri==32)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==4||yue==6||yue==9||yue==11)
					{
						if(ri==31)
						{
							ri=1;
							yue++;
						}
					}
					else if(yue==2)
					{
						if(ri==29)
						{
							ri=1;
							yue++;
						}
					}
					if(yue==13)
					{
						nian++;
						yue=1;
						ri=1;
					}
				}
			}
		}
		if(nian<0)
		{
			cout<<ri<<" "<<yue<<" "<<-nian<<" "<<"BC"<<endl;
		}
		else if(nian>0)
		{
			cout<<ri<<" "<<yue<<" "<<nian<<endl;
		}
	}
	return 0;
}
