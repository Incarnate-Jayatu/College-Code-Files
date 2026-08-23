//Sorting Algorithms
#include<iostream>
using namespace std;

class ArraySort{
	private:
		
		int arr[100];
		int len, count;
		bool sorted;
		
		void swap(int &a, int &b){
			int temp;
			temp = a;
			a = b;
			b = temp;
		}
		
		int partition(int low, int high){
    		int pivot = arr[high];
    		int i = low - 1;
    		for(int j = low; j < high; j++){
        		if(arr[j] <= pivot){
            		i++;
            		swap(arr[i], arr[j]);
        		}
    		}
    		swap(arr[i + 1], arr[high]);
    		return i + 1;
		}

		void quickSortRecursive(int low, int high){
    		if(low < high){
        		int pi = partition(low, high);
        		quickSortRecursive(low, pi - 1);
        		quickSortRecursive(pi + 1, high);
    		}
		}
		
	public:
		
		Array(){
			len =0;
			count=0;
			sorted = false;
		}
		
		void initialiseArray(){
			cout<<"Enter number of elements in your array(Max 100): ";
			cin>>count;
			if(count >0 && count <=100){
				cout<<" Enter array elements: ";
				for(int i=0; i<count; i++){
					cin>>arr[i];
				}
				len = count;
			}
			else{
				cout<<"Invalid number of elements have been entered!!!"<<endl;
				initialiseArray();
			}	
		}
		
		void bubbleSort(){
			if(len==0){
				cout<<"Array is empty !!!"<<endl;
				cout<<"Initialise the array!!!"<<endl;
				initialiseArray();
				return;
			}
			if(sorted == false){
				for(int i=0; i<count-1 && !sorted; i++){
					sorted =true;
					for(int j=0; j<count-i-1; j++){
						if(arr[j]>arr[j+1]){
							swap(arr[j], arr[j+1]);
						}
						sorted = false;
					}
				}
			}
			if(sorted == true){
				cout<<"Array is already sorted!!!"<<endl;
				cout<<"Initialise a new array!!!"<<endl;				
			}
		}
		
		void selectionSort(){
			if(len==0){
				cout<<"Array is empty !!!"<<endl;
				cout<<"Initialise the array!!!"<<endl;
				initialiseArray();
				return;
			}
			if(sorted == false){
				for(int i=0; i<len-1; i++){
					int min = i;
					for(int j=i+1; j<len; j++){
						if(arr[j]<arr[j+1]){
							min = j;
						}
					}
					if(min!=i){
						swap(arr[i], arr[min]);
					}
				}
				sorted = true;
				cout<<"Array has been Sorted using Selection Sort"<<endl;
			}
			if(sorted == true){
				cout<<"Array is already sorted!!!"<<endl;
				cout<<"Initialise a new array!!!"<<endl;				
			}
		}
		
		void insertionSort(){
			if(len==0){
				cout<<"Array is empty !!!"<<endl;
				cout<<"Initialise the array!!!"<<endl;
				initialiseArray();
				return;
			}
			if(sorted == false){
				for(int i=1; i<len; i++){
					int key =arr[i];
					int j=i-1;
					while(j>=0 && arr[j]>key){
						arr[j+1] = arr[j];
						j--;	
					}
					arr[j+1] = key;
				}
				sorted = true;
				cout<<"Array has been Sorted using Insertion Sort"<<endl;
			}
			if(sorted == true){
				cout<<"Array is already sorted!!!"<<endl;
				cout<<"Initialise a new array!!!"<<endl;
			}	
		}
		
		void quickSort(){
			if(len==0){
				cout<<"Array is empty !!!"<<endl;
				cout<<"Initialise the array!!!"<<endl;
				initialiseArray();
				return;
			}
			cout<<"Quick Sort function has not been initialised yet!!!"<<endl;
			if(sorted == false){	
				quickSortRecursive(0, len - 1);
        		sorted = true;
		        cout << "Array has been Sorted using Quick Sort" << endl;
			}
			if(sorted == true){
				cout<<"Array is already sorted!!!"<<endl;
				cout<<"Initialise a new array!!!"<<endl;				
			}
		}
		
		void displayArray(){
			if(sorted == false){
				cout<<"Your initial array:\t";
				for(int i=0; i<count; i++){
					cout<<arr[i]<<" || ";
				}
			}
			else{
				cout<<"Sorted array:\t";
				for(int i=0; i<count; i++){
					cout<<" || "<<arr[i]<<" || ";
				}
			}
		}
};

int main(){
	int choice;
	Array sort;
	
	do{
		cout<<"Select your choice: "<<endl;
		cout<<"1. Initialise array of integers \n2. Use Bubble Sort \n3. Use Selection Sort \n4. Use Insertion Sort \n5. Use Quick Sort \n6. Display array \n7. Exit"<<endl;
		cout<<"Enter you choice:  ";
		cin>>choice;
		switch(choice){
			case 1:{
				sort.initialiseArray();
				break;
			}
			case 2:{
				sort.bubbleSort();				
				break;
			}
			case 3:{
				sort.selectionSort();				
				break;
			}
			case 4:{
				sort.insertionSort();							
				break;
			}
			case 5:{
				sort.quickSort();
				sort.displayArray();				
				break;
			} 
			case 6:{
				sort.displayArray();
				break;
			}
			case 7:{
				cout<<"Exiting Sorting Program !!!"<<endl;			
				break;
			}
			default:{
				cout<<"Invalid Choice !!"<<endl;	
				break;
			}
		}
	}while(choice!=7);
	
	return 0;
}