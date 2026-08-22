#include<stdio.h>
int main()
{int a=30,b=10,c=5,d=15;
int r1,r2,r3,r4;
r1=(a+b)*c/d;
r2=((a+b)*c)/d;
r3=a+(b*c)/d;
r4=(a+b)*(c/d);
printf("result 1=%d\n",r1);
printf("result 2=%d\n",r2);
printf("result 3=%d\n",r3);
printf("result 4=%d\n",r4);
return 0;
}