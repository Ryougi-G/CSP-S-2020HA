#include<bits/stdc++.h>
#define Y1 365
#define Y2 366
using namespace std;
int T,a[15],b[15];
long long n;
void month1(int y,int d,int pd){
	/*
	if(d<=31){
		cout<<d+1<<" "<<"1"<<" "<<y<<" "<<"BC"<<'\n';
		return ;
	}
	*/
	if(pd==1){
		for(int i=1;i<=12;i++){
			if(d<=a[i]){
				cout<<d+1<<" "<<i<<" "<<y<<" "<<"BC"<<'\n';
				return ;
			}
			d-=a[i];
		}
	}
	else{
		for(int i=1;i<=12;i++){
			if(d<=b[i]){
				cout<<d+1<<" "<<i<<" "<<y<<" "<<"BC"<<'\n';
				return ;
			}
			d-=b[i];
		}
	}
}
void month2(int y,int d,int pd){
	/*
	if(d<=31){
		cout<<d+1<<" "<<"1"<<" "<<y<<" "<<"BC"<<'\n';
		return ;
	}
	*/
	if(pd==1){
		for(int i=1;i<=12;i++){
			if(d<=a[i]){
				cout<<d<<" "<<i<<" "<<y<<'\n';
				return ;
			}
			d-=a[i];
		}
	}
	else{
		for(int i=1;i<=12;i++){
			if(d<=b[i]){
				cout<<d<<" "<<i<<" "<<y<<'\n';
				return ;
			}
			d-=b[i];
		}
	}
}
long long ans[30];
long long dui[30];
void work(){
	scanf("%lld",&n);
	long long ANS=n;
	int p=0;
	ans[1]=732206059;dui[1]=2000000;
	ans[2]=366963559;dui[2]=1000000;
	ans[3]=184342309;dui[3]=500000;
	for(int i=1;i<=3;i++){
		if(n>ans[i]){
			ANS=ans[i];p=i;break;
		}
	}
	if(p){
		n-=ANS;
		for(int i=dui[p];i<=10000000;i++){
			if( (i%400==0) || ((i%4==0)&&(i%100!=0)) ){
				n-=Y2;
			}
			else n-=Y1;
	//		if(i==100000)
	//			cout<<ans-n<<'\n';
			if(i==1582 && n>=4) n+=4;
			if(n>Y2) continue;
			if(( ((i+1)%400==0) || (((i+1)%4==0)&&((i+1)%100!=0)) ) && n<Y2){
				month2(i+1,n,0);return ;
			}
			if(( ((i+1)%400!=0) && (((i+1)%4!=0)||((i+1)%100==0)) ) && n<Y1){
				month2(i+1,n,1);return ;
			}
			if(( ((i+1)%400==0) || (((i+1)%4==0)&&((i+1)%100!=0)) ) && n==Y2){
				cout<<"1"<<" "<<"1"<<" "<<i+1<<'\n';
				return ;
			}
			if(( ((i+1)%400!=0) && (((i+1)%4!=0)||((i+1)%100==0)) ) && n==Y1){
				cout<<"1"<<" "<<"1"<<" "<<i+1<<'\n';
				return ;
			}
	//		cout<<n<<'\n';
		}
	}
	if(n<365){
		month1(4713,n,0);return ;
	}
	for(int i=4713;i>=1;i--){
		if((i-1)%4==0) n-=Y2;
		else n-=Y1;
		if(n>Y2) continue;
		if((i-2)%4==0 && n<Y2){
			month1(i-1,n,0);return ;
		}
		if((i-2)%4!=0 && n<Y1){
			month1(i-1,n,1);return ;
		}
		if((i-2)%4==0 && n==Y2){
			cout<<"1"<<" "<<"1"<<" "<<i-1<<" "<<"BC"<<'\n';
			return ;
		}
		if((i-2)%4!=0 && n==Y1){
			cout<<"1"<<" "<<"1"<<" "<<i-1<<" "<<"BC"<<'\n';
			return ;
		}
	}
	n-=5;
	for(int i=1;i<=10000000;i++){
//		if(i==500000)
//			cout<<ANS-n<<'\n';
		if( (i%400==0) || ((i%4==0)&&(i%100!=0)) ){
			n-=Y2;
		}
		else n-=Y1;
		if(i==1582 && n>=4) n+=4;
		if(n>Y2) continue;
		if(( ((i+1)%400==0) || (((i+1)%4==0)&&((i+1)%100!=0)) ) && n<Y2){
			month2(i+1,n,0);return ;
		}
		if(( ((i+1)%400!=0) && (((i+1)%4!=0)||((i+1)%100==0)) ) && n<Y1){
			month2(i+1,n,1);return ;
		}
		if(( ((i+1)%400==0) || (((i+1)%4==0)&&((i+1)%100!=0)) ) && n==Y2){
			cout<<"1"<<" "<<"1"<<" "<<i+1<<'\n';
			return ;
		}
		if(( ((i+1)%400!=0) && (((i+1)%4!=0)||((i+1)%100==0)) ) && n==Y1){
			cout<<"1"<<" "<<"1"<<" "<<i+1<<'\n';
			return ;
		}
//		cout<<n<<'\n';
	}
}
int main()
{
	freopen("julian3.in","r",stdin);
	freopen("julian3.out","w",stdout);
	a[1]=b[1]=31,a[2]=28,b[2]=29,a[3]=b[3]=31,a[4]=b[4]=30;
	a[5]=b[5]=31,a[6]=b[6]=30,a[7]=b[7]=31;
	a[8]=b[8]=31,a[9]=b[9]=30,a[10]=b[10]=31;
	a[11]=b[11]=30,a[12]=b[12]=31;
	scanf("%d",&T);
	while(T--) work();
}
/*
4713 1 1
*/
/*
3
10
100
1000
-------------------------
3
2000000
3000000
4000000
*/
