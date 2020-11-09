#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int T=0,a[N],s[N],n=0,k=0;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>T;
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	for(int t=1;t<=T;t++)
	{
//		bool flag=0;
		if(t==1)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
				scanf("%d",&a[i]),s[i]=a[i];
		}
		if(t!=1)
		{
			scanf("%d",&k);
			int x,y;
			for(int i=1;i<=k;i++)
			{
				scanf("%d%d",&x,&y);
				a[x]=y;
			}
			for(int i=1;i<=n;i++)
				s[i]=a[i];
//			cout<<endl;
		}
		int head=1,ans=n;
		while(head<n)
		{
			if(head+1==n)
			{
				if(s[n]-s[head]>=0)
					ans--;
				cout<<ans<<endl;
//				flag=1;
				head++;
				continue;
			}
			if(s[n]-s[head]>=s[head+1])
			{
				s[n]-=s[head];//chi le bie de she
//				cout<<n<<" "<<head<<endl;
				head++;//bei chi,tui chu
				ans--;//zong shu liang--
				for(int i=n;i>head;i--)
					if(s[i]<s[i-1])
						swap(s[i],s[i-1]);
					else break;
				continue;
			}
			if(s[n]-s[head]<s[head+1])
			{
				cout<<ans<<endl;
//				cout<<"head "<<head<<endl;
//				for(int i=1;i<=n;i++)
//				cout<<s[i]<<endl;
//				cout<<endl;
				break;
			}
		}
	}
	return 0;
}
