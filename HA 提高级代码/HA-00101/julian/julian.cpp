#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int T;
int y, d, m, ans;

signed main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d", &T);
	
	while(T--){
		int n;
		scanf("%d", &n);
		
		if(n - 1095 <= 0){
			y = n/365, d = n%365;
			m = 1;
			for(int i = 1; i <= 12; i++){
				if(d - mon[i] > 0){
					m++, d -= mon[i];
				}  
			}
			if(!y && m == 1) printf("%d %d %d BC\n", d+1, m, 4713 - y);
			else printf("%d %d %d BC\n", d, m, 4713 - y);
			continue;
		}
		
		y = -4712;
		int tmp = n;
		for(int i = 0; ; i++){
			
			if(y <= 1582){
				if(i%4 == 0){
					if(tmp >= 366) tmp -= 366, y++;
					else break;
				}
				else{
					if(tmp >= 365) tmp -= 365, y++;
				}
			}
			
			else{
				if(((i%4 == 0) && (i % 100 != 0)) || (i%400) == 0){
					if(tmp >= 366) tmp -= 366, y++;
					else break;
				}
				else{
					if(tmp >= 365) tmp -= 365, y++;
				}
			}	
		}
		
		m = 1, d = tmp+1;
		for(int i = 1; i <= 12; i++){
			if(d - mon[i] > 0){
				m++, d -= mon[i];
			}  
		}
		
		if(y > 1582 || (y == 1582 && m == 10 && d >= 5))
			d += 10;
			
		if(y < 0) printf("%d %d %d BC\n", d, m, abs(y));
		else printf("%d %d %d\n", d, m, y);
		
	}
	return 0;
}
