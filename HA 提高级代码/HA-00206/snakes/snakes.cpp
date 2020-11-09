#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	srand(clock());
	cin>>t;
	
	while(t--)
	cout<<rand()%10<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
