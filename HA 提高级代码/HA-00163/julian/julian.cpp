#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline void wread(ll &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();
}
ll T,n,a,b,c;
int main(){
	freopen("julian.in","r",stdin);freopen("julian.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		wread(n);n++;
		if(n<=1721424){
			ll k;c=4713;b=1;
			if(n<=366) k=29;
			else{n-=366;c--;
				if(n>=0&&n%1461==0) c++;
				c-=(n/1461)*4;
				n%=1461;
				k=(n>1095?29:28);
				while(n>365) {n-=365;c--;}
			}
			if(n==0){a=31;b=12;
				printf("%lld %lld %lld",a,b,c);printf(" BC\n");
				continue;
			}
			if(n>31){n-=31;b++;//1-2
				if(n>k){n-=k;b++;//3
				if(n>31){n-=31;b++;//4
				if(n>30){n-=30;b++;//5
				if(n>31){n-=31;b++;//6
				if(n>30){n-=30;b++;//7
				if(n>31){n-=31;b++;//8
				if(n>31){n-=31;b++;//9
				if(n>30){n-=30;b++;//10
				if(n>31){n-=31;b++;//11
				if(n>30){n-=30;b++;//12
				}}}}}}}}}}}
			a=n;
			printf("%lld %lld %lld",a,b,c);
			printf(" BC\n");
		}
		else{
			n-=1721424;
			if(n>577737){
				n+=12;n-=14;
				b=1;c=0;
				c+=(n/146097)*400;
				n%=146097;
				if(n==0){a=31;b=12;
				printf("%lld %lld %lld\n",a,b,c);continue;
				}
				c+=(n/36524)*100;
				n%=36524;
				if(n==0){a=31;b=12;
				printf("%lld %lld %lld\n",a,b,c);continue;
				}
				c+=(n/1461)*4;
				n%=1461;
				if(n==0){a=31;b=12;
				printf("%lld %lld %lld\n",a,b,c);continue;
				}
				c++;int k=n>1095?29:28;//
				while(n>365) {n-=365;c++;}
				if(n==0){
					printf("31 12 %lld\n",c);
					continue;
				}
				if(n>31){n-=31;b++;//1-2
				if(n>k){n-=k;b++;//3
				if(n>31){n-=31;b++;//4
				if(n>30){n-=30;b++;//5
				if(n>31){n-=31;b++;//6
				if(n>30){n-=30;b++;//7
				if(n>31){n-=31;b++;//8
				if(n>31){n-=31;b++;//9
				if(n>30){n-=30;b++;//10
				if(n>31){n-=31;b++;//11
				if(n>30){n-=30;b++;//12
				}}}}}}}}}}}
				a=n;
				printf("%lld %lld %lld\n",a,b,c);
				}
			else{
				b=1;
				c=n/1461;c*=4;c++;
				n%=1461;
				int k=n>1095?29:28;
				while(n>365) {n-=365;c++;}
				if(n==0){
					printf("31 12 %lld\n",c);
					continue;
				}
				if(n>31){n-=31;b++;//1-2
				if(n>k){n-=k;b++;//3
				if(n>31){n-=31;b++;//4
				if(n>30){n-=30;b++;//5
				if(n>31){n-=31;b++;//6
				if(n>30){n-=30;b++;//7
				if(n>31){n-=31;b++;//8
				if(n>31){n-=31;b++;//9
				if(n>30){n-=30;b++;//10
				if(n>31){n-=31;b++;//11
				if(n>30){n-=30;b++;//12
				}}}}}}}}}}}
				a=n;
				printf("%lld %lld %lld\n",a,b,c);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
