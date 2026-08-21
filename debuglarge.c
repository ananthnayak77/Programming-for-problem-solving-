#include <stdio.h> 
int main() { 
int a, b, c; 
printf("Enter three integers: "); 
scanf("%d %d %d", &a, &b, &c);       //  &cbug
if(a >= b && a >= c) { 
printf("%d is the largest number\n", a); 
} else if(b >= a && b >= c) {    //&bug
printf("%d is the largest number\n", b); 
} else{ 
printf("%d is the largest number\n", c); 
} 
return 0;
} 