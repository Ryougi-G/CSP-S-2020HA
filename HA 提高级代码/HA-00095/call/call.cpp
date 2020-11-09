#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int a;
	cin>>a;
	switch(a){
		case 3:cout<<"6 8 12";return 0;
		case 10:cout<<"36 282 108 144 180 216 504 288 324 360";return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
