#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
inline int szread(){
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}
int main(){
	freopen("zoo.in","r",stdin);freopen("zoo.out","w",stdout);
	n=szread();m=szread();c=szread();k=szread();
	
	fclose(stdin);fclose(stdout);
	return 0;
}
