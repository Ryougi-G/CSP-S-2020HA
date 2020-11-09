#include<bits/stdc++.h>
#define LL long long 
#define ull unsigned long long
using namespace std;

int n,m,c,k;
ull fc[68];
ull a[1000005];
int book[66];
ull cnt=0;
map<int,int>mp;

inline int qr()
{
	int x=0,w=1;char a=0;
	while(a<'0'||a>'9'){if(w=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<3)+(x<<1)+(a^48);a=getchar();}
	return x*w;
}

inline ull qrl()
{
	ull x=0,w=1;char a=0;
	while(a<'0'||a>'9'){if(w=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<3)+(x<<1)+(a^48);a=getchar();}
	return x*w;
}

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	fc[0]=1;
	for(register int i=1;i<=63;i++)
		fc[i]=fc[i-1]<<1;	
	n=qrl();
	m=qrl();
	c=qrl();
	k=qrl();
	for(register int i=1;i<=n;i++)
		a[i]=qr();
	for(register int i=1;i<=n;i++)
	{
		ull op=a[i];
		for(register int j=63;j>=0;j--)
			if(op>=fc[j])
			{
				op-=fc[j];
				if(!book[j])
					book[j]=1;
			}
	}
	for(register int i=1;i<=m;i++)
	{
		int q=qr();
		int p=qr();
		if(!book[q])
		{
			book[q]=1;
			cnt++;
		}	
	}
	if(k-cnt==64)
	{
		if(n)
			cout<<(ull)pow((ull)2,(ull)63)-(ull)n+(ull)pow((ull)2,(ull)63)<<endl;
		else
			cout<<"18446744073709551616"<<endl;
	}
	else
		cout<<(ull)pow((ull)2,(ull)k-(ull)cnt)-n<<endl;
	return 0;
}
//2299160
