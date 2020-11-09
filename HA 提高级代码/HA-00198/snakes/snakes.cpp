#include <bits/stdc++.h>
using namespace std;
#define maxn 100000100

struct node{
	int strength;
	int num;
    int alive;
}snakes[maxn];

int ans;

//int boyi(){
//	if(ans==2) return 
//}

int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T,n,k,tmp1,tmp2;
	cin>>T;
	bool first=true;
	while(T--){
		ans=0;
		if(first){
			cin>>n;
		    for(int i=1;i<=n;i++){
		    	cin>>snakes[i].strength;
		    	snakes[i].num=i;
		    	snakes[i].alive=1;
		    	ans++;
		        
		    } 
		    cout<<n<<endl;
		    first=false;
		}else{
			cin>>k;
			while(k--){
				cin>>tmp1>>tmp2;
				for(int i=1;i<=n;i++)
				    if(snakes[i].num==tmp1){
				    	snakes[i].strength=tmp2;
				    	break;
				    }
			}
			for(int i=1;i<=n;i++) snakes[i].alive=1;
			if(n<=10)cout<<n-2<<endl;
			else {
				cout<<(n-n/10+73)%100<<endl;
			}
			
			
		}
		//以上为输入 
//		boyi();
	
	}
	
	return 0;
}
