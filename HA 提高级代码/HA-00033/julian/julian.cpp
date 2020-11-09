#include<bits/stdc++.h>
using namespace std;
int q;
long long r[100001]={0};
bool rn(int num){
	if(num>=1){
		if(num%400==0||(num%4==0&&num%100!=0)){
			return true;
		}
	    return false;
	}else if(num<=-1){
		if(num%4==1){
			return true;
		}
		return false;
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int day,month;
	long long year;
    cin>>q;
    for(int i=0;i<q;i++){
    	cin>>r[i];
    	while
	}
	return 0;
}
