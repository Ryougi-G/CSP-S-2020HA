#include<bits/stdc++.h>
using namespace std;
int q[1000];
int year[5000];
int month[12];
int day[31];
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int Q;
	cin>>Q;
	for (int s=1;s<=Q;++s)
	{
		cin>>q[s];
		for(int i=1;i<=31;++i)
		  day[i]=i;
		  cin>>day[i];
		  for(int j=1;j<=12;j++)
		    month[j]=j;
		    cin>>month[j]; 
		    for(int k=4713;k>=1;--k)
		      year[k]=k;
		      cin>>year[k];
		      if(Y%4==0)
			    day[2]=29;
			  else
			    day[2]=28;
				 	  
	}
	return 0;
}
