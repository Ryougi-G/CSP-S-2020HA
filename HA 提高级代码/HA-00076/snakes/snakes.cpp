#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int T,n,a[1000001],b[1000001],sum;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	priority_queue<int, vector<int>, greater<int> > q2;//小顶
	priority_queue<int, vector<int>, less<int> > q1;//dading
	cin>>T>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q1.push(a[i]);
		q2.push(a[i]);
	}
	sum=n;
	while(sum>0)
		{
			int temp1=q1.top();
			int temp2=q2.top();
			q1.pop();
			q2.pop();
			if(temp1-temp2>q2.top())//temp1表示当前最强的蛇 temp2表示当前最弱的蛇 
			{
				q1.push(temp1-temp2);
				sum--;
			}
			else
			{
				q1.push(temp1);
				q2.push(temp2);
				break;
			}
		}
	cout<<sum<<endl;
	T--;
	while(T--)
	{
		if(!q1.empty())
		{
			q1.pop();
		}
		if(!q2.empty())
		{
			q2.pop();
		}
		
		sum=n;
		int k;
		cin>>k;
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			a[x]=y;
		}
		
		for(int i=1;i<=n;i++)
		{
			q1.push(a[i]);
			q2.push(a[i]);
		}
		
		while(sum>0)
		{
			int temp1=q1.top();
			int temp2=q2.top();
			q1.pop();
			q2.pop();
			if(temp1-temp2>=q2.top())//temp1表示当前最强的蛇 temp2表示当前最弱的蛇 
			{
				q1.push(temp1-temp2);
				sum--;
			}
			else
			{
				q1.push(temp1);
				q2.push(temp2);
				break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
