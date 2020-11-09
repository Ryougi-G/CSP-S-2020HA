#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r,q,year,day,month;
ll m1[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
ll m2[13]={0,31,60,91,121,152,182,213,244,274,305,335,366};
#define fo(i,a,b) for(register int i=a;i<=b;i++)
inline ll read(){
	bool f=0;char c=getchar();ll x=0;
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f==1?-x:x;
}
bool judge_bc(ll r){
	if(r>=1721426) return false;
	return true;
}
void get(ll r,bool f,ll &month, ll &day){
	if(f){
		for(int i=11;i>=0;i--)
		if(m2[i]<=r){
			month=i+1;
			day=r-m2[i]+1;
			break;
		}
	}
	else{
		for(int i=11;i>=0;i--)
		if(m1[i]<=r){
			month=i+1;
			day=r-m1[i]+1;
			break;
		}
	}
}
bool judge_run(ll &r,ll &year){
	while(r>=365*3+366){
		r-=365*3+366;
		year+=4;
	//	if(year%100==0) r++;
	}
	if(r>=366||r==0)
		if(r!=0){
		year+=1+(r-366)/365;
		r-=366;
		r%=365;
	}
	if(year%4==0&&year%100!=0||year%400==0) return true;
	return false;
////	cout<<r<<endl;
//	if(r>365*3||r==0){
//	if(r!=0){
//	year+=4;	
//	r-=365*3;
//}
//	return true;
//}
//	else{
//		year+=r/365;
//		r%=365;
//		return false;
//	}
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q=read();
	while(q--){
		r=read();
		bool f1=judge_bc(r);
		if(r<=2529110){
			if(r<1721424){
				year=r/(365*3+366)*4;
				r%=365*3+366;
				bool f2;
				if(r>=366){
					year+=1+(r-366)/365;
					r-=366;
					r%=365;
					f2=true;
				}
				else f2=false;
				year=4713-year;
				get(r,f2,month,day);
				printf("%lld %lld %lld BC\n",day,month,year);
			}
			else{
				r-=1721424;
				year=r/(365*3+366)*4;
				r%=(366+365*3);
				bool f2=false;
				if(r>365*3||r==0){
					f2=true;
					if(r!=0){
					year+=4;
					r-=365*3;
				}
				}
				else year+=(r/365),r%=365;
				year++;
				get(r,f2,month,day);
				printf("%lld %lld %lld\n",day,month,year);
			}
		}
		else{
			r-=1721424;
			r-=(577095-366);
			year=1580;
			r+=12;
			year+=(r/(97*366+303*365)*400);
			r%=(97*366+303*365);
			bool f2=judge_run(r,year);
			get(r,f2,month,day);
			printf("%lld %lld %lld\n",day,month,year);
		}
	}
	return 0;
}
