//1 1 4713
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int date[13]={' ',31,28,31,30,31,30,31,31,30,31,30,31};
int q;
long long r;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
    cin>>q;
	for(int i=1;i<=q;i++){
		cin>>r;
		if(r<=1721424){//公元前 
		    int d=1,m=1,y=0;
			y=r/1461*4;//4年一周期 
			r-=r/1461*1461;
			if(r<=366){
				for(int i=1;i<=12;i++){
					if(i==2&&r-29>=0){
						r-=29;
						m++;
					}
					else{
						if(r-date[i]>=0){
							r-=date[i];
							m++;
						}
					}
				}
				d+=r;
				r=0;
			}else{
				r-=366;y++;
				int x=r/365;
				y+=x;r-=365*x;
				for(int i=1;i<=12;i++){
					if(r-date[i]>=0){
						m++;
						r-=date[i];
					}
				}
				d+=r;
			}
			
		    cout<<d<<" "<<m<<" "<<4713-y<<" "<<"BC"<<endl;
		}else if(r<=2299526){//公元后，没有换日历 
		    int d=1,m=1,y=1;
			r-=1721424;
			y+=r/1461*4;//4年一周期 
			r-=r/1461*1461;
			for(int i=1;i<=4;i++){
				if(r>=365){
					r-=365;
					y++;
					continue;
				}else{
					for(int j=1;j<=12;j++){
						if(i==4&&j==2&&r-29>=0){
							r-=29;
							m++;
						}else{
							if(r-date[j]>=0){
								r-=date[j];
								m++;
							}
						}
					}
				}
			}
			d+=r;
		    cout<<d<<" "<<m<<" "<<y<<endl;
		}else{//换成新历法 
			r-=2299526;
			if(r<=78){
				int d=14,m=10,y=1582;
				if(r<=17)cout<<d+r<<" "<<m<<" "<<y<<endl;
				else if(r<=47)cout<<r-17<<" "<<m+1<<y<<endl;
				else cout<<r-47<<" "<<m+2<<" "<<y<<endl;
			}else{
				r-=78;
				int d=1,m=1,y=1583,i;
				for(int i=y;;i++){
					if(((i%4==0&&i%100!=0)||(i%400==0))&&r-366>=0){
						y++;
						r-=366;
					}else if(r-365>=0){
						y++;
						r-=365;
					}else{
						for(int j=1;j<=12;j++){
							if(j==2&&r-29==0){
								m++;
								r-=29;
							}else{
								if(r-date[j]>=0){
									m++;
									r-=date[j];
								}
							}
						}
						d+=r;
			 	        cout<<d<<" "<<m<<" "<<y+1<<endl;
			 	        break;
					}
				}
				
			}
		}
		
	}	
	return 0;
}

