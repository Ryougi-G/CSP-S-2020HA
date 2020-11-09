#include <bits/stdc++.h>
using namespace std;
int q;
long long r;
int y,m,d;
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int dayr[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
long long rd(){
	long long f=1,x=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return f*x;
}
void work(){
	m=1;
	if(r>365){//burun
		r=(r-1)%365;
		while(r>=days[m]){
			r-=days[m];
			m++;
		}
		d=r+1;
	}
	else{//run
		while(r>=dayr[m]){
			r-=dayr[m];
			m++;
		}
		d=r+1;
	}
	return;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q=rd();
	while(q--){
		y=d=m=0;
		r=rd();
		if(r<=2299160){
			y=(r/1461)*4+(r%1461-1)/365;
			r%=1461;
			m=1;
			work();
			if(y<4713)
				printf("%d %d %d BC\n",d,m,4713-y);
			else
				printf("%d %d %d\n",d,m,y-4712);
			continue;
		}
		else{
			r-=1721060;//1 1 0
			y=(r/146097)*400+((r%146097-1)/36524)*100;
			r=r%146097;
			if(r>36524){//burun
				r=(r-1)%36524;
				if(r>=1460){//run
					y+=((r+1)/1461)*4+((r+1)%1461-1)/365;
					r=(r+1)%1461;
					work();
					printf("%d %d %d\n",d,m,y);
					continue;
				}
				else{//burun
					y+=r/365;
					r%=365;
					m=1;
					while(r>=days[m]){
						r-=days[m];
						m++;
					}
					d=r+1;
					printf("%d %d %d\n",d,m,y);
					continue;
				}
			}
			else{
				y+=r/1461*4+(r%1461-1)/365;
				r%=1461;
				m=1;
				work();
				printf("%d %d %d\n",d,m,y);
				continue;
			}
		}
	}
	return 0;
}
