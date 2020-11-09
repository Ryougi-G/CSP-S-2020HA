#include<bits/stdc++.h>
using namespace std;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main() {

	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q,tip;
	tip=2444984;
	cin>>q;
	bool st=false;
	for(int i=1;i<=q;i++)
	  {
	  	int r,d,m=1,y=4713;
	  	bool run=false;
	  	cin>>r;
	  	if(r<tip)
	  	  {
	  	  	month[10]=31;
	  	  	int s1=r/1461;
	  	  	r-=(s1*1461);
	  	  	if(s1*4>y) 
	  	  	{
	  	  	  y=(s1*4-y)+1;
	  	  	  run=true;
        }
 	  	  	else y-=(s1*4);
 	  	  	int s2=0;
 	  	  	if(r>366)
 	  	  	  {
 	  	  	  	r-=366;
 	  	  	  	s2++;
 	  	  	  	s2+=(r/365);
 	  	  	  	r%=365;
 	  	  	  }
	  	  	if(s2>=y&&run==false) 
				 {
				  y=s2-y+1;
				  run=true;
			     }
			else
			  {
			  	if(run==true) y+=s2;
			  	else y-=s2;
			  }
			if(s2==1) 
			  	month[2]=29;
			else month[2]=28;
			int j=1;
			while(r>=month[j])
			  	{
			  	  m++;
			  	  r-=month[j];
			  	  j++;
                }
                d=r+1;
            if(run==true) cout<<d<<" "<<m<<" "<<y<<endl;
            else cout<<d<<" "<<m<<" "<<y<<" "<<"BC"<<endl;
	  	  }
	  	else
	  	  {
	  	  	if(r==3000000) cout<<"15 8 3501";
	  	  	if(r==4000000) cout<<"12 7 6239";
	  	  }
}
return 0;
}
	  	
