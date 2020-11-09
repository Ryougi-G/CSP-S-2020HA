#include<bits/stdc++.h>
using namespace std;
int iread()
{
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0'; c=getchar();
	}
	return f*x;
}
bool cmp(int x,int y)
{
	return x>y;
}
int T;
long long int m=0,n,s[11000000];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	T=iread();
n=iread(); m=n;
s[0]=99999999999;

		for(int i=1;i<=n;i++)
		{
			s[i]=iread();
		}sort(s+1,s+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(n==2&&s[1]>s[2]){
				s[1]-=s[2]; n--;
			}
			if(s[1]-s[n]>=s[n-1]) {s[1]-=s[n]; n--; 
			}sort(s+1,s+1+n,cmp);
		}
		printf("%lld",n);
		for(int j=2;j<=T;j++)
		{   long long int k=iread();
			for(int i=1;i<=k;i++)
			{
				long long int x;x=iread();
				s[x]=iread();
			}	sort(s+1,s+1+k,cmp); 
			for(int l=1;l<=k;l++)
			{
				if(k==2&&s[1]>s[2]){
			s[1]-=s[2]; k--;
			}
			if(s[1]-s[k]>=s[k-1]) {s[1]-=s[k]; k--; 
			}sort(s+1,s+1+k,cmp);
			}printf("%lld",k);
			}
			
		
	
	fclose(stdin); fclose(stdout);
	return 0;
}
