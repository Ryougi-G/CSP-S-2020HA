#include<bits/stdc++.h>
using namespace std;
void sd(long long day,bool rn){
	day+=1;
	int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(rn==1){
		d[2]=29;
	}
	int m=1;
	while(day>d[m]){
		day-=d[m];
		m++;
	}
	printf("%d %d ",day,m);
}
void BC(int x){
	if(x<=0){
		printf("%d\n",-1*x+1);
	}
	else{
		printf("%d\n",x);
	}
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	long long Q,a,r;
	cin>>Q;
	for(int i=1;i<=Q;i++){
		scanf("%d",&r);
		a=-4712;
		if(r<=2305447){
			if(r>2299160){
				r+=10;
			}
			a+=(r/1461)*4;
			r%=1461;
			if(r<366){
				sd(r,true);
				BC(a);
			}
			else{
				r-=366;
				a=a+(r/365)+1;
				r%=365;
				sd(r,false);
				BC(a);
			}
		}
		else{
			r-=2305448;
			a=1600;
			a+=(r/146097)*400;
			r%=146097;
			if(r<366){
				sd(r,true);
				BC(a);
			}
			else{
				r--;
				a+=(r/36524)*100;
				r%=36524;
				if(r<365){
					sd(r,false);
					BC(a);
				}
				else{
					r++;
					a+=(r/1461)*4;
					r%=1461;
					if(r<366){
						sd(r,true);
						BC(a);
					}
					else{
						r-=366;
						a=a+(r/365)+1;
						r%=365;
						sd(r,false);
						BC(a);
					}
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//(ke2YI0gong2YU0)
