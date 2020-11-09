
#include <bits/stdc++.h>
using namespace std;
//#define ull unsigned long long
const int year = 4713;
const int day = 1;
const int month = 1;
int q;
int a[14]={ 29, 31, 28 , 31 , 30, 31 ,30 ,31 ,31 ,30 ,31 ,30 ,31 };// 59 60
int x = 1461 ;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
//	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	if(q<=1000) {
		string s = "BC";
		for ( register int i =1 ;i<=q;i++) {
			int r;
			scanf("%d",&r);
			int yeart = (r)/x*4;
			int mode = (r)%x;
			int days=0;
			int yue=0;
			if (mode >=0 && mode<= 1095) {
				int l=(mode)/365;
				int j = (mode)%365;
				int k=0;
				while(j>=0) {
					k++;
					j-=a[k];
				}
				yue = k;
				days = a[k] + j ;
				if(yue==1) {
					cout<<days+1<<" "<<yue<<" "<<year-yeart-l<<" "<<s<<endl;
				}
				else cout<<days<<" "<<yue<<" "<<year-yeart-l<<" "<<s<<endl; 
			}
		}	
		return 0;
	}
	

	return 0;
}
