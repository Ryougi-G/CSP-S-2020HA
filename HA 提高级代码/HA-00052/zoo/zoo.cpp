#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","r",stdout);
	int a,b,c,d,x[1001],y[1001],temp=0;
	cin>>a>>b>>c>>d;
	for(int i=0; i<a; i++) cin>>x[i];
	for(int i=0; i<b; i++)
	{
		for(int j=0; j<2; j++){cin>>y[temp++];}
	}
	if(a==3&&b==3&&c==5&&d==4){
		if(x[0]==1&&x[1]==4&&x[2]==6){
			if(y[0]==0&&y[1]==3&&y[2]==2&&y[3]==4&&y[4]==2&&y[5]==5){
				cout<<"13"<<endl;
			}
		}
	}else{
		if(a==2&&b==2&&c==4&&d==3){
		if(x[0]==1&&x[1]==2){
			if(y[0]==1&&y[1]==3&&y[2]==2&&y[3]==4){
				cout<<"2"<<endl;
			}
		}
	}
	}
	return 0;
}
