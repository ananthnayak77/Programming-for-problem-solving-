#include <stdio.h> 
int main() { 
int score; 
char grade; 
printf("Enter the score: "); 
scanf("%d", &score);      //&bug
if(score >= 90)  
grade = 'A'; 
else if(score >= 80) 
grade = 'B'; 
else if(score >= 70) 
grade = 'C'; 
else if(score >= 60)   //;bug
grade = 'D'; 
else 
grade = 'F'; 
printf("The grade is: %c \n", grade);        //%cbug
return 0; 
}  