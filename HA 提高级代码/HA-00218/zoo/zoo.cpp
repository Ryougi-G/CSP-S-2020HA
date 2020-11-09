#include<iostream>
#include<cstring>
#include<fstream>
#include<cmath>
#include<fstream>
using namespace std;
long long int n,m,c,k,sum;
int cnt=0;
long long int a[4097];
string b[4097];
string cache[101];
long long int p[4097],q[4097];
int main(){
freopen("zoo.in","r",stdin);
freopen("zoo.out","w",stdout);

cin >>n>>m>>c>>k;
cin >> n;
for(int i=0;i<n;i++){
	cin >> a[i];
}
for(int i=0;i<m;i++){
	cin >> p[i] >> q[i];
}
for(int i=0;i<n;i++){
	sum=a[i];
	for(int j=0;j<99999;j++){
		if(sum==0){
			cache[j]="0";
			cnt++;
			break;
		}
		if(sum%2==0){
			cache[j]="0";
			sum/=2;
			cnt++;
		}else if(sum%2==1){
			cache[j]="1";
			sum/=2;
			cnt++;
		}
	}
}

fclose(stdin);
fclose(stdout);
return 0;
}

