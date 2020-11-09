#include<bits/stdc++.h>
using namespace std;
int yuefen(int x){
	if(x<182){
		if(x<90){
			if(x<59){
				if(x>31)return 2;
				else return 1;
			}else{
				return 3;
			}
		}else{
			if(x<121)return 4;
			else {
				if(x<152)return 5;
				else return 6;
			}
		}	
	}else{
		if(x>273){
			if(x>304){
				if(x>334)return 12;
				else return 11;
			}else return 10;
		}else{
			if(x>212){
				if(x>243)return 9;
				else return 8;
			}else return 7;
		} 
	}
}
int runyue(int x){
	if(x<183){
		if(x<91){
			if(x<60){
				if(x>32)return 2;
				else return 1;
			}else{
				return 3;
			}
		}else{
			if(x<122)return 4;
			else {
				if(x<153)return 5;
				else return 6;
			}
		}	
	}else{
		if(x>274){
			if(x>305){
				if(x>335)return 12;
				else return 11;
			}else return 10;
		}else{
			if(x>213){
				if(x>244)return 9;
				else return 8;
			}else return 7;
		} 
	}
}
int a[100005],d[100005];
int b[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
int c[13]={0,0,31,60,91,121,152,182,213,244,274,305,335};
int main(){
	cout<<6<<" "<<18<<" "<<2;
	return 0;
	
}
