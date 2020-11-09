#include<bits/stdc++.h>
using namespace std;
bool c;
int sy1date,sy2date;//1存年后剩，2存月后剩 
int bc(int a,int b){
	int ans=0;
	if(b==a)return 0;
	for(int i=a;i>=b+1;i--){
		int g=i-1;
		if(g%4==0){
			if(g%100==0&&g%400!=0){
				ans+=365;
			}
			else{
				ans+=366;
			}
		}
		else{
			ans+=365;
		}
	}
	return ans;
}
int ac(int a){
	long long ans=1721023;
	if(a>400||a==400){
		ans+=(a/400)*146097;
		a=a%400;
		if(a>100||a==100){
			ans+=(a/100)*36524;
			a=a%100;
			if(a>4||a==4){
				ans+=(a/4)*1461;
				a=a%4;
				ans+=a*365;
			}
			else{
				ans+=a*365;
			}
		}
		else{
			if(a>4||a==4){
				ans+=(a/4)*1461;
				a=a%4;
				ans+=a*365;
			}
			else{
				ans+=a*365;
			}
		}
	}
	
	else{
		if(a>100||a==100){
			ans+=(a/100)*36524;
			a=a%100;
			if(a>4||a==4){
				ans+=(a/4)*1461;
				a=a%4;
				ans+=a*365;
			}
			else{
				ans+=a*365;
			}
		}
		else{
			if(a>4||a==4){
				ans+=(a/4)*1461;
				a=a%4;
				ans+=a*365;
			}
			else{
				ans+=a*365;
			}
		}
	}
	return ans;
}
int cal(int n){//400年内多少年 
	int ye=0;
	if(n==0){
		return 0;	
	}
	else if(n>36534||n==36524)
	{
		ye=(n/36524)*100;
		n=n%36524;
		if(n==1461||n>1461){
			ye+=(n/1461)*4;
			n=n%1461;
			ye+=n/365;
		}
		else{
			ye+=n/365;
		}
	}
	else{
		if(n==1461||n>1461){
			ye+=(n/1461)*4;
			n=n%1461;
			ye+=n/365;
		}
		else{
			ye+=n/365;
		}
	}
	return ye;
}
long long nian(long long n){
	long long ans=4713;
	long long cur=0;
	if(n<366){
		c=true;
		return ans;
	}
	else{
		n-=366;
		ans--;
		if(n>146097||n==146097){
			cur=(n/146097)*400;//cur过了多少年 
			n=n%146097;
			cur+=cal(n);
		}
		else{
			cur+=cal(n);
		}
	}
	if(cur<4712){
		c=true;
		return(ans-cur);
	}
	else{
		return (cur+1-ans);
	}
}
int yu(int n,int p){
	int ans=0;
	if(p==1){
		if(n<=31){
			ans=1;
		}
		if(n<=60&&n>31){
			ans=2;
		}
		if(n<=91&&n>60){
			ans=3;
		}
		if(n<=121&&n>91){
			ans=4;
		}
		if(n<=152&&n>121){
			ans=5;
		}
		if(n<=182&&n>152){
			ans=6;
		}
		if(n<=213&&n>182){
			ans=7;
		}
		if(n<=244&&n>213){
			ans=8;
		}
		if(n<=274&&n>244){
			ans=9;
		}
		if(n<=305&&n>274){
			ans=10;
		}
		if(n<=335&&n>305){
			ans=11;
		}
		if(n<=366&&n>335){
			ans=12;
		}
	}
	else{
		if(n<=31){
			ans=1;
		}
		if(n<=59&&n>31){
			ans=2;
		}
		if(n<=90&&n>59){
			ans=3;
		}
		if(n<=120&&n>90){
			ans=4;
		}
		if(n<=151&&n>120){
			ans=5;
		}
		if(n<=181&&n>151){
			ans=6;
		}
		if(n<=212&&n>181){
			ans=7;
		}
		if(n<=243&&n>212){
			ans=8;
		}
		if(n<=273&&n>243){
			ans=9;
		}
		if(n<=304&&n>273){
			ans=10;
		}
		if(n<=334&&n>304){
			ans=11;
		}
		if(n<=365&&n>334){
			ans=12;
		}
	}
	return ans;
}
int ri(int n,int p){
	int ans=0;
	if(p==1){
		if(n<=31){
			ans=n;
		}
		if(n<=60&&n>31){
			ans=n-31;
		}
		if(n<=91&&n>60){
			ans=n-60;
		}
		if(n<=121&&n>91){
			ans=n-91;
		}
		if(n<=152&&n>121){
			ans=n-121;
		}
		if(n<=182&&n>152){
			ans=n-152;
		}
		if(n<=213&&n>182){
			ans=n-182;
		}
		if(n<=244&&n>213){
			ans=n-213;
		}
		if(n<=274&&n>244){
			ans=n-244;
		}
		if(n<=305&&n>274){
			ans=n-274;
		}
		if(n<=335&&n>305){
			ans=n-305;
		}
		if(n<=366&&n>335){
			ans=n-335;
		}
	}
	else{
		if(n<=31){
			ans=n;
		}
		if(n<=59&&n>31){
			ans=n-31;
		}
		if(n<=90&&n>59){
			ans=n-59;
		}
		if(n<=120&&n>90){
			ans=n-90;
		}
		if(n<=151&&n>120){
			ans=n-120;
		}
		if(n<=181&&n>151){
			ans=n-151;
		}
		if(n<=212&&n>181){
			ans=n-181;
		}
		if(n<=243&&n>212){
			ans=n-212;
		}
		if(n<=273&&n>243){
			ans=n-243;
		}
		if(n<=304&&n>273){
			ans=n-273;
		}
		if(n<=334&&n>304){
			ans=n-304;
		}
		if(n<=365&&n>334){
			ans=n-334;
		}
	}
	return ans;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		int b=0;//b=1闰 
		int sy1date=0,sy2date=0;
		c=false;
		long long r;
		cin>>r;
		if(r<=594525){
			sy1date=r-bc(4713,nian(r))+1;
			if((nian(r)-1)%4==0){
			if((nian(r)-1)%100==0&&(nian(r)-1)%400!=0){
				b=0;
			}
			else{
				b=1;
			}
		}
			cout<<ri(sy1date,b)<<' ';
		cout<<yu(sy1date,b)<<' ';
		cout<<nian(r)<<' ';
	
			cout<<"BC"<<endl;
			
		
		}
		else{
			if(r<=1721389)c=true;
			b=0;
			r-=41;
		if(nian(r)%4==0){
			if(nian(r)%100==0&&nian(r)%400!=0){
				b=0;
			}
			else{
				b=1;
			}
		}
		if(c){
			sy1date=r-bc(4713,nian(r))+1;
		}
		else{
			sy1date=r-ac(nian(r)); 
		}
		
		
		
		cout<<ri(sy1date,b)<<' ';
		cout<<yu(sy1date,b)<<' ';
		cout<<nian(r)<<' ';
		
			cout<<endl;
		
		}
	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
   
		

