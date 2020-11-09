#include <bits/stdc++.h>
using namespace std;

int q;
int r[100010];

int date1(int x){
	int a , b = 1 , c = 4713;
	int yf1[13] = {31,28,31,30,31,30,31,31,30,31,30,31} , yf2[13] = {31,29,31,30,31,30,31,31,30,31,30,31};
	for (int i = 1; i <= x; i++){
		x = x - yf1[i];
		if (x > 0) b++;
		else {
			x = x + yf1[i];
			break;
		}
	} 
	a = x;
	return a;
}

int date2(int x){
	int a , b = 1 , c = 4713;
	int yf1[13] = {31,28,31,30,31,30,31,31,30,31,30,31} , yf2[13] = {31,29,31,30,31,30,31,31,30,31,30,31};
	for (int i = 1; i <= x; i++){
		x = x - yf1[i];
		if (x > 0) b++;
		else {
			x = x + yf1[i];
			break;
	    }
	} 
	a = x;
	return b;
}

int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin >> q;
	for (int i = 1; i <= q; i++){
		cin >> r[i];
	}
	for (int i = 1; i <= q; i++){
		cout << date1(r[i]) << " " << date2(r[i]) << " " << "4713" << " " << "BC" << endl;
	}
	return 0;
}
