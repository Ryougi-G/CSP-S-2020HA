#include <iostream>
#include <cstdio>
using namespace std;
int ybc(int y){
	if(y % 4 == 1){
		return 366;
	}else{
		return 365;
	}
}
int mbc(int m, int y){
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
		return 31;
	}else if(m == 2){
		if(ybc(y) == 366){
			return 29;
		}else{
			return 28;
		}
	}else{
		return 30;
	}
}
int yadju(int y){
	if((y % 4 == 0 && y <1582) || (y % 4 == 0 && y % 100 != 0 && y > 1582) || (y % 400 == 0 && y > 1582)){
		return 366;
	}else if (y == 1582){
		return 355;
	}else{
		return 365;
	}
}
int madju(int m, int y){
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 12 || (m == 10 && yadju(y) != 355)){
		return 31;
	}else if(m == 2){
		if(yadju(y) == 366){
			return 29;
		}else{
			return 28;
		}
	}else if(m == 10 && yadju(y) == 355){
		return 21;
	}else{
		return 30;
	}
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int n;
	cin >> n;
	long long day[n + 1];
	for (int i = 1; i <= n; i ++){
		cin >> day[i];
		long long d = 1,m = 1,y = 4713;
		d += day[i];
		while(d > 1461 && y >= 5){
			d -= 1461;
			y -= 4;
		}
		while(d > ybc(y) && y >= 1){
			d -= ybc(y);
			y --;
		}
		if(y >= 1){
			while(d > mbc(m,y)){
				d -= mbc(m,y);
				m ++;
			}
			cout << d << " " << m << " " << y << " BC" << endl;
		}else {
			y = 1;
			while(d > 1461){
				d -= 1461;
				y += 4;
				if(y == 1581){
					break;
				}
			}
			while(d > yadju(y)){
				d -= yadju(y);
				y ++;
				
			}
			if(y == 1585){
				while(d > 10763217){
					d -= 10763217;
					y += 400;
				}
				for(int j = 0; j < 4; j ++ ){
					if(j = 0){
						if(d > 2690805){
							d -= 2690805;
							y += 100;
						}else{
							break;
						}
					}else{
						if(d > 2690804){
							d -= 2690804;
							y += 100;
						}else{
							break;
						}
					}
				}
				while(d > 1461){
					d -= 1461;
					y -= 4;
				}
				while(d > yadju(y)){
					d -= yadju(y);
					y ++;
				}
			}
			while(d > madju(m,y)){
				d -= madju(m,y);
				m ++;
			}
			if (y == 1582 && m == 10 && d > 4){
				d += 10;
			}
			cout << d << " " << m << " " << y << endl;
		}
	}
	return 0;
}
