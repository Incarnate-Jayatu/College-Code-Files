//Program 15
/* Implement a complete Sparse Matrix ADT supporting: 
● Create 
● Display 
● Addition 
● Transpose 
● Search 
● Insert 
● Delete*/
#include<iostream>
#include<iomanip>
#define MAX 100
using namespace std;

class SparseMatrixADT{
	private: 
		struct Element{
			int row;
			int col;
			int value;
		};
		int rows, cols;
    	int nonZero;
    	Element data[MAX];
	public:
		void create()
    	{
        	cout << "Enter number of rows: ";
        	cin >> rows;
        	cout << "Enter number of columns: ";
        	cin >> cols;
        	cout << "Enter number of non-zero elements: ";
        	cin >> nonZero;
        	cout << "\nEnter Row Column Value\n";
        	for(int i = 0; i < nonZero; i++)
        	{
            	cin >> data[i].row >> data[i].col >> data[i].value;
        	}
    	}
		void displayTriplet()
    	{
    		if(nonZero == 0){
    			cout<<"Sparse Matrix is Empty!!!"<<endl;
    			return;
			}
        	cout << "\nTriplet Representation\n";
        	cout << "Row\tCol\tValue\n";
        	for(int i = 0; i < nonZero; i++)
        	{
            	cout << data[i].row << "\t" << data[i].col << "\t" << data[i].value << endl;
        	}
    	}
    	void displayMatrix()
    	{
    		if(nonZero == 0){
    			cout<<"Sparse Matrix is Empty!!!"<<endl;
    			return;
			}
        	cout << "\nOriginal Matrix\n";
        	for(int i = 0; i < rows; i++)
        	{
            	for(int j = 0; j < cols; j++)
            	{
                    // Find if an element exists at row i, col j
                    int foundValue = 0;
                    for(int k = 0; k < nonZero; k++) {
                        if(data[k].row == i && data[k].col == j) {
                            foundValue = data[k].value;
                            break;
                        }
                    }
                    cout << foundValue << "\t";
            	}
            	cout << endl;
        	}
    	}
    	void add(SparseMatrixADT obj1, SparseMatrixADT obj2)
		{
			 // 1. Check if matrices can be added
    		if(obj1.rows != obj2.rows || obj1.cols != obj2.cols) {
        		cout << "Matrix size mismatch! Cannot add." << endl;
        		return;
    		}
    		// 2. Set dimensions for the current result matrix
    		rows = obj1.rows;
    		cols = obj1.cols;
    		nonZero = 0;
    		int i = 0; // Pointer for obj1
    		int j = 0; // Pointer for obj2
    		// 3. Process both matrices together
    		while(i < obj1.nonZero && j < obj2.nonZero) {
        		// Case A: obj1 element comes first
        		if(obj1.data[i].row < obj2.data[j].row || (obj1.data[i].row == obj2.data[j].row && obj1.data[i].col < obj2.data[j].col)) {
            		data[nonZero] = obj1.data[i];
            		nonZero++;
            		i++;
        		}
		        // Case B: obj2 element comes first
        		else if(obj2.data[j].row < obj1.data[i].row || (obj2.data[j].row == obj1.data[i].row && obj2.data[j].col < obj1.data[i].col)) {
            		data[nonZero] = obj2.data[j];
            		nonZero++;
            		j++;
        		}
        		// Case C: Same row and column index found
        		else {
            		int sum = obj1.data[i].value + obj2.data[j].value;
            		if(sum != 0) { // Store only if result is not zero
		                data[nonZero].row = obj1.data[i].row;
        		        data[nonZero].col = obj1.data[i].col;
                		data[nonZero].value = sum;
		                nonZero++;
		            }
        		    i++;
            		j++;
        		}
    		}
    		// 4. Copy remaining elements from matrix 1 (if any)
    		while(i < obj1.nonZero) {
        		data[nonZero] = obj1.data[i];
        		nonZero++;
        		i++;
    		}
    		// 5. Copy remaining elements from matrix 2 (if any)
    		while(j < obj2.nonZero) {
        		data[nonZero] = obj2.data[j];
        		nonZero++;
        		j++;
    		}
    		cout << "\nAddition completed successfully!" << endl;	
		}
    	void transpose()
    	{
        	cout << "\nTranspose (Triplet Representation)\n";
        	cout << "Row\tCol\tValue\n";
        	for(int c = 0; c < cols; c++)
        	{
            	for(int i = 0; i < nonZero; i++)
            	{
                	if(data[i].col == c)
                	{
                	    cout << data[i].col << "\t" << data[i].row << "\t" << data[i].value << endl;
    	            }
	            }
        	}
    	}
    	void search()
    	{
        	int r, c;
        	cout << "\nEnter row and column to search: ";
        	cin >> r >> c;
        	for(int i = 0; i < nonZero; i++)
        	{
        		if(data[i].row == r && data[i].col == c)
        		{
            		cout << "Value = " << data[i].value << endl;
            		return;
        		}
        	}
        	cout << "Value = 0" << endl;
    	}
    	void insert(){
    		int r, c, v;
			cout << "Enter row and column index of the element to insert/update: ";
			cin >> r >> c;
			cout << "Enter value to insert: ";
			cin >> v;
            if(r >= rows || c >= cols || r < 0 || c < 0) 
			{
                cout << "Invalid Matrix Boundaries !!!" << endl;
                return;
            }
			for(int i = 0; i < nonZero; i++)
			{
				if(data[i].row == r && data[i].col == c)
        		{
            		data[i].value = v;
                    cout << "Value updated successfully." << endl;
            		return;
        		}
			}
            if(nonZero >= MAX) 
			{
                cout << "Matrix Full! Cannot insert." << endl;
                return;
            }
            data[nonZero].row = r;
            data[nonZero].col = c;
            data[nonZero].value = v;
            nonZero++;
            cout << "Element inserted successfully." << endl;
		}
		void deleteelement()
		{
			int r, c;
			cout << "Enter row and column index of the element to delete: ";
			cin >> r >> c;
			for(int i = 0; i < nonZero; i++)
			{
				if(data[i].row == r && data[i].col == c)
        		{
            		for(int j = i; j < nonZero - 1; j++) 
					{
                        data[j] = data[j + 1];
                    }
                    nonZero--;
                    cout << "Element deleted successfully." << endl;
            		return;
        		}
			}
			cout << "Element not found at specified index." << endl;
		}
};

int main(){
	int choice, c2;
	SparseMatrixADT spm, spm1, spm2;
	do{
		cout << "\nSelect your choice: " << endl;
		cout << "1. Create \n2. Display \n3. Add \n4. Transpose \n5. Search \n6. Insert \n7. Delete \n8. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch(choice){
			case 1:{
				spm.create();
				break;
			}
			case 2:{
				cout << "Select your choice: " << endl;
				cout << "1. Triplet format \n2. Matrix Format\n";
				cout << "Enter your choice: ";
				cin >> c2;
				switch(c2){
					case 1:{
						spm.displayTriplet();
						break;
					}
					case 2:{
						spm.displayMatrix();
						break;
					}
					default:{
						cout << "Invalid Choice !!!" << endl;
						break;
					}
				}
				break;
			}
			case 3:{
				cout<<"Creating Sparse Matrix 1: "<<endl;
				spm.create();
				cout<<"Creating Sparse Matrix 2: "<<endl;
				spm1.create();
				spm2.add(spm, spm2);
				break;
			}	
			case 4:{
				spm.transpose();
				break;
			}	
			case 5:{
				spm.search();
				break;
			}
			case 6:{
				spm.insert();
				break;
			}	
			case 7:{
				spm.deleteelement();
				break;
			}
			case 8:{
				cout << "Exiting Program !!!" << endl;
				break;
			}
			default:{
				cout << "Invalid Choice !!!" << endl;
				break;
			}
		}
	}while(choice!=8);
	return 0;
}
