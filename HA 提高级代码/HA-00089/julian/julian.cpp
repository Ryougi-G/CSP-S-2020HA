#include<bits/stdc++.h>
using namespace std;
long q,num;
int day,m,y;
int monthr[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int monthp[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int year1[405],year2[405];
void getrun(int x)
{
	if(x==366){cout<<31<<" "<<12<<" ";return;}
	for(int i=1;i<=12;i++)
	{
		if(x<monthr[i]){printf("%d %d ",x+1,i);break;		}
		x-=monthr[i];
	}
	return;
}
void getp(int x)
{
	if(x==365){cout<<31<<" "<<12<<" ";return;}
	for(int i=1;i<=12;i++)
	{
		if(x<monthp[i]){printf("%d %d ",x+1,i);break;		}
		x-=monthp[i];
	}
	return;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	for(int i=1;i<=400;i++)
	{
		if(((i-1)%4==0&&(i-1)%100!=0)||(i-1)%400==0)year1[i]=366;
		else year1[i]=365;
	}
	for(int i=1;i<=400;i++)
	{
		if(((i)%4==0&&(i)%100!=0)||(i)%400==0)year2[i]=366;
		else year2[i]=365;
	}
	cin>>q;
	while(q>0)
	{
		scanf("%ld",&num);
		if(num<1143875)
		{
			int n4=num/1461;
			num=num-(n4)*1461;
			n4*=4;
			if(num>366){num-=366;n4++;	}
			else
			{
				getrun(num);
				printf("%d BC\n",4713-n4);
				q--;
				continue;
			}
			while(num>=365){n4++;num-=365;	}
			getp(num);
				printf("%d BC\n",4713-n4);
				q--;
				continue;
		}
		else
		{
			num-=1143875;
			if(num<78)
			{
				if(num<17){cout<<15
				+num<<" "<<10<<" "<<1582<<" "<<"BC";q--;continue;}
				num-=17;
				if(num<30){cout<<num+1<<" "<<11<<" "<<1582<<" "<<"BC";q--;continue;}
				num-=30;
				cout<<num+1<<" "<<12<<" "<<1582<<" "<<"BC";q--;continue;
		    }
		    num-=78;
		     	if(num<577449)
		     	{
		     		int n400=num/146097;
		     		num=num-(n400)*146097;
			        n400*=400;
			        	for(int i=1;i<=400;i++)
			        	{
			        		if(num<year1[i]){
							if(year1[i]==365)
							{
								getp(num);
								printf("%d BC\n",1581-n400);
				                q--;
				                
			        		}    		
							     
								 if(year1[i]==366)
							{
								getrun(num);
								printf("%d BC\n",1581-n400);
				                q--;
				                
			        		}  break;            }
			        		num-=year1[i];
			        		n400++;
			        	}
		     	}
		     	else
		     	{
		     		num=num-2000000+278570;
		     		long n400=0;
		     			num-=145731;
		     		 n400=num/146097;
		     		num=num-(n400)*146097;
			        ++n400*=400;
			        num+=4;
		     		
		        	for(int i=1;i<400;i++)
			        	{
			        		if(num<year1[i])
							{
							if(year1[i]==365)
							{
								getp(num);
								printf("%ld \n",n400);
				                q--; 
			        		}    		
							     
								 if(year1[i]==366)
							{
								getrun(num);
								printf("%ld \n",n400);
				                q--;
				                
			        		}        break;      }
			        		num-=year1[i];
			        		n400++;
			        	}
		     	}
                                                
	   }
    }
	return 0;
}
