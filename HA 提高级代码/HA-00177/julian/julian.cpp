#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
inline void read(ll &x)
{
	x=0;
	ll f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}	
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	x*=f;
}
int months1[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int months2[13]={0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
	freopen("julian.in", "r", stdin);
	freopen("julian.out", "w", stdout);
	ll q, r;
	read(q);
	ll first=-4713;
	for(int i=1; i<=q; i++)
	{
		read(r);
		if(r<1721424)
		{
			ll w=r/1461;
			ll yu=r%1461;
			ll year=first+w*4;
			int tot=0;
			while(1)
			{
				int days;
				if((year+1)%4==0)
				{
					days=366;
				}else{
					days=365;
				}
				if(tot+days<=yu)
				{
					tot+=days;
					year++;
				}else{
					break;
				}
			}
			int h;
			int yuu=yu-tot;
			for(h=1; h<=12; h++)
			{
				if((year+1)%4==0)
				{
					if(yuu>=months2[h]) yu-=months2[h];
					else break;
				}else{
					if(yuu>=months1[h]) yu-=months1[h];
					else break;
				}
			}
			cout << yuu+1 << " " << h << " " << -year << " BC\n";
		}else if(r<2299161){
			r-=1721424;
			first=1;
			ll w=r/1461;
			r%=1461;
			ll year=first+w*4;
			if(r>=1095){
				r-=1095;
				year=year+3;
				int h;
				for(h=1; h<=12; h++)
				{
					if(r>=months2[h]) r-=months2[h];
					else break;
				}
				cout << r+1 << " " << h << " " << year << endl;
			}else{
				year+=r/365;
				r%=365;
				int h;
				for(h=1; h<=12; h++)
				{
					if(r>=months1[h]) r-=months1[h];
					else break;
				}
				cout << r+1 << " " << h << " " << year << endl;
			}
		}else if(r<=2299177){
			r-=2299161;
			cout << 15 + r << " " << 10 <<  " " << 1582 << endl;
		}else if(r<=2299238){
			r-=2299178;
			int h;
			for(h=11; h<=12; h++)
			{
				if(r>=months1[h]) r-=months1[h];
				else break;
			}
			cout << r+1 << " " << h << " " << 1582 << endl;
		}else if(r<=2305447){
			first=1583;
			r-=2299239;
			ll year=first+r/1461*4;
			r%=1461;
			if(r<365)
			{
				int h;
				for(h=1; h<=12; h++)
				{
					if(r>=months1[h]) r-=months1[h];
					else break;
				}
				cout << r+1 << " " << h << " " << year << endl;
			}else if(r<731){
				int h;
				r-=365;
				year++;
				for(h=1; h<=12; h++)
				{
					if(r>=months2[h]) r-=months2[h];
					else break;
				}
				cout << r+1 << " " << h << " " << year << endl;
			}else{
				r-=731;
				year+=r/365;
				r%=365;
				int h;
				for(h=1; h<=12; h++)
				{
					if(r>=months1[h]) r-=months1[h];
					else break;
				}
				cout << r+1 << " " << h << " " << year << endl;
			}
		}else{
			r-=2305448;
			first=1600;
			ll year=first+r/146097*400;
			r%=146097;
			ll tot=0;
			while(1)
			{
				int days;
				if(year%4==0&&year%100!=0||year%400==0)
				{
					days=366;
				}else{
					days=365;
				}
				if(tot+days<=r)
				{
					tot+=days;
					year++;
				}else break;
			}
			int h;
			ll yu=r-tot;
			for(h=1; h<=12; h++)
			{
				if(year%4==0&&year%100!=0||year%400==0)
				{
					if(yu>=months2[h]) yu-=months2[h];
					else break;
				}else{
					if(yu>=months1[h]) yu-=months1[h];
					else break;
				}
			}
			cout << yu+1 << " " << h << " " << year << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
