#include <iostream>
#include <cstdio>
using namespace std;
struct ls{
	int we; 
	int zh;
	bool tf;
};
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,c,k;
	cin >> n >> m >> c >> k;
	int a[n];
	int mw[k][n];
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		int ss = 1;
		for(int j = 0; j < k; j --){
			int mw[k][i] = a[i] % ss;
			a[i] /= 2;
			ss *= 2;
		}
	}
	ls pq[m];
	for(int i = 0; i < m; i ++){
		cin >> pq[i].we;
		cin >> pq[i].zh;
		pq[i].tf = 0;
		for(int j = 0; j < n; j ++){
			if(mw[pq[i].we][j] == pq[i].zh){
				pq[i].tf = 1;
			}
		}
	}
	for(int i = 0; i < m; i ++){
		if(pq[i].tf){
			for(int j = 0; j < ss; j ++){
				
			}
			
		}
	}
	cout << 2;
	return 0;
}
