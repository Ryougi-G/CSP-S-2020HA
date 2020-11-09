#include<cstdio>
#include<iostream>
#define rt register int
using namespace std;
struct snack
{
	int mark,a;
};
snack data[4],s[4];
bool check[4];
bool cmp(const snack&x,const snack&y)
{
	if(x.a>y.a) return true;
	else if(x.a==y.a) return x.mark>y.mark;
}
int main()
{
	freopen("snacks.in","r",stdin);
	freopen("snacks.out","w",stdout);
	int t,n;
	scanf("%ld%ld",&t,&n);
	for(rt i=1;i<=t;i++)
	{
		if(i==1)
		{
			for(rt j=1;j<=3;j++)
			{
				scanf("%ld",&data[j].a);
				data[j].mark=j;
				check[j]=true;
			}
			for(rt j=1;j<=3;j++)
			{
				int z=0,b=0;
				for(rt k=1;k<=3;k++)
					if(check[k] && (data[k].a>z || (data[k].a==z && data[k].mark>b)))
					{
						z=data[k].a;
						b=data[k].mark;
					}
				s[j].a=z;
				s[j].mark=b;
				check[b]=false;
			}
			if(s[1].a-s[3].a>s[2].a || (s[1].a-s[3].a==s[2].a && s[1].mark>s[2].mark)) {printf("1\n");continue;}
			else {printf("3\n");continue;}
			
		}
		else
		{
			int x;
			scanf("%ld",&x);
			for(rt j=1;j<=x;j++)
			{
				int y,z;
				scanf("%ld%ld",&y,&z);
				data[y].a=z;
			}
			for(rt j=1;j<=3;j++) check[j]=true;
			for(rt j=1;j<=3;j++)
			{
				int z=0,b=0;
				for(rt k=1;k<=3;k++)
					if(check[k] && (data[k].a>z || (data[k].a==z && data[k].mark>b)))
					{
						z=data[k].a;
						b=data[k].mark;
					}
				s[j].a=z;
				s[j].mark=b;
				check[b]=false;
			}
			if(s[1].a-s[3].a>s[2].a || (s[1].a-s[3].a==s[2].a && s[1].mark>s[2].mark)) {printf("1\n");continue;}
			else {printf("3\n");continue;}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
