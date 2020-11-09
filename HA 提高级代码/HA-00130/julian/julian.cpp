#include<bits/stdc++.h>
using namespace std;
long long Q,r;
int ay,am,ad;
int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	freopen("julian3.in","r",stdin);
	freopen("julian.out","w",stdout);
	//17214231721117
	cin>>Q;
	for(int i=1; i<=Q; i++){
		cin>>r;
		ay=4713;am=1;ad=1;bool cm=false,cy=false;
		if(r<=1721422) cy=false;
		else cy=true;
		ay-=4*(r/(365*3+366));r=r%(365*3+366);
		if(r<366){ cm=true;}
		else{ ay-=1+(r-366)/365;r=(r-366)%365;}
		if(cy==true){
			ay=abs(ay)+1;
		}
		if(ay>=1582 && cy==true){
			if((ay==1582 && r>=273)||(ay>1582)){
				r+=10;
			}
			if(ay>=1600){
				for(int j=1600; j<=ay; j+=100){
					if(j%400!=0)r++;
				}
		        ay+=4*(r/(365*3+366));r=r%(365*3+366);
		        for(int j=ay; j<ay+4; j++){
		        	if((j%4==0 && j%100!=0) || j%400==0){
		        		if(r<366){
		        			cm=true;break;
						}else{
							r-=366;ay++;
						}
					}else{
						if(r<365){
							cm=false;break;
						}else{
							r-=365;ay++;
						}
					}
				}
			}
		}
		
		if(r<59){
			if(r>=31){ r%=31;am++;}
		}else{
			if(cm==true) m[1]=29;
			for(int j=0; j<12; j++){
				if(r>=m[j]) {am++;r-=m[j];}
				else{ break;}
			}
			m[1]=28;
		}
		
		ad+=r;
		
		cout<<ad<<" "<<am<<" "<<ay;
		if(cy==true) cout<<endl;
		else cout<<" BC"<<endl;
	}
	
}
