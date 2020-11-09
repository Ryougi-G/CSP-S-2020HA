#include<bits/stdc++.h>
using namespace std;
long long q,n;
int j,zan;
int a[13]{0,31,0,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","r",stdout);
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int nian=-4713,yue=1,ri=0;
		cin>>n;
		j=0;n=n+1;
		while(n>0)
		{
			if(j==12)
				j=0;
			if(yue==12)//月份满十二进一 
			{
				nian++;
				yue=0;
			}
			j++;
			if(j==2)
			{
				if(nian>=1582&&nian%4==0&&nian%100!=0)
					zan=29;
				else if(nian>=1582&&nian%400==0)
					zan=29;
				else if(nian<=1582&&nian%4==0)
					zan=29;
				else 
					zan=28;
			}
			else 
				zan=a[j];
			if(n-zan>=0)
			{
				yue++;
				n=n-zan;
				if(n-zan>=0&&nian==1528&&yue==10)
					n=n+10;	
			}
			else if(nian==1528&&yue==10&&n+10-zan>=0)
			{
				yue++;
				n=n+10-zan;
			}
			else if(nian==1528&&yue==10&&n+10-zan<0&&n-zan>=-26)
			{
				n=n+10-zan;
				ri=ri+n;
				n=0;
				nian++;
				cout<<ri<<' ';
				cout<<yue<<' ';
				cout<<abs(nian)<<endl;
			}
			else
			{
				ri=ri+n;
				n=0;
				if(nian<0)
				{
					cout<<ri<<' ';
					cout<<yue<<' ';
					cout<<abs(nian)<<' '<<"BC"<<endl;
				}	
				else
				{
					nian++;
					cout<<ri<<' ';
					cout<<yue<<' ';
					cout<<abs(nian)<<endl;
				}
			}
//			cout<<n<<' '<<nian<<' '<<yue<<' '<<ri<<"***"<<endl;
		}
	}
	return 0;
}

