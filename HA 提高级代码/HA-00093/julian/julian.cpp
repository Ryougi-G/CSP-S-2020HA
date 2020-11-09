#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
int q;
struct edge
{
  int Id;
  ll num;
}a[maxn];
int Mon[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int poi_Mon=1;
int poi_Y=4713;
int flag=false;  //是否到了公元以后 
inline int mycmp(edge x,edge y)
{
  return x.num<y.num;
}
inline int check_Yearfir(int x)
{
  if((x-1)%4==0)
    return true;
  return false;
}
inline int check_Year(int x)
{
  if(x%400==0)
    return true;
  else
    if(x%4==0&&x%100!=0)
      return true;
  return false;
}
int main()
{
  freopen("julian.in","r",stdin);
  freopen("julian.out","w",stdout);
  scanf("%d",&q);
  for(int i=1;i<=q;i++)
    scanf("%lld",&a[i].num);
  for(int i=1;i<=q;i++)
  {
  	int flagy=false;
  	int flag1582=false;
  	poi_Mon=1;
    poi_Y=4713;
	ll temp_=a[i].num+1;
	flag=false;
	for(;;)
	  {
	    if(!flag)
	      flagy=check_Yearfir(poi_Y);
	    else
	      flagy=check_Year(poi_Y);
	    if(flagy)
	      Mon[2]=29;
	    if(flag&&poi_Y==1582)
	      Mon[10]=21,flag1582=true;
	    if(temp_<=Mon[poi_Mon])
	    {
	      if(flag1582&&poi_Mon==10)
	        if(temp_>4)
	          temp_+=10;
	      cout<<temp_<<' '<<poi_Mon<<' '<<poi_Y<<' ';
		  if(!flag)
		    puts("BC");
		  else
		    cout<<endl;
		  break;
		}
		temp_=temp_-Mon[poi_Mon];
		Mon[2]=28;
		poi_Mon++;
		if(poi_Mon==13)
		{
		  poi_Mon=1;
		  if(!flag)
		    poi_Y--;
		  else
		    poi_Y++;
		}
		if(poi_Y==0)
		{
		  poi_Y=1;
		  flag=true;
		}
		//cout<<poi_Y<<' '<<flag<<' '<<poi_Mon<<' '<<Mon[poi_Mon]<<endl;
	  }
  }
  return 0;
}
