#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000
struct qwq
{
	int day,month;
	long long year;
}ans[maxn];
long long q,rlr[maxn],a;
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int monn[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
     cin>>q;
     for(int i=1;i<=q;i++)
     {
     	scanf("%lld",&rlr[i]);
     	rlr[i]++,ans[i].month++;
     }
     for(int i=1;i<=q;i++)
     {
     	 a=1;   
		 ans[i].year=-4713; 
     	while(rlr[i]>mon[a])
     	{
     	   if(ans[i].year==0) ans[i].year++;
     	  if(ans[i].year<1583) 
     	  {
     	  	if((ans[i].year<0&&ans[i].year%4==-1)||(ans[i].year>0&&ans[i].year%4==0))
			{
			   if(a>12) a-=12;
		       if(ans[i].month>12) ans[i].year++,ans[i].month-=12;
     	       rlr[i]-=monn[a],ans[i].month++;
     	       ++a;
     	    }
			 else 
     	    {
     	       if(a>12) a-=12;
		       if(ans[i].month>12) ans[i].year++,ans[i].month-=12;
     	       rlr[i]-=mon[a],ans[i].month++;
     	       ++a;
     	    }
     	  }   
		  
     	  else
		  if(ans[i].year>=1583) 
     	  {
     	  	if((ans[i].year%4==0&&ans[i].year%100!=0)||ans[i].year%400==0)
			{
			   if(a>12) a-=12;
		       if(ans[i].month>12) ans[i].year++,ans[i].month-=12;
     	       rlr[i]-=monn[a],ans[i].month++;
     	       ++a;
     	    }
			 else 
     	    {
     	       if(a>12) a-=12;
		       if(ans[i].month>12) ans[i].year++,ans[i].month-=12;
     	       rlr[i]-=mon[a],ans[i].month++;
     	       ++a;
     	    } 
     	  }
     	}
     	if(ans[i].year>1582||(ans[i].year==1582&&ans[i].month>10)||(ans[i].year==1582&&ans[i].month==10&&ans[i].day>15)) 
		{
		  ans[i].day=rlr[i]+10;
	    }
	    else ans[i].day=rlr[i];
	    if(rlr[i]>mon[a])
	    rlr[i]-=mon[a],ans[i].month++;
     	printf("%d",ans[i].day);
     	cout<<' ';
     	printf("%d",ans[i].month);
     	cout<<' ';
     	if(ans[i].year<0) printf("%lld",ans[i].year*(-1)),cout<<' ',printf("%s\n","BC");
     	if(ans[i].year>=0) printf("%lld",ans[i].year),cout<<' ',printf("\n");
     }
	return 0;
}
