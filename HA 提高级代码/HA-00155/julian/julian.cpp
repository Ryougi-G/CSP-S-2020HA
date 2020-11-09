#include <bits/stdc++.h>
using namespace std;

long long d,y,m; 
long long n;
long long a[1010];
int yueping[13]={29,31,28,31,30,31,30,31,31,30,31,30,31};
int yuerun[13]={29,31,29,31,30,31,30,31,31,30,31,30,31};

void panduan(){
	if(y==0){
		y++;
	}
	return;
}

int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sibainian=a[i]/1461;
		y=-4713+4*sinian;
		panduan();
		if(y>0){
			y++;
		}
		a[i]=a[i]-sinian*1461;
		if(a[i]<366){
			int k=1;
			while(a[i]>yuerun[k]){
				a[i]=a[i]-yuerun[k];
				k++;
			}
			d=a[i],m=k;
		}else{
			a[i]=a[i]-366;
			y++;
			panduan();
			for(int k=1;k<=3;k++){
				if(a[i]>365){
					a[i]=a[i]-365;
					y++;
					panduan();
				}else{
					while(a[i]>yueping[k]){
						a[i]=a[i]-yueping[k];
						k++;
					}
					d=a[i],m=k;
				}
			}
		}
		if(y<0){
			cout<<d+1<<' '<<m<<' '<<-y<<" BC"<<endl;
		}else{
			cout<<d+1<<' '<<m<<' '<<y<<endl;
		}
	}
	return 0; 
}
