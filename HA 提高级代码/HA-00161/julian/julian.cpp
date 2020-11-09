#include<bits/stdc++.h>

using namespace std;

#define ll long long

int Q;

ll n,moth1[20],moth2[20],year,fouryear,fenjie,ansyear,ansmoth,ansday;//moth为月份天数前缀和 

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>Q;
	ansyear=-4712;//最后如果是负的或0要减一输出 
	year=365;
	fouryear=4*365+1;
	for(int i=1;i<=12;i++){
		moth1[i]=moth1[i-1];
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12) moth1[i]+=31;
		else if(i==2) moth1[i]+=28;
		else moth1[i]+=30;
		moth2[i]=moth2[i-1];
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12) moth2[i]+=31;
		else if(i==2) moth2[i]+=29;
		else moth2[i]+=30;
	}
	fenjie=((4712+1581)/4+1)+(4713+1581)*365+moth1[9]+4;//日历变为格里高力历 
	while(Q--){
		scanf("%lld",&n);
		n++;
		ansyear=-4712;
		if(n<=fenjie){//单纯使用儒略历 
			if(n<=366){
				ansyear=-4712;
				ansmoth=lower_bound(moth2+1,moth2+1+12,n)-moth2;
				ansday=n-moth2[ansmoth-1];
			}
			else {
				n-=366;
				ansyear=-4711;
				ansyear+=(n/fouryear)*4;
				n%=fouryear;
				if(n==0){
					ansyear--;
					ansmoth=12;
					ansday=31;
				}else {
					int t=0;
					t=n/year;
					if(t<=2||(n%year==0&&t==3)){
						n=n%year;
						if(n==0){
							ansyear+=(t-1);
							ansmoth=12;
							ansday=31;
						} 
						else {
							ansyear+=t;
							ansmoth=lower_bound(moth1+1,moth1+1+12,n)-moth1;
							ansday=n-moth1[ansmoth-1];
						}
					} 
					else {
						ansyear+=3;
						n-=(year*3);
						ansmoth=lower_bound(moth2+1,moth2+12+1,n)-moth2;
						ansday=n-moth2[ansmoth-1];
					}
				}
				
			}
		} 
		else{//混用 
			
		}
		printf("%lld ",ansday);
		printf("%lld ",ansmoth);
		if(ansyear<=0) printf("%lld BC\n",(ansyear-1)*(-1));
		else printf("%lld\n",ansyear); 
	}
	return 0;
}
