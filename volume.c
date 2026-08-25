#include<stdio.h>
int main()
{int r,v,a;
printf("enter the radius =");
scanf("%d",&r);
v=(4*3.14*r*r*r)/3;
a=4*3.14*r*r;
printf("volume of sphere=%d\n",v);
printf("surface area of the sphere=%d\n",a);
}