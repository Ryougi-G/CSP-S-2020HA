#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int year,day,month,n,Bc;
	cin>>n;
	if (n<=0){
		fclose(stdin);
	fclose(stdout);
		return 0;
	}
	
	int sum[n];
	for(int i=0;i<n;i++){
		cin>>sum[i];
	}
	for(int i=0;i<n;i++){
		if(sum[i]>16436){
			sum[i]-=16436;
			year=sum[i]/365;
			month=sum[i]%365/30;
			day=sum[i]%=
			365%30;
			cout<<day<<" "<<month<<" "<<year<<endl;
		}
		else{
			sum[i]=16436-sum[i];
			year=sum[i]/365;
			month=sum[i]%365/30;
			day=sum[i]%365%30;
			cout<<day<<" "<<month<<" "<<year<<"BC"<<endl;
		}
	}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
