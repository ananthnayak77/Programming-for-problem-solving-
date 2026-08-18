#include <stdio.h> 
int main() { 
char operator; 
double num1, num2, result; 
printf("Enter an operator (+, -, *, /): "); 
scanf(" %c", &operator);     //&bug
printf("Enter two operands: "); 
scanf("%lf %lf", &num1, &num2);     //&bug
switch(operator) { 
case '+': 
result = num1 + num2;  //==bug
printf("your ans is =%lf",result); 
break; 
case '-': 
result = num1 - num2;   //==bug
printf("your ans is =%lf",result);  
break; 
case '*': 
result = num1 * num2;
printf("your ans is =%lf",result);  
break; 
case '/': 
if(num2 != 0){
result = num1 / num2;
printf("your ans is =%lf",result);}    //{}bug
else{
printf("Division by zero error\n");    //{}bug
result = 0; }
break; 
default :    //:bug
printf("Invalid operator\n"); 
result = 0; 
break; 
} 
printf("Result: %lf\n", result); 
return 0; 
}