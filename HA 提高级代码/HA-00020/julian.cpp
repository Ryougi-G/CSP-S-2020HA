#include<bits/stdc++.h>
#define DMY_AK_CSP2020 return 0
using namespace std;
int q;
long long r;
int one_year_run(int x,int &d,int &m){
	if(x<=30){
		d=1+x;
		m=1;
		return 0;
	}else if(x<=59){
		d=x-30;
		m=2;
		return 0;
	}else if(x<=90){
		d=x-59;
		m=3;
		return 0;
	}else if(x<=120){
		d=x-90;
		m=4;
		return 0;
	}else if(x<=151){
		d=x-120;
		m=5;
		return 0;
	}else if(x<=181){
		d=x-151;
		m=6;
		return 0;
	}else if(x<=212){
		d=x-181;
		m=7;
		return 0;
	}else if(x<=243){
		d=x-212;
		m=8;
		return 0;
	}else if(x<=273){
		d=x-243;
		m=9;
		return 0;
	}else if(x<=304){
		d=x-273;
		m=10;
		return 0;
	}else if(x<=334){
		d=x-304;
		m=11;
		return 0;
	}else{
		d=x-334;
		m=12;
		return 0;
	}
}
int one_year_irrun(int x,int &d,int &m){
	if(x<=30){
		d=1+x;
		m=1;
		return 0;
	}else if(x<=59-1){
		d=x-30;
		m=2;
		return 0;
	}else if(x<=90-1){
		d=x-59+1;
		m=3;
		return 0;
	}else if(x<=120-1){
		d=x-90+1;
		m=4;
		return 0;
	}else if(x<=151-1){
		d=x-120+1;
		m=5;
		return 0;
	}else if(x<=181-1){
		d=x-151+1;
		m=6;
		return 0;
	}else if(x<=212-1){
		d=x-181+1;
		m=7;
		return 0;
	}else if(x<=243-1){
		d=x-212+1;
		m=8;
		return 0;
	}else if(x<=273-1){
		d=x-243+1;
		m=9;
		return 0;
	}else if(x<=304-1){
		d=x-273+1;
		m=10;
		return 0;
	}else if(x<=334-1){
		d=x-304+1;
		m=11;
		return 0;
	}else{
		d=x-334+1;
		m=12;
		return 0;
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	while(q--){
		scanf("%lld",&r);
		if(r<=1721423){
			int k1=r/1461;
			r-=k1*1461;
			if(r<=365){
				int x,y;
				k1+=one_year_run(r,x,y);
				printf("%d %d %d BC\n",x,y,4713-4*k1);
			}
			else if(r<=730){
				int x,y;r-=366;
				k1+=one_year_irrun(r,x,y);
				printf("%d %d %d BC\n",x,y,4713-4*k1-1);
			}
			else if(r<=1095){
				int x,y;r-=731;
				k1+=one_year_irrun(r,x,y);
				printf("%d %d %d BC\n",x,y,4713-4*k1-2);
			}else{
				int x,y;r-=1096;
				k1+=one_year_irrun(r,x,y);
				printf("%d %d %d BC\n",x,y,4713-4*k1-3);
			}
		}
		else if(r<=1721424+577736){
			r-=1721424;
			int k1=r/1461;
			r-=k1*1461;
			//cout<<r<<' ';
			if(r<=364){
				int x,y;
				k1+=one_year_irrun(r,x,y);
				printf("%d %d %d\n",x,y,1+4*k1);
			}
			else if(r<=729){
				int x,y;r-=365;
				k1+=one_year_irrun(r,x,y);
				printf("%d %d %d\n",x,y,1+4*k1+1);
			}
			else if(r<=1094){
				int x,y;r-=730;
				k1+=one_year_irrun(r,x,y);
				printf("%d %d %d\n",x,y,1+4*k1+2);
			}else{
				int x,y;r-=1095;
				k1+=one_year_run(r,x,y);
				printf("%d %d %d\n",x,y,1+4*k1+3);
			}
		}
		else if(r<=1721424+577732+82+17*365+4){
			r+=10;
			r-=1721424;
			int k1=r/1461;
			r-=k1*1461;
			//cout<<r<<' ';
			if(r<=364){
				int x,y;
				k1+=one_year_irrun(r,x,y);
				printf("%d %d %d\n",x,y,1+4*k1);
			}
			else if(r<=729){
				int x,y;r-=365;
				k1+=one_year_irrun(r,x,y);
				printf("%d %d %d\n",x,y,1+4*k1+1);
			}
			else if(r<=1094){
				int x,y;r-=730;
				k1+=one_year_irrun(r,x,y);
				printf("%d %d %d\n",x,y,1+4*k1+2);
			}else{
				int x,y;r-=1095;
				k1+=one_year_run(r,x,y);
				printf("%d %d %d\n",x,y,1+4*k1+3);
			}
			
		}
		else{
			r-=1721424+577732+82+17*365+5;
			int k0=r/146097;
			r-=k0*146097;
			int k1=r/36524;
			r-=k1*36524;
			int k3=r/1461;
			r-=k3*1461;
			//cout<<r<<' '<<k0<<' '<<k1<<' '<<k3<<endl;
			if(r<=365){
				int x,y;
				k1+=one_year_run(r,x,y);
				printf("%d %d %d\n",x,y,1600+400*k0+100*k1+4*k3);
			}
			else if(r<=730){
				int x,y;r-=366;
				k1+=one_year_irrun(r,x,y);
				printf("%d %d %d\n",x,y,1601+400*k0+100*k1+4*k3);
			}
			else if(r<=1095){
				int x,y;r-=731;
				k1+=one_year_irrun(r,x,y);
				printf("%d %d %d\n",x,y,1602+400*k0+100*k1+4*k3);
			}else{
				int x,y;r-=1096;
				k1+=one_year_irrun(r,x,y);
				printf("%d %d %d\n",x,y,1603+400*k0+100*k1+4*k3);
			}
		}
	}
	DMY_AK_CSP2020;
}
