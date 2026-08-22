//Program 12
/*Implement an Array ADT with the following operations: 
● Create 
● Display 
● Insert 
● Delete 
● Search 
● Update 
● Count */
#include<iostream>
using namespace std;

class Array{
	private:
		int arr[100];
		int len;
		int n;	
	public:
		Array(){
			n=0;
			len=0;	
		}	
		
		void create(){
			cout<<"Enter number of elements in the array: ";
			cin>>n;
			cout<<"Enter "<<n<<" elements of array: ";
			for(int i=0; i<n; i++){
				cin>>arr[i];
				len++;
			}
		}
		
		void display()
    	{
        	if (len == 0)
        	{
            	cout << "Array is empty." << endl;
            	return;
        	}
        	cout << "Array Elements: ";
        	for (int i = 0; i < len; i++)
        	{
            	cout << arr[i] << " ";
        	}
        	cout << endl;
    	}
		
		void insert(int val){
        	if(len==100){
        		cout<<"Array is full. "<<endl;
        		return;
			}
			else{
				arr[len] = val;
        		len++;
			}
		}
		
		void searchelement(int v) {                                //function to search an element in the array
        	bool found = false;
        	for (int i = 0; i < len; i++) {
            	if (arr[i] == v) {
                	cout << "Your desired element is found at index " << i << " of the array." << endl;
                	found = true;
                	break; // Stop searching once found
            	}
        	}
        	if (!found) {
            	cout << "Element not found in the array." << endl;
        	}
    	} 
    	
    	 void update(int pos, int value)      //function to update element in the array
    	{
        	if (pos < 0 || pos >= len)
        	{
            	cout << "Invalid Position!" << endl;
            	return;
        	}
        	arr[pos] = value;
        	cout << "Element Updated Successfully." << endl;
    	}
    	
    	void deleteAtPosition(int pos)
    	{
        	if (len == 0)
        	{
            	cout << "Array is Empty!" << endl;
            	return;
        	}
        	if (pos < 0 || pos >= len)
        	{
            	cout << "Invalid Position!" << endl;
            	return;
        	}
        	for(int i = pos; i < len-1; i++)
        	{
            	arr[i] = arr[i + 1];
        	}
        	len--;
        	cout << "Element Deleted Successfully." << endl;
    	}
    	
    	void count(){
    		cout<<"Count of elements in array: "<<len;
		}
		
};

int main(){
	Array a;
	int choice, value, position;
	do{
		cout<<"Select your choice: "<<endl;
		cout<<"1. Create an array \n2. Display array \n3. Insert an element at end \n4. Delete at position \n5. Search an element \n6. Update an element \n7. Elements count \n8. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:{
				a.create();
				break;
			}
			case 2:{
				a.display();
				break;
			}
			case 3:{
				cout<<"Enter value to be placed at end: ";
				cin>>value;
				a.insert(value);
				break;
			}
			case 4:{
				cout<<"Enter position of element to delete(0-indexed): ";
				cin>>position;
				a.deleteAtPosition(position);
				break;
			}
			case 5:{
				cout<<"Enter element to search: ";
				cin>>value;
				a.searchelement(value);
				break;
			}
			case 6:{
				cout<<"Enter position of element to be inserted (0-indexed):  ";
				cin>>position;
				cout<<"Enter value to update:  ";
				cin>>value;
				a.update(position, value);
				break;
			}
			case 7:{
				a.count();
				break;
			}
			case 8:{
				cout<<"Exiting Program !!!"<<endl;
				break;
			}
			default:{
				cout<<"Invalid Choice !!!"<<endl;
				break;
			}
		}
	}while(choice!=8);
	return 0;
}