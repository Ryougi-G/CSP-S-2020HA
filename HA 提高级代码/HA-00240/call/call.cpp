#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	frezope("call.in","r",stdio);
	frezope("call.out","w",stdout);

	fclose(stdio);
	fclose(stdout);
	return 0;
}
