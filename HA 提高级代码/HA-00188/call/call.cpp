#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,q,gong[100050];
struct han{
	int typ,num,cal;
	vector<int>diao;
	int qwqqq;
	han()
	{
		typ=0;num=0;cal=0;qwqqq=0;
	}
};
int coushu,len,lenn[100050],cff;
han hanshu[100050];
void run(int kk)
{
	han j=hanshu[kk];
	if(j.typ==1)
	{
		gong[j.num]=((gong[j.num]%998244353)+(j.cal%998244353))%998244353;
	}
	else if(j.typ==2)
	{
		for(int i=1;i<=n;i++)
		{
			gong[i]=((gong[i]%998244353)*(j.cal%998244353))%998244353;
		}
	}
	else if(j.typ==3)
	{
		for(int i=0;i<j.qwqqq;i++)
		{
			run(j.diao[i]);
		}
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>gong[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>hanshu[i].typ;
		int j=hanshu[i].typ;
		if(j==1)
		{
			cin>>hanshu[i].num>>hanshu[i].cal;
		}
		else if(j==2)
		{
			cin>>hanshu[i].cal;
		}
		else if(j==3)
		{
			cin>>cff;
			for(int qq=1;qq<=cff;qq++)
			{
				cin>>coushu;
				hanshu[i].diao.push_back(coushu);
				hanshu[i].qwqqq++;
			}
		}
	}
	cin>>len;
	for(int i=1;i<=len;i++)
	{
		cin>>lenn[i];
		//run(lenn[i]);
	}
	for(int i=1;i<=len;i++)
	{
		//cin>>lenn[i];
		run(lenn[i]);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<gong[i]<<" ";
	}
	return 0;
}
