#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int qr(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int as[100005],y[100005],d[100005],m[100005],pd[100005];
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int Q = qr();
	for(int i = 1;i <= Q; ++i){
		as[i]=qr();
	}
	for(int i = 1;i <= Q; ++i){
		if(as[i] <= 1721424){
			int x  = as[i] / 1461;
			int xa = as[i] % 1461 + 1;
			if(xa > 366){
				xa -= 366;
				y[i] =4713 - x*4 - 1 - xa / 365;
				xa %= 365;
				if(xa == 0){ m[i] = 12; d[i] = 30;y[i] += 1;}
				else if(xa > 0&&xa <= 31){		m[i]=1;	d[i]=xa;}
				else if(xa > 31&&xa <=59){	m[i]=2; d[i]=xa-31;}
				else if(xa > 59&&xa <=90){	m[i]=3;	d[i]=xa-59;}
				else if(xa > 90&&xa <=120){	m[i]=4;	d[i]=xa-90;}
				else if(xa > 120&&xa <=151){m[i]=5;	d[i]=xa-120;}
				else if(xa > 151&&xa <=181){m[i]=6;	d[i]=xa-151;}
				else if(xa > 181&&xa <=212){m[i]=7;	d[i]=xa-181;}
				else if(xa > 212&&xa <=243){m[i]=8;	d[i]=xa-212;}
				else if(xa > 243&&xa <=273){m[i]=9;	d[i]=xa-243;}
				else if(xa > 273&&xa <=304){m[i]=10;d[i]=xa-273;}
				else if(xa > 304&&xa <=334){m[i]=11;d[i]=xa-304;}
				else if(xa > 334&&xa <=365){m[i]=12;d[i]=xa-334;}
				pd[i]=0;
			}
			else{
				y[i] =4713 - x*4 - 1;
				if(xa == 0){ m[i] = 12; d[i] = 30;y[i] += 1;}
				else if(xa > 0&&xa <= 31){	m[i]=1;	d[i]=xa;}
				else if(xa > 31&&xa <=60){	m[i]=2; d[i]=xa-31;}
				else if(xa > 60&&xa <=91){	m[i]=3;	d[i]=xa-60;}
				else if(xa > 91&&xa <=121){	m[i]=4;	d[i]=xa-91;}
				else if(xa > 121&&xa <=152){m[i]=5;	d[i]=xa-121;}
				else if(xa > 152&&xa <=182){m[i]=6;	d[i]=xa-152;}
				else if(xa > 182&&xa <=213){m[i]=7;	d[i]=xa-182;}
				else if(xa > 213&&xa <=244){m[i]=8;	d[i]=xa-213;}
				else if(xa > 244&&xa <=274){m[i]=9;	d[i]=xa-244;}
				else if(xa > 274&&xa <=305){m[i]=10;d[i]=xa-274;}
				else if(xa > 305&&xa <=335){m[i]=11;d[i]=xa-305;}
				else if(xa > 335&&xa <=366){m[i]=12;d[i]=xa-335;}
				pd[i]=0;
			}
		}
		else{
			if(as[i] > 2299161){
				as[i] += 10;
				as[i] += (as[i]-2299161)/36524;
			}
			int x  = as[i] / 1461 ;
			int xa = as[i] % 1461 + 1;
			if(xa > 366){
				xa -= 366;
				y[i] =x*4 + 1 + xa / 365 - 4712;
				xa %= 365;
				if(xa == 0){ m[i] = 12; d[i] = 30;y[i] += 1;}
				else if(xa > 0&&xa <= 31){		m[i]=1;	d[i]=xa;}
				else if(xa > 31&&xa <=59){	m[i]=2; d[i]=xa-31;}
				else if(xa > 59&&xa <=90){	m[i]=3;	d[i]=xa-59;}
				else if(xa > 90&&xa <=120){	m[i]=4;	d[i]=xa-90;}
				else if(xa > 120&&xa <=151){m[i]=5;	d[i]=xa-120;}
				else if(xa > 151&&xa <=181){m[i]=6;	d[i]=xa-151;}
				else if(xa > 181&&xa <=212){m[i]=7;	d[i]=xa-181;}
				else if(xa > 212&&xa <=243){m[i]=8;	d[i]=xa-212;}
				else if(xa > 243&&xa <=273){m[i]=9;	d[i]=xa-243;}
				else if(xa > 273&&xa <=304){m[i]=10;d[i]=xa-273;}
				else if(xa > 304&&xa <=334){m[i]=11;d[i]=xa-304;}
				else if(xa > 334&&xa <=365){m[i]=12;d[i]=xa-334;}
				pd[i]=1;
			}
			else{
				y[i] =x*4 - 4711;
				if(xa == 0){ m[i] = 12; d[i] = 30;y[i] += 1;}
				else if(xa > 0&&xa <= 31){	m[i]=1;	d[i]=xa;}
				else if(xa > 31&&xa <=60){	m[i]=2; d[i]=xa-31;}
				else if(xa > 60&&xa <=91){	m[i]=3;	d[i]=xa-60;}
				else if(xa > 91&&xa <=121){	m[i]=4;	d[i]=xa-91;}
				else if(xa > 121&&xa <=152){m[i]=5;	d[i]=xa-121;}
				else if(xa > 152&&xa <=182){m[i]=6;	d[i]=xa-152;}
				else if(xa > 182&&xa <=213){m[i]=7;	d[i]=xa-182;}
				else if(xa > 213&&xa <=244){m[i]=8;	d[i]=xa-213;}
				else if(xa > 244&&xa <=274){m[i]=9;	d[i]=xa-244;}
				else if(xa > 274&&xa <=305){m[i]=10;d[i]=xa-274;}
				else if(xa > 305&&xa <=335){m[i]=11;d[i]=xa-305;}
				else if(xa > 335&&xa <=366){m[i]=12;d[i]=xa-335;}
				pd[i]=1;
			}
		}
	}
	for(int i = 1;i <= Q;++i){
		printf("%d %d %d",d[i],m[i],y[i]);
		if(!pd[i])printf(" BC\n");
		else printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
