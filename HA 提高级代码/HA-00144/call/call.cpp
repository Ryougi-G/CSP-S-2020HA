#include<vector>
#include<bits/stdc++.h>
using namespace std;
inline int SQHread(){
	int fh=1,dx=0;
	char ch;
	ch=getchar();	
	while(ch<'0'||ch>'9'){
		if(ch=='-')	fh=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		dx=dx*10+ch-'0';
		ch=getchar();
	}
	return dx*fh;
}
const int P=998244353;
int n,a[100002],m,x,shunxv;
struct node{
	int leixing,howmuch,which;
	vector<int> zhixing;
}fuc[100002];
void SQHdo(int num){
	switch(fuc[num].leixing){
		case 1:
			a[fuc[num].which]=(a[fuc[num].which]+fuc[num].howmuch)%P;
		break;
		case 2:
			for(int i=1;i<=n;++i)
				a[i]=(a[i]*fuc[num].howmuch)%P;
		break;
		case 3:
			for(int i=0;i<fuc[num].howmuch;++i)
				SQHdo(fuc[num].zhixing[i]);
		break;
	}
}
int main(){

	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=SQHread();
	for(int i=1;i<=n;++i)
		a[i]=SQHread();
	m=SQHread();
	for(int i=1;i<=m;++i){
		fuc[i].leixing=SQHread();
		if(fuc[i].leixing==1){
			fuc[i].which=SQHread();
			fuc[i].howmuch=SQHread()%P;
		}
		else if(fuc[i].leixing==2){
			fuc[i].howmuch=SQHread()%P;
		}
		else if(fuc[i].leixing==3){
			fuc[i].howmuch=SQHread();
			for(int j=1;j<=fuc[i].howmuch;++j){
				fuc[i].zhixing.push_back(SQHread());
			}
		}
	}
	x=SQHread();
	for(int i=1;i<=x;++i)
		SQHdo(SQHread());
	for(int i=1;i<=n;++i)
		printf("%d ",a[i]%P);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
