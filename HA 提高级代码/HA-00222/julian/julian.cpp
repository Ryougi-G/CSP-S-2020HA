#include"cstdio"
#include"iostream"
#include"algorithm"
#include"cstdlib"
#include"cstring"
using namespace std;
int Q;
const int mo[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&Q);
	while(Q--){
		long long Day,Year,Month;
		bool ok=false;
		scanf("%lld",&Day);
		for(long long s=-4713;;s++){
			if(s==0)continue;
			long long tmp;
			if(s<0)tmp=-s-1;
			else tmp=s;
			if(s<1582){
				if(tmp%4==0){
					ok=true;
					if(Day<=366){
						Year=s;
						break;
					}
					else Day-=366;
				}
				else{
					ok=false;
					if(Day<=365){
						Year=s;
						break;
					}
					else Day-=365;
				}
			}
			else if(s==1582){
				ok=false;
				if(tmp<=355){
					Year=s;
					break;
				}
				Day-=355;
			}
			else{
				if(tmp%4==0&&tmp%100!=0||tmp%400==0){
					ok=true;
					if(Day<=366){
						Year=s;
						break;
					}
					else Day-=366;
				}
				else{
					ok=false;
					if(Day<=365){
						Year=s;
						break;
					}
					else Day-=365;
				}
			}
		}
		for(int i=1;i<=12;i++){
			if(i==2&&ok==true){
				if(Day>=29)Day-=29;
				else{
					Month=i;
					break;
				}
			}
			else{
				if(Day>=mo[i])Day-=mo[i];
				else{
					Month=i;
					break;
				}
			}
		}
		if(Year<0){
			printf("%lld %lld %lld BC\n",Day+1,Month,-Year);
		}
		else{
			printf("%lld %lld %lld\n",Day+1,Month,Year);
		}
	}
	return 0;
}
/*
3
10
100
1000
*/
/*
3
2000000
3000000
4000000
*/
