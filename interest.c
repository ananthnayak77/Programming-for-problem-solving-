#include<stdio.h>
#include<math.h>
int main()
{double p,n,r,si,ci;
printf("enter the principle=");
scanf("%lf",&p);
printf("enter the time=");
scanf("%lf",&n);
printf("enter the rate=");
scanf("%lf",&r);
si=p*n*r/100;
ci=p*(pow((1+r/100),n))-p;
printf("the simple interest is =%2lf\n",si);
printf("the compound interest is =%2lf\n",ci);
return 0;
}