#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	frezope("snakes.in","r",stdio);
	frezope("snakes.out","w",stdout);

	fclose(stdio);
	fclose(stdout);
	return 0;
}
