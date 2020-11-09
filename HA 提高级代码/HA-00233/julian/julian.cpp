#include<bits/stdc++.h>
using namespace std;
int n;
int run[14]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int ping[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//int xin[14]={0,31,29,31,30,31,30,31,31,30,21,30,31};//366-10=356
int a[100086];
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int f=0;
		if(a[i]<31)
		{
			cout<<a[i]+1<<" "<<1<<" "<<4713<<" BC"<<endl;
			f=1;
		}
		if(f==0&&a[i]<=1721423)
		{
			int sum=4713,ss=1,yue=0;
			while(a[i]>=31&&a[i]<=1721423)
			{
				while(a[i]>=ping[ss]&&(sum-1)%4!=0)
				{
					//cout<<a[i]<<" "<<ping[ss]<<endl;
					a[i]-=ping[ss];
					yue++;
					if(yue>12)
					{
						yue-=12;	
						sum--;
					}//cout<<ss<<endl;
					if(ss==12)ss=0;
					ss++;
				}
				while(a[i]>=run[ss]&&(sum-1)%4==0)
				{
					//cout<<a[i]<<" "<<run[ss]<<endl;
					a[i]-=run[ss];
					yue++;
					if(yue>12)
					{
						yue-=12;	
						sum--;
					}//cout<<ss<<endl;
					if(ss==12)ss=0;
					ss++;
				}
			}
			yue+=1;
			if(yue>12)yue-=12,sum++;
			cout<<a[i]+1<<" "<<yue<<" "<<sum<<" BC"<<endl;//395
		}
		else if(f==0)
		{
			int abc=a[i]-1721423;
			int sum=1,ss=1,yue=0;
		//	int nn=0;
//			for(int j=1;j<=1582;j++)
//			if(j%4==0&&j%100==0)nn++;
			//cout<<nn<<endl;
			if(abc<=577825)
			{
				while(abc>=31)
				{
					while(abc>=ping[ss]&&sum%4!=0)
					{
						//cout<<a[i]<<" "<<ping[ss]<<endl;
						abc-=ping[ss];
						yue++;
						if(yue>12)
						{
							yue-=12;	
							sum++;
						}//cout<<ss<<endl;
						if(ss==12)ss=0;
						ss++;
					}
					while(abc>=run[ss]&&sum%4==0)
					{
						//cout<<a[i]<<" "<<run[ss]<<endl;
						abc-=run[ss];
						yue++;
						if(yue>12)
						{
							yue-=12;	
							sum++;	
						}//cout<<ss<<endl;
						if(ss==12)ss=0;
						ss++;
					}
				}
				yue+=1;
				if(yue>12)yue-=12,sum++;
				cout<<abc<<" "<<yue<<" "<<sum<<endl;
			}
			else
			{
				//abc-=25;
				abc=abc-577825;
				yue=11;
				sum=1582;
				ss=11;
				while(abc>=31)
				{
					while((abc>=ping[ss]&&sum%4!=0)||(abc>=ping[ss]&&sum%4==0&&sum%100==0))
					{
						//cout<<a[i]<<" "<<ping[ss]<<endl;
						abc-=ping[ss];
						yue++;
						if(yue>12)
						{
							yue-=12;	
							sum++;
							
						}//cout<<ss<<endl;
						if(ss==12)ss=0;
						ss++;
					}
					while((abc>=run[ss]&&sum%400==0)||(abc>=run[ss]&&sum%4==0&&sum%100!=0))
					{
						//cout<<a[i]<<" "<<run[ss]<<endl;
						abc-=run[ss];
						yue++;
						if(yue>12)
						{
							yue-=12;	
							sum++;
						
						}//cout<<ss<<endl;
						if(ss==12)ss=0;
						ss++; 
					}
				}
				yue+=1;
				if(yue>12)yue-=12,sum++;
				cout<<abc<<" "<<yue<<" "<<sum<<endl;
			}
		}
	}
	return 0;
}
