#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100010];
long long d,m=12,y;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	int d1,m1;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		y=-4713;
		m=1;
		d=1;	
		while (a[i]--){
			d++;
				if(y<0){
					if((m==4||m==6||m==9||m==11)&&d>=30){
					m++;
					d-=30;
				}
				else if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d>=31){
					m++;
					d-=31;
				}
				else {
					m++;
					if(y<1582&&-1*(y-1)%4==0&&d>=29)
					d-=29;
					else if(d>=28&&-1*(y-1)%4!=0)
					d-=28;
				}
				}
				if(y>0){
					if((m==4||m==6||m==9||m==11)&&d>=30){
					m++;
					d-=30;
				}
				else if((m==1||m==7||m==12)&&d>=31){
					m++;
					d-=31;
				}
				else if((m==3||m==5||m==8||m==10)&&d>=31){
					m++;
					d-=31;
				}
				else {
					m++;
					if(y<1582&&abs(y)%4==0&&d>=29)
					d=0;
					else d-=29;
				}
				if(y==1582&&m==10&&d==4)
				d+=12;
					if(y>=1582&&y%4==0&&y%100!=0&&d>=29){
						m++;
						d-=29;
					}
					else if(y>=1582&&y%400==0&&d>=29){
						m++;
						d-=29;
					}
					else if((y>=1582&&y%100==0&&y%400!=0&&d>=28)){
						m++;
						d-=28;
					}
			}
			if(m==12){
				m=0;
				if(y+1!=0)
				y+=1;
				else y+=2;
		}
	}
	if(y<0)
		cout<<d<<' '<<m<<' '<<-1*(y)<<' '<<"BC"<<endl;
		else cout<<d<<' '<<m<<' '<<y<<endl;
}
	return 0;
}
