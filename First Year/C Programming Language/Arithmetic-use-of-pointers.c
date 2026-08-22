#include <stdio.h> 
 int main()  
{ 
    int arr[5] = {5, 10, 15, 20, 25}; 
    int *ptr1 = arr;        // points to arr[0] 
    int *ptr2 = arr + 3;    // points to arr[3] 
    printf("Pointer Arithmetic Demonstration:\n"); 
    printf("Value at ptr1 (arr[0]): %d\n", *ptr1); 
    printf("Value at ptr2 (arr[3]): %d\n", *ptr2); 
    // Pointer increment 
    ptr1++; 
    printf("\nAfter ptr1++ (now points to arr[1]): %d\n", *ptr1); 
    // Pointer decrement 
    ptr2--; 
    printf("After ptr2-- (now points to arr[2]): %d\n", *ptr2); 
    // Pointer difference 
    printf("\nDifference between pointers (ptr2 - ptr1): %ld\n", (ptr2 -  
ptr1)); 
    return 0; 
 }
