//Student Records – Write & Read Using fread and fwrite 
#include <stdio.h> 
#include <stdlib.h> 
struct Student  
{ 
    int roll; 
    char name[30]; 
    float marks; 
 }; 
 int main()  
{ 
    FILE *fp; 
    struct Student s; 
    int n, i; 
    fp = fopen("students.dat", "wb"); 
    if (fp == NULL)  
    { 
        printf("Error opening file!\n"); 
        return 1; 
    } 
    printf("Enter number of students: "); 
    scanf("%d", &n); 
    printf("\n--- Enter Student Records ---\n"); 
    for (i = 0; i < n; i++)  
    { 
        printf("\nStudent %d\n", i + 1); 
        printf("Roll: "); 
        scanf("%d", &s.roll); 
        printf("Name: "); 
        scanf("%s", s.name); 
        printf("Marks: "); 
        scanf("%f", &s.marks); 
        fwrite(&s, sizeof(struct Student), 1, fp); 
    } 
    fclose(fp); 
    // Reading data using fread 
    fp = fopen("students.dat", "rb"); 
    if (fp == NULL)  
    { 
        printf("\nError opening file for reading!\n"); 
        return 1; 
    } 
    printf("\n--- Student Records in File ---\n"); 
    while (fread(&s, sizeof(struct Student), 1, fp))  
    { 
        printf("\nRoll: %d\n", s.roll); 
        printf("Name: %s\n", s.name); 
        printf("Marks: %.2f\n", s.marks); 
    } 
    fclose(fp); 
    return 0; 
} 
