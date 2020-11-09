#include <algorithm>
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
const int maxN = 1e6 + 10;

struct Node{
	int fir, sec;
	bool operator <(Node b)const{
		return (fir < b.fir) && (sec < b.sec);
	}
};

void doit();

int T, n;
bool flag = false;
int a[maxN];
set <Node> snak;
int main(void){
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	scanf("%d", &T);
	while (T > 0){
		scanf("%d", &n);
		if (flag)
			for (int i = 1; i <= n; i ++){
				int x, y;
				scanf("%d%d", &x, &y);
				a[x] = y;
			}
		else
			for (int i = 1; i <= n; i ++)
				scanf("%d", &a[i]);
		flag = true;
		doit();
		T --;
	}
	return 0;
}

void doit(){
	snak.clear();
	for (int i = 1; i <= n; i ++){
		Node e = {a[i], i};
		snak.insert(e);
	}
	while (true){
		set <Node>::iterator ed, bg;
		bg = snak.begin();
		ed = snak.end();
		ed --;
		int beg = bg->fir, end = ed->fir;
		int pos = ed->sec;
		ed --;
		int end1 = ed->fir;
		ed ++;
		if ((end - end1) > beg){
			end -= end1;
			snak.erase(ed);
			snak.erase(bg);
			Node e = {end, pos};
			snak.insert(e);
		}
		else
			break;
	}
	printf("%d\n", snak.size());
}
