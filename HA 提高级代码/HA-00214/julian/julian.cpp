#include<bits/stdc++.h>
using namespace std;
int n;
int a[30]={0,31,28,31,30,31,30,31,31,30,31,30,31};
long long r;
long long dd=1,mm=1,yy=-4713;
int y=yy,d=dd,m=mm;
bool f=0;
void out(int x1,int y1,int z1){
	cout<<x1<<' '<<y1<<' '<<abs(z1);
	if(z1<0)cout<<' '<<"BC";
	cout<<endl;
	f=1;
	return ;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	int dey;
	for(int i=1;i<=n;i++){
		cin>>r;
		f=0;
		y=yy;
		d=dd;
		m=mm;
		while(f==0){
			if(y==0)y++;
			if(y>=1582)r+=10;
			if(y>0){
				if((abs(y)%4==0&&abs(y)%100!=0)||abs(y)%400==0)dey=366;
	        	else dey=365;
			}
			else{
				if(abs(y)%4==0)dey=366;
	         	else dey=365;
			}
			if(dey==366){
				a[2]=29;
				//cout<<213;
			}
			else a[2]=28;
			if(r-dey<0){
				while(f==0){
					if(r-a[m]<0){
						out(r+d,m,y);
					}
					else if(r-a[m]==0){
						m++;
						out(d,m,y);
						break;
					}
				    else{
				    	r-=a[m];                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
						m++;
					}
				}
			}
			else if(r-dey==0){
			    y++;
		     	out(d,m,y);
		     	break;
		    }
			else{
			   	r-=dey;
		    	y++;
			} 	
		}
	}
	return 0;
}
