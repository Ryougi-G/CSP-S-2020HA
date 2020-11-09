#include <bits/stdc++.h>
using namespace std;
long long int snake[2002];
struct exs{
	long long int num;
	long long int str;
}sn[2002];
bool cmp(exs a,exs b){
	if(a.str<b.str) return 1;
	else if(a.str==b.str) return a.num<b.num;
	else return 0;
}
int main() {
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	long long int T;
	cin>>T;
	long long int n;
	cin>>n;
	long long int ans=n;
	for(int i=0;i<T;i++){
		if(n==3){
			if(i==0){
				for(int j=0;j<3;j++){
					cin>>snake[j];
				}
			}
			else{
				int k;
				cin>>k;
				for(int j=0;j<k;j++){
					int tmp1,tmp2;
					cin>>tmp1>>tmp2;
					snake[tmp1-1]=tmp2;
				}
			}
			if(snake[0]+snake[1]<=snake[2]) cout<<"1"<<endl;
			else cout<<"3"<<endl;
		}
		else{
			if(i==0){
				for(int j=0;j<n;j++){
					cin>>sn[j].str;
					snake[j]=sn[j].str;
					sn[j].num=j;
				} 
			}
			else{
				int k;
				cin>>k;
				for(int j=0;j<n;j++){
					sn[j].str=snake[j];
					sn[j].num=j;
				}
				for(int j=0;j<k;j++){
					long long int tmp1,tmp2;
					cin>>tmp1>>tmp2;
					sn[tmp1-1].str=tmp2;
				}
			}
			while(true){
				//for(int j=0;j<n;j++) cout<<sn[j].str<<" ";
				//cout<<endl;
				if((sn[ans-1].str-sn[0].str==sn[1].str&&sn[ans-1].num>sn[1].num)||sn[ans-1].str-sn[0].str>sn[1].str||sn[ans-1].num==sn[1].num){
					sn[ans-1].str-=sn[0].str;
					sn[0].str=1000000001;
					sort(sn,sn+n,cmp);
					ans--;
				}
				else{
					cout<<ans<<endl;
					ans=n;
					break;
				}
				if(ans==0){
					cout<<"1"<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
