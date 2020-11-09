#include<bits/stdc++.h>

using namespace std;

const long long int N = 10000000;

long long int q;

long long int julian[N];int pingrun,x,y,m,n,o    ,  zhang,xin        ,yu;

struct first{
	int day;
	int month;
	int year;
	bool gongyuan;
};
first shuzu[N];


int yue(int i,int yy)
{
	if(pingrun == 1)
	{
	if(i<=30)
	x = 1 ,y = i+1;
	else if(i<=59)
	x = 2 , y= i-30;
	else if(i<=90) x= 3 ,y=i-59+1;
	else if(i<=120) x = 4,y=i-90;
	else if(i<= 151) x = 5,y=i-120;
	else if(i<=181) x =6,y=i-151;
	else if(i<=212) x= 7,y=i-181;
	else if(i<=243) x = 8,y=i-212;
	else if(i<= 273) x = 9,y=i-243;
	else if(i<= 304) x = 10,y=i-273;
	else if(i<=334) x= 11,y=i-304;
	else if(i<=365) x =12,y=i-334;
	
	}

    else {
	if(i<=31)
	x = 1 ,y = i;
	else if(i<=59)
	x = 2 , y= i-31;
	else if(i<=90) x= 3 ,y=i-59;
	else if(i<=120) x = 4,y=i-90;
	else if(i<= 151) x = 5,y=i-120;
	else if(i<=181) x =6,y=i-151;
	else if(i<=212) x= 7,y=i-181;
	else if(i<=243) x = 8,y=i-212;
	else if(i<= 273) x = 9,y=i-243;
	else if(i<= 304) x = 10,y=i-273;
	else if(i<=334) x= 11,y=i-304;
	else if(i<=365) x =12,y=i-334;}
	
}


int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++)
	cin>>julian[i];
	
	for(int i=1;i<=q;i++)

	if(julian[i]<=1721423)
	{
		m=(julian[i]+1)/1461;
		o=(julian[i]+1)-1461*m;
		shuzu[i].year=4713-m*4;
		if(o<=366)
		{
			pingrun = 1;
			yue(o-1,pingrun);
			shuzu[i].month = x;
	     shuzu[i].day = y;
	    printf("%d %d %d BC\n",shuzu[i].day,shuzu[i].month,shuzu[i].year);
	   
		}
		
		else if(o<=10000)
		{
			pingrun = 0;
			zhang = (o-366)%365;
			xin = (o-366)/365;
			if(zhang!=0)
			shuzu[i].year  -= xin+1;
			
			else {
			shuzu[i].year -= xin;
			zhang = 1;}
			yue(zhang,pingrun);
			shuzu[i].month = x;
	     shuzu[i].day = y;
	    printf("%d %d %d BC\n",shuzu[i].day,shuzu[i].month,shuzu[i].year);
		}
		
	}
	else 
	{
		julian[i] = julian[i]-1721423;
		if(julian[i]<=577737)
		{
			
		m=(julian[i])/1461;
		o=(julian[i])-1461*m;
		shuzu[i].year=4*m;
		if(o<=1095)
		{
			pingrun = 0;
			zhang = o%365;
			xin =  o/365;
			if(zhang!=0)
			shuzu[i].year  += xin+1;
			
			else {
			shuzu[i].year += xin;
			zhang = 365;}
			yue(zhang,pingrun);
			shuzu[i].month = x;
	     shuzu[i].day = y;
	    printf("%d %d %d\n",shuzu[i].day,shuzu[i].month,shuzu[i].year);
		}
		else 
		{
			pingrun = 1;
			zhang = o-1095;
			shuzu[i].year +=4;
			yue(zhang,pingrun);
			shuzu[i].month = x;
	     shuzu[i].day = y;
	    printf("%d %d %d/n",shuzu[i].day,shuzu[i].month,shuzu[i].year);
		}		
		}
		
		
		else 
		{
			julian[i]=julian[i]-577737;
			
				if(julian[i]<=78)
				{
					if(julian[i]<=17)
					printf("%d 10 1582\n",julian[i]+14);
					else if(julian[i]<=47)
					printf("%d 11 1582\n",julian[i]-17);
					else if(julian[i]<=78)
					printf("%d 12 1582\n",julian[i]-47);
				}
				
				
				else
				{
					julian[i]=julian[i]+10+577737;
					m=(julian[i])/1461;
		o=(julian[i])-1461*m;
		shuzu[i].year=4*m;
		if(o<=1095)
		{
			pingrun = 0;
			zhang = o%365;
			xin =  o/365;
			if(zhang!=0)
			shuzu[i].year  += xin+1;
			
			else {
			shuzu[i].year += xin;
			zhang = 365;}
			yue(zhang,pingrun);
			shuzu[i].month = x;
	     shuzu[i].day = y;
	     
	    printf("%d %d %d\n",shuzu[i].day,shuzu[i].month,shuzu[i].year);
		}
			    
		
		}
}}
fclose(stdin);
fclose(stdout);
	return 0;
	
}
