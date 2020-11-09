#include<bits/stdc++.h>
using namespace std;
int q,n,a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
const int bc=1721423,ac=2299160;
//2299149


template<typename type_of_scan>
void scan(type_of_scan &x){
	type_of_scan f=1;char s=getchar();x=0;
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	x*=f;
}
//4713 1582
void work1(){
	int m=n/365,trmonth=1,tryear=0,trday=1,ol=n,mo,op1,op2,flag=0;
	mo=4713-m-1;op1=4712/4-mo/4;op2=n%365;op2-=op1;
	while(op2<0){
		op2=op2+365;mo++;
		if(!(mo%4)) op2++;
	}
	tryear=mo+1;flag=!(mo%4);
	for(int i=0;i<12;i++){
		if(i==1&&flag){
			if(op2<=29){
				trday=op2;
				break;
			}else op2-=29,trmonth++;
		}else {
			if(op2<=a[i]){
				trday=op2;
				break;
			}else op2-=a[i],trmonth++;
		}
	}
	printf("%d %d %d BC\n",trday,trmonth,tryear);
}
void work2(){
	n-=bc;
	int m=n/365,trmonth=1,tryear=0,trday=0,ol=n,mo,op1,op2,flag=0;
	mo=m;op1=m/4;op2=n%365;op2-=op1;
	while(op2<0){
		op2=op2+365;mo--;
		if(!(mo%4)) op2++;
	}
	tryear=mo;flag=!(mo%4);
	for(int i=0;i<12;i++){
		if(i==1&&flag){
			if(op2<=29){
				trday=op2;
				break;
			}else op2-=29,trmonth++;
		}else {
			if(op2<=a[i]){
				trday=op2;
				break;
			}else op2-=a[i],trmonth++;
		}
	}
	printf("%d %d %d\n",trday,trmonth,tryear+1);
}

int calc(int x){
	return (int)x/4-(int)x/100+(int)x/400;
}

void work3(){
	n-=ac;
	int year=0,month=1,day=0,op1,op2;
	if(n<=78) {
		year=1582;
		if(n<=17) month=10,day=n;
		else if(n-17<=30) month=11,day=n-17;
		else month=12,day=n-17-30;
		printf("%d %d %d\n",day,month,year);
		return ;
	}
	year=1583;n-=78;
	int m=1583+n/365,mo;mo=calc(m)-calc(1582);
	op2=(n%365)-mo;year=m;
	while(op2<0){
		op2+=365;year--;
		if(!(year%4)&&((year%100)||!(year%400))) op2++;
	}
	bool flag=(!(year%4))&&((year%100)||!(year%400));
	for(int i=0;i<12;i++){
		if(i==1&&flag){
			if(op2<=29){
				day=op2;
				break;
			}else op2-=29,month++;
		}else {
			if(op2<=a[i]){
				day=op2;
				break;
			}else op2-=a[i],month++;
		}
	}
	printf("%d %d %d\n",day,month,year);
	return ;
};

int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scan(q);
	while(q--){
		scan(n);
		if(n<=bc) work1();
		else if(n<=ac) work2();
		else work3();
	}
	return 0;
}
/*
3
2000000
3000000
4000000

*/
/*
14 9 763
15 8 3501
12 7 6239
*/
/*
3
958153104
543525290
283727928
30 12 2618621
7 8 1483409
31 7 772108
*/
