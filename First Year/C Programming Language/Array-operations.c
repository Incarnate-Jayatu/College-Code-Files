#include <stdio.h> 
int insert(int arr[], int n, int element, int position); 
int delete(int arr[], int n, int position); 
void search(int arr[], int n, int key); 
void sort(int arr[], int n, int order); // order = 1 → ascending, 2 → descending 
void display(int arr[], int n); // helper to show array after insert/delete/sort
int main()  
{ 
    int arr[10]; 
    int n, choice, element, position, key, order; 
    printf("Enter number of elements (max 10): "); 
    scanf("%d", &n); 
    if (n > 10 || n < 0)  
    { 
        printf("Invalid number of elements!\n"); 
        return 0; 
    } 
    printf("Enter %d elements:\n", n); 
    for (int i = 0; i < n; i++) 
    { 
     scanf("%d", &arr[i]); 
    } 
    printf("\n--- Array Operations Menu ---\n"); 
    printf("1. Insert Element\n"); 
    printf("2. Delete Element\n"); 
    printf("3. Search Element\n"); 
    printf("4. Sort Array\n"); 
    printf("Enter your choice: "); 
    scanf("%d", &choice); 
    switch (choice)  
    { 
        case 1:
            if (n >= 10)  
            { 
                printf("Array is full! Cannot insert.\n"); 
                break; 
            } 
            printf("Enter element to insert: "); 
            scanf("%d", &element); 
            printf("Enter position (1 to %d): ", n + 1); 
            scanf("%d", &position); 
            n = insert(arr, n, element, position); 
            display(arr, n); 
            break; 
        case 2: 
            if (n == 0)  
            { 
                printf("Array is empty! Cannot delete.\n"); 
                break; 
            } 
            printf("Enter position to delete (1 to %d): ", n); 
            scanf("%d", &position); 
            n = delete(arr, n, position); 
            display(arr, n); 
            break; 
        case 3: 
            printf("Enter element to search: "); 
            scanf("%d", &key);
            search(arr, n, key); 
            break; 
        case 4: 
            if (n == 0)  
            { 
                printf("Array is empty! Cannot sort.\n"); 
                break; 
            } 
            printf("Choose sorting order:\n"); 
            printf("1. Ascending Order\n"); 
            printf("2. Descending Order\n"); 
            printf("Enter your choice: "); 
            scanf("%d", &order); 
            if (order == 1 || order == 2)  
            { 
                sort(arr, n, order); 
                printf("Array sorted successfully!\n"); 
                display(arr, n); 
            }  
            else  
            { 
                printf("Invalid choice for order!\n"); 
            } 
            break; 
        default: 
            printf("Invalid choice! Exiting.\n");
         } 
    return 0; 
}

int insert(int arr[], int n, int element, int position)  
{ 
    if (position < 1 || position > n + 1)  
    { 
        printf("Invalid position!\n"); 
        return n; 
    } 
    for (int i = n; i >= position; i--) 
    { 
     arr[i] = arr[i - 1]; 
    } 
    arr[position - 1] = element; 
    n++; 
    printf("Element inserted successfully.\n"); 
    return n; 
}

int delete(int arr[], int n, int position)  
{ 
    if (position < 1 || position > n)  
 { 
        printf("Invalid position!\n"); 
        return n; 
    } 
    for (int i = position - 1; i < n - 1; i++) 
    { 
     arr[i] = arr[i + 1]; 
 }  
    n--; 
    printf("Element deleted successfully.\n"); 
    return n; 
} 

void search(int arr[], int n, int key)  
{ 
    for (int i = 0; i < n; i++)  
 { 
        if (arr[i] == key)  
  { 
            printf("Element %d found at position %d.\n", key, i + 1); 
            return; 
        } 
    } 
    printf("Element not found in the array.\n"); 
}

void sort(int arr[], int n, int order)  
{ 
    int temp; 
    for (int i = 0; i < n - 1; i++)  
 { 
        for (int j = 0; j < n - i - 1; j++)  
  { 
            if ((order == 1 && arr[j] > arr[j + 1]) || (order == 2 && arr[j] < arr[j + 1]))  
   { 
                temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
        } 
    } 
} 

void display(int arr[], int n)  
{ 
    if (n == 0)  
 { 
        printf("Array is empty!\n"); 
        return; 
    } 
    printf("Array elements: "); 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
