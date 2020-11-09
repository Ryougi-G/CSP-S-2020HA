#include<bits/stdc++.h>
using namespace std;
int su[25],sum;
void change(int x)
{
	if(x/2==0) return;
	sum++;
	change(x/2);
	su[sum]
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	
	return 0;
}
