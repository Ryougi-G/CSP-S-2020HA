#include<iostream>
#include<cstdio>
using namespace std;
long n,nian1=4713,nian2=1,yue=1,ri=1;
long long r;
void workone()
{
	if(nian1%4==1&&nian1>0){
		if(ri>29&&yue==2&&nian1>0){
			yue++;
			ri-=29;
		}
	    }else
		if(ri>29&&yue==2&&nian1>0){
			yue++;
			ri-=28;
		}
	if(nian2%4==1)
		if(ri>29&&yue==2){
			yue++;
			ri-=29;
		}
		if(nian2%4!=1)
		if(ri>28&&yue==2){
			yue++;
			ri-=28;
		}
	if((yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)&&ri>31){
			ri-=31;
			yue++;
	}else
	if((yue==4||yue==6||yue==9||yue==11)&&ri>30){
		ri-=30;
		yue++;
	}
	if(yue>12&&nian1>0){
		yue-=12;
		nian1--;
	}
	if(nian1==1&&yue>12){
		nian2++;
		nian1=-1;
	}
}
void worktwo()
{
	if(nian2%4==0&&nian2%100!=0||nian2%400==0)
	{
		if(ri>29&&yue==2)
		{
			yue++;
			ri-=29;
		}
	}else
	if(nian2%4!=0)
		if(ri>28&&yue==2)
		{
			yue++;
			ri-=28;
		}
	if((yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)&&ri>31)
	{
		ri-=31;
		yue++;
	}
	if((yue==4||yue==6||yue==9||yue==11)&&ri>30){
		ri-=30;
		yue++;
	}
	if(yue>12){
		yue-=12;
		nian2++;
	}
}
int main ()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	    nian1=4713;nian2=1;yue=1;ri=1;
		cin>>r;
		ri+=r;
	    if(nian1>0||nian2<1582&&yue<10&&ri<5){
	    	do{
	    		workone();
	    	}while(ri>28);
    	}else
	    if(nian2>=1582&&yue>=10&&ri>=5||nian2>=1582){
		    ri+=10;
	    	do{
	    		worktwo();
	    	}while(ri>28);
	    }
	    if(nian1>0)
	    cout<<ri<<' '<<yue<<' '<<nian1<<' '<<"BC";
	    else
	    cout<<ri<<' '<<yue<<' '<<nian2;
	}
	return 0;
}
