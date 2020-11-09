#include<bits/stdc++.h>
using namespace std;
int yue[12]={32,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int n;
	cin>>n;
	int m;
	int y=4713;
	int d=1;
	int a=1;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		m++;
		while(m>365){	
			if(y==0)
			{
				y=-1;
			}
		  	if(m>=365&&y%4!=0){
				m-=365;
				y--;
				yue[0]=31;
			}
			else if(m>=366&&y%4==0)
			{
				m-=366;
				y--;
				yue[0]=31;
			}
		}
				for(int j=0;j<=11;j++)
				{
					if(m>=yue[j]&&j!=1)
					{
						m-=yue[j];
						a++;
					}
					else if(j==1&&m>yue[j]){
						if(y%4==0){
							m-=29;
							a++;
						}
						else{
							m-=28;
							a++;
						}	
					}
				}	
				if(y<0){
					cout<<m<<" "<<a<<" "<<y*(-1)<<endl;
				    a=1;
				}
				else{
					cout<<m<<" "<<a<<" "<<y<<" "<<"BC"<<endl;
					a=1;
				}
	}			
	return 0;
}
