#include <stdio.h>
int main ()
{int a[10],b[10],c[10],n,m,i;
printf("enter the number of elements in array 1=");
scanf("%d",&n);
printf("enter the number of elements in array 2=");
scanf("%d",&m);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<m;i++)
scanf("%d",&b[i]);
if (m==n)
{
    for(i=0;i<n;i++)
    {
        c[i]=a[i]+b[i];
        printf("th sum of array is %d\n",c[i]);
    }    
}
else
{
    printf("arrays of different sizes cannot be added");
}
return 0;
}