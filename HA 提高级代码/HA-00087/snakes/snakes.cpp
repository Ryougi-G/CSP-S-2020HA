#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T;
	cin >> T;
	int n;
	cin >> n;
	if(n == 3){
		int a[3];
		sort(a,a + 3);
		if(a[1] == a[2]){
			cout << 3 <<endl<< 2 << endl << 1;
		}else if(a[1] >= a[0]){
			cout << 2 << endl << 1;
			
		}
	}
	return 0;
}
