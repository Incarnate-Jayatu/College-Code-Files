#include <stdio.h>  
int main()  
 { 
    double num1, num2; 
    printf("Enter the first number: "); 
    scanf("%lf", &num1); 
    printf("Enter the second number: "); 
    scanf("%lf", &num2); 
    printf("\n--- Results ---\n"); 
    printf("Addition:  %.2lf\n", num1 + num2); 
    printf("Subtraction:  %.2lf\n", num1 - num2); 
    printf("Multiplication:  %.2lf\n", num1 * num2); 
    printf("Division:  %.2lf\n", num1 / num2); 
    return 0; 
 }
