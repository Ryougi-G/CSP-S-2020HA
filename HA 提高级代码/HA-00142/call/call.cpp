#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<iostream>

#define MAXN 100005

using namespace std;

inline int read(){
	int w=0,f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch>='9'){
		w=(w<<1)+(w<<3)+(ch-48);
	}
	return w*f;
}

int main(void){
	
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	
	/*
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡ 
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡Áå½´ txdy£¡
*/
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cout<<rand()%998244353<<" ";
	}

	return 0;
}


