#include<stdio.h>
int main()
{
    int n,rev=0,temp=n,d;
    printf("enter a number");
    scanf("%d",&n);
    while (temp >0)
    {
        d=temp%10;
        rev=rev*10+d;
        temp=temp/10;
    }
    if (rev==n)
    {
        printf("the number is a palindrome");
    }
    else
    {
        printf("the number is not a palindrome");
    }
    return 0;
}