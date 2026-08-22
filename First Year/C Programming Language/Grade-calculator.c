#include<stdio.h> 
int main() 
{ 
   float Eng, Sci, Math, Sst, Mar, total, per; 
   printf("Enter marks of English: "); 
   scanf("%f", &Eng); 
   printf("Enter marks of Marathi: "); 
   scanf("%f", &Mar); 
   printf("Enter marks of Science: "); 
   scanf("%f", &Sci); 
   printf("Enter marks of Mathematics: "); 
   scanf("%f", &Math); 
   printf("Enter marks of Social Science: "); 
   scanf("%f", &Sst); 
   total = Eng + Mar + Sci + Math + Sst; 
   per = (total / 500.0) * 100;  
   printf("\nTotal Marks: %.2f / 500.00\n", total); 
   printf("Percentage: %.2f%%\n\n", per); 
   if(per >= 95) 
   { 
       printf("Grade: A\n"); 
       printf("Result: Merit\n"); 
   } 
   else if(per >= 75)  
   { 
       printf("Grade: B\n"); 
       printf("Result: Distinction\n"); 
   } 
   else if(per >= 65)  
   { 
       printf("Grade: C\n"); 
       printf("Result: First Class\n"); 
   } 
    else if(per >= 40)  
   { 
       printf("Grade: D\n"); 
       printf("Result: Second Class\n"); 
   } 
   else if(per >= 35)  
   { 
       printf("Grade: E\n"); 
       printf("Result: Pass Class\n"); 
   } 
   else  
   { 
       printf("Grade: F\n"); 
       printf("Result: Fail\n"); 
   } 
   return 0; 
} 
