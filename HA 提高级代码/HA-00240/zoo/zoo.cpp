#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	frezope("zoo.in","r",stdio);
	frezope("zoo.out","w",stdout);

	
	fclose(stdio);
	fclose(stdout);
	return 0;
}
