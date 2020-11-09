#include<bits/stdc++.h>
using namespace std;
int q;
long long r[100010];
int ts[13]={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
cin>>q;
for(int i=1;i<=q;i++)
cin>>r[i];
for(int i=1;i<=q;i++)
{
	int tian=r[i],yue=1,nian=4713,ans=0,qaq=0;
	for( ;qaq=0;)
	{
		for(int j=0;j<=11;j++)
		{
			if(tian<ts[j]){
				qaq=1;
				ts[13]=0;
			}
			else{
				if((nian==1582)&&(ans==1))	ts[9]=23;
			if(nian-1%4==0)	ts[1]=29;
			if((nian>=1583)&&((ans==1)&&((nian%400==0)||((nian%4==0)&&(nian%100!=0)))))	ts[1]=29;
			tian=tian-ts[j];
			yue++;
			if((yue==13)&&(ans==0)){
				nian--;
				yue=1;}
				if(nian==0){
					ans=1;
					nian=1;
				}	
			if((yue==13)&&(ans==1))
			{
				nian++;
				yue=1;
			}
			}			
		}
	}
	tian=tian+1;
	if((nian=1582)&&((ans==1)&&((yue==10)&&(tian==6))))	tian=14;
	if(ans==0)	cout<<tian<<" "<<yue<<" "<<nian<<" "<<"BC"<<endl;
	if(ans==1)	cout<<tian<<" "<<yue<<" "<<nian<<endl;	
}
	return 0;
}
