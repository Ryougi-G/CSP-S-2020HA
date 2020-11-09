#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long q,a,s[10000],ns=1461,ny=36524,nb=146097,fg=2299159,bc=1721423;
int nian=0,yue=1,ri=0;
int js(int x){
	
	
	nian=x/365;
	x=x%365;
	
    for(int i=1;i<=x;i++)
    {
    	ri++;
    	if(yue==1&&ri==32) {
    		yue=2;
    		ri=1;
    	} 
    	if(yue==2&&ri==29){
    		yue=3;
    		ri=1;
    	}
       if(yue==3&&ri==32){
    		yue=4;
    		ri=1;
    	}if(yue==4&&ri==31){
    		yue=5;
    		ri=1;
    	}if(yue==5&&ri==32){
    		yue=6;
    		ri=1;
    	}if(yue==6&&ri==31){
    		yue=7;
    		ri=1;
    	}if(yue==7&&ri==32){
    		yue=8;
    		ri=1;
    	}if(yue==8&&ri==32){
    		yue=9;
    		ri=1;
    	}if(yue==9&&ri==31){
    		yue=10;
    		ri=1;
    	}if(yue==10&&ri==32){
    		yue=11;
    		ri=1;
    	}if(yue==11&&ri==31){
    		yue=12;
    		ri=1;
    	}
    }
	
}


int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
	scanf("%d",&a);
	if(a<=28){
		cout<<a+1<<" "<<"1"<<" "<<"4713"<<" "<<"BC"<<endl;
	}
	if(a<fg&&a<=bc&&a>28){
		
		int nns=a/ns;
		a=a%ns;
		js(a);
		
		cout<<ri<<" "<<yue<<" "<<4713-(4*nns+nian)<<" "<<"BC"<<endl;
	}
	if(a<=fg&&a>bc){
		a=a-bc;
		int nns=a/ns;
		a=a%ns;
		js(a);
		cout<<ri<<" "<<yue<<" "<<1+(nns*4+nian)<<endl;
	}
	if(a>fg){
		a=a-fg;
		if(a>78){
			a=a-78;
			int nnb=a/nb;
			a=a%nb;
			int nny=a/ny;
			a=a%ny;
			int nns=a/ns;
			a=a%ns;
			
			js(a);
			
			cout<<ri<<" "<<yue<<" "<<1583+(nnb*400+nny*100+nns*4+nian)<<endl;
		}
	}
}
	return 0;
}
