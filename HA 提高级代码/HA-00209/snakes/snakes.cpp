#include<bits/stdc++.h>
#define MIN (1 << 31)
using namespace std;
struct snack
{
	int value;
	int number;
	bool operator <(const snack &x) const
	{
		return value < x.value || (value == x.value && number < x.number);
	}
}S[100000];
priority_queue <snack> a;
priority_queue <snack> b;
int main()
{
//*/
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
//*/
	int n, ans;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		if(i == 0)
		{
			ans = k;
			for(int j = 0; j < k; j++)
			{
				scanf("%d", &S[j].value);
				S[j].number = j;
				a.push(S[j]);
				snack temp = S[j];
				temp.value = -temp.value; 
				b.push(temp);
			}
		}
		else
		{
			for(int j = 0; j < k; j++)
			{
				int num;
				scanf("%d", &num);
				scanf("%d", &S[num].value);
				if(S[num].number != MIN)
				{
					a.push(S[num]);
					snack temp = S[num];
					temp.value = -temp.value; 
					b.push(temp);
				}
			}
		}
		snack temp = a.top(), temp1 = b.top();
		temp1.value = -temp1.value;
		a.pop();
		b.pop();
		while(temp.value - temp1.value >= a.top().value || -b.top().value < temp.value - temp1.value)
		{
			S[temp1.number].number = MIN;
			ans--;
			temp1 = b.top();
			temp1.value = -temp1.value;
			b.pop();
			if(temp.value < a.top().value)
			{
				a.push(temp);
				temp = a.top();
				a.pop(); 
			}
		}
		while(!a.empty())
		{
			a.pop();
		}
		while(!b.empty())
		{
			b.pop();
		}
		printf("%d", ans);
		if(i != n - 1)
			printf("\n");
	}
	return 0;
}
