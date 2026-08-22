#include<stdio.h> 
int main() 
{ 
    int no; 
    printf("Enter the number: "); 
    scanf("%d", &no); 
    if(no%2 == 0) 
    { 
        printf("%d is Even Number", no); 
    } 
    else 
    { 
        printf("%d is Odd Number", no); 
    } 
    return 0; 
} 
