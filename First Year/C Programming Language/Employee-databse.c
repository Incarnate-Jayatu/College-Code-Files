#include <stdio.h> 
// Function to compare strings case-insensitively 
int strEqualIgnoreCase(char str1[], char str2[])  
{ 
    int i = 0; 
    while (str1[i] != '\0' && str2[i] != '\0')  
    { 
        char c1 = str1[i], c2 = str2[i]; 
        // convert to lowercase if uppercase 
        if (c1 >= 'A' && c1 <= 'Z') c1 = c1 + 32; 
        if (c2 >= 'A' && c2 <= 'Z') c2 = c2 + 32; 
        if (c1 != c2) return 0; 
        i++; 
    } 
    return (str1[i] == '\0' && str2[i] == '\0'); 
} 
struct Employee  
{ 
    char name[50]; 
    int id; 
    char department[30]; 
    float salary; 
}; 
 
int main()  
{ 
    int n, i; 
    printf("Enter number of employees: "); 
    scanf("%d", &n); 
    struct Employee employees[n]; 
    for (i = 0; i < n; i++)  
    { 
        printf("\nEnter details for Employee %d\n", i + 1); 
        printf("Name: "); 
        scanf(" %[^\n]", employees[i].name); 
        printf("ID: "); 
        scanf("%d", &employees[i].id); 
        printf("Department (Tech / HR / Sales): "); 
        scanf(" %[^\n]", employees[i].department); 
        printf("Salary: "); 
        scanf("%f", &employees[i].salary); 
    } 
    for (i = 0; i < n; i++)  
    { 
        printf("\nEmployee %d:\n", i + 1); 
        printf("Name: %s\n", employees[i].name); 
        printf("ID: %d\n", employees[i].id); 
        printf("Department: %s\n", employees[i].department); 
        printf("Salary: %.2f\n", employees[i].salary); 
    } 
    return 0; 
} 
