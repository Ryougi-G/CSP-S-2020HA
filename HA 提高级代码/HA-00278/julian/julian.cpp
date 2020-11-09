#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
	int ri,Q,i,si,Day,Mouth,Year,a,b;
	cin>>Q; 
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	for(i=0;i<=Q;i++){
	cin>>ri;
	a=ri%365;
	}
	if(a<6295){
	if(a>4713)	
	Year=a-4713-1;
	if((Year-1)%4==0){
	b=ri-365*Year-(Year-1)/4;
	for(int j=1;j<=12;j++)
	if(j=1||j=3||j=5||j=7||j=8||j=10||j=12||b>0)
		b==b-31;
		else
		if(j=2)
		b==b-29;
		else
		b==b-30;
	}
	else{
		for( int j=1;j<=12;j++)
	if(j=1||j=3||j=5||j=7||j=8||j=10||j=12||b>0)
		b==b-31;
		else
		if(j=2||b>0)
		b==b-28;
		else
		b==b-30;
	}	
	cout<<Day<<" "<<Mouth<<" "<<Year<<endl;
	}
    else{
	if(Year%400==0&&Year%4==0||Year%100!=0)
	{
	for(int j=1;j<=12;j++)
	if(j=1||j=3||j=5||j=7||j=8||j=10||j=12||b>0)
		b==b-31;
		else
	if(j=2)
		b==b-29;
		else
		b==b-30;
	}
	else{
	for(int j=1;j<=12;j++)
	if(j=1||j=3||j=5||j=7||j=8||j=10||j=12||b>0)
		b==b-31;
		else
		if(j=2)
		b==b-28;
		else
		b==b-30;
	}	
	cout<<Day<<" "<<Mouth<<" "<<Year<<" "<<"BC"<<endl;
    } 	
	return 0;
}
