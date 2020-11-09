#include <iostream>
#include <cstdio>
using namespace std;
long long q,r,day=1,mon=1,yer=-4713;
int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void krv(long long r){
	yer+=(r/1461)*4;
	r%=1461;
	if(r>=366){
		r-=366;
		yer++;
	}
	yer+=r/365;
	r%=365;
	if(yer>=0)yer++;
	if(yer>0&&(yer)%4==0){
		m[2]++;
	}
	if(yer<0&&(3-yer)%4==0){
		m[2]++;
	}
	for(int i=1;i<=12;i++){
		if(r-m[i]<0){
			day+=r;
			break;
		}else{
			mon++;
			r-=m[i];
		}
	}
	return;
}
void kr(long long r){
	if(r<=15){
		day+=r;
	}else if(r<=78){
		r-=16;
		day=1,mon=11;
		for(int i=11;i<=12;i++){
			if(r-m[i]<0){
				day+=r;
				break;
			}else{
				mon++;
				r-=m[i];
			}
		}
	}else{
		yer=1583,mon=1,day=1;
		r-=79;
		if(r<=365){
			for(int i=1;i<=12;i++){
				if(r-m[i]<0){
					day+=r;
					break;
				}else{
					mon++;
					r-=m[i];
				}
			}
		}else{
			r-=365;
			yer++;
			if(r<=1461*4){
				yer+=(r/1461)*4;
				r%=1461;
				if(r>=366){
					r-=366;
					yer++;
				}
				yer+=r/365;
				r%=365;
				if(yer%4==0){
					m[2]=29;	
				}
				for(int i=1;i<=12;i++){
					if(r-m[i]<0){
						day+=r;
						break;
					}else{
						mon++;
						r-=m[i];
					}
				}
				m[2]=28;
			}else{
				yer=1600;
				r-=1461*4;
				yer+=(r/146097)*400;
				r%=146097;
				yer+=(r/36524)*100;
				r%=36524;
				if(r>=1460&&yer%100==0){
					yer+=4;
					r-=1460;
				}
				yer+=(r/1461)*4;
				r%=1461;
				if(r>=366&&((yer%4==0&&yer%100!=0)||(yer%400==0))){
					r-=366;
					yer++;
				}
				yer+=r/365;
				r%=365;
				m[2]=28;
				if((yer%4==0&&yer%100!=0)||(yer%400==0))m[2]=29;
				for(int i=1;i<=12;i++){
					if(r-m[i]<0){
						day+=r;
						break;
					}else{
						mon++;
						r-=m[i];
					}
				}
				m[2]=28;
			}
		}
	}
	return;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin >> q;
	bool tmp=0;
	while(q--){
		cin >> r;
		tmp=0,day=1,mon=1,yer=-4713,m[2]=28;
		if(r<=2299160){
			krv(r);
			if(yer<0){
				yer=-yer;
				tmp=1;
			}
			cout << day << " " << mon << " " << yer;
			if(tmp) cout << " " << "BC";
			cout << endl;
		}else{
			day=15,yer=1582,mon=10;
			r-=2299161;
			kr(r);
			cout << day << " " << mon << " " << yer << endl;
		}
		
	}
	return 0;
}
//4713 1 1 bc
// 1582 10 5 1582 10 14
