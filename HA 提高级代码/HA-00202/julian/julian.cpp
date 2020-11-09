#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int pd = 1721424;
int a[N];
int Y[14] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int R[14] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool RN(int x) {
	if(x % 400 == 0)return true;
	if(x % 4 == 0) {
		if((x % 100) != 0) {
			return true;
		}
	}
	return false;
}

void work1(int x) {
	int year1 = 0;
	int k = 4;
	while(x >= 366) {
		if(k == 4) {
			year1++;
			x = x - 366;
		} else {
			x = x - 365;
			year1++;
		}
		k = k % 4; k++;
	}
	if(x == 0) {
		int temp = 4713 - k;
		cout << "1 1 "<< temp << " BC" << endl;
		return; 
	}
	if(k != 4) {
		int Temp = 1;
		for(int i = 1; i <= 12; i++) {
			if(x >= Y[i]) {
				x -= Y[i];
				Temp++;
			} else break;
		}
		cout <<x + 1<<" "<<Temp<<" "<<4713-year1<<" BC" << endl;		
	}
	if(k == 4) {
		int Temp = 1;
		for(int i = 1; i <= 12; i++) {
			if(x >= R[i]) {
				x -= R[i];
				Temp++;
			} else break;
		}
		cout <<x + 1<<" "<<Temp<<" "<<4713-year1<<" BC" << endl;		
	}
	return; 
}

void work2(int x) {
	x -= 1721424;
	int year2 = 0;
	int k = 1;
	while(x >= 366) {
		if(k == 4) {
			year2++;
			x = x - 366;
		} else {
			x = x - 365;
			year2++;
		}
		k = k % 4; k++;
	}
	year2++;
	if(k != 4) {
		int Temp = 1;
		for(int i = 1; i <= 12; i++) {
			if(x >= Y[i]) {
				x -= Y[i];
				Temp++;
			} else break;
		}
		cout <<x + 1<<" "<<Temp<<" "<<year2<< endl;		
	}
	if(k == 4) {
		int Temp = 1;
		for(int i = 1; i <= 12; i++) {
			if(x >= R[i]) {
				x -= R[i];
				Temp++;
			} else break;
		}
		cout <<x + 1<<" "<<Temp<<" "<< year2 << endl;		
	}
	return; 
}
void work3(int x) {
	x -= 2299160;
	if(x >= 1 && x <= 17) {cout<<14+x<<" "<<10<<" "<<1582<<endl;return;}
	if(x >= 18 && x <= 47){cout<<x-17<<" "<<11<<" "<<1582<<endl;return;}
	if(x >= 48 && x <= 78){cout<<x-47<<" "<<12<<" "<<1582<<endl;return;}
	x -= 79;//x = 0 :1 1 1583
	int year3 = 0;
	for(int i = 1583; i <= 4000000; i++) {
		if(!RN(i)) {
			if(x >= 365) {
				x -= 365;
				year3++;
			}
			else break;
		}
		if(RN(i)) {
			if(x >= 366) {
				x -= 366;
				year3++;
			}
			else break;
		}
	}
	//cout << 1583 + year3 << endl;
	int MON = 1;
	if(!RN(1583 + year3)) {
		for(int i = 1; i <= 12; i++) {
			if(x >= Y[i]) {
				x -= Y[i];
				MON++;
			} else break;
		}
		cout<<x+1<<" "<<MON<<" "<<1583+year3<<endl;
		return;
	}
	if(RN(1583 + year3)) {
		for(int i = 1; i <= 12; i++) {
			if(x >= R[i]) {
				x -= R[i];
				MON++;
			} else break;
		}
		cout<<x+1<<" "<<MON<<" "<<1583+year3<<endl;
		return;
	}	
}

void work4(int x) {
	x -= 2299160;
	if(x >= 1 && x <= 17) {cout<<14+x<<" "<<10<<" "<<1582<<endl;return;}
	if(x >= 18 && x <= 47){cout<<x-17<<" "<<11<<" "<<1582<<endl;return;}
	if(x >= 48 && x <= 78){cout<<x-47<<" "<<12<<" "<<1582<<endl;return;}
	x -= 79;//x = 0 :1 1 1583
	int year3 = 0;
	for(int i = 1583; i <= 40000000; i++) {
		if(!RN(i)) {
			if(x >= 365) {
				x -= 365;
				year3++;
			}
			else break;
		}
		if(RN(i)) {
			if(x >= 366) {
				x -= 366;
				year3++;
			}
			else break;
		}
	}
	//cout << 1583 + year3 << endl;
	int MON = 1;
	if(!RN(1583 + year3)) {
		for(int i = 1; i <= 12; i++) {
			if(x >= Y[i]) {
				x -= Y[i];
				MON++;
			} else break;
		}
		cout<<x+1<<" "<<MON<<" "<<1583+year3<<endl;
		return;
	}
	if(RN(1583 + year3)) {
		for(int i = 1; i <= 12; i++) {
			if(x >= R[i]) {
				x -= R[i];
				MON++;
			} else break;
		}
		cout<<x+1<<" "<<MON<<" "<<1583+year3<<endl;
		return;
	}	
}


int main() {
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] <= 1721424) work1(a[i]);
		if(a[i] <= 2299160 && a[i] > 1721424) work2(a[i]);
		if(a[i] > 2299160 && a[i] <= 10000000) work3(a[i]);
		if(a[i] > 10000000) work4(a[i]);
	}
	return 0;
}
