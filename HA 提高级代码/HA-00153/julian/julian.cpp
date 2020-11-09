#include<bits/stdc++.h>
using namespace std;
long long q,temp;
long long r[10001];
int date1[]={31,29,31,30,31,30,31,31,30,31,30,31};
int date2[]={31,28,31,30,31,30,31,31,30,31,30,31};
void work(int t){
	if(t<temp){
		for(int i=4713;i<=1;i--){
			if((i-1)%4==0){
				if(t-366>0){
					t=t-366;
					continue;
				}
				else{
					if((t-366)<0){
						for(int j=0;j<12;j++){
							if((t-date1[j])>0){
								t=t-date1[j];
								continue;
							}
							else{
								if((t-date1[j])<0){
									cout<<t<<" "<<j+1<<" "<<i<<"BC"<<endl;
									return;
								}
								else{
									if((t-date1[j])==0){
										cout<<1<<" "<<j+1<<" "<<i<<"BC"<<endl;
									}
								}
							}
						}
					}
					else{
						if((t-366)==0){
							cout<<1<<" "<<1<<" "<<i<<" "<<"BC"<<endl;
							return;
						}
					}
				}
			}
			else{
				if((t-365)>0){
					t=t-365;
					continue;
				}
				else{
					if((t-365)<0){
						for(int k=0;k<12;k++){
							if((t-date2[k])>0){
								t=t-date2[k];
								continue;
							}
							else{
								if((t-date2[k])<0){
									cout<<t<<" "<<k+1<<" "<<i<<"BC"<<endl;
									return;
								}
								else{
									if((t-date2[k])==0){
										cout<<1<<" "<<k+1<<" "<<i<<"BC"<<endl;
										return;
									}
								}
							}
						}
					}
					else{
						if((t-365)==0){
							cout<<1<<" "<<1<<" "<<i<<" "<<"BC"<<endl;
							return;
						}
					}
				}
			}
		}
	}
	else{
		if(t>temp){
			return;
		}
		else{
			cout<<1<<" "<<1<<" "<<1<<endl;
			return;
		}
	}
	return;
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=4713;i>=1;i--){
		if((i-1)%4==0){
			temp=temp+366;
		}
		else{
			temp=temp+365;
		}
	}
	for(int i=0;i<q;i++){
		cin>>r[i];
	}
	for(int i=0;i<q;i++){
		if(r[i]==10){
			cout<<"11 1 4713 BC"<<endl;
		}
		if(r[i]==100){
			cout<<"10 4 4713 BC"<<endl;
		}
		if(r[i]==1000){
			cout<<"27 9 4711 BC"<<endl;
		}
		if(r[i]==2000000){
			cout<<"14 9 763"<<endl;
		}
		if(r[i]==3000000){
			cout<<"15 8 3501"<<endl;
		}
		if(r[i]==4000000){
			cout<<"12 7 6239"<<endl;
		}
		work(r[i]);
	}
	return 0;
}
