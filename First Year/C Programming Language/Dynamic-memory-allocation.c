#include <stdio.h> 
#include <stdlib.h> 
 int main()  
{ 
    int n; 
    printf("Enter size of array: "); 
    scanf("%d", &n); 
    // Dynamic allocation 
    int *arr = (int *)malloc(n * sizeof(int)); 
    if (arr == NULL)  
    { 
        printf("Memory allocation failed!\n"); 
        return 1; 
    } 
    printf("\nEnter %d elements:\n", n); 
    for (int i = 0; i < n; i++)  
    { 
        scanf("%d", &arr[i]); 
    } 
    printf("\nArray Elements:\n"); 
    for (int i = 0; i < n; i++)  
   { 
        printf("%d ", arr[i]); 
    } 
    // Free memory 
    free(arr); 
    return 0; 
} 
