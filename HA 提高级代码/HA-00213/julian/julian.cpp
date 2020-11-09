#include<iostream>
#include<cstdio>
using namespace std;
int q[1001]; 
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>q[i];
	}
	for(int i=0;i<n;i++){
		if(q[i]<=30){
			cout<<q[i]+1<<" "<<1<<" "<<4713<<" "<<"BC"<<endl;
		}
		if(q[i]>30&&q[i]<=59){
			cout<<q[i]-31+1<<" "<<2<<" "<<4713<<" "<<"BC"<<endl;
		}
		if(q[i]>59&&q[i]<=90){
			cout<<q[i]-60+1<<" "<<3<<" "<<4713<<" "<<"BC"<<endl;
		}
		if(q[i]>90&&q[i]<=120){
			cout<<q[i]-91+1<<" "<<4<<" "<<4713<<" "<<"BC"<<endl;
		}
		if(q[i]>120&&q[i]<=151){
			cout<<q[i]-121+1<<" "<<5<<" "<<4713<<" "<<"BC"<<endl;
		}
		if(q[i]>151&&q[i]<=181){
			cout<<q[i]-152+1<<" "<<6<<" "<<4713<<" "<<"BC"<<endl;
		}
		if(q[i]>181&&q[i]<=212){
			cout<<q[i]-182+1<<" "<<7<<" "<<4713<<" "<<"BC"<<endl;
		}
		if(q[i]>212&&q[i]<=243){
			cout<<q[i]-213+1<<" "<<8<<" "<<4713<<" "<<"BC"<<endl;
		}
		if(q[i]>243&&q[i]<=273){
			cout<<q[i]-244+1<<" "<<9<<" "<<4713<<" "<<"BC"<<endl;
		}
		if(q[i]>273&&q[i]<=304){
			cout<<q[i]-274+1<<" "<<10<<" "<<4713<<" "<<"BC"<<endl;
		}
		if(q[i]>304&&q[i]<=334){
			cout<<q[i]-305+1<<" "<<11<<" "<<4713<<" "<<"BC"<<endl;
		}
		if(q[i]>334&&q[i]<=365){
			cout<<q[i]-355+1<<" "<<12<<" "<<4713<<" "<<"BC"<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
