#include<bits/stdc++.h>
using namespace std;
bool flag(int a){
	if(a%100!=0&&a%4==0){
		return true;
	}
	if(a%400==0){
		return true;
	}
	return false;
}
void r(int n){
	int y=4713;
	int m=1;
	int d=1;
	for(int i=365;i<=n;n-=365)
	{
		y--;
		if((y-1)%4==0)
		{
			n--;
			if(n<0){
				n+=366;
				y++;	
			}
		}
		if(n<0){
				n+=365;
				y++;	
			}
	}
	for(int i=31;i<=n;n-=31){
		m++;
		if(m==2&&(y-1)%4==0){
			n+=2;
		}
		/*if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
			n++;
		}*/
		if(m==4||m==6||m==9||m==11){
			n++;	
		}
	}
	if(y<=0){
		y=-y+1;
		d++;
	}
	d+=n;
	/*if(n>1723534)
	d++;*/
	cout<<d<<" "<<m<<" "<<y;
}	
void g(int n){
	int y=1582;
	int m=10;
	int d=15;
	for(int i=365;i<=n;n-=365)
	{
		y++;
		if(flag(y))
		{
			n--;
			if(n<0){
				y--;
				n+=366;	
			}
		}
		if(n<0){
				y--;
				n+=365;	
			}
	}
	for(int i=31;i<=n;n-=31){
		m++;
		if(m==2&&flag(y)){
			n+=2;
		}
		if(m==4||m==6||m==9||m==11){
			n++;	
		}
	}
	d+=n;
	if(y==0&&m==1){
		y=1;
		d--;
	}
	if(y<0){
		y=-y+1;
		d++;
	}
	cout<<d<<" "<<m<<" "<<y;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q;
	cin>>q;
	int w;
	while(q--){
		cin>>w;
		if(w<=1721423){
			r(w);
			cout<<" "<<"BC";
		}
		
		if(w>1721423&&w<2301637){
			r(w);
		}
		if(w>2301637){
			g(w-2301637);
		}
		cout<<endl;
	}
	
	return 0;
}
