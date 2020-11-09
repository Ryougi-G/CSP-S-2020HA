#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int n;
	cin>>n;
	cout<<rand()%n<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
