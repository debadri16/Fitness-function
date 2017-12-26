#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int check_max(int a[],int *c)          //to check if all the digits are 1
{
int i,p=0;
*c=0;
for(i=0;i<10;i++)
	{
	if(a[i]==0)
		{
		p=1;
		(*c)++;
		}
	}
return(p);
}

void copy(int a[],int b[])
{                                         //to copy one number to the other
int i;
for(i=0;i<10;i++)
	a[i]=b[i];
}

void main()
{
int p=0,s=0,t,i,j,count,r,a[10][10];
unsigned long long int m=1;
clrscr();
srand(time(0));
printf("the numbers are-\n");
for(i=0;i<10;i++)
	{
	for(j=0;j<10;j++)
		{
		a[i][j]=rand()%2;
		printf("%d",a[i][j]);
		}
	printf("\n");
	}
printf("press any key to start fliping(display will be cleared)\n");
scanf("%d");
while(m)
	{
	for(i=0;i<10;i++)
		{
		t=rand()%10;
		a[i][t]=!a[i][t];
		p=check_max(a[i],&count);               //to check number of '1's
		if(count>5)
			{
			r=rand()%10;
			p=check_max(a[r],&count);
			if(count<=5)
				copy(a[i],a[r]);
			}
		if(p==0)
			s++;
		}
	if(s==3)                      //to count how many numbers are maximum,
		break;                //in this code we are checking for 3 maximum numbers
	m++;
	s=0;
	clrscr();
	printf("%llu\n",m);
	}
printf("\nat %llu th eteration\n",m);
for(i=0;i<10;i++)
	{
	for(j=0;j<10;j++)
		{
		printf("%d",a[i][j]);
		}
	printf("\n");
	}
getch();
}