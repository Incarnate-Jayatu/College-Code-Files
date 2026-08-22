//Access & Modify Array Elements Using Pointers . Increment each element by 5 
#include <stdio.h> 
 int main()  
{ 
    int arr[5] = {10, 20, 30, 40, 50}; 
    int *ptr = arr;  // pointer to first element of array 
    printf("Original Array:\n"); 
    for (int i = 0; i < 5; i++)  
    { 
        printf("arr[%d] = %d\n", i, *(ptr + i)); 
    } 
    // Modify array elements using pointer 
    for (int i = 0; i < 5; i++)  
    { 
        *(ptr + i) = *(ptr + i) + 5; 
    } 
    printf("\nModified Array (each element + 5):\n"); 
    for (int i = 0; i < 5; i++)  
    { 
        printf("arr[%d] = %d\n", i, arr[i]); 
    } 
    return 0; 
 }
