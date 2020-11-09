#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<string>
#include<cstring>
#include<set>
using namespace std;
long long q,sum[10000000];
long long y=-4713,m=1,d=1;
int months[13]={31,28,31,30,31,30,31,31,30,31,30,31};
int monthspro[13]={31,29,31,30,31,30,31,31,30,31,30,31};

bool isrunnian(int n){
	if(n>0&&n%400==0) return 1;
	if(n>0&&n%4==0&&n%100!=0) return 1;
	if(n<0&&(n+1)%400==0) return 1;
	if(n<0&&(n+1)%4==0&&(n+1)%100!=0) return 1;
}

long long isDMY(long long n){
	if(n>=2299542) n=n+10;
	long long yy=0;
	long long answer=0;
	long long ansnum=0;
	if(n%1461==0){
		yy=(n/1461)*4;
		y=y+yy;
		if(y<0)
		cout<<d<<" "<<m<<" "<<abs(y)<<" "<<"BC";
		if(y>=0)
		cout<<d<<" "<<m<<" "<<y;
	}
	if(n%1461>=0&&n%1461<=366) {
		answer=n%1461; 
		yy=(n/1461)*4;
		y=yy+y;
		if(isrunnian(n)==1){
			for(long long i=0;i<12;i++){
				if(answer>monthspro[i]){
					answer=answer-monthspro[i];
					ansnum++;
				}
			}
		}
		else if(isrunnian(n)==0){
			for(long long i=0;i<12;i++){
				if(answer>monthspro[i]){
					answer=answer-months[i];
					ansnum++;
				}
			}
		}
		m=m+ansnum;
		d=d+answer;
		if(y<0)
			cout<<d<<" "<<m<<" "<<abs(y)<<" "<<"BC";
		if(y>=0)
			cout<<d<<" "<<m<<" "<<y;
		}
	if(n%1461>366&&n%1461<=731) {
		answer=n%1461-366; 
		yy=(n/1461)*4+1;
		y=yy+y;
		if(isrunnian(n)==1){
			for(long long i=0;i<12;i++){
				if(answer>monthspro[i]){
					answer=answer-monthspro[i];
					ansnum++;
				}
			}
		}
		else if(isrunnian(n)==0){
			for(long long i=0;i<12;i++){
				if(answer>monthspro[i]){
					answer=answer-months[i];
					ansnum++;
				}
			}
		}
		m=m+ansnum;
		d=d+answer;
		if(y<0)
			cout<<d<<" "<<m<<" "<<abs(y)<<" "<<"BC";
		if(y>=0)
			cout<<d<<" "<<m<<" "<<y+1;
	} 
	if(n%1461>731&&n%1461<=1096){
		answer=n%1461-731; 
		yy=(n/1461)*4+2;
		y=yy+y;
		if(isrunnian(n)==1){
			for(long long i=0;i<12;i++){
				if(answer>monthspro[i]){
					answer=answer-monthspro[i];
					ansnum++;
				}
			}
		}
		else if(isrunnian(n)==0){
			for(long long i=0;i<12;i++){
				if(answer>monthspro[i]){
					answer=answer-months[i];
					ansnum++;
				}
			}
		}
		m=m+ansnum;
		d=d+answer;
		if(y<0)
			cout<<d<<" "<<m<<" "<<abs(y)<<" "<<"BC";
		if(y>=0)
			cout<<d<<" "<<m<<" "<<y+2;
	}
	if(n%1461>1096) {
		answer=n%1461-1096; 
		yy=(n/1461)*4+1;
		y=yy+y;
		if(isrunnian(n)==1){
			for(long long i=0;i<12;i++){
				if(answer>monthspro[i]){
					answer=answer-monthspro[i];
					ansnum++;
				}
			}
		}
		else if(isrunnian(n)==0){
			for(long long i=0;i<12;i++){
				if(answer>monthspro[i]){
					answer=answer-months[i];
					ansnum++;
				}
			}
		}
		m=m+ansnum;
		d=d+answer;
		if(y<0)
			cout<<d<<" "<<m<<" "<<abs(y)<<" "<<"BC";
		if(y>=0)
			cout<<d<<" "<<m<<" "<<y+3;
	}
	
}

int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(long long i=1;i<=q;i++){
		cin>>sum[i];
		isDMY(sum[i]);	
	}
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
