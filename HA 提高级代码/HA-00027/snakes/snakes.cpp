#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,t,sum;
int a[1001111],k[1001111],p,q,g,x[11];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t;
	cin>>n;
	sum=n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int b=0;b<n-1;b++)
	   {   
	      sort(a,a+n);
		  if(a[n-1]-a[b]>a[n-2])
	      {
		    a[n-1]-=a[b];
		    a[b]=0;
	        sum--;
	      }
	     else 
		 {
		 	g=sum;
		 	break;
		 }	 
	   }
	for(int d=0;d<t-1;d++)
	{
		for(int i=0;i<t-1;i++)
	{
	    cin>>p;
 	    for(int J=0;J<p;J++)
 	   {
		   cin>>q>>k[J];
		   a[q-1]=k[J];
	   }
	   for(int j=0;j<n-1;j++)
	   {   
	      sort(a,a+n);
	      if(a[n-1]-a[j]<=a[n-2]&&a[n-1]-a[j]>=a[j]) sum--;
	      	if(a[n-1]-a[j]>=a[n-2])
	      {
	      	int num=a[n-1]-a[j];
	      	int _num=a[j];
	      	sort(a,a+n);
	      	a[n-1]-=a[j];
		    a[j]=0;
	      	if(num<a[n])
	      	{
	      	  a[n-1]+=_num;
		      a[j]=_num;
	      	}else sum--;
	      }
		  else x[d]=sum;
	   }
	 }
    }
	cout<<g<<endl;
	for(int i=0;i<t-1;i++) cout<<x[i]+1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
