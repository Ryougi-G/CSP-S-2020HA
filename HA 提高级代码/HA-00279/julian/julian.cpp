#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 100010;
int ca[4];//[0]为年份，[1]为月份,[2]为日期,[3]为公元 
ll d[MAXN];
int sand[14];
int n,temp,ne;

void solveans(ll da){
	ne=da-temp;
	for(int j=ne;j>0;j--){
		ca[2] +=1;
		if((ca[0]-1)%4 == 0 && ca[3]==0 || 
			ca[0]%4 == 0 && ca[3]==1 && ca[0]<=1582 ||
			ca[0]%4 == 0 && ca[0]%100 != 0 && ca[3]==1 && ca[0]>1582 ||
			ca[0]%400 == 0 && ca[3]==1 && ca[0]>1582){ //是闰年 
				
				if (ca[1]==2) {
					if (ca[2]==sand[13]+1) {
						ca[2]=1;
						ca[1] +=1;
					}
				}
				else {
					if (ca[2]==sand[ca[1]]+1){
						ca[2]=1;
						ca[1] +=1;
					}
				}
				
			}
			
		else{
				if (ca[2]==sand[ca[1]]+1){
						ca[2]=1;
						ca[1] +=1;
				}
				if (ca[0]==1582 && ca[1]==10 && ca[2]==5 && ca[3]==1 ) ca[2]=15;
			}
			
		if (ca[1]==12+1){
			ca[1]=1;
			if (ca[3]==0) ca[0] -=1;
			else ca[0] +=1;
			if(ca[0]==0){
				ca[0]=1;
				ca[3]=1;
			}
		} 
	}
	if (ca[3]== 0) printf("%d %d %d BC\n",ca[2],ca[1],ca[0]);
	else printf("%d %d %d\n",ca[2],ca[1],ca[0]);
	temp=da;
}

int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	
	ca[0]=4713;
	ca[1]=1;
	ca[2]=1;
	ca[3]=0;
	
	sand[1]=31;
	sand[2]=28;
	sand[3]=31;
	sand[4]=30;
	sand[5]=31;
	sand[6]=30;
	sand[7]=31;
	sand[8]=31;
	sand[9]=30;
	sand[10]=31;
	sand[11]=30;
	sand[12]=31;
	sand[13]=29; //闰年2月 
	
	scanf("%d",&n);
	for (int i=1 ;i<=n;i++)
		scanf("%lld",&d[i]);
	sort(d+1,d+n+1);
	//for(int i=1 ;i<=n;i++) printf("%d ",d[i]);
	
	for (int i=1;i<=n;i++){
		solveans(d[i]);
	}
	return 0;
}
