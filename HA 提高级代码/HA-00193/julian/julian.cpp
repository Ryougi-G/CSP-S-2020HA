#include<bits/stdc++.h>
using namespace std;
int pmonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int q,r;
int wd,wy,wm;
int main()
{    
	freopen("julain.in","r",stdin);
	freopen("julain.out","w",stdout);

	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{	wd=1;wy=-4713;wm=1;
		scanf("%d",&r);
		for(int q=1;q<=r;q++)
		{ 
		 if(wy<0)
		{  if(((wy+1)%4)==0) pmonth[2]=29;else pmonth[2]=28;
		    wd++;
		  if(wd==(pmonth[wm]+1)) 
	     {   
	    	wm++;wd=1;
	    	if(wm==13)
	    	{
	    		wy++;
	    		
	    		if(wy==0)
	    		{
	    		wy=1;
				wm=1;	
	    		}else wm=1;
	    	} 
	     }
		}
		if(wy>0&&wy<=1582)
		{  if((wy%4)==0) pmonth[2]=29;else pmonth[2]=28;
		if(wy==1582&&wm==10&&wd==4) wd=15;else wd++;
		
			if(wd==(pmonth[wm]+1))
			{
				wm++;
				wd=1;
				if(wm==13)
				{
					wy++;if((wy%4)==0) pmonth[2]=29;else pmonth[2]=28;
					wm=1;
					wd=1;
				}
			}
		}
		 if(wy>1582)
		{  if((wy%400)==0&&((wy%4==0)||(wy%100!=0))) pmonth[2]=29;else pmonth[2]=28;
	
			wd++;
			if(wd==(pmonth[wm]+1))
			{
				wm++;
				wd=1;
				if(wm==13)
				{
					wy++;
					wm=1;
					wd=1;
				}
			}
		} 
		}
		if(wy<0)
	{
		cout<<wd<<" "<<wm<<" "<<(-1*wy)<<" "<<"BC";
	}
	else
	{
		cout<<wd<<" "<<wm<<" "<<wy;
	}
	}
	
	
	fclose(stdin);
	fclose(stdout);
}
