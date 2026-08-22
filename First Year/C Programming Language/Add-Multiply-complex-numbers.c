#include <stdio.h> 
struct Complex  
{ 
    int real; 
    int imag; 
}; 
struct Complex addComplex(struct Complex c1, struct Complex c2)  
{ 
    struct Complex result; 
    result.real = c1.real + c2.real; 
    result.imag = c1.imag + c2.imag; 
    return result; 
} 
struct Complex multiplyComplex(struct Complex c1, struct Complex c2)  
{ 
    struct Complex result; 
    result.real = (c1.real * c2.real) - (c1.imag * c2.imag); 
    result.imag = (c1.real * c2.imag) + (c1.imag * c2.real); 
    return result; 
} 
void displayComplex(struct Complex c)  
{ 
    if (c.imag >= 0) 
    { 
     printf("%d + %di\n", c.real, c.imag); 
    }    
    else 
    { 
     printf("%d - %di\n", c.real, -c.imag); 
     }         
} 
int main()  
{ 
    struct Complex c1, c2, result; 
    int choice; 
    printf("Enter first complex number:\n"); 
    printf("Real part: "); 
    scanf("%d", &c1.real); 
    printf("Imaginary part: "); 
    scanf("%d", &c1.imag); 
    printf("\nEnter second complex number:\n"); 
    printf("Real part: "); 
    scanf("%d", &c2.real); 
    printf("Imaginary part: "); 
    scanf("%d", &c2.imag); 
    printf("\nChoose operation:\n"); 
    printf("1. Addition\n"); 
    printf("2. Multiplication\n"); 
    printf("Enter your choice: "); 
    scanf("%d", &choice); 
    switch(choice)  
    { 
        case 1: 
            result = addComplex(c1, c2); 
            printf("\nAddition of complex numbers: "); 
            displayComplex(result); 
            break; 
        case 2: 
            result = multiplyComplex(c1, c2); 
            printf("\nMultiplication of complex numbers: "); 
            displayComplex(result); 
            break; 
        default: 
            printf("Invalid choice!\n"); 
    } 
    return 0; 
} 
