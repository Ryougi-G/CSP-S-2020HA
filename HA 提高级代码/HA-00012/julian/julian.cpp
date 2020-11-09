#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#define ll long long
#define re register
#define il inline
using namespace std;
il int read(){
	int x=0,f=1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch = getchar();
	}
	return x;
}

int q,r;
int d,m,y;
int md[13]{0,31,28,31,30,31,30,31,31,30,31,30,31};
int fy = 1461;
bool flag = true;

il bool is_run(int x){
	if(x<=1582){
		if(x<0)x++;
		return x%4==0;
	}else {
		if(x%400==0||x%4==0&&x%100!=0)return true;
		else return false;
	}
}

il void print(int d,int m,int y){
	if(y<0)
	printf("%d %d %d BC",d,m,-y);
	else {
		if(y==1582&&m==10&&d>=5&&d<=14){
			d+=10;
			if(d>31){
				d-=30;
				m++;
			}
		}
		printf("%d %d %d",d,m,y);
	}
}

il void calc(int r){
	d=1,m=1,y=-4713;
	if(r>=1721058){
		y=1;
		r-=1721058;
	}if(r>=577095){
		y=1580;
		r-=577095;
	}
	if(r>fy&&y<0){
		y+=4*(r/fy);
		r%=fy;
	}
	
	if(r>fy){
		int tmp = r/fy;
		y+=4*(tmp);
		r%=fy;
		r+=tmp/25;
	}
	if(r==0){
		print(d,m,y);
		return ;
	}
	if(r>=365){
		if(r==365&&is_run(y)){
			print(31,12,y);
		}else while(r>365){
			r-=365+is_run(y);
			y++;
		}
	}
	if(r==0){
		print(d,m,y);
		return ;
	}
	if(r>md[m]){
		while(r>md[m]){
			r-=md[m];
			if(m==2&&is_run(y)){
				r--;
			}
			m++;
		}
	}
	d+=r;
	print(d,m,y);
}

int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q=read();
	while(q--){
		r=read();
		calc(r);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

