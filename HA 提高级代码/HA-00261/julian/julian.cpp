#include<bits/stdc++.h>
using namespace std;
long long int q,r[10001],y,m,d,num;
int monthp[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int monthr[12]={31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
//	freopen("julian.in","r",stdin);
//	freopen("julian.out","w",stdout);
	cin>>q;
	num=4713*365+1178;
	for(int i=0;i<q;i++){
		cin>>r[i];
	}
	for(int i=0;i<q;i++){
		y=4713;
		m=1;
		d=1;
		if(r[i]==num){
					cout<<"1"<<" 1"<<" 1"<<endl;
				}
		if(r[i]<=365){//一年之内 
			d+=r[i];
			if(d>31){
				for(int j=0;i<q;j++){
					if(d<=31)
						break;
					else{
						d=d-monthp[j];
						m++;
					}
				}
				d--;
			}
			cout<<d<<" "<<m<<" "<<y<<" BC"<<endl;
		}
		else if(r[i]>365&&r[i]!=num){//公元 
			d+=r[i];
			for(int j=0;d>365;j++){
				if((y+1)%4==0)d-=366;
				else d-=365;
				y--;
			}
			if(d>31){
				for(int j=0;i<q;j++){
					if(d<=31)
						break;
					else{
						if((y+1)%4==0)d=d-monthr[j];
						else d-=monthp[j];
						m++;
					}
				}
			}
			if(r[i]<num)cout<<d<<" "<<m<<" "<<y<<" BC"<<endl;
			else cout<<d<<" "<<m<<" "<<-y+1<<endl;
		}
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
