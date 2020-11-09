#include <bits/stdc++.h>
using namespace std;
long long ans=0,fe=0,an[2000001]={0},me[2000001][2]={0},pd=0,v[2000001]={0};
int n,m,c,k;
int main(int argc, char** argv) {
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++){
	    cin>>an[i];
	    for(int j=0;an[i]>>j;j++){
	    	if(((pd>>j)&1)==0&&((an[i]>>j)&1)==1){
	    		pd+=1<<j;
			}
		}
	}	
	for(int i=1;i<=m;i++){
		cin>>me[i][0]>>me[i][1];//i位 p种
		if(((pd>>me[i][0])&1)==0&&v[me[i][1]]==0){
			fe+=1<<me[i][0];//等于1代表不能选
		} 
		else  v[me[i][1]]=1;
	}
	//cout<<fe;
	for(long long i=0;i<=(1<<k)-1;i++){
		int w=1;
		for(int j=0;j<=k;j++){
			if((((fe>>j)&1)==1)&&((i>>j)&1==1)){
				w=0;
				break;
			}
		}
		if(w==1){
			ans++;
			//cout<<i<<endl;
		}
    }
	cout<<ans-n;
	return 0;
}
/*
4 3 5 5
1 4 6 16
0 1
3 2
4 3
*/
