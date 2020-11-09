#include <bits/stdc++.h>
using namespace std;

int t , n , k;
int a[1000010] , b[100010][2];
queue<int> q1 , q2;

void paixu(int x[1000010])
{
	
	for (int i = 1; i <= n; i++){
		if (x[i] < x[i + 1]){
			int y = x[i];
			x[i] = x[i + 1];
			x[i + 1] = y;
		}
	}
	for (int i = 1; i <= n; i++){
		q1.push(x[i]);
	}
	for (int i = n; i >= 1; i--){
		q2.push(x[i]);
	}
}

int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin >> t >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cin >> k;
	for (int i = 1;  i <= k; i++){
		cin >> b[i][1] >> b[i][2];
	}
	int ans = n;
	for (int i = 1; i <= t; i++){
		for (int j = 1; j <= n; j++){
			paixu(a);
			int s = q1.front();
			q1.pop();
			if (s - q2.front() > q1.front()) ans = ans - 1;
			else break;
		}
		cout << ans << endl;
	}
	return 0;
}
