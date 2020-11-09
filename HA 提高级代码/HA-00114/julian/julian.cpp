#include<bits/stdc++.h>
using namespace std;
int Q;
long long a[1000000];
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++) scanf("%d",&a[i]);
	for(int i=1;i<=Q;i++)
	{
		int qi=-4713,qi2=1,qi3=1;
	while(a[i]>0)	
	{
		if(qi<1582)
		{
			if(qi<0)
			{
				if((abs(qi)-1)%4!=0) 
				{
					if(a[i]>=365) 
					{
						a[i]-=365;
						if(qi!=-1) qi++;
						else qi=1;
					}
					else
					{
							if(qi2==1||qi2==3||qi2==5||qi2==7||qi2==8||qi2==10||qi2==12)
							{
								if(a[i]>=31) qi2++,a[i]-=31;
								else qi3+=a[i],a[i]=0;
							}
							if(qi2==2)
							{
								if(a[i]>=28) qi2++,a[i]-=28;
								else qi3+=a[i],a[i]=0;
							}
							if(qi2==4||qi2==6||qi2==9||qi2==11) 
							{
								if(a[i]>=30) qi2++,a[i]-=30;
								else qi3+=a[i],a[i]=0;
							}	
					}
				}
				else
				{
					if(a[i]>=366) 
					{
						a[i]-=366;
						if(qi!=-1) qi++;
						else qi=1;
					}
					else
					{			
							if(qi2==1||qi2==3||qi2==5||qi2==7||qi2==8||qi2==10||qi2==12)
							{
								if(a[i]>=31) qi2++,a[i]-=31;
								else qi3+=a[i],a[i]=0;
							}
							if(qi2==2)
							{
								if(a[i]>=29) qi2++,a[i]-=29;
								else qi3+=a[i],a[i]=0;
							}
							if(qi2==4||qi2==6||qi2==9||qi2==11) 
							{
								if(a[i]>=30) qi2++,a[i]-=30;
								else qi3+=a[i],a[i]=0;
							}
			    	}
				}
			}
			else
			{
				if(qi%4!=0) 
				{
					if(a[i]>=365) 
					{
						a[i]-=365;
						qi++;
					}
					else
					{
							if(qi2==1||qi2==3||qi2==5||qi2==7||qi2==8||qi2==10||qi2==12)
							{
								if(a[i]>=31) qi2++,a[i]-=31;
								else qi3+=a[i],a[i]=0;
							}
							if(qi2==2)
							{
								if(a[i]>=28) qi2++,a[i]-=28;
								else qi3+=a[i],a[i]=0;
							}
							if(qi2==4||qi2==6||qi2==9||qi2==11) 
							{
								if(a[i]>=30) qi2++,a[i]-=30;
								else qi3+=a[i],a[i]=0;
							}	
					}
				}
				else
				{
					if(a[i]>=366) 
					{
						a[i]-=366;
						qi++;
					}
					else
					{
							if(qi2==1||qi2==3||qi2==5||qi2==7||qi2==8||qi2==10||qi2==12)
							{
								if(a[i]>=31) qi2++,a[i]-=31;
								else qi3+=a[i],a[i]=0;
							}
							if(qi2==2)
							{
								if(a[i]>=29) qi2++,a[i]-=29;
								else qi3+=a[i],a[i]=0;
							}
							if(qi2==4||qi2==6||qi2==9||qi2==11) 
							{
								if(a[i]>=30) qi2++,a[i]-=30;
								else qi3+=a[i],a[i]=0;
							}
			    	}
				}
			}
		}
		if(qi==1582)
		{
			if(a[i]>=355) qi++,a[i]-=355;
			else
			{
			if(qi2==1||qi2==3||qi2==5||qi2==7||qi2==8||qi2==12)
			{
				if(a[i]>=31) a[i]-=31,qi2++;
				else qi3+=a[i],a[i]=0;
			}
			if(qi2==2)
			{
				if(a[i]>=28) a[i]-=28,qi2++;
				else qi3+=a[i],a[i]=0;
			}
			if(qi2==4||qi2==6||qi2==9||qi2==11)
			{
				if(a[i]>=30) a[i]-=30,qi2++;
				else qi3+=a[i],a[i]=0;
			}
			if(qi2==10)
			{
				if(a[i]>=21) a[i]-=21,qi2++;
				else
					{
						if(a[i]<=3) qi3+=a[i],a[i]=0;
						else qi3+=10+a[i],a[i]=0;
					}
			}
			}
		}
		if(qi>1582)
		{
			if((qi%100!=0&&qi%4==0)||(qi%400==0))
				{
					if(a[i]>=366) 
					{
						a[i]-=366;
						qi++;
					}
					else
					{
							if(qi2==1||qi2==3||qi2==5||qi2==7||qi2==8||qi2==10||qi2==12)
							{
								if(a[i]>=31) qi2++,a[i]-=31;
								else qi3+=a[i],a[i]=0;
							}
							if(qi2==2)
							{
								if(a[i]>=29) qi2++,a[i]-=29;
								else qi3+=a[i],a[i]=0;
							}
							if(qi2==4||qi2==6||qi2==9||qi2==11) 
							{
								if(a[i]>=30) qi2++,a[i]-=30;
								else qi3+=a[i],a[i]=0;
							}
			    	}
				}
		 else 
				{
					if(a[i]>=365) 
					{
						a[i]-=365;
						qi++;
					}
					else
					{
							if(qi2==1||qi2==3||qi2==5||qi2==7||qi2==8||qi2==10||qi2==12)
							{
								if(a[i]>=31) qi2++,a[i]-=31;
								else qi3+=a[i],a[i]=0;
							}
							if(qi2==2)
							{
								if(a[i]>=28) qi2++,a[i]-=28;
								else qi3+=a[i],a[i]=0;
							}
							if(qi2==4||qi2==6||qi2==9||qi2==11) 
							{
								if(a[i]>=30) qi2++,a[i]-=30;
								else qi3+=a[i],a[i]=0;
							}	
					}
				}	
		}
	}
	if(qi<0) 
	{
		cout<<qi3<<' '<<qi2<<' '<<abs(qi)<<' '<<"BC";
		if(i!=Q) cout<<endl;
	}
	else
	{
		cout<<qi3<<' '<<qi2<<' '<<qi;
		if(i!=Q) cout<<endl;
	}
	}
	return 0;
}
