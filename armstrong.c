#include<stdio.h>
int main()
{int num,original=num,sum=0,digit;
printf("enter th number=");
scanf("%d",&num);
original=num;
while(num>0)
{digit=num%10;
sum=sum+digit*digit*digit;
num=num/10;
}
if(sum==original)
printf("armstrong number");
else
printf("not armstrong number");
return 0;
}