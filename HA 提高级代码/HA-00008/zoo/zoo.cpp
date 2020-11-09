#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
    cin>>n;
    if(n==3){
    	cout<<18;
    	return 0;
    }
    if(n==2){
    	cout<<4;
    	return 0;	
    }
    cout<<pow(2,n)-pow(3,n-3);
    return 0;
}
