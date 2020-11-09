#include<bits/stdc++.h>
using namespace std;
int t,s[4],m;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int i,k,j,l;
	cin>>t;
	cin>>k;
	if(k!=3)return 0;
	cin>>s[1]>>s[2]>>s[3];sort(s+1,s+4);
	if(s[3]>s[1]+s[2])cout<<1;
	else cout<<3;
	cout<<endl;t--;
	while(t--){
		cin>>k;
		for(i=0;i<k;i++){
			cin>>j>>l;
			s[j]=l;
		}
		sort(s+1,s+4);
		if(s[3]>s[1]+s[2])cout<<1;
		else cout<<3;
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
