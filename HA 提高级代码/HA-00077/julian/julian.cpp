#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
/*
inline int readd()
{
	int x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if()
	}
}
*/
void js(int &a,int &b,int &c,int j)
{
	//a--;
	while(j>365)
	{
		if(a>1581)
		{
			if(a%400==0||(a%4==0&&a%100!=0))
			{
				j-=366;
			}
			else j-=365;
			a++;
		}
		else
		{
			if(a%4==0)
			{
				j-=366;
			}
			else
			{
				j-=365;
			}
			a++;
			if(a==0) a++;
			if(a==1582) j+=9;
		}
	}//cout<<j<<endl;
	if(a>1581)
	{
		//cout<<123<<endl;
		if(j==365&&!(a%400==0&&(a%4==0&&a%100!=0)))
		{
			a++;return;
		}
		if(a%400==0&&(a%4==0&&a%100!=0))
		{
			while(j>30){
				j-=30;
				b++;
				if(b==2||b==4||b==6||b==8||b==9||b==11) j--;
				if(b==3) j++;
			}
			if(!(b==2||b==4||b==6||b==8||b==9||b==11)&&j>=30)
			{
				b++;
				if(b==3) c+=j-29;
				else c+=j-30;
				return;
			}
			else{
				if(b==3&&j>28)
				{
					b++;c+=j-29;return;
				}
				c+=j;return;
			}
		}
		else
		{
			
			while(j>30)
			{
				j-=30;
				//cout<<j<<endl;
				b++;
				if(b==2||b==4||b==6||b==8||b==9||b==11) j--;
				if(b==3) j+=2;
				
			}
			if(!(b==2||b==4||b==6||b==8||b==9||b==11)&&j>=30)
			{
				b++;
				if(b==3) c+=j-28;
				else c+=j-30;
				return;
			}
			else{
				if(b==3&&j>27)
				{
					b++;c+=j-28;return;
				}
				c+=j;return;
			}
		}	
	}
	else
	{
		if(j==365&&!(a%4==0))
		{
			a++;if(a==0) a++;return;
		}
		
		if(a%4==0)
		{
			while(j>30){
				j-=30;
				b++;
				if(b==2||b==4||b==6||b==8||b==9||b==11) j--;
				if(b==3) j++;
			}
			if(!(b==2||b==4||b==6||b==8||b==9||b==11)&&j>=30)
			{
				b++;
				if(b==3) c+=j-29;
				else c+=j-30;
				return;
			}
			else{
				if(b==3&&j>28)
				{
					b++;c+=j-29;return;
				}
				c+=j;return;
			}
		}
		else
		{
			
			while(j>30)
			{
				j-=30;
				b++;
				if(b==2||b==4||b==6||b==8||b==9||b==11) j--;
				if(b==3) j+=2;
				
			}if(b==4||b==9) j--;
			if(!(b==2||b==4||b==6||b==8||b==9||b==11)&&j>=30)
			{
				b++;
				if(b==3) c+=j-28;
				else c+=j-30;
				return;
			}
			else{
				if(b==3&&j>27)
				{
					b++;c+=j-28;return;
				}
				c+=j;return;
			}
		}			
	}

}
int main()
{
	freopen("julian.in","rb",stdin);
	freopen("julian.out","wb",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0,j=0,ye,da,mo;i<n;++i)
	{
		scanf("%d",&j);
		ye=-4713;mo=1;da=1;
		js(ye,mo,da,j);
		printf("%d %d %d",da,mo,abs(ye));
		if(ye<0) printf(" BC");
		puts("");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
