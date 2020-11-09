#include<bits/stdc++.h>
using namespace std;
char c[33][10]={"0","1","10","11","100","101","110","111","1000",
"1001","1010","1011","1100","1101","1110","1111","10000","10001",
"10010","10011","10100","10101","10110","10111","11000","11001",
"11010","11011","11100","11101","11110","11111","100000"};
int n,k,m,cc,a[39],rip=0;
bool ca[19],ma[39];
int main()
{
	
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	memset(ca,false,sizeof(ca));
	if(k<=5)
	{
		cin>>n>>m>>cc>>k;
		int kk=pow(2.0,k);
		for(int i=1;i<=n;i++)
		cin>>a[i];
		int p,q;
		for(int i=1;i<=m;i++)
		{
			cin>>p>>q;
			for(int j=1;j<=n;j++)
			{
				if(c[a[j]][p]=='1')
				ca[q]=true;
			}
			if(ca[q])
			for(int j=1;j<=kk;j++)
			{
				if(c[j][p]=='1')
				ma[j]=true;
			}
		}
		for(int i=1;i<=n;i++)
		ma[a[i]]=false;
		for(int i=1;i<=kk;i++)
		if(ma[i])
		rip++;
		cout<<rip<<'\n';
		
		return 0;
	}
	else
	cout<<0<<'\n';
	
	return 0;
}

//R.I.P.
