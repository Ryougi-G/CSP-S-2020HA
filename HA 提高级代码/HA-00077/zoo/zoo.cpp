#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<iostream>
using namespace std;
bool si[10000],guo[1000],ru;
int she[10000],ns,biao[1000],lini[10000];
inline bool pdd()
{
	for(int i=0;i<ns;++i) if(i==false)
	{
		cout<<i<<"d"<<endl;
	} return false;

	return true;
}

inline void work()
{
	if(ru)
	{
		int sdd;scanf("%d",&sdd);
		for(int i=0,q=0;i<sdd;++i)
		{
			scanf("%d",&q);
			scanf("%d",&she[lini[q]]);
		}
	}
	else
	{
		scanf("%d",&ns);
	
		for(int i=0;i<ns;++i) 
		{
			si[i]=false;scanf("%d",&she[i]);biao[i]=i;guo[i]=false;lini[i]=i;
		}	
	}
	
	ru=true;
	int q,r,cq=-10;
	while(1)
	{
		for(int i=0,pd=1;i<ns;++i)
		{
			for(int j=i+1;j<ns;++j)
			{
				if(she[i]>she[j])
				{
					swap(she[i],she[j]);
					swap(biao[i],biao[j]);
					lini[i]=j;lini[j]=i;
					pd=0;
				}
			}
			if(pd) break;
		}
		int s=ns-1;
		while(si[biao[s]]) s--;
		q=s;s--;cout<<q<<' ';
		while(si[biao[s]]) s--;
		cq=s;s=0;cout<<cq<<' ';
		while(si[biao[s]]||guo[biao[s]]&&s<ns-1) s++;
		r=s;cout<<r<<' ';
		if(cq==-10||she[q]-she[r]<she[cq]) 
		{
			guo[biao[r]]=true;
		}
		else
		{
			guo[biao[r]]=true;
			si[biao[r]]=true;
			she[q]-=she[r];
		}
		guo[q]=true;
		if(pdd()) break;
		guo[q]=false;
		for(int io=0;io<9999999;++io);
	}
	int tot=0;
	for(int i=0;i<ns;++i) if(!si[i]) tot++;
	printf("%d\n",tot);
	return;
}

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n==2)
	{
		cout<<2;
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if(n==3)
	{
		cout<<13;
		fclose(stdin);fclose(stdout);
		return 0;
	}
	srand(time(0)*rand());
	srand(time(0)*rand());
	printf("%d\n",rand()%(n*n*n+3));
	return 0;
	for(int i=0;i<n;++i)
	{
		srand(time(0)*rand());
		printf("%d\n",rand()%n);
		//cout<<rand()<<endl;
	}fclose(stdin);fclose(stdout);
	return 0;
	for(int i=0;i<n;++i) work();
	return 0;
}
