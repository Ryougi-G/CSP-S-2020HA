#include <bits/stdc++.h>
#define ll long long
#define maxn 101000
using namespace std;

ll julianday;
int a[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int b[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int years,months,days;
struct node{
	int day;
	int month;
	int year;
}ans[maxn];

void calc(ll n){
	years=-4712,months=12,days=31;
	n--;
	int flag=1,times=3;
	while(n-365>=0){
		if(flag){
			n-=365;
			times++;
			if(times==4){
				flag=0;
				times=1;
			}
		}
		else {
			if(n>=366) n-=366,years++,flag=1;
			else break;
		}
	}
	int tmp;
	for(int i=12;;i--){
		if(i<=0) i=12;
		if(flag){
			tmp=a[i];
			if(n>=a[i]){
				n-=a[i],months--;
				if(months==0){
					months=12,years++;
					if(years%4) flag=0;
				} 
			} 
		    else break;
		}
		     
		else{
			tmp=b[i];
			if(n>=b[i]){
				n-=b[i],i++,months--;
				if(months==0){
					months=12,years++;
					if(!abs(years)%4) flag=1;
				} 
			} 
			else break;
		}     
	}
	if(n) days=n;
	else{
		months++;
		if(months==13){
			months=1;
			years--;
		}
		days=tmp;
	}
}

int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int Q,i=0;
	cin>>Q;
	while(Q--){
		int flag=0;
		cin>>julianday;
		i++;
		calc(julianday);
		if(years<0) {
			years=-years;
			flag=1;
		}
        
		cout<<days<<" "<<months<<" "<<years<<" ";
		if(flag) cout<<"BC";
		cout<<endl;
	}
	return 0;
}

