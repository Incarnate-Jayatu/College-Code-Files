#include<stdio.h> 
int main() 
{ 
  int r1, c1, r2, c2, r, c; 
  printf("Enter number of rows of matrix 1: "); 
  scanf("%d", &r1); 
  printf("Enter number of columns of matrix 1: "); 
  scanf("%d", &c1); 
  printf("Enter number of rows of matrix 2: "); 
  scanf("%d", &r2); 
  printf("Enter number of columns of matrix 2: "); 
  scanf("%d", &c2); 
  if(c1 != r2) 
  { 
    printf("Matrix can't be multiplied as they don't satisfy condition for multiplication"); 
  }
  else 
  { 
    int A[r1][c1], B[r2][c2], M[r][c], i, j, k, s = 0; 
    r = r1, c =  c2;    
    printf("\nEnter elements of matrix 1:\n"); 
    for(i=0; i<r1; i++) 
    { 
      for(j=0; j<c1; j++) 
      { 
        scanf("%d", &A[i][j]); 
      } 
    }
    printf("Matrix 1:\n"); 
    for(i=0; i<r1; i++) 
    { 
      for(j=0; j<c1; j++) 
      { 
        printf("%d\t", A[i][j]); 
      } 
      printf("\n"); 
    }    
    printf("\nEnter elements of matrix 2:\n"); 
    for(i=0; i<r2; i++) 
    { 
      for(j=0; j<c2; j++) 
      { 
        scanf("%d", &B[i][j]); 
      } 
    }    
    printf("Matrix 2:\n"); 
    for(i=0; i<r2; i++) 
    { 
      for(j=0; j<c2; j++) 
      { 
        printf("%d\t", B[i][j]); 
      } 
      printf("\n"); 
    }
    for(i=0; i<r1; i++) 
    { 
      for(j=0; j<c2; j++) 
      { 
        for(k=0; k<c1; k++) 
        { 
          s = s + A[i][k]*B[k][j]; 
        } 
      } 
    }
    printf("\n\nMultiplication of the two matrices is:\n"); 
    for(i=0; i<r; i++) 
    { 
      for(j=0; j<c; j++) 
      { 
        printf("%d\t", M[i][j]); 
      } 
      printf("\n"); 
      } 
    } 
  return 0; 
}
