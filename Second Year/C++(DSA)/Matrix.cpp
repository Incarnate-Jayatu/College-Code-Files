//Matrix Operations
#include<iostream>
using namespace std;

class SingleMatrix{
	private: 
		int rows, cols, value;
		int Mat[10][10];
	public:
		SingleMatrix(){
			rows=0;
			cols=0;
			value=0;
		}	
		
		void creatematrix(){
			cout<<"Enter number of rows: ";
			cin>>rows;
			cout<<"Enter number of columns: ";
			cin>>cols;
			cout<<"Enter "<<rows*cols<<" elements of matrix: ";
			for(int i=0; i<rows; i++){
				for(int j=0; j<cols; j++){
					cin>>Mat[i][j];
				}
			}	
		}
		
		void insertelement(){
			if(rows==0||cols==0){
				cout<<"Matrix is Empty!!"<<endl;
				return;
			}
			else{
				int r, c; 
				cout<<"Enter position you want to insert an element (0-indexed row and column number): ";
				cin>>r>>c;
				cout<<"Enter element you want to insert: ";
				cin>>value;
				Mat[r][c]=value;
			}
		}
		
		void searchelement(){
			if(rows == 0 || cols == 0){
        		cout << "Matrix is empty!!" << endl;
        		return;
   			}
    		cout << "Enter value to search: ";
    		cin >> value;
    		for(int i = 0; i < rows; i++){
	        	for(int j = 0; j < cols; j++){
    	        	if(Mat[i][j] == value){
        	        	cout << "Element found at position: " << i+1 << " rows & " << j+1 << " column" << endl;
            	    	return;
            		}
        		}
    		}
    		cout << "Element not found in the matrix" << endl;	
		}
		
		void deleteelement(){
			if(rows==0||cols==0){
				cout<<"Matrix is empty!!"<<endl;
				return;
			}
			else{
				int r, c;
				cout<<"Enter position of element you want to delete (0-indexed row and column number): ";
				cin>>r>>c;
				Mat[r][c]=0;
			}
		}
		
		void transposematrix(){
			if(rows==0||cols==0){
				cout<<"Matrix is empty!!"<<endl;
				return;
			}
			else{
				int temp[10][10];
				for(int i=0; i<rows; i++){
					for(int j=0; j<cols; j++){
						temp[j][i]=Mat[i][j];
					}
				}
				int temp_dimension = rows;
   				rows = cols;
    			cols = temp_dimension;
				for(int i=0; i<rows; i++){
					for(int j=0; j<cols; j++){
						Mat[i][j]=temp[i][j];
					}
				}
			}
		}
		void uppertriangularmatrix(){ 
    		if(rows==0||cols==0){ 
        		cout<<"Matrix is empty!!"<<endl; 
        		return; 
    		} 
    		else if(rows!=cols){ 
        		cout<<"Non-square matrix can't be used to define upper triangular matrix."<<endl; 
    		} 
    		else{ 
        		bool isUpper = true;
        		for(int i=0; i<rows; i++){ 
            		for(int j=0; j<cols; j++){ 
                		if(i > j){ 
            	        	if(Mat[i][j] != 0){ 
        	                	isUpper = false;
    	                    	break;
	                    	} 
	                	} 
            		} 
            		if(!isUpper) 
						break;
        		} 
        		if(isUpper){
            		cout<<"It is an Upper triangular matrix"<<endl;
        		} 
				else{
            		cout<<"It is not an Upper triangular matrix"<<endl;
        		}
    		} 
		}

		
		void displaymatrix(){
			if(rows==0||cols==0){
				cout<<"Matrix is empty!!"<<endl;
				return;
			}
			else{
				for(int i=0; i<rows; i++){
					for(int j=0; j<cols; j++){ 
						cout<<Mat[i][j]<<"\t";
					}
					cout<<"\n";
				}
			}
		}
};

class DoubleMatrix{
	private:
		int rows1, cols1, rows2, cols2;
		int Mat1[10][10], Mat2[10][10];
	public:
		DoubleMatrix(){
			rows1=0;
			cols1=0;
			rows2=0;
			cols2=0;
		}
		
		void creatematrice(){
			cout<<"Enter number of rows of matrix 1: ";
			cin>>rows1;
			cout<<"Enter number of columns of matrix 1: ";
			cin>>cols1;
			cout<<"Enter "<<rows1*cols1<<" elements of matrix: ";
			for(int i=0; i<rows1; i++){
				for(int j=0; j<cols1; j++){
					cin>>Mat1[i][j];
				}
			}
			cout<<"Enter number of rows of matrix 2: ";
			cin>>rows2;
			cout<<"Enter number of columns of matrix 2: ";
			cin>>cols2;
			cout<<"Enter "<<rows2*cols2<<" elements of matrix: ";
			for(int i=0; i<rows2; i++){
				for(int j=0; j<cols2; j++){
					cin>>Mat2[i][j];
				}
			}
		}
		
		void addmatrice(){
			if(rows1==0||cols1==0||rows2==0||cols2==0){
				cout<<"Matrices can't be added"<<endl;
				return;
			}
			else if(rows1!=rows2||cols1!=cols2){
				cout<<"Matrices with different orders can't be added"<<endl;
				return;
			}
			else{
				int s[10][10];
				int r=rows1, c=cols1;
				for(int i=0; i<r; i++){
					for(int j=0; j<c; j++){
						s[i][j]=Mat1[i][j]+Mat2[i][j];
					}
				}
				cout<<"Matrix obtained after adding both the matrices is: "<<endl;
				for(int i=0; i<r; i++){
					for(int j=0; j<c; j++){
						cout<<s[i][j]<<"\t"; 
					}
					cout<<"\n";
				}
			}
		}
		
		void submatrice(){
			if(rows1==0||cols1==0||rows2==0||cols2==0){
				cout<<"Matrices can't be subtracted"<<endl;
				return;
			}
			else if(rows1!=rows2||cols1!=cols2){
				cout<<"Matrices with different orders can't be subtracted"<<endl;
				return;
			}
			else{
				int s[10][10];
				int r=rows1, c=cols1;
				for(int i=0; i<r; i++){
					for(int j=0; j<c; j++){
						s[i][j]=Mat1[i][j]-Mat2[i][j];
					}
				}
				cout<<"Matrix obtained after subtracting both the matrices is: "<<endl;
				for(int i=0; i<r; i++){
					for(int j=0; j<c; j++){
						cout<<s[i][j]<<"\t"; 
					}
					cout<<"\n";
				}
			}
		}
		
		void mulmatrice(){
			if(rows1 == 0 || cols1 == 0 || rows2 == 0 || cols2 == 0){
				cout << "Matrices are empty! Cannot multiply." << endl;
				return;
			}
			if(cols1 != rows2){
				cout << "Multiplication not possible! Columns of Matrix 1 must equal Rows of Matrix 2." << endl;
				return;
			}
			int p[10][10] = {0};
			for(int i = 0; i < rows1; i++) {
				for(int j = 0; j < cols2; j++) {
					for(int k = 0; k < cols1; k++) {
						p[i][j] += Mat1[i][k] * Mat2[k][j];
					}
				}
			}
			cout << "Matrix obtained after multiplying both matrices is: " << endl;
			for(int i = 0; i < rows1; i++) {
				for(int j = 0; j < cols2; j++) {
					cout << p[i][j] << "\t";
				}
				cout << "\n";
			}
		}
		
		void displaymatrice(){
			cout<<"First matrix is:\n";
			for(int i=0; i<rows1; i++){
				for(int j=0; j<cols1; j++){
					cout<<Mat1[i][j]<<"\t";
				}
				cout<<"\n";
			}
			cout<<"\nSecond matrix is:\n";
			for(int i=0; i<rows2; i++){
				for(int j=0; j<cols2; j++){
					cout<<Mat2[i][j]<<"\t";
				}
				cout<<"\n";
			}	
		}
};

int main(){
	SingleMatrix sm;
	DoubleMatrix dm;
	char choice2, choice3, ch1, ch2, ch3;
	int choice;
	do{
		cout<<"Select your choice: "<<"\n1. Operations on single matrix"<<"\n2. Operations on double matrix"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				do{
					cout<<"Select your choice of operation: "<<"\na. Create a matrix"<<"\nb. Insert an element in matrix";
					cout<<"\nc. Search an element in matrix"<<"\nd. Delete an element in the matrix"<<"\ne. Transpose of matrix"<<"\nf. Identify Upper Triangular matrix ";
					cout<<"\ng. Display matrix"<<endl;
					cout<<"Enter the desired operation on the matrix: ";
					cin>>choice2;
					switch(choice2){
						case 'a': 
							sm.creatematrix(); 
							break;
						case 'b': 
							sm.insertelement(); 
							break;
						case 'c': 
							sm.searchelement(); 
							break;
						case 'd': 
							sm.deleteelement(); 
							break;
						case 'e': 
							sm.transposematrix(); 
							break;
						case 'f':
							sm.uppertriangularmatrix();
							break;
						case 'g': 
							sm.displaymatrix(); 
							break;		
						default: 
							cout<<"Invalid Choice!!"<<endl; 
							break;
					}
					cout<<"Do you want to switch Matrix operation type for double matrices?(Y for yes, N for No): ";
					cin>>ch1;
					if(ch1!='Y')
						cout<<"Exiting Single Matrix Operations"<<endl;					
				}while(ch1!='Y');
				break;
			case 2:
				do{
					cout<<"Select your choice of operation: "<<"\na. Create two matrices"<<"\nb. Add two matrices"<<"\nc. Subtract two matrices";
					cout<<"\nd. Multiply two matrices"<<"\ne. Display matrices"<<endl;
					cout<<"Enter your choice: ";
					cin>>choice3;
					switch(choice3){
						case 'a': 
							dm.creatematrice(); 
							break;
						case 'b': 
							dm.addmatrice(); 
							break;
						case 'c': 
							dm.submatrice(); 
							break;
						case 'd': 
							dm.mulmatrice(); 
							break;
						case 'e': 
							dm.displaymatrice(); 
							break;	
						default: 
							cout<<"Invalid choice!!"<<endl; 
							break;				
					}
					cout<<"Do you want to switch Matrix operation type for double matrices?(Y for yes, N for No): ";
					cin>>ch2;
					if(ch2!='Y')
						cout<<"Exiting Double Matrice Operations"<<endl;
				}while(ch2=='Y');
				break;	
		}
		cout<<"Do you want to switch between matrix type?(Y for yes, N for No): ";
		cin>>ch3;
		if(ch3!='Y')
			cout<<"Exiting Program!!"<<endl;
	}while(ch3=='Y');
	return 0;
}