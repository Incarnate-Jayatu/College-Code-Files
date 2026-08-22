#include<stdio.h> 
int main() 
{ 
    int n; 
    unsigned long long factorial = 1; 
    printf("Enter any number: "); 
    scanf("%d", &n); 
    
 if(n<0) 
    { 
        printf("Error Factorial can't be calculated"); 
    } 
    else 
    { 
        for(int i=1; i<=n; ++i) 
        { 
            factorial=factorial*i; 
        } 
        printf("Factorial of %d = %llu", n, factorial); 
    } 
    return 0; 
}
