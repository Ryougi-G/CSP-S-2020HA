#include<cstdio>
using namespace std;
int q,i,a,y,yy,m,d,r[100001];
int month[12]={31,59,90,120,151,181,212,243,273,304,334,365};
int main()
{
	freopen("julian.in","r",stdin);
    freopen("julian.out","w",stdout);
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    scanf("%d",&r[i]);
    int bcd=4713*365+1178+1;
    int y4=365*4+1;
    for(i=1;i<=q;i++)
    {
     //if(r[i]<=bcd)
    {
     y=(r[i]/y4)*4;
     yy=(r[i]%y4)/365;
     y=4713-y-yy;
     d=(r[i]%y4)%365;
     m=1;
	 for(a=10;a>=0;a--)
     {
     if(d>=month[a])
      {
     	m=a+2;
     	d=d-month[a];
     	if(m=1)
	  d=d+1;
	  break;
      };
     };printf("%d %d %d BC\n",d,m,y);
    };
    }
    /*else
    {
    	r[i]-=bcd
    }*/
    fclose(stdin);
    fclose(stdout);
	return 0;
};
