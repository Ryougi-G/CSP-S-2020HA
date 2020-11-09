#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
long long jF=146097,jO=36524,jf=1461;
long long mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
long long pd1;
long long tp;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	long long n,m;
	cin>>n;
	for(long long i=1;i<=n;i++){
		scanf("%d",&m);
		tp=1;
		if(m>2397778){
			m+=12;
			m-=50;
			tp=2;
		}
		a=-4712;b=1;c=1;
		
		if(tp==1){
			pd1=m/(jF+3);
			a+=pd1*400;
			m=m%(jF+3);
			while(1){
				if(a%4==0){
					if(m<366)break;
					else m-=366;
				}
				else {
					if(m<365)break;
					else m-=365;
				}
				a++;
			}
			}
			
			else{
			pd1=m/(jF);
			a+=pd1*400;
			m=m%(jF);
			while(1){
				if((a%4==0&&a%100!=0)||a%400==0){
					if(m<366)break;
					else m-=366;
				}
				else {
					if(m<365)break;
					else m-=365;
				}
				a++;
				}
			}
			mon[2]=28;
			if(tp==2){if((a%4==0&&a%100!=0)||a%400==0)mon[2]=29;}
			else if(a%4==0)mon[2]=29;
			while(1){
				if(m>mon[b]){
					m-=mon[b];b++;
				}
				else break;
		}
		c+=m;
		if(a<=0)a--;
		if(mon[b]<c){c-=mon[b];b++;}
		if(b>12){b-=12;a++;}
		printf("%d %d %d",abs(c),abs(b),abs(a));
		if(a<0)printf(" BC");printf("\n");
		//cout<<m<<endl;
	}
}
