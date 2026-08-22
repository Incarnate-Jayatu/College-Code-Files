#include <stdio.h> 
int main()  
{ 
    int rows, cols; 
    printf("Enter the number of rows: "); 
    scanf("%d", &rows); 
    printf("Enter the number of columns: "); 
    scanf("%d", &cols); 
    if(rows != cols) 
    { 
     printf("Matrix of different orders can't be added"); 
    } 
    else 
    { 
       int matrixA[rows][cols], matrixB[rows][cols], sumMatrix[rows][cols]; 
       int i, j; 
       printf("\nEnter the elements of the first matrix:\n"); 
       for (i = 0; i < rows; i++)  
       { 
           for (j = 0; j < cols; j++)  
           { 
             scanf("%d", &matrixA[i][j]); 
           } 
       } 
       printf("\nEnter the elements of the second matrix:\n"); 
       for (i = 0; i < rows; i++)  
       { 
          for (j = 0; j < cols; j++)  
          { 
            scanf("%d", &matrixB[i][j]); 
          } 
       } 
       for (i = 0; i < rows; i++)  
       { 
          for (j = 0; j < cols; j++)  
          { 
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j]; 
          } 
       } 
       printf("\nThe sum of the two matrices is:\n"); 
       for (i = 0; i < rows; i++)  
       { 
          for (j = 0; j < cols; j++)  
          { 
            printf("%d\t", sumMatrix[i][j]); 
          } 
          printf("\n"); // Move to the next line after each row 
       } 
    } 
    return 0; 
}
