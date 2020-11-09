#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
int year,month,day;
int q,r;
int gq = (4713*365)+(25*47)+5;
int gh = gq+(1582*365)+(25*15)+20+31*5+30*4+28+15;

int we(int x)
{
	int y,m,d;
	y = x/365;
	m = (x-365*y)/31;
	d = (x-365*y)-m*31;
	//cout<<"y="<<y<<" m="<<m<<" d="<<d<<endl;
	year = 4713-y;
	month = m+1;
	day = d+1; 
	
}
int main()
{
 	freopen("julian.in","r",stdin);
 	freopen("julian.out","w",stdout);
 	cin>>q;
	for(int i=1; i<=q; i++)
	{
		cin>>r;
		if(r<gq)
		{
			we(r);
			cout<<day<<" "<<month<<" "<<year<<" BC"<<endl;
		}
		else if(r>gq && r<gh)
		{
			we(r);
			cout<<day<<" "<<month<<" "<<year<<endl;
		}
		else if(r>gh)
		{
			we(r);
			cout<<day<<" "<<month<<" "<<year<<endl;
		}
		
	}
	
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

/*
3
10
100
1000


11 1 4713 BC
10 4 4713 BC
27 9 4711 BC
*/
