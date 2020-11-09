#include<cstdio>
//#include<cassert>
#include<algorithm>
//#include<bits/stdc++.h>

using std::sort;

const int N=1e6+100;

inline bool isodd(int x)
{
	return x==1 || x==3 || x==5 || x==7 || x==8 || x==10 || x==12;
}

inline bool isryear(int y)
{
	int x=0;
	if (y>0) x=y;
	else x=-(y+1);
	if (y<=1582) return x%4==0;
	return (x%4==0 && x%100!=0) || (x%400==0);
}

struct Qry
{
	int r,id,y,m,d;
	bool operator< (const Qry& _) const {return r<_.r;}
	Qry(int r,int id):r(r),id(id),y(0),m(0),d(0){}
	Qry(){}
}q[N];

int ansy[N],ansm[N],ansd[N];

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int Q;
	scanf("%d",&Q);
	for (int i=1,r;i<=Q;++i) scanf("%d",&r),q[i]=Qry(r,i);
	sort(q+1,q+Q+1);
	int r=q[Q].r;
//	fprintf(stderr,"%d",r);
	int y=-4713,m=1,d=1;
	int ptr=1;
	while (q[ptr].r==0) {q[ptr].y=-4713;q[ptr].m=1;q[ptr].d=1;++ptr;}
	for (int i=1;i<=r;++i)
	{
		++d;
		//删掉的日期 
		if (y==1582 && m==10 && d==5) d=15;
		//如果是闰年的二月 
		if (d>=29 && m==2)
		{
			if ((isryear(y) && d==29)==false) ++m,d=1;
		}
		//如果是闰月，有31天 
		else if (isodd(m) && d==32) ++m,d=1;
		//如果平月，则30天 
		else if (!isodd(m) && d==31) ++m,d=1;
		if (m>=13) m=1,++y;
		if (y==0) y=1; 
		while (i==q[ptr].r) q[ptr].y=y,q[ptr].m=m,q[ptr].d=d,++ptr;
//		if (tmp!=i-1) fprintf(stderr,"%d %d\n",tmp,i);
//		tmp=i;
//		if (i>q[ptr].r) {printf("%d  %d %d %d %d",q[ptr].r,i,y,m,d);return 0;}
	}
	
	for (int i=1;i<=Q;++i) ansy[q[i].id]=q[i].y,ansm[q[i].id]=q[i].m,ansd[q[i].id]=q[i].d;
	for (int i=1;i<=Q;++i)
		if (ansy[i]>=1) printf("%d %d %d\n",ansd[i],ansm[i],ansy[i]);
		else printf("%d %d %d BC\n",ansd[i],ansm[i],-ansy[i]);
}
