#include <stdio.h>
int main()
{
    int a,b,sum,diff,prod,quo;
    printf("enter the number1 =\n",a);
    printf("enter the number2 =\n",b);
    scanf("%d%d",&a,&b);
    sum=a+b;
    diff=a-b;
    prod=a*b;
    quo=a/b;
    printf("sum of the two given numbers is =%d",sum);
    printf("difference of the two given numbers is =%d",diff);
    printf("product of the two given numbers is =%d",prod);
    printf("quotient of the two given numbers is =%d",quo);
    return 0;
}