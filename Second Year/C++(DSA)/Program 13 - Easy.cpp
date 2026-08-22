//Program 13
/*Write a program to insert an element in Array ADT at: 
● Beginning 
● End 
● Any specified position */
#include<iostream>
using namespace std;
class Array{
	private:
		int arr[100];
		int len;
		void display(){                      //function to display the array
    	    if (len == 0){
	            cout << "Array is empty!";
        	} 
			else {
            	cout << "Array elements: ";
            	for (int i = 0; i < len; i++) {
            	    cout << arr[i] << "  ";
           		}
        	}
        	cout << endl;
    	}
	public:
		Array(){
			len = 0;
		}
		
		void create(){
			cout<<"Enter number of ellements of array: ";
			cin>>n;
			cout<<"Enter elements of array: ";
			for(int i=0; i<n; i++){
				cin>>arr[i];
				len++;
			}
		}
		
		void insertbeg(int val){
			if (len == 100) {
            	cout << "Array is full!!" << endl;
        	}
        	else if(len==0){
        		cout<<"Array is empty!!"<<endl;
			}
        	else{
        		for (int i = 0; i<len; i++) {					//shift elements to right;
	                arr[i+1] = arr[i];
            	}
            	arr[0] = val;
            	len++;
            	cout << "Element inserted successfully!" << endl;
			}
			 
		}
		
		void insertend(int v) {							//function to insert elements at end of array
        	if (len == 100) {
            	cout << "Array is full!!" << endl;
            	return;
        	}
        	else if(len==0){
        		cout<<"Array is empty!!"<<endl;
			}
			else{
        		arr[len] = v;
        		len++;
        		display();
			}
		}
		
		void insertpos(int p, int v) {                          //function to insert element at a desired position
        	if (len == 100) {
            	cout << "Array is full!!" << endl;
        	} 
        	else if (p >= 0 && p <= len) {
            	for (int i = len; i > p; i--) {					//shift elements to right;
	                arr[i] = arr[i - 1];
            	}
            	arr[p] = v; // Insert the value
            	len++;      // Increment length
            	cout << "Element inserted successfully!" << endl;
        	} 
        	else if(len==0){
        		cout<<"Array is empty!!"<<endl;
			}
        	else {
            	cout << "Invalid position! Insertion not possible." << endl;
        	}
        	display();
    	}	
};

int main(){
	Array a;
	char dochoice;
	int choice, value, position;
	cout<<"Array is empty now."<<endl;
	do{
		cout<<"Select you choice for array: "<<endl;
		cout<<"1. Create a array of integers\n"<<"2. Insert at Beginning\n"<<"3. Insert at End\n"<<"4. Insert at Specified Position\n"<<"5. Exit\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:{
				a.create();
				break;
			}
			case 2:{
				cout<<"Enter element to insert: ";
				cin>>value;
				a.insertbeg(value);
				break;
			}
			case 3:{
				cout<<"Enter element to insert: ";
				cin>>value;
				a.insertend(value);
				break;
			}
			case 4:{
				cout<<"Enter position you want to enter: ";
				cin>>position;
				cout<<"Enter element to insert: ";
				cin>>value;	
				a.insertpos(position, value);
				break;
			}
			case 5:{
				cout<<"Exiting Program!!!"<<endl;
				break;
			}
			default:{
				cout<<"Invalid Choice!!!"<<endl;
				break;
			}
		}
	}while(choice!=4);
}