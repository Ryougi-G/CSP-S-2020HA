#include <bits/stdc++.h>
using namespace std;
int T,a,ans1,ans2,ans3;
int Month[13]={0,31, 0,31,30, 31, 30, 31, 31, 30, 31, 30, 31};
int Month2[2][13]={{-1,31,59,90,120,151,181,212,243,273,304,334,365},
                   {-1,31,60,91,121,152,182,213,244,274,305,335,366}};
/*bool pan1(int x){
	if(x%4==0) return true;
	else return false;
}*/
/*bool pan2(int x){
	if(x%400==0||(x%4==0&&x%100!=0)) return true;
	else return false;
}*/
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&a);
		ans1=ans2=ans3=0;
		if(a<=2299161){
			if(a<=1721424){
				while(a>1461){ans1=a/1461*4;a%=1461;}
				int k,temp=0;
				if(a>365){ans1+=a/365;a%=365;}
				if(a>365){ans1+=a/365;a%=365;}
				if(a>366){ans1+=a/366;a%=366;temp=1;}
			//cout<<ans1<<' '<<a<<endl;
				if(temp){
					cout<<0<<endl;
					for(k=1;k<=12;k++){
						if(a<=Month2[1][k]) break;
					}
					ans2=k;
					ans3=a-Month2[1][k-1];
				}
				else{
					for(k=1;k<=12;k++){
						if(a<=Month2[0][k]) break;
					}
					ans2=k;
					ans3=a-Month2[0][k-1];
				}
				printf("%d %d %d BC\n",ans3,ans2,4713-ans1);
			}
			else{
				a-=1721424;
				while(a>1461){ans1=a/1461*4;a%=1461;}
				int k,temp=1;
				if(a>365){ans1+=a/365;a%=365;temp=0;}
				if(a>365){ans1+=a/365;a%=365;temp=0;}
				if(a>365){ans1+=a/365;a%=365;temp=0;}
			//cout<<ans1<<' '<<a<<endl;
				if(temp){
					for(k=1;k<=12;k++){
						if(a<=Month2[1][k]) break;
					}
					ans2=k;
					ans3=a-Month2[1][k-1];
				}
				else{
					for(k=1;k<=12;k++){
						if(a<=Month2[0][k]) break;
					}
					ans2=k;
					ans3=a-Month2[0][k-1];
				}
				printf("%d %d %d \n",ans3,ans2,ans1+1);
			}
		}
		else{
			a-=2299161;
			if(a<=78){
				if(a-17<=0) printf("%d %d %d\n",a,10,1582);
				else if(a-17-30<=0) printf("%d %d %d\n",a-17,11,1582);
				else printf("%d %d %d\n",a-47,12,1582);
			}
			else{
				while(a>146097){ans1=a/146097*400;a%=146097;}
				if(a>36524){ans1+=a/36524*100;a%=36524;}
				if(a>36524){ans1+=a/36524*100;a%=36524;}
				if(a>36524){ans1+=a/36524*100;a%=36524;}
				while(a>1461){ans1+=a/1461*4;a%=1461;}
				int k,temp=0;
				if(a>365){ans1+=a/365;a%=365;}
				if(a>366){ans1+=a/366;a%=366;temp=1;}
				if(a>365){ans1+=a/365;a%=365;}
			//cout<<ans1<<' '<<a<<endl;
				if(temp){
			//cout<<0<<endl;
					for(k=1;k<=12;k++){
						if(a<=Month2[1][k]) break;
					}
					ans2=k;
					ans3=a-Month2[1][k-1];
				}
				else{
					for(k=1;k<=12;k++){
						if(a<=Month2[0][k]) break;
					}
					ans2=k;
					ans3=a-Month2[0][k-1];
				}
				printf("%d %d %d\n",ans3,ans2,ans1+1582);
				
			}
		}
	}
	return 0;
}

