#include<bits/stdc++.h>
using namespace std;
int q;
int DAY=1,MONTH=1,YEAR=-4713;
int rnday[20]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int bsrnday[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int rn=366,bsrn=365;
int ture_gl=146097,false_gl=36525;
inline int read()
{
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}
bool isrunnian(int x)
{
	if(x<1582){
		if(x<0)x++;
		if(x%4==0)return 1;
		return 0;
	}else{
		if((x%4==0&&x%100!=0)||x%400==0)return 1;
		return 0;
	}
}
void solve(int x)
{
	if(x>2299161)x+=10;
	int tDAY=1,tMONTH=1,tYEAR=-4713;
	if(x>1721424){
		x-=1721424;
		tYEAR=1;
	}
	while(x){
		if(tYEAR==0)tYEAR++;
		if(tYEAR>=1601&&x>ture_gl){
			if(x%ture_gl){
				tYEAR+=x/ture_gl*400;
				x%=ture_gl;
			}else{
				x--;
				tYEAR+=x/ture_gl*400;
				x%=ture_gl;
				x++;
			}
			continue;
		}
		if(tYEAR!=-1&&-4401<=tYEAR&&tYEAR<=801&&x>false_gl*4){
			x-=false_gl*4;
			tYEAR+=400;
			continue;
		}
		if(tYEAR!=-1&&-4701<=tYEAR&&tYEAR<=1501&&x>false_gl){
			x-=false_gl;
			tYEAR+=100;
			continue;
		}
		if(isrunnian(tYEAR)){
			if(x>rn){
				tYEAR++;
				x-=rn;
				continue;
			}
			int yue=1;
			for(yue=1;yue<=12;yue++)
			if(x>rnday[yue])
				x-=rnday[yue];
			else break;
			printf("%d %d %d",x,yue,abs(tYEAR));
			if(tYEAR<0)printf(" BC\n");
			else printf("\n");
			return ;
		}else{
			if(x>bsrn){
				tYEAR++;
				x-=bsrn;
				continue;
			}
			int yue=1;
			for(yue=1;yue<=12;yue++)
			if(x>bsrnday[yue])
				x-=bsrnday[yue];
			else break;
			printf("%d %d %d",x,yue,abs(tYEAR));
			if(tYEAR<0)printf(" BC\n");
			else printf("\n");
			return ;
		}
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q=read();
	while(q--)
		solve(read()+1);
}
