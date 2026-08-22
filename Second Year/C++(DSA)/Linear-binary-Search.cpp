#include<iostream>
using namespace std;

class Array{
	private:
		int arr[20];
		int len, n;
		bool c = true;

		void bubbleSort() {
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - i - 1; j++) {
					if (arr[j] > arr[j + 1]) {
						int temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		}

	public:
		Array(){
			len=0;
			n=0;
		}
		void createarray(){
			cout<<"Enter number of elements in the array: ";
			cin>>n;
			if(n>20 || n<1){
				cout<<"Numbers of elemts should be from 1 to 20"<<endl;
			}
			else{
				cout<<"Enter "<<n<<" elements of the array (Enter elements in ascending order): ";
				for(int i=0; i<n; i++){
					cin>>arr[i];
				}
				len = n;		
			}
		}	
		void displayarray(){
			if(len == 0){
				cout<<"Array is empty!!"<<endl;
			}
			else{
				for(int i=0; i<n; i++){
					cout<<arr[i]<<"\t";
				}
				cout << endl;
			}
		}	
		void linearsearch(int v){
			c = false;
			if(len == 0){
				cout<<"Array is empty!!"<<endl;
			}
			else{
				for(int i=0; i<n; i++){
					if(arr[i] == v){
						cout<<"Position of your value is "<<i+1<<endl;
						c = true;
					}
				}
				if(c == false){
					cout<<"Element not found in array!!"<<endl;
				}
			}		
		}

		void binarysearch(int val){
			if(len == 0){
				cout<<"Array is empty!!"<<endl;
				return;
			}

			bubbleSort();

			int low = 0;
			int high = n - 1;
			bool found = false;

			while (low <= high) {
				int mid = low + (high - low) / 2;

				if (arr[mid] == val) {
					cout << "Element is found at sorted position " << mid + 1 << endl;
					found = true;
					break;
				}
				else if (arr[mid] < val) {
					low = mid + 1;
				}
				else {
					high = mid - 1;
				}
			}

			if (!found) {
				cout << "Element not found in array!!" << endl;
			}
		}
};

int main(){
	int choice, value;
	Array a;
	do{
		cout<<"\nSelect your choice: "<<endl;
		cout<<"1. Create array \n2. Display array \n3. Linear Search \n4. Binary Search \n5. Exit" << endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				a.createarray();
				break;
			case 2:
				a.displayarray();
				break;
			case 3:
				cout<<"Enter value to search: ";
				cin>>value;
				a.linearsearch(value);
				break;
			case 4:
				cout<<"Enter value to search: ";
				cin>>value;
				a.binarysearch(value);
				break;
			case 5:
				cout<<"Exiting Program!!!"<<endl;
				break;
			default:
				cout<<"Invalid Choice!!!"<<endl;
				break;																
		}
	}while(choice!=5);
	return 0;
}
