#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int r,y,n=4713,q,l,L[1000000000];
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>L[i];		
	}
	for(int j=0;j<q;j++)
	{
		L[j]==L[l];
		if(L[j]<=30)//1
		{
			r=L[j]+1;
	        y=1;
		    cout<<r<<' '<<y<<' '<<n;
		}
		else
		{
			if(L[j]<=58&&L[j]>30)//2
			{
				r=L[j]-30;
	   	        y=2;
	   	        cout<<r<<' '<<y<<' '<<n;
			}
			else
			{
				 if(L[j]<=89&&L[j]>58)//3
				 {
				 	r=L[j]-58;
	   	   	        y=3;
	   	   	        cout<<r<<' '<<y<<' '<<n;
				 }
				 else
				 {
				 	if(L[j]<=119&&L[j]>89)//4
				 	{
				 		r=L[j]-89;
	   	     	        y=4;
	   	     	        cout<<r<<' '<<y<<' '<<n;
				 	}
				 	else
				 	{
				 		if(L[j]<=150&&L[j]>119)//5
				 		{
				 			r=L[j]-119;
	   	     	            y=5;
	   	     	            cout<<r<<' '<<y<<' '<<n;
				 		}
				 		else
				 		{
				 			if(L[j]<=180&&L[j]>150)//6
				 			{
				 				r=L[j]-150;
	   	     	                y=6;
	   	     	                cout<<r<<' '<<y<<' '<<n;
				 			}
				 			else
				 			{ 
							    if(L[j]<=211&&L[j]>180)//7
							    {
							    	r=L[j]-180;
	   	     	                    y=7;
	   	     	                    cout<<r<<' '<<y<<' '<<n;
							    }
							    else
							    {
							    	if(L[j]<=242&&L[j]>211)//8
							    	{
							    		r=L[j]-211;
	   	     	                        y=8;
	   	     	                        cout<<r<<' '<<y<<' '<<n;
							    	}
							    	else
							    	{
							    		if(L[j]<=272&&L[j]>242)//9
							    		{
							    			r=L[j]-242;
	   	     	                            y=9;
	   	     	                            cout<<r<<' '<<y<<' '<<n;
							    		}
							    		else
							    		{
							    			if(L[j]<=303&&L[j]>272)//10
							    			{
							    				r=L[j]-272;
	   	     	                                y=10;
	   	     	                                cout<<r<<' '<<y<<' '<<n;
							    			}
							    			else
							    			{
							    				if(L[j]<=333&&L[j]>303)//11
							    				{
							    					r=L[j]-303;
	   	     	                                    y=11;
	   	     	                                    cout<<r<<' '<<y<<' '<<n;
							    				}
							    				else
                                                {	
							    					r=L[j]-334;
	   	     	                                    y=12;
	   	     	                                    cout<<r<<' '<<y<<' '<<n;
							    				
							    				}
							    			}
							    		}
							    	}
							    }
				 			}
				 		}
				 	}
				 }
			}	
		}
		cout<<' '<<"BC"<<endl;
	}
	return 0;
}
