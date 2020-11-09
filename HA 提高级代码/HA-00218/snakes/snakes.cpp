#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<iomanip>
#include<fstream>
using namespace std;
long long int n[50000],a[50000],b[50000];
int t,n1,maxx=1,minn=1;
int main(){
freopen("snakes.in","r",stdin);
freopen("snakes.out","w",stdout);

cin >> t;
cin >> n1;
	for(int i=0;i<n1;i++){
	cin >> a[i];
	}
	
for(int i=0;i<n1;i++){
	if(a[i]!=0)
	b[i]=a[i];
	if(a[i]==0)
	break;
}
for(int i=0;i<n1;i++){
	if(b[i]>b[maxx]){
		maxx=i;
	}
}
for(int i=0;i<n1;i++){
	if(b[i]<b[minn]){
		minn=i;
	}
}


fclose(stdin);
fclose(stdout);
return 0;
}

