#include<bits/stdc++.h>
using namespace std;
inline int qr()
{
	int x=0;bool f=1;char ch=getchar();
	while(ch<'0'||ch>'9') 
	{if(ch=='-') f=0;ch =getchar();	}
	while(ch>='0'&&ch<='9') 
	{x=(x<<3)+(x<<1)+(ch^'0');ch =getchar();}
	return f?x:-x;
}
int q,r[100100],tot,flag;
int tg=0,lanian,latot,ladr,fto=0;
int rete[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	int nian=0;
	for(register int i=1;i<=q;i++)
		r[i]=qr();
	sort(r+1,r+q+1);
	for(register int w=1;w<=q;w++)
	{
		nian=0;
		int dr=r[w];
		if(tg==9)
		{
			nian=lanian,tot=latot,dr=dr-r[w-1]+ladr;
			flag=3;
				for(int i=nian;i<=1000000;i++)
				{
				if((i%4==0&&i%100!=0)||(i%400==0))
				{
					if(dr<366)
					{
						flag=1;
						break;
					}
					dr-=366;
					nian++;	
				}
				else
				{
					if(dr<365)
					{
						flag=0;
						break;
					}
					dr-=365;
					nian++;		
				}
				}
				while(dr)
				{
					if(tot>12)
					{
						nian++;
						tot=1;
						fto=1;
					}
					if(tot>12&&fto!=1) 
					{
						break;
					}
					if(tot==2&&dr>rete[tot]&&flag==1)
					{
						dr-=29;
						tot++;
					}	
					else
					{
						if(dr>rete[tot])
						{
							dr-=rete[tot];
							tot++;
						}
						else
						break;
					}				
				}
				printf("%d %d %d\n",dr+10,tot,nian+2);		
		}
		else
		{
		if(dr<=1721387)
		{
			 flag=2;
			for(int i=4712;i>=0;i--)
			{
				if(i%4==0)
				{
					if(dr<366)
					{
						flag=1;
						break;
					}
					dr-=366;
					nian++;	
				}
				else
				{
					if(dr<365)
					{
						flag=0;
						break;
					}
					dr-=365;
					nian++;		
				}
			}
			 tot = 1;
			while(dr)
			{
				if(tot==2&&dr>rete[tot]&&flag==1)
				{
					dr-=29;
					tot++;
				}	
				else
				{
					if(dr>rete[tot])
					{
						dr-=rete[tot];
						tot++;
					}
					else
					break;
				}				
			}
			printf("%d %d %d ",dr+1,tot,(4713-nian));
			printf("BC\n");
		}
		else
		{
			dr-=1721423;
			flag=3;
			for(int i=1;i<=1582;i++)
			{
				if(i%4==0)
				{
					if(dr<366)
					{
						flag=1;
						break;
					}
					dr-=366;
					nian++;	
				}
				else
				{
					if(dr<365)
					{
						flag=0;
						break;
					}
					dr-=365;
					nian++;		
				}
			}
			 tot = 1;
			while(dr)
			{
				if(tot>12) 
				break;
				if(tot==2&&dr>rete[tot]&&flag==1)
				{
					dr-=29;
					tot++;
				}	
				else
				{
					if(dr>rete[tot])
					{
						dr-=rete[tot];
						tot++;
					}
					else
					break;
				}				
			}
			if(dr<=rete[tot])
			{
				printf("%d %d %d\n",dr,tot,nian+1);
			}
			else/////////////////
			{
				flag=3;
				for(int i=1583;i<=9000;i++)
				{
				if((i%4==0&&i%100!=0)||(i%400==0))
				{
					if(dr<366)
					{
						flag=1;
						break;
					}
					dr-=366;
					nian++;	
				}
				else
				{
					if(dr<365)
					{
						flag=0;
						break;
					}
					dr-=365;
					nian++;		
				}
				}
				int tot = 1;
				while(dr)
				{
					if(tot>12) break;
					if(tot==2&&dr>rete[tot]&&flag==1)
					{
						dr-=29;
						tot++;
					}	
					else
					{
						if(dr>rete[tot])
						{
							dr-=rete[tot];
							tot++;
						}
						else
						break;
					}				
				}
				tg=9;lanian=nian,latot=tot,ladr=dr;
				if(nian>1582||(nian==1582&&tot>=10&&dr>=5)||(nian==1582&&tot==10&&dr>=5))
				{
					printf("%d %d %d\n",dr+10,tot,nian+2);
				}	
				else
				printf("%d %d %d\n",dr,tot,nian+2);
			}		
		}
	}
	}
	return 0;
}
