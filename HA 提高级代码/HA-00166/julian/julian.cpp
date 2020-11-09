#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
#define ll long long
ll T,n,y,m,d,d2;
const int Y=1461;
int a[30]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){ x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
inline bool cmp(ll x){
	return x%4==0? x%100==0? x%400==0? true:false :true :false;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	T=read();
	while(T--){
		int flag=0,i=1;
		n=read();m=d=1;
		y=(n/Y)*4;d2=n%Y+1;
		y=4713-y;
		if(y<=0) y=-(y-1),flag=1;
		if(y>1582&&flag){
			if(d2>=10){
				if(d2==10){
					d2=0;
					m=1,d=1;
				}
				else d2-=10;
			}
			else{
				y--;m=12;d=31-(10-d2);d2=0;
			}
		}
		while(d2>0){
			if(y==1582&&i==10&&flag) a[10]=21;
			if(i==2){
				if(y>1582&&flag&&cmp(y))
				    a[2]=29;
				else if(y<=1582&&flag&&y%4==0)
					a[2]=29;
				else if(!flag&&(y-1)%4==0)
					a[2]=29;
			}
			if(d2<=a[i]){
				if(d2==a[i]) m=i+1,d=1;
				else{
				    m=i,d=d2;
					if(y==1582&&i==10&&flag){
					    if(d2<=4) d=d2;
					    else d=(d2-4)+14;
					}
				} a[2]=28,a[10]=31;
				if(m==13){
					if(flag) y++;
					else y--;
					if(y<=0) y=-(y-1),flag=1;
					m=1;
				}
				break;
			}
			d2-=a[i++];
			if(i==13){
				if(flag) y++;
				else y--;
				if(y<=0) y=-(y-1),flag=1;
				i=1;
			}
			a[2]=28;
			if(y==1582) a[10]=31;
		}
		cout<<d<<' '<<m<<' '<<y;
		if(!flag) cout<<" BC";
		cout<<endl;
	}
	return 0;
}
