#include<stdio.h> 
int main() 
{ 
 char str[20]; 
 int len=0, i=0; 
 printf("Enter the word: "); 
 scanf("%s", &str); 
 while(str[i] != '\0') 
 { 
  len ++; 
  i++; 
 } 
 printf("Length of the the word %s is %d", str, len); 
 return 0; 
} 
