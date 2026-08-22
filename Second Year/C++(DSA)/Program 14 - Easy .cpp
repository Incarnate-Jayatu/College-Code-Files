//Program 14
/* Implement Matrix ADT with operations: 
● Create 
● Display 
● Update 
● Get Element */
#include<iostream>
using namespace std;

class Matrix{
	private:
		int matrix[10][10];
    	int rows, cols;
    public:
		Matrix(){
			rows = 0;
        	cols = 0;
		}	
		void createMatrix()
    	{
        	cout << "Enter number of rows: ";
        	cin >> rows;
        	cout << "Enter number of columns: ";
        	cin>> cols;
        	if(rows>10 || cols>10){
        		cout<<"Row and Column value should be less than 10"<<endl;
			}
			else if(rows<=0 || cols<=0){
				cout<<"Invalid row or column values"<<endl;
				rows =0; cols =0;
			}
			else{
				cout << "Enter matrix elements:\n";
	        	for (int i = 0; i < rows; i++)
	        	{
        	    	for (int j = 0; j < cols; j++)
    	        	{
	                	cin >> matrix[i][j];
            		}
        		}	
			}
    	}
    	void displayMatrix()
   		{
        	if (rows == 0 || cols == 0)
        	{
            	cout << "Matrix is empty.\n";
            	return;
        	}
        	cout << "Matrix:\n";
        	for (int i = 0; i < rows; i++)
        	{
            	for (int j = 0; j < cols; j++)
            	{
                	cout << matrix[i][j] << "\t";
            	}
            	cout << endl;
        	}
    	}
    	void updateElement()
    	{
	        int r, c, value;
        	cout << "Enter row index: ";
        	cin >> r;
        	cout << "Enter column index: ";
        	cin >> c;
        	if (r >= 0 && r < rows && c >= 0 && c < cols)
        	{
            	cout << "Enter new value: ";
            	cin >> value;
            	matrix[r][c] = value;
            	cout << "Element updated successfully.\n";
        	}
        	else if (rows == 0 || cols == 0)
        	{
            	cout << "Matrix is empty.\n";
            	return;
        	}
        	else
        	{
            	cout << "Invalid position.\n";
        	}
    	}
    	void getelement(){
    		if (rows == 0 || cols == 0)
        	{
            	cout << "Matrix is empty.\n";
            	return;
        	}
    		int r, c;
    		cout<<"Enter row index of position: ";
    		cin>>r;
    		cout<<"Enter column index of position: ";
    		cin>>c;
    		cout<<"Element found at your desired position: "<<matrix[r][c]<<endl;
		}
};

int main(){
	Matrix m;
	int choice;
	do{
		cout<<"Select your choice: "<<endl;
		cout<<"1. Create matrix \n2. Display matrix \n3. Update element of matrix \n4. Get element from matrix \n5. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:{
				m.createMatrix();
				break;
			}
			case 2:{
				m.displayMatrix();
				break;
			}
			case 3:{
				m.updateElement();
				break;
			}
			case 4:{
				m.getelement();
				break;
			}
			case 5:{
				cout<<"Exiting Program !!!"<<endl;
				break;
			}
			default:{
				cout<<"Invalid Choice !!!"<<endl;
				break;
			}
		}
	}while(choice!=5);
	return 0;
}