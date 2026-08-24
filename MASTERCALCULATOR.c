#include<stdio.h>
#include<math.h>
int main()
{int a,b,symb;
double r;
printf("MASTER CALCULATOR\nENTER YOUR HUSTLE\n");
scanf("%d%c%d",&a,&symb,&b);
if(symb=='+')
{r=a+b;
printf("%d + %d = %lf\n",a,b,r);}
else if(symb=='-')
{r=a-b;
printf("%d - %d = %lf\n",a,b,r);}
else if(symb=='*')
{r=a*b;
printf("%d * %d = %lf\n",a,b,r);}
else if(symb=='^')
{r=pow(a,b);
printf("%d ^ %d = %lf\n",a,b,r);}
else if(symb=='%')
{if (b==0)
{printf("modulo by zero is not possible\n");}
else
{r=a%b;}
printf("%d %% %d = %lf\n",a,b,r);}
else if(symb=='/')
{if (b==0)
{printf("division by zero is not possible\n");}
else
{r=a/b;}
{printf("%d / %d = %lf\n",a,b,r);}
}
else
{printf("Invalid operator\n");}
return 0;
}