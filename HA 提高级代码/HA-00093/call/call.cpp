#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
const int maxn=1e5+10;
ll a[maxn];
int mul_[maxn];
int n,m,q;
int Add_[maxn];
int flag1=false;
int flag2=false;
vector<int> v[maxn];
inline void init()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%lld",&a[i]);
  scanf("%d",&m);
}
inline void work_1(int pos,int d)
{
  a[pos]=(a[pos]+d)%mod;
}
inline void work_2(int d)
{
  for(int i=1;i<=n;i++)
    a[i]=a[i]*d%mod;
}
inline void dfs(int x)
{
  for(int i=1;i<v[x].size();i++)
  {
  	int y=v[x][i];
    if(v[y][0]==1)
      work_1(v[y][1],v[y][2]);
    if(v[y][0]==2)
      work_2(v[y][1]);
    if(v[y][0]==3)
      dfs(y);
  }
}
inline void work_power()
{
  for(int i=1;i<=m;i++)
  {
    int opt;
    scanf("%d",&opt);
    if(opt==1)
    {
	  int x,y;
	  scanf("%d%d",&x,&y);
	  v[i].push_back(1);
	  v[i].push_back(x);
	  v[i].push_back(y);
	}
	if(opt==2)
	{
	  int y;
	  scanf("%d",&y);
	  v[i].push_back(2);
	  v[i].push_back(y);
	  flag2=true;
	}
	if(opt==3)
	{
	  int len=0;
	  scanf("%d",&len);
	  v[i].push_back(3);
	  for(int j=1;j<=len;j++)
	  {
	  	int x;
	  	scanf("%d",&x);
	    v[i].push_back(x);
	  }
	}
  }
  scanf("%d",&q);
  for(int i=1;i<=q;i++)
  {
    int x;
    scanf("%d",&x);
    if(v[x][0]==1)
      work_1(v[x][1],v[x][2]);
    if(v[x][0]==2)
      work_2(v[x][1]);
    if(v[x][0]==3)
      dfs(x);
  }
  for(int i=1;i<=n;i++)
    printf("%d ",a[i]);
  cout<<endl;
}
int main()
{
  freopen("call.in","r",stdin);
  freopen("call.out","w",stdout);
  init();
  if(n<=1000)
    work_power();
  else
  {
    for(int i=1;i<=n;i++)
    printf("%d ",a[i]);
    cout<<endl;
  }
  return 0;
}
