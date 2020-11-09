#include<bits/stdc++.h>
using namespace std;
int a[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline int read(){
	int w=1,s=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')
			w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
bool run(int y){
	if(y<0)
		y=(-y);
	if(y<=1582){
		if(y==0||y%4==0){
			return true;
		}
		else
			return false;
	}
	else{
		if(y%400==0)
			return true;
		else if(y%4==0&&y%100!=0)
			return true;
		else
			return false;
	}
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int t;
	t=read();
	while(t--){
		int sumy=-4712,sumd=1,summ=1;
	long long n;
	n=read();
	long long N=n;
	if(n<=2299249){
		if(n<=1721400){//公元1年以前
			while(n>=365){
				if(run(sumy))
					n-=366;
				else
					n-=365;
				sumy++;
			}
			if(n==0){
				cout<<summ<<" "<<sumd<<" "<<sumy-1<<"BC"<<endl;
			}
			else if(n==-1){
				cout<<12<<" "<<31<<" "<<sumy-1-1<<"BC"<<endl; 
			}
			else{
				while(n>0){
					n-=a[summ];
					summ++;
				}
				if(n<0){
					summ--;
					n+=a[summ];
					if(N==n)
					cout<<n+1<<" "<<summ<<" "<<-(sumy-1)<<"BC"<<endl;
					else
					cout<<n<<" "<<summ<<" "<<-(sumy-1)<<"BC"<<endl;
				}
			}
		}
		else{//公元1583年以前 
			n-=1721424;
			sumy=1;
			if(n==0)
				cout<<1<<" "<<1<<" "<<1<<endl;
			else{
				while(n>=365){
					if(run(sumy))
						n-=366;
					else
						n-=365;
					sumy++;
				}
				if(n==0){
				cout<<sumd<<" "<<summ<<" "<<sumy<<endl;
				}
				else if(n==-1){
					cout<<31<<" "<<12<<" "<<sumy-1<<endl; 
				}
				else{
					//cout<<sumy<<" "<<summ<<" "<<sumd<<" "<<endl;
					//cout<<n<<endl;
					//cout<<0<<endl;
					while(n>0){
						n-=a[summ];
						summ++;
					}
					//cout<<n<<" "<<summ<<endl;
					if(n<0){
						summ--;
						n+=a[summ];
						if(N==n)
						cout<<n+1<<" "<<summ<<" "<<sumy<<endl;
						else
						cout<<n<<" "<<summ<<" "<<sumy<<endl;
					}
					else{
							cout<<31<<" "<<summ-1<<" "<<sumy<<endl;
						}
					}
				}
			}
		}
	else{//公元1583年以后 
		n-=1721424;
		n+=10;
			sumy=1;
			if(n==0)
				cout<<1<<" "<<1<<" "<<1<<endl;
			else{
				while(n>=365){
					if(run(sumy))
						n-=366;
					else
						n-=365;
					sumy++;
				}
				if(n==0){
				cout<<sumd<<" "<<summ<<" "<<sumy<<endl;
				}
				else if(n==-1){
					cout<<31<<" "<<12<<" "<<sumy-1<<endl; 
				}
				else{
					//cout<<sumy<<" "<<summ<<" "<<sumd<<" "<<endl;
					//cout<<n<<endl;
					//cout<<0<<endl;
					while(n>0){
						n-=a[summ];
						summ++;
					}
					//cout<<n<<" "<<summ<<endl;
					if(n<0){
						summ--;
						n+=a[summ];
						if(N==n)
						cout<<n+1<<" "<<summ<<" "<<sumy<<endl;
						else
						cout<<n+1<<" "<<summ<<" "<<sumy<<endl;
					}
					else{
						cout<<31<<" "<<summ-1<<" "<<sumy<<endl;
					}
				}
			}
		}
	}

}
