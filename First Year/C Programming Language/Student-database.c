#include <stdio.h> 
struct Student  
{ 
    char name[50]; 
    int rollno; 
    float marks[5]; 
    float total; 
    float percentage; 
}; 
int main()  
{ 
    int n, i, j; 
    const char subjects[5][20] = {"English", "Maths", "Computer Science", 
"Science", "2nd Language"}; 
    printf("Enter number of students: "); 
    scanf("%d", &n); 
    struct Student students[n];  
    for (i = 0; i < n; i++)  
    { 
        printf("\nEnter details for Student %d\n", i + 1); 
        printf("Name: "); 
        scanf(" %[^\n]", students[i].name);    
        printf("Roll Number: "); 
        scanf("%d", &students[i].rollno); 
        students[i].total = 0; 
        printf("Enter marks for following subjects out of 100\n"); 
        for (j = 0; j < 5; j++)  
        { 
            printf("Enter marks in %s: ", subjects[j]); 
            scanf("%f", &students[i].marks[j]); 
            students[i].total += students[i].marks[j]; 
        } 
        students[i].percentage = students[i].total / 5.0; 
    } 
    printf("\n--- Student Database ---\n"); 
    for (i = 0; i < n; i++)  
    { 
        printf("\nStudent %d:\n", i + 1); 
        printf("Name: %s\n", students[i].name); 
        printf("Roll Number: %d\n", students[i].rollno); 
        for (j = 0; j < 5; j++)  
        { 
                      printf("%s: %.2f\n", subjects[j], students[i].marks[j]); 
        } 
        printf("Total: %.2f\n", students[i].total); 
        printf("Percentage: %.2f%%\n", students[i].percentage); 
    } 
    return 0; 
} 
