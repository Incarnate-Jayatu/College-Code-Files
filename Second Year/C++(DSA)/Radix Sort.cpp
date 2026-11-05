//RADIX SORT
/* Sorts integers by processing one digit position at a time (from least significant to most significant), 
using a stable Counting Sort as the subroutine 
for each digit — after processing all digit positions, the array is fully sorted.*/
/*When to use: Sorting large collections of fixed-width integers or strings where the number of digits d is small 
relative to log n — common in sorting large ID lists or radix-friendly keys.*/
//Best Case Time Complexity:  O(d(n+b)) 
//Average case Time Complexity:  O(d(n+b))
//Worst Case TIme Complexity:  O(d(n+b))
//Space Complexity: O(n+b)

#include <iostream>
using namespace std;
void countingSortDigit(int a[], int n, int exp){
    int output[100], count[10] = {0};
    for (int i = 0; i < n; i++) count[(a[i]/exp)%10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i-1];
    for (int i = n-1; i >= 0; i--) {
        int digit = (a[i]/exp)%10;
        output[count[digit]-1] = a[i];
        count[digit]--;
    }
    cout<<"\nSorted Array: "<<endl;
    for (int i = 0; i < n; i++) a[i] = output[i];
}
int main() {
    int arr[] = {170,45,75,90,802,24,2,66};
    int n = 8, maxVal = 0;
    cout<<"\nInitial Array: "<<endl;
    for (int i = 0; i < n; i++) cout<<arr[i]<<"\t";
    for (int i = 0; i < n; i++) if (arr[i] > maxVal) maxVal = arr[i];
    for (int exp = 1; maxVal/exp > 0; exp *= 10) countingSortDigit(arr, n, exp);
    for (int i=0;i<n;i++) cout << arr[i] << " ";
}