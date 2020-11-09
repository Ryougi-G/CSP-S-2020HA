#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 100010;
int n,q,c,temp,x;
int d[MAXN],ca,con[MAXN];
vector<int> st[MAXN];

void deali(int i){
	scanf("%d",&temp);
	st[i].push_back(temp);
	scanf("%d",&temp);
	st[i].push_back(temp);
}

void dealii(int i){
	scanf("%d",&temp);
	st[i].push_back(temp);
}

void dealiii(int i){
	scanf("%d",&temp);
	for(int j=1;j<=temp;j++){
		scanf("%d",&x);
		st[i].push_back(x);	
	}
}

void solvei(int i){
	d[st[i][1-1]] += st[i][2-1];
}

void solveii(int i){
	for(int j=1;j<=n;j++)
		d[j] *= st[i][1-1];
}

void solveiii(int i){
	//printf("%d\n",st[i].size());
	for (int j=0;j<(st[i].size());j++){
		//printf("%d\n",st[i][j]);
		//printf("%d\n",con[st[i][j]]);
		if (con[st[i][j]]==1) solvei(st[i][j]);
		if (con[st[i][j]]==2) solveii(st[i][j]);
		if (con[st[i][j]]==3) solveiii(st[i][j]);
	}
}

int main(){
	freopen ("call.in","r", stdin);
	freopen ("call.out","w", stdout);
	scanf ("%d",&n);
	for (int i=1 ;i<=n;i++)
		scanf("%d",&d[i]);
	scanf("%d",&c);
	for (int i=1;i<=c;i++){
		scanf("%d",&con[i]);
		if (con[i]==1) deali(i);
		if (con[i]==2) dealii(i);
		if (con[i]==3) dealiii(i);
	}
	scanf("%d",&q);
	for	(int i=1;i<=q;i++){
		scanf("%d",&ca);
	//	printf("%d\n",con[ca]);
		if (con[ca]==1) solvei(ca);
		if (con[ca]==2) solveii(ca);
		if (con[ca]==3) solveiii(ca);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",d[i]%998244353);
	return 0;
}
