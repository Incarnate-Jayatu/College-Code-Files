#include<stdio.h> 
int main() 
{ 
 char str1[20], str2[20], str3[40]; 
 int i = 0, j = 0; 
 printf("Enter the first word: "); 
 scanf("%s", &str1); 
 printf("Enter the second word: "); 
 scanf("%s", &str2); 
 while(str1[i] != '\0') 
 { 
  str3[j] = str1[i]; 
  i++; 
  j++; 
 } 
 i=0; 
 while(str2[i] != '\0') 
 { 
  str3[j] = str2[i]; 
  j++; 
  i++; 
 } 
 str3[j] = '\0'; 
 printf("Concatenated string is %s.", str3); 
 return 0; 
}
