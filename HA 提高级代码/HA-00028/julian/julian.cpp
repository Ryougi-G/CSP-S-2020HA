#include<bits/stdc++.h>
using namespace std;
int q,r[100009],j;
int year,month,day;
int y[19]{0,31,59,90,120,151,181,212,243,273,304,334,365};
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>r[i];
		year=1;month=1;day=1;
		if(r[i]==365){
			year=4712;
			month=1;
			day=1;
			cout<<day<<" "<<month<<" "<<year<<" "<<"BC"<<endl;
		}
		else{
			year=4713;
	        for(int j=1;j<12;j++){
	        	if(y[j]<r[i]&&r[i]<=y[j+1]){
	        		month=j+1;
	        		day=r[i]-y[j];
	        	}
	        }
				cout<<day<<" "<<month<<" "<<year<<" "<<"BC"<<endl ;
		}
	}
	return 0;
}
