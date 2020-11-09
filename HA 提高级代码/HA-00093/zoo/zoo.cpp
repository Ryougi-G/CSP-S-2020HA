//分段，n<=20 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,c,k;
const int maxn=1e6+10;
ll a[maxn];
int b[maxn]; 
int tot=0;
int flagb[70];
int w[maxn];  //所有不合法的二进制位 
int flag[70];  //书中的饲料i是否已经采购 
inline void work_1(ll x)
{
  ll temp_=x;
  int cnt=0;
  while(temp_)
  {
    int now_=temp_&1;
    if(now_&&flagb[cnt])
      flag[cnt]=true;
    temp_>>=1;
    cnt++;
  }
}
inline void init()
{
  scanf("%d%d%d%d",&n,&m,&c,&k);
  for(int i=1;i<=n;i++)
    scanf("%lld",&a[i]);
  for(int i=1;i<=m;i++)
  {
    int y;
    scanf("%d%d",&b[i],&y);
    flagb[b[i]]=true;
  }
  for(int i=1;i<=n;i++)
    work_1(a[i]);
}
inline int check_(ll x)
{
  int temp_=x;
  int cnt=0;
  while(temp_)
  {
    int now_=temp_&1;
    if(now_&&(!flag[cnt])&&flagb[cnt])
      return false;
    temp_>>=1;
    cnt++;
  }
  return true;
}
inline void work_power()
{
  int ans=0;
  for(int i=0;i<(1<<k);i++)
  {
    if(check_(i))
      ans++;
  }
  printf("%d\n",ans-n);
}
inline void work_()
{
  ll ans1=0;
  ll ans=(1<<k)-n;
  for(int i=0;i<=k;i++)
  {
    if(!flag[i]&&flagb[i])
      w[++tot]=i;
  }
  if(tot==0)
  {
    printf("%lld\n",ans);
    return;
  }
  sort(w+1,w+tot+1);
  w[tot+1]=k-1;
  ans1+=1LL*(1<<w[1]);
  for(int i=2;i<=tot+1;i++)
  {
    if(w[i]==w[i-1])
      break;
    for(int j=1;j<=i-1;j++)
      ans1+=1LL*(1<<(w[i]-w[j]-1))*(1<<w[j]);
  }
  printf("%lld\n",ans-ans1);
}
int main()
{
  freopen("zoo.in","r",stdin);
  freopen("zoo.out","w",stdout);
  init();
  if(n<=20)
    work_power();
  else
    work_();
  return 0;
}
