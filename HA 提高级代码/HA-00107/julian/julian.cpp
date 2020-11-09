#include<bits/stdc++.h>
using namespace std;
unsigned long long q,da=1,mo=1,ye=4713,qi=1;
inline unsigned long long szread(){
	unsigned long long res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
return res*f;}
struct node{
	unsigned long long rz,n,y,r,b,g;
}rr[100010];
int cmpl(node a,node x){
	return a.rz<x.rz;
}
int cmpr(node a,node x){
	return a.b<x.b;
}
int main(){
	freopen("julian.in","r",stdin);freopen("julian.out","w",stdout);
	q=szread();
	for(int i=1;i<=q;++i){
		rr[i].rz=szread();rr[i].b=i;
	}
	sort(rr+1,rr+q+1,cmpl);long long j=1;
	for(unsigned long long i=1;i<=rr[q].rz;++i){
		if(qi==1){
			if(mo==1||mo==3||mo==5||mo==7||mo==8||mo==10||mo==12){
				if(da==31&&mo==12&&ye==1) da=1,mo=1,ye=1,qi=0; 
				else if(da==31&&mo==12&&ye!=1) da=1,mo=1,ye-=1;
				else if(da==31&&mo!=12) da=1,mo+=1;
				else ++da;
			}
			else if(mo==2){
				if((ye-1)%4==0&&da==29) da=1,++mo;
				else if((ye-1)%4!=0&&da==28) da=1,++mo;
				else ++da;
			}
			else {
				if(da==30) da=1,mo+=1;
				else ++da;
			}
		}
		else if(qi==0){
			if(mo==1||mo==3||mo==5||mo==7||mo==8||mo==10||mo==12){
				if(ye==1852&&mo==10&&da==4) da=14;
				if(da==31&&mo==12) da=1,mo=1,ye+=1;
				else if(da==31&&mo!=12) da=1,mo+=1;
				else ++da;
			}
			else if(mo==2){
				if(ye<=1582){
					if(ye%4==0&&da==29) da=1,++mo;
					else if(ye%4!=0&&da==28) da=1,++mo;
					else ++da;}
				else if(ye>1582){
					if(ye%400==0) if(da==29) da=1,++mo;else ++da;
					else if(ye%4==0&&ye%100!=0) if(da==29) da=1,++mo;else ++da;
					else if(da==28) da=1,++mo;
					else ++da;
				}
			}
			else {
				if(da==30) da=1,mo+=1;
				else ++da;
			}
		}
		if(i==rr[j].rz) {
			rr[j].r=da;rr[j].y=mo;rr[j].n=ye;rr[j].g=qi;++j;cout<<i<<" "<<da<<" "<<mo<<endl;
		}
	}
	sort(rr+1,rr+q+1,cmpr);
	for(int i=1;i<=q;++i) {
		if(rr[i].g==1){
			printf("%llu %llu %llu BC\n",rr[i].r,rr[i].y,rr[i].n);
		}
		else if(rr[i].g==0){
			printf("%llu %llu %llu\n",rr[i].r,rr[i].y,rr[i].n);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
