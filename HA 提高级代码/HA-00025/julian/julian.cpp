#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int flag=0;//0是平年,1是闰年 
	int a;
	int nian,yue=1,ri=1;
	double y[14]={' ',31,28,31,30,31,30,31,31,30,31,30,31};
	double y1[14]={' ',31,29,31,30,31,30,31,31,30,31,30,31};
	double y2[14]={' ',31,29,31,30,31,30,31,31,30,21,30,31};
	int n;
	cin>>n;
	int x=1721423;//公元前1年12月31日 
	int x1=577460;//1年1月1日-1581年12月31日 
	for(int i=1;i<=n;i++){
		flag=0;
		yue=1;
		ri=1;
		cin>>a;
		if(a<=x){
			nian=4713;
			for(;;){
				if((nian-1)%4!=0&&a>365){
					a-=365;
					nian--;
				}else if((nian-1)%4==0&&a>366){
					a-=366;
					nian--;
					flag=1;
				}else{
					break;
				}
			}
			if(flag==0){	
				for(int i=1;i<=12;i++){
					if(a>y[i]){
						a-=y[i];
						yue++;
					}else{
						break;
					}
				}
				if(yue==1){
					ri=ri+a;
				}else{
					ri=a;
				}
			}else{
				for(int i=1;i<=12;i++){
					if(a>y1[i]){
						a-=y1[i];
						yue++;
					}else{
						ri=a+ri;
						break;
					}
				}
			}
			cout<<ri<<" "<<yue<<" "<<nian<<" "<<"BC"<<endl;
		}else if(a>x&&a<=(x+x1)){
			ri=1;
			nian=1;
			a=a-x;
			for(;;){
				if((nian)%4!=0&&a>365){
					a-=365;
					nian++;
				}else if((nian)%4==0&&a>366){
					a-=366;
					nian++;
					flag=1;
				}else{
					break;
				}
			}
			if(flag==0){	
				for(int i=1;i<=12;i++){
					if(a>y[i]){
						a-=y[i];
						yue++;
					}else{
						ri=a+ri;
						break;
					}
				}
			}else{
				for(int i=1;i<=12;i++){
					if(a>=y1[i]){
						a-=y1[i];
						yue++;
					}else{
						ri=a+ri;
						break;
					}
				}
			}
			cout<<ri<<" "<<yue<<" "<<nian;
		}else if(a>(x+x1)&&a<=(x+x1+356)){
			ri=0;
			yue=1;
			nian=1;
			a=a-(x+x1);
			for(int i=1;i<=12;i++){
				if(a>=y2[i]){
					a-=y2[i];
					yue++;
				}else{
					ri=ri+a;
					break;
				}
			}
			if(yue==10&&ri>=5&&ri<=14){
				ri+=10;
			}
			cout<<ri<<" "<<yue<<" "<<1582;
		}else{
			a=a-x-x1-356;
			nian=1583;
			for(;;){
				if((nian)%4==0){
					if((nian)%100==0&&(nian)%400!=0){
						if(a>365){
							a-=365;
							nian++;
						}else{
							break;
						}	
					}else{
						if(a>366){
							a-=366;
							nian++;
						}else{
							break;
						}
					}
				}else{
					if(a>365){
						a-=365;
						nian++;
					}else{
						break;
					}
				}
			}
			if(flag==0){	
				for(int i=1;i<=12;i++){
					if(a>y[i]){
						a-=y[i];
						yue++;
					}else{
						ri=a+ri;
						break;
					}
				}
			}else{
				for(int i=1;i<=12;i++){
					if(a>=y1[i]){
						a-=y1[i];
						yue++;
					}else{
						ri=a+ri;
						break;
					}
				}
			}
			cout<<ri<<" "<<yue<<" "<<nian;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
