// File Copy Program (Using fread & fwrite). Copies contents of one file into another using block read/write. 
#include<stdio.h> 
#include <stdlib.h> 
int main()  
{ 
    FILE *src, *dest; 
    char sourceFile[50], destFile[50]; 
    char ch; 
    size_t bytesRead; 
    printf("Enter source file name: "); 
    scanf("%s", sourceFile); 
    printf("Enter destination file name: "); 
    scanf("%s", destFile); 
    src = fopen(sourceFile, "rb"); 
    if (src == NULL)  
    { 
        printf("Error: Cannot open source file!\n"); 
        return 1; 
    } 
    dest = fopen(destFile, "wb"); 
    if (dest == NULL)  
    { 
        printf("Error: Cannot create destination file!\n"); 
        fclose(src); 
        return 1; 
    } 
    while ((ch = fgetc(src)) != EOF)  
    { 
        fputc(ch, dest); 
    } 
    printf("File copied successfully.\n"); 
    fclose(src); 
    fclose(dest); 
    return 0; 
 } 
