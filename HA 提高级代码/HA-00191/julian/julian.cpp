#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	int q;
	cin >> q;
	double day;
    double d = 1, m = 1; 
    int y = 4713;
	for(int i = 0; i < q; i++){
		while(day > 0){
		if(d + day >= 30 && m == 4 || d + day >= 30 && m == 6 || d + day >= 30 && m == 9 || d + day >= 30 && m == 11){
			d = day - d;
			m += 1; 
		}else if(d + day >= 31 && m != 2){
			m += 1;
			d = 31 - day - 2;
		}else if(y % 4 != 0){
			m += 1;
			d = 28 - d;
		}else{
			m += 1;
		    d = 29 - d;
		}
		if(m > 12){
			y -= 1;
			m = 1;
		}
		day = day - 30 + d;
	}
	if(y < 0){
	cout << d << " " << m << " " << y << "BC" << endl;
    }else{
	cout << d << " " << m << " " << 4713 - y + 1;
    }  
	}
    
	return 0;
}
