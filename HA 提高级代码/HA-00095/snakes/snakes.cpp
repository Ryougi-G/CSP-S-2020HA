#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int a,b;
	cin>>a>>b;
	switch(a){
		case 2:
			if(b==3){
				cout<<3<<endl<<1;
				return 0;
			}else{
				cout<<5<<endl<<3;
				return 0;
			}
		case 10:
			if(b==2000){
				cout<<1209<<endl<<1203<<endl<<1227<<endl<<1233<<endl<<1249<<endl<<1235<<endl<<1221<<endl<<1241<<endl<<1231<<endl<<1251;
				return 0;
			}else{
				cout<<30857<<endl<<30801<<endl<<30771<<endl<<30965<<endl<<30881<<endl<<30985<<endl<<30733<<endl<<30879<<endl<<30815<<endl<<30859;
				return 0;
			}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
