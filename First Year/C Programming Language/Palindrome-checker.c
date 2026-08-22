#include<stdio.h> 
int main() 
{ 
 char str[20]; 
 int len = 0, i = 0, palindrome = 1; 
 printf("Enter the word:  "); 
 scanf("%s", &str); 
 while(str[len] != '\0') 
 { 
  len++; 
 } 
 for(i = 0; i < len/2; i++) 
 { 
  char left = str[i]; 
  if(left >= 'A' && left <= 'Z') 
  { 
   left = left + ('a' - 'A'); 
  } 
  char right = str[len-i-1]; 
  if(right >= 'A' && right <= 'Z') 
  { 
   right = right + ('a' - 'A'); 
  } 
  if(left != right) 
  { 
   palindrome = 0; 
   break; 
  } 
 } 
 if(palindrome) 
 { 
  printf("%s is a palindrome word.\n", str); 
 } 
 else 
 { 
  printf("%s is not a palindrome word. \n", str); 
 } 
 return 0; 
} 
