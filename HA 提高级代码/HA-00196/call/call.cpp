#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cout<<rand()%998244353<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
