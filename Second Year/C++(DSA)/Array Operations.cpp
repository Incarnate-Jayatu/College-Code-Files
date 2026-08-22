#include<iostream>
using namespace std;
class Array{
	private:
		int arr[100];
		int len;
	public:
		Array(){                             //Constructor
			len=0;
		}	
		void insertend(int v) {							//function to insert elements at end of array
        	if (len == 10) {
            	cout << "Array is full!!" << endl;
            	return;
        	}
        	arr[len] = v;
        	len++;
		}
    	void insertpos(int p, int v) {                          //function to insert element at a desired position
        	if (len == 10) {
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
        	else {
            	cout << "Invalid position! Insertion not possible." << endl;
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
    	void getelement(int v) {                                     //function to get element's index position
        	if (v >= 0 && v < len) {
            	cout << "Element at Index " << v << " is: " << arr[v] << endl;
        	} 
			else {
            	cout << "Index out of range!" << endl;
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
    void display() {                      //function to display the array
        if (len == 0) {
            cout << "Array is empty!";
        } 
		else {
            cout << "Array elements: ";
            for (int i = 0; i < len; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main(){
	Array a;
	char dochoice;
	int choice, value, position;
	cout<<"Array is empty now."<<endl;
	do{
		cout<<"Select you choice for array: "<<endl;
		cout<<"1. Insert at End\n"<<"2. Insert at Position\n"<<"3. Search for Element\n"<<"4. Get Element at Index\n"<<"5. Update Element\n"<<"6. Display Array\n"<<endl;
		cout<<"Enter you choice:  ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter element to insert: ";
				cin>>value;
				a.insertend(value);
				break;
			case 2:
				cout<<"Enter position you want to enter: ";
				cin>>position;
				cout<<"Enter element to insert: ";
				cin>>value;	
				a.insertpos(position, value);
				break;
			case 3:
				cout<<"Enter element to search: ";
				cin>>value;
				a.searchelement(value);
				break;
			case 4:
				cout<<"Enter index position: ";
				cin>>value;
				a.getelement(value);
				break;
			case 5:
            	cout << "Enter Position: ";
            	cin >> position;
            	cout << "Enter New Value: ";
            	cin >> value;
            	a.update(position, value);
            	break;
            break;	
			case 6:
				a.display();
				break;
			default:
				cout<<"Invalid choice";	
		}
		cout<<"Do you want to continue further with more choices? (Y for yes & N for no):   ";
		cin>>dochoice;
		if(dochoice!='Y')
			cout<<"Exiting Program"<<endl;
	}while(dochoice=='Y');
	return 0;
}