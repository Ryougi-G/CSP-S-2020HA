#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q,b=0,r[100000],n[100000],y[100000],ri[100000],yr[13]={31,29,31,30,31,30,31,31,30,31,30,31};
	string zong[100000][4];
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>r[i];	
		n[i]=r[i]/365;
		r[i]-=n[i]*365;
		if(n[i]%4>0){
			b=n[i]%365;
		}
		r[i]-=b;
		for(int j=1;j<=12;j++){
			if((r[i]-3)%4==0){
				yr[2]=29;
			}
			else{
				yr[2]=28;
			}
			r[i]-=yr[j];
			y[i]++;
			if(r[i]<0){
				r[i]+=yr[j-1];
				y[i]--;
				break;
			}
		}
		ri[i]=r[i];
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=4;j++){
			if(j==3){
				if(n[i]>4713){
					zong[i][j]=n[i]-4713;
				}
				else if(4713>n[i]){
					zong[i][j]=4713-n[i];
				}
			}
			if(j==2){
				zong[i][j]=y[i];
			}
			if(j==1){
				zong[i][j]=r[i];
			}
			if(j==4){
				if(n[i]<4713){
					zong[i][j]='BC';
				}
				else{
					zong[i][j]=" ";
					
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=4;j++){
			cout<<zong[i][j]<<" ";
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
