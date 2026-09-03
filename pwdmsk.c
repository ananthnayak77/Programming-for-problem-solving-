#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{char pw[10],un[10];
int i=0,n;
printf("Enter username:");
gets(un);
printf("Enter password:");
gets(pw);
for(i=0;pw[i]!='\0';i++)
{pw[i]='*';}
printf("Masked password: %s",pw);
return 0  ;
}
