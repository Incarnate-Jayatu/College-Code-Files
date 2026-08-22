#include<iostream> 
using namespace std; 

class Array{ 
private: 
    int arr[20]; 
    int len, n; 
    bool c = true; 
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
            
            // Automatic Sorting Validation
            bool isSorted = true;
            for(int i = 0; i < n - 1; i++) {
                if(arr[i] > arr[i+1]) {
                    isSorted = false;
                    break;
                }
            }
            
            if(!isSorted) {
                cout << "Error: Elements were not entered in ascending order! Array not created." << endl;
                n = len; // Revert n back to the last valid length
            } else {
                len = n; 
                cout << "Array created successfully!" << endl;
            }
        } 
    } 
    
    void displayarray(){ 
        if(len == 0){ 
            cout<<"Array is empty!!"<<endl; 
        } 
        else{ 
            for(int i=0; i<len; i++){ 
                cout<<arr[i]<<"\t"; 
            } 
            cout << endl; 
        } 
    } 

    // Feature Component: Ordered Insertion
    void insertElement(int val) {
        if(len >= 20) {
            cout << "Array Overflow! Cannot insert more elements." << endl;
            return;
        }
        
        // Find position to insert while maintaining sorted order
        int i = len - 1;
        while(i >= 0 && arr[i] > val) {
            arr[i + 1] = arr[i]; // Shift elements to the right
            i--;
        }
        
        arr[i + 1] = val; // Insert the value
        len++; // Increase active size
        n = len;
        cout << "Element inserted successfully!" << endl;
    }

    // Feature Component: Element Deletion
    void deleteElement(int val) {
        if(len == 0) {
            cout << "Array underflow! Nothing to delete." << endl;
            return;
        }
        
        int pos = -1;
        // Search for the element position
        for(int i = 0; i < len; i++) {
            if(arr[i] == val) {
                pos = i;
                break;
            }
        }
        
        if(pos == -1) {
            cout << "Element not found for deletion!" << endl;
            return;
        }
        
        // Shift remaining elements to the left to overwrite the target
        for(int i = pos; i < len - 1; i++) {
            arr[i] = arr[i + 1];
        }
        
        len--; // Decrease active size
        n = len;
        cout << "Element deleted successfully!" << endl;
    }

    void linearsearch(int v){ 
        c = false; 
        if(len == 0){ 
            cout<<"Array is empty!!"<<endl; 
        } 
        else{ 
            for(int i=0; i<len; i++){ 
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
        int low = 0; 
        int high = len - 1; 
        bool found = false; 
        while (low <= high) { 
            int mid = low + (high - low) / 2; 
            if (arr[mid] == val) { 
                cout << "Element is found at sorted position " << mid + 1 << endl; 
                found = true; 
                break; 
            } else if (arr[mid] < val) { 
                low = mid + 1; 
            } else { 
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
        cout<<"1. Create array \n2. Display array \n3. Linear Search \n4. Binary Search \n5. Insert Element \n6. Delete Element \n7. Exit" << endl; 
        cout<<"Enter your choice: "; 
        cin>>choice; 
        switch(choice){ 
            case 1: a.createarray(); break; 
            case 2: a.displayarray(); break; 
            case 3: cout<<"Enter value to search: "; cin>>value; a.linearsearch(value); break; 
            case 4: cout<<"Enter value to search: "; cin>>value; a.binarysearch(value); break; 
            case 5: cout<<"Enter value to insert: "; cin>>value; a.insertElement(value); break;
            case 6: cout<<"Enter value to delete: "; cin>>value; a.deleteElement(value); break;
            case 7: cout<<"Exiting Program!!!"<<endl; break; 
            default: cout<<"Invalid Choice!!!"<<endl; break; 
        } 
    }while(choice!=7); 
    return 0; 
}
