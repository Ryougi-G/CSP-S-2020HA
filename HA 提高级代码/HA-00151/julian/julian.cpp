#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q,r,i,j,y,mh[13];
	mh[1]=31;mh[2]=28;mh[3]=31;mh[4]=30;mh[5]=31;mh[6]=30;
	mh[7]=31;mh[8]=31;mh[9]=30;mh[10]=31;mh[11]=30;mh[12]=31;
	cin>>q;
	for(i=1;i<=q;i++)
	{
		cin>>r;
		r++;
		y=0;
		int d=365;
		while(1)
		{
			if(y%4==0)
				d++;
			if(r<d)
				break;
			r=r-d;
			if(y%4==0)
				d--;
			y++;
		}
		if(y%4==0)
			mh[2]=29;
		if(y!=0)
			mh[1]=30;
		y=4713-y;
		j=1;
		while(r>=mh[j])
		{
			r=r-mh[j];
			j++;
		}
		cout<<r<<' '<<j<<' '<<y<<' '<<"BC"<<endl;
	}
}
