#include<stdio.h>
#include<stdlib.h>
int left[4],right[4];
long int a1,a2,m[100001];
void play(long int n);
int pd()
{
	int day=0;
	if(left[0]==1582&&left[3]==1)
	{
	
	
	
	{
		if(left[0]==right[0])
		{
			if(left[1]==right[1])
			{
				day==right[2]-left[2];
			}
			else
			{
				//day
			if(left[1]==1||left[1]==3||left[1]==5||left[1]==7||left[1]==8||left[1]==10||left[1]==12) day+=(31-left[2]);
			if(left[1]==4||left[1]==6||left[1]==9||left[1]==11) day+=(30-left[2]);
			if(left[1]==2)
			{
				
				if(left[0]%4!=0||(left[0]%400!=0&&left[0]%100==0)) day+=(28-left[2]);
				else day+=(29-left[2]);
			}
			left[1]++;
			
		//month	
			for(;left[1]<right[1];left[1]++)
			{
				if(left[1]==1||left[1]==3||left[1]==5||left[1]==7||left[1]==8||left[1]==10||left[1]==12) day+=31;
				if(left[1]==4||left[1]==6||left[1]==9||left[1]==11) day+=30;
				if(left[1]==2)
				{
				
					if(left[0]%4!=0||(left[0]%400!=0&&left[0]%100==0)) day+=28;
					else day+=29;
				}
			}
			day+=right[2];
			
			}
		}
		else
		{
		
		//day
			if(left[1]==1||left[1]==3||left[1]==5||left[1]==7||left[1]==8||left[1]==10||left[1]==12) day+=(31-left[2]);
			if(left[1]==4||left[1]==6||left[1]==9||left[1]==11) day+=(30-left[2]);
			if(left[1]==2)
			{
				
				if(left[0]%4!=0||(left[0]%400!=0&&left[0]%100==0)) day+=(28-left[2]);
				else day+=(29-left[2]);
			}
			left[1]++;
			
		//month	
			for(;left[1]<=12;left[1]++)
			{
				if(left[1]==1||left[1]==3||left[1]==5||left[1]==7||left[1]==8||left[1]==10||left[1]==12) day+=31;
				if(left[1]==4||left[1]==6||left[1]==9||left[1]==11) day+=30;
				if(left[1]==2)
				{
				
					if(left[0]%4!=0||(left[0]%400!=0&&left[0]%100==0)) day+=28;
					else day+=29;
				}
			}
			left[0]++;
			
		//year	
			for(;left[0]<right[0];left[0]++)
			{
				if(left[0]%4!=0||(left[0]%400!=0&&left[0]%100==0)) day+=365;
				else day+=366;
			}
			
		//last	
			for(left[1]=1;left[1]<right[1];left[1]++)
			{
				if(left[1]==1||left[1]==3||left[1]==5||left[1]==7||left[1]==8||left[1]==10||left[1]==12) day+=31;
				if(left[1]==4||left[1]==6||left[1]==9||left[1]==11) day+=30;
				if(left[1]==2)
				{
				
					if(left[0]%4!=0||(left[0]%400!=0&&left[0]%100==0)) day+=28;
					else day+=29;
				}
			}
			day+=right[2];
		}
	}
	
	
	}
	else
	{
		if(left[3]==0)
	{
		if(left[0]==right[0])
		{
			if(left[1]==right[1])
			{
				day=right[2]-left[2];
			}
			else
			{
				//day
			if(left[1]==1||left[1]==3||left[1]==5||left[1]==7||left[1]==8||left[1]==10||left[1]==12) day+=(31-left[2]);
			if(left[1]==4||left[1]==6||left[1]==9||left[1]==11) day+=(30-left[2]);
			if(left[1]==2)
			{
				
				if(left[0]%4!=0) day+=(28-left[2]);
				else day+=(29-left[2]);
			}
			left[1]++;
			
		//month	
			for(;left[1]<right[1];left[1]++)
			{
				if(left[1]==1||left[1]==3||left[1]==5||left[1]==7||left[1]==8||left[1]==10||left[1]==12) day+=31;
				if(left[1]==4||left[1]==6||left[1]==9||left[1]==11) day+=30;
				if(left[1]==2)
				{
				
					if(left[0]%4!=0) day+=28;
					else day+=29;
				}
			}
			day+=right[2];
			
			}
		}
		else
		{
		
		//day
			if(left[1]==1||left[1]==3||left[1]==5||left[1]==7||left[1]==8||left[1]==10||left[1]==12) day+=(31-left[2]);
			if(left[1]==4||left[1]==6||left[1]==9||left[1]==11) day+=(30-left[2]);
			if(left[1]==2)
			{
				
				if(left[0]%4!=0) day+=(28-left[2]);
				else day+=(29-left[2]);
			}
			left[1]++;
			
		//month	
			for(;left[1]<=12;left[1]++)
			{
				if(left[1]==1||left[1]==3||left[1]==5||left[1]==7||left[1]==8||left[1]==10||left[1]==12) day+=31;
				if(left[1]==4||left[1]==6||left[1]==9||left[1]==11) day+=30;
				if(left[1]==2)
				{
				
					if(left[0]%4!=0) day+=28;
					else day+=29;
				}
			}
			left[0]--;
			
		//year	
			for(;left[0]>right[0];left[0]--)
			{
				if(left[0]%4!=0) day+=365;
				else day+=366;
			}
			
		//last	
			for(left[1]=1;left[1]<right[1];left[1]++)
			{
				if(left[1]==1||left[1]==3||left[1]==5||left[1]==7||left[1]==8||left[1]==10||left[1]==12) day+=31;
				if(left[1]==4||left[1]==6||left[1]==9||left[1]==11) day+=30;
				if(left[1]==2)
				{
				
					if(left[0]%4!=0||(left[0]%400!=0&&left[0]%100==0)) day+=28;
					else day+=29;
				}
			}
			day+=right[2];
		}
	}
	else
	{
		if(left[0]==right[0])
		{
			if(left[1]==right[1])
			{
				day==right[2]-left[2];
			}
			else
			{
				//day
			if(left[1]==1||left[1]==3||left[1]==5||left[1]==7||left[1]==8||left[1]==10||left[1]==12) day+=(31-left[2]);
			if(left[1]==4||left[1]==6||left[1]==9||left[1]==11) day+=(30-left[2]);
			if(left[1]==2)
			{
				
				if(left[0]%4!=0) day+=(28-left[2]);
				else day+=(29-left[2]);
			}
			left[1]++;
			
		//month	
			for(;left[1]<right[1];left[1]++)
			{
				if(left[1]==1||left[1]==3||left[1]==5||left[1]==7||left[1]==8||left[1]==10||left[1]==12) day+=31;
				if(left[1]==4||left[1]==6||left[1]==9||left[1]==11) day+=30;
				if(left[1]==2)
				{
				
					if(left[0]%4!=0) day+=28;
					else day+=29;
				}
			}
			day+=right[2];
			
			}
		}
		else
		{
		
		//day
			if(left[1]==1||left[1]==3||left[1]==5||left[1]==7||left[1]==8||left[1]==10||left[1]==12) day+=(31-left[2]);
			if(left[1]==4||left[1]==6||left[1]==9||left[1]==11) day+=(30-left[2]);
			if(left[1]==2)
			{
				
				if(left[0]%4!=0) day+=(28-left[2]);
				else day+=(29-left[2]);
			}
			left[1]++;
			
		//month	
			for(;left[1]<=12;left[1]++)
			{
				if(left[1]==1||left[1]==3||left[1]==5||left[1]==7||left[1]==8||left[1]==10||left[1]==12) day+=31;
				if(left[1]==4||left[1]==6||left[1]==9||left[1]==11) day+=30;
				if(left[1]==2)
				{
				
					if(left[0]%4!=0) day+=28;
					else day+=29;
				}
			}
			left[0]++;
			
		//year	
			for(;left[0]<right[0];left[0]++)
			{
				if(left[0]%4!=0) day+=365;
				else day+=366;
			}
			
		//last	
			for(left[1]=1;left[1]<right[1];left[1]++)
			{
				if(left[1]==1||left[1]==3||left[1]==5||left[1]==7||left[1]==8||left[1]==10||left[1]==12) day+=31;
				if(left[1]==4||left[1]==6||left[1]==9||left[1]==11) day+=30;
				if(left[1]==2)
				{
				
					if(left[0]%4!=0) day+=28;
					else day+=29;
				}
			}
			day+=right[2];
		}
	}
	
	
	}
	return day;
}
void zb()
{
	left[0]=4712;left[1]=1;left[2]=1;left[3]=0;right[0]=0;right[1]=12;right[2]=31;right[3]=0;
	a1=pd();
	left[0]=1;left[1]=1;left[2]=1;left[3]=1;right[0]=1582;right[1]=10;right[2]=4;right[3]=1;
	a2=a1+pd()+1;
	
}
void play(long int n)
{
	int i,j,k;
	long int d,l;
	if(n>a2)
	{
		i=1582;j=10;k=15;
		left[0]=1582;left[1]=10;left[2]=15;left[3]=1;right[0]=i;right[1]=j;right[2]=k;right[3]=1;
		while(pd()<(n-a2))
		{
			i++;left[0]=1582;left[1]=10;left[2]=15;left[3]=1;right[0]=i;right[1]=j;right[2]=k;right[3]=1;
		}i--;
		while(pd()<(n-a2))
		{
			j++;left[0]=1582;left[1]=10;left[2]=15;left[3]=1;right[0]=i;right[1]=j;right[2]=k;right[3]=1;
		}j--;
		while(pd()<(n-a2))
		{
			k++;left[0]=1582;left[1]=10;left[2]=15;left[3]=1;right[0]=i;right[1]=j;right[2]=k;right[3]=1;
		}k--;
		printf("%d %d %d\n",j,k,i);
	}
	else if(n>a1)
	{
		i=1;j=1;k=1;
		left[0]=1;left[1]=1;left[2]=1;left[3]=1;right[0]=i;right[1]=j;right[2]=k;right[3]=1;
		while(pd()<(n-a1))
		{
			i++;left[0]=1;left[1]=1;left[2]=1;left[3]=1;right[0]=i;right[1]=j;right[2]=k;right[3]=1;
		}
		i--;
		while(pd()<(n-a1))
		{
			j++;left[0]=1;left[1]=1;left[2]=1;left[3]=1;right[0]=i;right[1]=j;right[2]=k;right[3]=1;
		}
		j--;
		while(pd()<(n-a1))
		{
			k++;left[0]=1;left[1]=1;left[2]=1;left[3]=1;right[0]=i;right[1]=j;right[2]=k;right[3]=1;
		}
		k--;
		printf("%d %d %d\n",j,k,i);
	}
	else
	{
		i=4712;j=1;k=1;
		left[0]=4712;left[1]=1;left[2]=1;left[3]=0;right[0]=i;right[1]=j;right[2]=k;right[3]=0;	d=pd();
		l=n-a1;
		for(;d<l;)
		{
			i--;left[0]=4712;left[1]=1;left[2]=1;left[3]=0;right[0]=i;right[1]=j;right[2]=k;right[3]=0;
			d=pd();
		}
		i++;
		while(pd()<(n-a1))
		{
			j++;left[0]=4712;left[1]=1;left[2]=1;left[3]=0;right[0]=i;right[1]=j;right[2]=k;right[3]=0;
		}
		j--;
		while(pd()<(n-a1))
		{
			k++;left[0]=4712;left[1]=1;left[2]=1;left[3]=0;right[0]=i;right[1]=j;right[2]=k;right[3]=0;
		}
		k--;
		printf("%d %d %d BC\n",j,k,i);
	}
}
int main()
{
freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int i,j;

	zb();
	scanf("%d",&i);
	for(j=0;j<i;j++)
	{
	
		scanf("%ld",&m[j]);
		
	}
	for(j=0;j<i;j++)
		play(m[j]);
	
	return 0;
}
