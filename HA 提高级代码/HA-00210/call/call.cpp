#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *f1,*f2;
	f1=fopen("call1.in.txt","r");
	f2=fopen("call1.out","w");
	fclose(f1);
	fclose(f2);
	return 0;
}
