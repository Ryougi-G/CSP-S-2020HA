#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
unsigned long long n,m,c,hh,nh,a;
int k;
bool sd[70];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin >> n >> m >> c >> k;
	int temp,tmp;
	for(int i=0;i<n;i++){
		cin >> a;
		hh=hh|a;
	}
	for(int i=0;i<k;i++)sd[i]=1;
	for(int i=1;i<=m;i++){
		cin >> temp >> tmp;
		sd[temp]=(bool)((hh>>temp)&1);
	}
	for(int i=0;i<k;i++){
		nh=nh|(sd[i]*(1<<i));
	}
	cout << nh-n+1;
	return 0;
} 
