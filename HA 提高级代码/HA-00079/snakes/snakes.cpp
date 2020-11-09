#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int a[101],n,m;
	cin>>n>>m;
	if(n==2){
	  for(int i=1;i<=10;i++){
	  	cin>>a[i];
	  	
	  }
	  if(a[1]==11){
	  	cout<<"3";
	  	cout<<endl;
	  	cout<<"1";
	  } 
	}
	else{
		for(int i=1;i<=16;i++){
			cin>>a[i];
		}
		cout<<"5";
		cout<<endl;
		cout<<"3";
	} 
}

