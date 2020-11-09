#include<bits/stdc++.h>
using namespace std;
const int N=10088888;
const int ab=1721423;
int q;
long long w[100009]; 
int pmon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int rmon[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int smon[13]={0,31,28,31,30,31,30,31,31,30,21,30,31};
int bcy[5000];
long long ady[N];
bool bcr(int x){
	return (x-1)%4==0;
}
bool adr(int x){
	return (x%400==0)||(x%4==0&&x%100!=0);
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>w[i];
	}
	
	bcy[4713]=0;
	for(int i=4712;i>=1;i--){
		bcy[i]=bcy[i+1]+365;
		if(i%4==0) bcy[i]++;
	}
	ady[1]=1721424;
	for(int i=2;i<=1582;i++){
		ady[i]=ady[i-1]+365;
		if(i%4==0)ady[i]++;
	}
	ady[1583]=ady[1582]+355;
	for(int i=1584;i<=10000009;i++){
		ady[i]=ady[i-1]+365;
		if(adr(i))ady[i]++;
	}
	for(int i=1;i<=q;i++){
		if(w[i]==365){
		cout<<"1 1 4712"<<endl;continue;}
	
		if(w[i]<1721423){
			int k=4713;
			while(bcy[k]<=w[i])k--;
			k++;
			int year=k;
			int ese=w[i]-bcy[year]+1;
			int month=1;
			if(bcr(year)){
				while(ese-rmon[month]>=0){
					ese-=rmon[month];
					month++;
				}
			}else{
				while(ese-pmon[month]>=0){
					ese-=pmon[month];
					month++;
				}
			}
			int day=ese;
			if(day==0)day++;
			cout<<day<<" "<<month<<" "<<year<<" BC"<<endl;
		}
		else{
			int l=1,r=10000003;
			while(r-l>1){
				int mid=(l+r)/2;
				if(ady[mid]<w[i])l=mid;
				else r=mid;
			}
			int year=l;
			if(year!=1582){
				int ese=w[i]-ady[year]+1;
				int month=1;
				if(adr(year)){
					while(ese-rmon[month]>=0){
						ese-=rmon[month];
						month++;
					}
				}else{
					while(ese-pmon[month]>=0){
						ese-=pmon[month];
						month++;
					}
				}
				int day=ese;
				if(day==0)day++;
				cout<<day<<" "<<month<<" "<<year<<endl;
			}
			else{
				int ese=w[i]-ady[year]+1;
				int month=1;
				while(ese-smon[month]>=0){
					ese-=pmon[month];
					month++;
				}
				int day=ese;
				if(day==0)day++;
				cout<<day<<" "<<month<<" "<<year<<endl;
			}
		}
	}
	/*cout<<bcy[1]<<endl;
	for(int i=1;i<=20;i++)cout<<ady[i]<<endl;*/
	return 0;
}

