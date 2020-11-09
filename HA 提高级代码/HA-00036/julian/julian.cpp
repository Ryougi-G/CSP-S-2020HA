#include<bits/stdc++.h>
using namespace std;
int n;
int b1,b2,b3,b4;//b1 4定定方 b2 噫方 b3 埖方 b4 晩方 
void fb(int a){
	b1=a/1461;a%=1461;
	if(a>=366){
	b2++;a-=366;b2+=a/365;a%=365;
	if(a<31){b3=1;b4=a+1;return;}
	if(31<=a&&a<59){b3=2;b4=a-30;return;}
	if(59<=a&&a<90){b3=3;b4=a-58;return;}
	if(90<=a&&a<120){b3=4;b4=a-89;return;}
	if(120<=a&&a<151){b3=5;b4=a-119;return;}
	if(151<=a&&a<181){b3=6;b4=a-150;return;}
	if(181<=a&&a<212){b3=7;b4=a-180;return;}
	if(212<=a&&a<243){b3=8;b4=a-211;return;}
	if(243<=a&&a<273){b3=9;b4=a-242;return;}
	if(273<=a&&a<304){b3=10;b4=a-272;return;}
	if(304<=a&&a<334){b3=11;b4=a-303;return;}
	if(334<=a){b3=12;b4=a-333;return;}
	}
	else{
	b2=0;
	if(a<31){b3=1;b4=a+1;return;}
	if(31<=a&&a<60){b3=2;b4=a-30;return;}
	if(60<=a&&a<91){b3=3;b4=a-59;return;}
	if(91<=a&&a<121){b3=4;b4=a-90;return;}
	if(121<=a&&a<152){b3=5;b4=a-120;return;}
	if(152<=a&&a<182){b3=6;b4=a-151;return;}
	if(182<=a&&a<213){b3=7;b4=a-181;return;}
	if(213<=a&&a<244){b3=8;b4=a-212;return;}
	if(244<=a&&a<274){b3=9;b4=a-243;return;}
	if(274<=a&&a<305){b3=10;b4=a-273;return;}
	if(305<=a&&a<335){b3=11;b4=a-304;return;}
	if(335<=a){b3=12;b4=a-334;return;}
	}
}
int a1,a2,a3,a4,a5,a6;//a1 400定(146097)定方 a2 100定(36524)定方 a3 4定(1461)定方 a4 噫方 b5 埖方 b6 晩方 
void fa(int a){
	a1=a/146097;a%=146097;
	a2=a/36524;a%=36524;
	a3=a/1461;a%=1461;
	if(a==365){a4=1;a5=1;a6=1;return;}
	if(a<365){
		a4=0;
		if(a<31){a5=1;a6=a+1;return;}
		if(31<=a&&a<59){a5=2;a6=a-30;return;}
		if(59<=a&&a<90){a5=3;a6=a-58;return;}
		if(90<=a&&a<120){a5=4;a6=a-89;return;}
		if(120<=a&&a<151){a5=5;a6=a-119;return;}
		if(151<=a&&a<181){a5=6;a6=a-150;return;}
		if(181<=a&&a<212){a5=7;a6=a-180;return;}
		if(212<=a&&a<243){a5=8;a6=a-211;return;}
		if(243<=a&&a<273){a5=9;a6=a-242;return;}
		if(273<=a&&a<304){a5=10;a6=a-272;return;}
		if(304<=a&&a<334){a5=11;a6=a-303;return;}
		if(334<=a){a5=12;a6=a-333;return;}
	}
	if(a==731){a4=2;a5=1;a6=1;return;}
	if(a<731){
		a4=1;a-=365;
		if(a<31){a5=1;a6=a+1;return;}
		if(31<=a&&a<60){a5=2;a6=a-30;return;}
		if(60<=a&&a<91){a5=3;a6=a-59;return;}
		if(91<=a&&a<121){a5=4;a6=a-90;return;}
		if(121<=a&&a<152){a5=5;a6=a-120;return;}
		if(152<=a&&a<182){a5=6;a6=a-151;return;}
		if(182<=a&&a<213){a5=7;a6=a-181;return;}
		if(213<=a&&a<244){a5=8;a6=a-212;return;}
		if(244<=a&&a<274){a5=9;a6=a-243;return;}
		if(274<=a&&a<305){a5=10;a6=a-273;return;}
		if(305<=a&&a<335){a5=11;a6=a-304;return;}
		if(335<=a){a5=12;a6=a-334;return;}
	}else{
		a4+=2;a-=731;a4+=a/365;a%=365;
		if(a<31){a5=1;b4=a+1;return;}
		if(31<=a&&a<59){a5=2;a6=a-30;return;}
		if(59<=a&&a<90){a5=3;a6=a-58;return;}
		if(90<=a&&a<120){a5=4;a6=a-89;return;}
		if(120<=a&&a<151){a5=5;a6=a-119;return;}
		if(151<=a&&a<181){a5=6;a6=a-150;return;}
		if(181<=a&&a<212){a5=7;a6=a-180;return;}
		if(212<=a&&a<243){a5=8;a6=a-211;return;}
		if(243<=a&&a<273){a5=9;a6=a-242;return;}
		if(273<=a&&a<304){a5=10;a6=a-272;return;}
		if(304<=a&&a<334){a5=11;a6=a-303;return;}
		if(334<=a){a5=12;a6=a-333;return;}
	}
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int i,k,a;
	char q=' ',B='B',C='C';
	cin>>n;
	while(n--){
		scanf("%d",&a);
		if(a==0)printf("1 1 4713 BC\n");else{
		if(a==1721424)printf("1 1 1\n");else{
		if(a<1721424){
			fb(a);b1*=4;b1=4713-b1-b2;
			printf("%d%c%d%c%d%c%c%c\n",b4,q,b3,q,b1,q,B,C);
		}else{
		if(a==2299526)printf("15 10 1582\n");else{
		if(a<2299526){
			fb(a);b1*=4;b1=b1+b2-4712;
			printf("%d%c%d%c%d\n",b4,q,b3,q,b1);
		}else{
		if(a==2299603)printf("1 1 1583\n");else{//1583%4=3
		if(a<2299603){
			fb(a+10);b1*=4;b1=b1+b2-4712;
			printf("%d%c%d%c%d\n",b4,q,b3,q,b1);
		}else{
			fa(a-2299604);a1=a1*400+a2*100+a3*4+a4+1584;if(a<=2500)a1--;
			printf("%d%c%d%c%d\n",a6,q,a5,q,a1);
		}
		}
		}
		}
		}
		}
		}
	}
	return 0;
}
