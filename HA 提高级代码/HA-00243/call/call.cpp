#include<bits/stdc++.h>
using namespace std;
int n,m,a[101001],q,ask[20001];
struct fuction{
	int num;
	int andpl,andd;
	int mul;
	int make_num;
	int turing[2001];
}mxy[2001];
void anddd(int x,int and_num){
	a[x]+=and_num;
}
void mull(int mull){
	for(int i=1;i<=n;i++){
		a[i]*=mull;
	}
}
void askk(int x,int y){
	switch(x){
			case 1:{
				anddd(mxy[y].andpl,mxy[y].andd);
				break;
			}
			case 2:{
			mull(mxy[y].mul);
				break;
			}
			case 3:{
				for(int j=1;j<=mxy[y].make_num;j++){
					int d=mxy[y].turing[j];
					askk(mxy[d].num,mxy[y].turing[j]);
				}
				break;
			}
		
	}
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&mxy[i].num);
		switch(mxy[i].num){
			case 1:{
				scanf("%d%d",&mxy[i].andpl,&mxy[i].andd);
				mxy[i].mul=1;
				mxy[i].make_num=0;
				memset(mxy[i].turing,0,sizeof(mxy[i].turing));
				break;
			}
			case 2:{
				scanf("%d",&mxy[i].mul);
				mxy[i].andd=0;
				mxy[i].andpl=0;
				mxy[i].make_num=0;
				memset(mxy[i].turing,0,sizeof(mxy[i].turing));
				break;
			}
			case 3:{
				scanf("%d",&mxy[i].make_num);
				for(int j=1;j<=mxy[i].make_num;j++)scanf("%d",&mxy[i].turing[j]);
				mxy[i].andd=0;
				mxy[i].andpl=0;
				mxy[i].mul=1;
				break;
			}
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		scanf("%d",&ask[i]);
	}
	for(int i=1;i<=q;i++){
		askk(mxy[ask[i]].num,ask[i]);
	}
	for(int i=1;i<= n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
