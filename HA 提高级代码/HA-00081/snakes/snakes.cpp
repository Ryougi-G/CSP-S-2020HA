#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<fstream>
#define MAXN 99999999
using namespace std;
ifstream cin("snakes.in");
ofstream cout("snakes.out");
struct snakes{
	int num;
	int val;
	bool flag;
};
int T,n,end=0;
snakes s[MAXN];
int ans[MAXN]={};
int k[T];
int l[MAXN];
int main(){
	cin>>T>>n;
	for(int i=1;i<=n;i++){
		s[i].flag=true;
		s[i].num=i;
		cin>>s[i].val;
	}
	for(int i=1;i<=n;i++){
		sort(s,s+n);
		for(int j=1;j<=n;j++){
			if(s[n].val-s[i].val>s[j].val||s[n].val-s[i].val==0&&s[i].num>s[j].num){
			    s[i].flag=false;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i].val>0&&s[i].flag==true)
			end++;
	}
	for(int i=2;i<=T;i++){
		cin>>k[i];
		for(int m=1;m<=k[i];m++){
			cin>>l[m];
		}
		for(int m=1;m<=k[i];m+2){
			swap(l[m+1],s[m].val)
		}
		l[MAXN]={};
		sort(s,s+n);
		for(int h=1;h<=n;h++){
			if(s[h].flag==true){
			for(int j=1;j<=n;j++){
				if(s[n].val-s[h].val>s[j].val||s[n].val-s[h].val==0&&s[h].num>s[j].num){
			   		s[h].flag=false;
					}
				ans[i]++;
				}	
			}	
		} 	
	}
	cout<<end<<endl;
	for(int i=2;i<=T;i++){
		cout<<ans[i]<<endl;
	}
	cin.lose();
	cout.close();
	return 0;	
}
