#include <stdio.h> 
int sod(int n)                      //SUM OF DIGITS FUNCTION 
{ 
    int sum = 0; 
    while (n > 0)  
 { 
        sum += n % 10; 
        n /= 10; 
    } 
    return sum; 
} 
void swap_by_reference(int *ptrA, int *ptrB)           //SWAP BY REFERENCE FUNCTION 
{ 
    int temp = *ptrA; 
    *ptrA = *ptrB; 
    *ptrB = temp; 
} 
void swap_by_value(int a, int b)              //SWAP BY VALUE FUNCTION 
{ 
    int temp; 
    printf("\nBefore swapping (by value): %d, %d", a, b); 
    temp = a; 
    a = b; 
    b = temp; 
    printf("\nAfter swapping (by value): %d, %d", a, b); 
} 
 
 
int GCD(int a, int b)                             //GREATEST COMMON FACTOR FUNCTION 
{ 
    while (b != 0)  
 { 
        int temp = b; 
        b = a % b; 
        a = temp; 
    } 
    return a; 
} 
int LCM(int a, int b)                       //LEAST COMMON MULTIPLE FUNCTION  
{ 
    return (a * b) / GCD(a, b); 
} 
int main()                                       //MAIN FUNCTION 
{ 
    int ch, n1, n2; 
    printf("----- CHOICE CODES -----"); 
    printf("\n 1. Sum of Digits"); 
    printf("\n 2. Swapping Numbers using Call by Value"); 
    printf("\n 3. Swapping Numbers using Call by Reference"); 
    printf("\n 4. GCD & LCM"); 
    printf("\nEnter Your Choice Code:  "); 
    scanf("%d", &ch); 
    switch (ch)                               // START OF SWITCH 
    { 
        case 1: 
            printf("Enter a number: "); 
            scanf("%d", &n1); 
            printf("Sum of digits of %d = %d\n", n1, sod(n1)); 
            break; 
        case 2: 
            printf("Enter two numbers: "); 
            scanf("%d %d", &n1, &n2); 
            swap_by_value(n1, n2); 
            break; 
        case 3: 
            printf("Enter two numbers: "); 
            scanf("%d %d", &n1, &n2); 
            printf("\nBefore swapping (by reference): %d, %d", n1, n2); 
            swap_by_reference(&n1, &n2); 
            printf("\nAfter swapping (by reference): %d, %d", n1, n2); 
            break; 
        case 4: 
            printf("Enter two numbers: "); 
            scanf("%d %d", &n1, &n2); 
            printf("GCD of %d and %d = %d\n", n1, n2, GCD(n1, n2)); 
            printf("LCM of %d and %d = %d\n", n1, n2, LCM(n1, n2)); 
            break; 
        default: 
            printf("\nInvalid Choice Code"); 
            break; 
    } 
    return 0; 
} 
