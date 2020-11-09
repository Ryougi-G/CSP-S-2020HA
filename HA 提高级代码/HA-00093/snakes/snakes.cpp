#include <bits/stdc++.h>
using namespace std;
int T;
int n;
struct edge
{
  int Id;
  int val;
}a[1001000];
inline bool mycmp(edge x,edge y)
{
  return (x.val>y.val) || (x.val==y.val&&x.Id>y.Id);
}
inline void work_power()
{
  for(int i=1;i<=n;i++)
    a[i].Id=i;
  sort(a+1,a+n+1,mycmp);
  int d=a[1].val-a[3].val;
  if(d<a[2].val)
    puts("3");
  else
    if(d==a[2].val&&a[1].Id<a[2].Id)
      puts("3");
    else
      if(d==a[2].val&&a[1].Id>a[2].Id)
        puts("1");
      else
        if(d>a[2].val)
          puts("1");
}
inline void work_1()
{
  if(n&1)
    printf("%d\n",n);
  else
    printf("%d\n",n/2);
}
int main()
{
  freopen("snakes.in","r",stdin);
  freopen("snakes.out","w",stdout);
  scanf("%d",&T);
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%d",&a[i].val);
  if(n==3)
    work_power();
  else
    work_1();
  T--;
  while(T--)
  {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
	  int x,y;
	  scanf("%d%d",&x,&y);
	  a[x].val=y;
	}
	if(n==3)
	  work_power();
	else
	  work_1();
  }
  return 0;
}
