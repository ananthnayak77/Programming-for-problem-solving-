#include <stdio.h>
int main ()
{int a,b,c;
printf ("enter the num1=\n");
printf ("enter the num2=\n");
printf ("enter the num3=\n");
scanf("%d%d%d",&a,&b,&c);
if (a>=b && a>=c)
{printf("the largest numis %d\n",a);}
else if (b>=a && b>=c)
{printf("the largest numis %d\n",b);}
else
{printf("the largest numis %d\n",c);}
return 0;    
}