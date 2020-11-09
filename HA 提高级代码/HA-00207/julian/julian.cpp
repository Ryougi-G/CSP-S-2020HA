#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int q;
unsigned long long r;
int md[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int d=1,m=1,y=-4713;
bool run_nian(int x,int t){
	if(t==1){
		x+=1;
		return x%4==0;
	}else if(t==2){
		return x%4==0;
	}else if(t==3){
		return (x%400==0)||(x%4==0&&x%100!=0);
	}
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin >> q ;
	for(int i=1;i<=q;i++){
		cin >> r ;
		d=1,m=1,y=-4713;
		while(r!=0){
			if(y<1582||(y==1582&&m<=10)||(y==1582&&m==10&&d<=4)){
				if(y<0){
					if(run_nian(y,1)){
						if(r>366){
							y++;
							r-=366;
							if(y==0){
								y++;
							}
						}
					}else{
						if(r>365){
							y++;
							r-=365;
							if(y==0){
								y++;
							}
						}
					}
				}else{
					if(run_nian(y,2)){
						if(r>366){
							y++;
							r-=366;
							if(y==0){
								y++;
							}
						}
					}else{
						if(r>365){
							y++;
							r-=365;
							if(y==0){
								y++;
							}
						}
					}
				}
				for(int j=1;j<=12;j++){
					if(j!=2){
						if(r>=md[j]){
							r-=md[j];
							d=1;
							m++;
							if(m==13){
								m=1;
								y++;
								if(y==0){
									y++;
								}
							}
						}else{
							d+=r;
							r=0;
							break;
						}
					}else{
						if(y<0){
							if(run_nian(y,1)){
								if(r>=29){
									r-=29;
									d=1;
									m++;
								}else{
									d+=r;
									r=0;
									break;
								}
							}else{
								if(r>=28){
									r-=28;
									d=1;
									m++;
								}else{
									d+=r;
									r=0;
									break;
								}
							}
						}else{
							if(run_nian(y,2)){
								if(r>=29){
									r-=29;
									d=1;
									m++;
								}else{
									d+=r;
									r=0;
									break;
								}
							}else{
								if(r>=28){
									r-=28;
									d=1;
									m++;
								}else{
									d+=r;
									r=0;
									break;
								}
							}
						}	
					}
					if(r==0){
						break;
					}
				}
			}else if(y==1582&&m==10&&d>=5&&d<15){
				d=15;
			}else if(y>1582||(y==1582&&m>10)||(y==1582&&m==10&&d>=15)){
				if(run_nian(y,3)){
					if(r>366){
						y++;
						r-=366;
						if(y==0){
							y++;
						}
					}
				}else{
					if(r>365){
						y++;
						r-=365;
						if(y==0){
							y++;
						}
					}
				}
				for(int j=1;j<=12;j++){
					if(j!=2){
						if(r>=md[j]){
							r-=md[j];
							d=1;
							m++;
							if(m==13){
								m=1;
								y++;
								if(y==0){
									y++;
								}
							}
						}else{
							d+=r;
							r=0;
							break;
						}
					}else{
						if(run_nian(y,3)){
							if(r>=29){
								r-=29;
								d=1;
								m++;
							}else{
								d+=r;
								r=0;
								break;
							}
						}else{
							if(r>=28){
								r-=28;
								d=1;
								m++;
							}else{
								d+=r;
								r=0;
								break;
							}
						}	
					}
				}
			}
		}
		if(y>1582||(y==1582&&m>10)||(y==1582&&m==10&&d>=15)){
			d+=10;
		}
		cout << d << " " << m << " " << abs(y) ;
		if(y<0){
			cout << " BC" ;
		}
		cout << '\n' ;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
