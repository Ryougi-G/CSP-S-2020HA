#include<stdio.h>
#include<stdlib.h>
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	FILE *f1,*f2;
	f1=fopen("julian.in","r");
	f2=fopen("julian.out","w");
	long long int a,y=-4713,m=1,d=1;
	long long int k;
	long long int n;
	fscanf(f1,"%lld",&n);
	for(k=0;k<n;k++)
	{
		fscanf(f1,"%lld",&a);
		long long int round=0;
		if(a<=2299160)
		{
			round=(a-a%1461)/1461;
			y+=round*4;
			if(round>=1179)y++;
			long long int left=a%1461;
			if(round==1178&&left>=366)y++;
			int i,j;
			for(i=0;i<4;i++)
			{
				if(i==0&&left<366)break;
				else if(left<365)break;
				if(i==0)left-=366;
				else left-=365;
			}
			y+=i;
			if(i==0)month[1]=29;
			for(j=0;j<12;j++)
			{
				if(left<month[j])break;
				left-=month[j];
			}
			month[1]=28;
			m=j+1;
			d=left+1;
			if(y<0)fprintf(f2,"%lld %lld %lld BC\n",d,m,-y);
			else fprintf(f2,"%lld %lld %lld\n",d,m,y);
		}
		else if(a>=2299161&&a<=2299177)
		{
			fprintf(f2,"%lld 10 1582\n",a-2299146);
		}
		else if(a>=2299178&&a<=2299207)
		{
			fprintf(f2,"%lld 11 1582\n",a-2299177);
		}
		else if(a>=2299208&&a<=2299238)
		{
			fprintf(f2,"%lld 12 1582\n",a-2299207);
		}
		else if(a>=2299239&&a<=2305447)
		{
			y=1583;
			long long int a2=a-2299239;
			round=(a2-a2%1461)/1461;
			y+=round*4;
			long long int left=a2%1461;
			int i,j;
			for(i=0;i<4;i++)
			{
			if(i==1&&left<366)break;
				else if(left<365)break;
				if(i==1)left-=366;
				else left-=365;
			}
			y+=i;
			if(i==1)month[1]=29;
			for(j=0;j<12;j++)
			{
				if(left<month[j])break;
				left-=month[j];
			}
			month[1]=28;
			m=j+1;
			d=left+1;
			fprintf(f2,"%lld %lld %lld\n",d,m,y);
		}
		else if(a>=2305448)
		{
			y=1600;
			long long int a3=a-2305449;
			long long int round1=(a3-a3%146097)/146097;
			long long int left1=a3%146097;
			long long int left2=left1;
			y+=round1*400;
				int flag=0;
			if(left1>=0&&left1<=36524)flag=1;
			else if(left1>=36525&&left1<=73048)
			{
				y+=100;left2=left1-36525;
			}
			else if(left1>=73049&&left1<=109572)
			{
				y+=200;left2=left1-73049;
			}
			else 
			{
				y+=300;left2=left1-109573;
			}
			long long int round2;
			long long int left3;
			if(flag==1)
			{
				round2=(left2-left2%1461)/1461;
				left3=left2%1461;
			}
			else
			{
				if(left2>=58)
				{
					round2=(left2+1-(left2+1)%1461)/1461;
					left3=(left2+1)%1461;
				}
				else
				{
					round2=0;
					left3=left2;
				}
			}
			y+=round2*4;
			int i,j;
			for(i=0;i<4;i++)
			{
				if(i==0&&left3<366&&(round2!=0||flag==1))break;
				else if(left3<365)break;
				if(i==0&&(round2!=0||flag==1))left3-=366;
				else left3-=365;
			}
			if(i==0&&(round2!=0||flag==1))month[1]=29;
			for(j=0;j<12;j++)
			{
				if(left3<month[j])break;
				left3-=month[j];
			}
			month[1]=28;
			y+=i;
			m=j+1;
			d=left3+1;
			fprintf(f2,"%lld %lld %lld\n",d,m,y);
		}
	}
	
	fclose(f1);
	fclose(f2);
	return 0;
}
