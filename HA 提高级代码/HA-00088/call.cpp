#include <bits/stdc++.h>
using namespace std;
long long int n,num[100010],fn;

struct func{
	long long int type;
	long long int p=0,v=0;
	long long int use[2001],un=0;
}F[2001];

void dfs(int tmp1){
		for(int j=0;j<F[tmp1].un;j++){
			int t=F[tmp1].use[j];
			//cout<<t<<endl;
			if(F[t].type==1){
				num[F[t].p]+=F[t].v;
											cout<<F[t].p<<" "<<F[t].v<<endl;
			}
			else if(F[t].type==2){
									      cout<<F[t].v<<endl;
				for(int j=0;j<n;j++){
					num[j]*=F[t].v;
				} 
			}	
			else if(F[t].type==3){
				dfs(t);
			}
		}
}
int main() {
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	cin>>fn;
	for(int i=0;i<fn;i++){
		int tmp;
		cin>>tmp;
		if(tmp==1){
			int tmp1,tmp2;
			cin>>tmp1>>tmp2;
			F[i].type=1;
			F[i].p=tmp1-1;
			F[i].v=tmp2;
		}
		else if(tmp==2){
			int tmp1;
			cin>>tmp1;
			F[i].type=2;
			F[i].v=tmp1;
		}
		else if(tmp==3){
			F[i].type=3;
			int tmp1=0;
			cin>>tmp1;
			F[i].un=tmp1;
			for(int j=0;j<tmp1;j++){
				int tmp2;
				cin>>tmp2;
				tmp2--;
				F[i].use[j]=tmp2;
			}
		}
	}
	int go=0,tott=1;
	cin>>go;
	for(int i=0;i<go;i++){
		int tmp1;
		cin>>tmp1;
		tmp1--;
		//cout<<F[tmp1].type<<endl;
		if(F[tmp1].type==1){
			num[F[tmp1].p]+=F[tmp1].v;
												cout<<F[tmp1].p<<" "<<F[tmp1].v<<endl;
		}
		else if(F[tmp1].type==2){
										cout<<F[tmp1].v<<endl;
			for(int j=0;j<n;j++){
				num[j]*=F[tmp1].v;
			}
		}
		else if(F[tmp1].type==3){
			 dfs(tmp1);
		}
	}
	for(int i=0;i<n;i++) cout<<num[i]<<" ";
	return 0;
}
