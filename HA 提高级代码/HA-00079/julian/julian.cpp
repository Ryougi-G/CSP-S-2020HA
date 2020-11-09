#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100001],y,cs=4713;
int pts[12]={31,28,31,30,31,30,31,31,30,31,31,31};
int rts[12]={31,29,31,30,31,30,31,31,30,31,31,31};
int nf[4]={365,365,366,365};
int gnf[4]={365,365,365,366};
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]<1721423){
			while(a[i]>0){
			    int js=1;
				if(a[i]<30){
					cout<<1+a[i]<<" "<<"1"<<" "<<cs<<" "<<"BC";
					cout<<endl;
					break;
				}
				else if(a[i]<366){
					while(a[i]>0&&a[i]>rts[js+1])
					{
					a[i]-=rts[js];
					js++;
					}
					cout<<a[i]<<" "<<js<<" "<<"4713"<<" "<<"BC";
					cout<<endl;
					break;
				}
				else{
					int jsn=0,jsy=0,j=0;
					while((a[i]>nf[jsn+1])&&a[i]>0){
					    jsn++;
						a[i]-=nf[jsn];
						if(jsn==4){
							jsn=0;
							j+=4;
						}
						j+=jsn;
					}
					int pn=4713-j;
					if(pn%4==0){
					while(a[i]>0&&a[i]>rts[js+1])
					{
					a[i]-=rts[jsy];
					jsy++;
				    }
					cout<<a[i]+1<<" "<<jsy<<" "<<pn<<" "<<"BC";
					cout<<endl;
					break;
					}
					else{
						pn+=1;
						while(a[i]>0&&a[i]>pts[jsy+1])
					{
					a[i]-=pts[jsy];
					jsy++;
					}
					cout<<a[i]+1<<" "<<jsy+1<<" "<<pn<<" "<<"BC";
					cout<<endl;
					break;
					}
					
				}
			}
		}
		else{
			a[i]-=1721423;
		if(a[i]<30){
			cout<<a[i]+1<<" "<<"1"<<" "<<"1";
	  }
	  else if(a[i]<365){
	  	int js=0;
	  	while(a[i]>0&&a[i]>pts[js+1]){
				a[i]-=pts[js];
				js++;
			}
			cout<<a[i]<<" "<<js+1<<" "<<"1";
			cout<<endl;
			break;
		  }
		  else{
		  	int jsn=0,jsy=0,j=0;
					while((a[i]>nf[jsn+1])&&a[i]>0){
					    jsn++;
						a[i]-=nf[jsn];
						if(jsn==4){
							jsn=0;
							j+=4;
						}
						j+=jsn;
					}
					int pn=j;
					if(pn%100!=0&&pn%4==0){
					while(a[i]>0&&a[i]>rts[jsy+1])
					{
					a[i]-=rts[jsy];
					jsy++;
				    }
					cout<<a[i]+1<<" "<<jsy<<" "<<pn;
					cout<<endl;
					break;
					}
					else{
						pn+=1;
					while(a[i]>0&&a[i]>pts[jsy+1])
					{
					a[i]-=pts[jsy];
					jsy++;
					}
					cout<<a[i]+1<<" "<<jsy+1<<" "<<pn;
					cout<<endl;
					break; 
		  }
		}
	  }
	 
}   
 return 0;
}
	
	


