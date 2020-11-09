#include<bits/stdc++.h>
using namespace std;
int q,r[100100];
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool rn_h(int x){
	if(x%100==0){
		if(x%400==0)return 1;
		else return 0;
	}
	else if(x%4==0)return 1;
	return 0;
}
bool rn_q(int x){
	if((x-1)%4==0)return 1;
	return 0;
}
bool rn_z(int x){
	if(x%4==0)return 1;
	return 0;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)scanf("%d",&r[i]);
	for(int i=1;i<=q;i++){
		if(r[i]<=1721424){
			int x=r[i];
			int d=x+1,m=1,y=4713;
			if(rn_q(y)==1)mon[2]=29;
			else mon[2]=28;
			while(1){
				if(d<=mon[m]){
					printf("%d %d %d BC\n",d,m,y);
					break;
				}
				else{
					d-=mon[m];
					m++;
					if(m==13){
						m=1;
						y--;
						if(rn_q(y)==1)mon[2]=29;
						else mon[2]=28;
					}
				}
			}
		}
		else if(r[i]<2299249){
			int x=r[i]-1721424;
			int d=x+1,m=1,y=1;
			if(rn_z(y)==1)mon[2]=29;
			else mon[2]=28;
			while(1){
				if(d<=mon[m]){
					printf("%d %d %d\n",d,m,y);
					break;
				}
				else{
					d-=mon[m];
					m++;
					if(m==13){
						m=1;
						y++;
						if(rn_z(y)==1)mon[2]=29;
						else mon[2]=28;
					}
				}
			}
		}
		else{
			int x=r[i]-1721426;
			int d=x+1,m=1,y=1;
			if(rn_h(y)==1)mon[2]=29;
			else mon[2]=28;
			while(1){
				if(d<=mon[m]){
					printf("%d %d %d\n",d,m,y);
					break;
				}
				else{
					d-=mon[m];
					m++;
					if(m==13){
						m=1;
						y++;
						if(rn_h(y)==1)mon[2]=29;
						else mon[2]=28;
					}
				}
			}
		}
	}
	return 0;
}
