#include<bits/stdc++.h>
using namespace std;
inline int SQHread(){
	int fh=1,dx=0;
	char ch;
	ch=getchar();	
	while(ch<'0'||ch>'9'){
		if(ch=='-')	fh=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		dx=dx*10+ch-'0';
		ch=getchar();
	}
	return dx*fh;
}
int yea,month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int n,day,sqh;
bool runnian(int ye){
	int bc=ye<0?1:0;
	if(ye>=1583&&ye%100==0){
		if(ye%400==0)	return 1;
		else return 0;		
	}
	return abs((ye+bc))%4==0?1:0;
}
int countMonth(){
	if(runnian(yea))	month[2]=29;
	int mon;
	for(mon=1;mon<=12;++mon){
		if(sqh<=month[mon])	break;
		sqh-=month[mon];
	}
	month[2]=28;
	return mon;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	n=SQHread();
	for(int xh=1;xh<=n;++xh){
		day=SQHread();
		if(day<1721058){
			if(day<=365){
				yea=-4713;
				sqh=day+1;
			}
			else{
				yea=-4713+(((day-366)/1461)*4+((day-366)%1461)/365)+1;
				sqh=((day-366)%1461)%365+1;
			}
			
			int ansy=yea,ansm=countMonth();
			int ansd=sqh;
			printf("%d %d %d BC\n",ansd,ansm,-ansy);
		}
		else{
			day-=1721058;
			if(day<=1095){
				yea=day/365;
				sqh=day%365+1; 
			}
			else{
				if(day>=2299245-1721058)	{
					day+=10;
				}
				yea=(day-1095)/1461*4+(day-1095)%1461/365+3;
				sqh=(day-1095)%1461%365;
				if(day>=2299245-1721058)sqh=sqh+(yea-1500)/100-(yea-1500)/400-1;
			}
			int ansy=yea,ansm=countMonth();
			int ansd=sqh;
			printf("%d %d %d \n",ansd,ansm,ansy);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
