//Polynomial ADT
#include<iostream>
#include<cmath>					//Header file to use the power function
using namespace std;

class Polynomial{                     //class Polynomial 
	private:
		struct Term{				//structure definition
			int coeff;
			int exp;
		};
		int n;
		Term Polyarr[200];
	public:
		Polynomial(){               //constructor
			n=0;
		}	
		
		void create(){                //function to create polynomial
			cout<<"Enter number of terms: ";
			cin>>n;
			cout<<"Share data in Descending Order Only"<<endl;
			for(int i=0; i<n; i++){
				cout<<"Enter Coefficient of the term: ";
				cin>>Polyarr[i].coeff;
				cout<<"Enter Exponent of the term: ";
				cin>>Polyarr[i].exp;
			}
		}
		
		Polynomial add(Polynomial a, Polynomial b){       //function to add two polynomials
			Polynomial result;
			int i=0, j=0, k=0;
			while(i<a.n && j<b.n){
				if(a.Polyarr[i].exp==b.Polyarr[j].exp){
					result.Polyarr[k].coeff = a.Polyarr[i].coeff + b.Polyarr[j].coeff;
					result.Polyarr[k].exp = a.Polyarr[i].exp;
					i++; j++; k++;
				}
				else if(a.Polyarr[i].exp>b.Polyarr[j].exp){
					result.Polyarr[k] = a.Polyarr[i];
					i++; k++;					
				}
				else{
					result.Polyarr[k] = b.Polyarr[j];
					j++; k++;
				}
			}
			while(i<a.n){
				result.Polyarr[k] = a.Polyarr[i];
				i++; k++;
			}
			while(j<b.n){
				result.Polyarr[k] = b.Polyarr[j];
				j++; k++;
			}
			result.n = k;
			return result;
		}
		
		Polynomial sub(Polynomial c, Polynomial d){					//function to subtract two polynomials
			Polynomial result;
			int i=0, j=0, k=0;
			while(i<c.n && j<d.n){
				if(c.Polyarr[i].exp==d.Polyarr[j].exp){
					result.Polyarr[k].coeff = c.Polyarr[i].coeff - d.Polyarr[j].coeff;
					result.Polyarr[k].exp = c.Polyarr[i].exp;
					i++; j++; k++;
				}
				else if(c.Polyarr[i].exp>d.Polyarr[j].exp){
					result.Polyarr[k] = c.Polyarr[i];
					i++; k++;					
				}
				else{
					result.Polyarr[k].coeff = -d.Polyarr[j].coeff;
    				result.Polyarr[k].exp = d.Polyarr[j].exp;
    				j++; k++;
				}
			}
			while(i<c.n){
				result.Polyarr[k] = c.Polyarr[i];
				i++; k++;
			}
			while(j<d.n){
				result.Polyarr[k].coeff = -d.Polyarr[j].coeff;
    			result.Polyarr[k].exp = d.Polyarr[j].exp;
    			j++;
    			k++;
			}
			result.n = k;
			return result;
		}
		
		Polynomial multiply(Polynomial a, Polynomial b){       //function to multiply two polynomials
			Polynomial result;
			// Edge case: if either polynomial is empty, return an empty polynomial
			if(a.n == 0 || b.n == 0){
				result.n = 0;
				return result;
			}
			// Nested loops to multiply every term of 'a' with every term of 'b'
			for(int i = 0; i < a.n; i++){
				for(int j = 0; j < b.n; j++){
					// Step 1: Multiply coefficients and add exponents
					int new_coeff = a.Polyarr[i].coeff * b.Polyarr[j].coeff;
					int new_exp = a.Polyarr[i].exp + b.Polyarr[j].exp;
					// Step 2: Check if a term with this exponent already exists in our result array
					bool found = false;
					for(int k = 0; k < result.n; k++){
						if(result.Polyarr[k].exp == new_exp){
							result.Polyarr[k].coeff += new_coeff; // Combine like terms
							found = true;
							break;
						}
					}		
					// Step 3: If it's a new exponent, insert it as a new term
					if(!found){
						result.Polyarr[result.n].coeff = new_coeff;
						result.Polyarr[result.n].exp = new_exp;
						result.n++; // Increase the count of terms in result
					}
				}
			}
			// Step 4: Sort the final result array in Descending Order of exponents
			// (Using standard Bubble Sort to keep the format simple and clean)
			for(int i = 0; i < result.n - 1; i++){
				for(int j = 0; j < result.n - i - 1; j++){
					if(result.Polyarr[j].exp < result.Polyarr[j+1].exp){
						// Swap the terms
						Term temp = result.Polyarr[j];
						result.Polyarr[j] = result.Polyarr[j+1];
						result.Polyarr[j+1] = temp;
					}
				}
			}
			// Step 5: Clean up any terms where coefficients became 0 due to cancellations
			int valid_terms = 0;
			Polynomial final_result;
			for(int i = 0; i < result.n; i++){
				if(result.Polyarr[i].coeff != 0){
					final_result.Polyarr[valid_terms] = result.Polyarr[i];
					valid_terms++;
				}
			}
			final_result.n = valid_terms;
			return final_result;
		}
		
		void degree(){										//function to display degree of a polynomial
			if (n <= 0) {
        		cout << "Degree of Polynomial is: 0" << endl;
        		return;
   			}
    		int deg = Polyarr[0].exp; 
    		for(int i = 1; i < n; i++) { 
        		if(Polyarr[i].coeff != 0 && Polyarr[i].exp > deg) {
            		deg = Polyarr[i].exp; 
        		}
    		} 
    		cout << "Degree of Polynomial is: " << deg << endl; 
		}
		
		void evaluate(int y){							//function to evaluate a polynomial
			int res=0;
        	for(int i=0;i<n;i++){
            	res += Polyarr[i].coeff * (int)pow(y, Polyarr[i].exp);
        	}
        	cout<<"Value of Polynomial is: "<<res<<endl;
		}
		
		void search(int exponentvalue){					//function to search coefficient of an exponent in the polynomial
    		if(n==0){
        		cout<<"Polynomial is Empty.\n";
        		return;
    		}
    		for(int i=0;i<n;i++){
        		if(Polyarr[i].exp==exponentvalue){
            		cout<<"Coefficient of the required term is: "<<Polyarr[i].coeff<<endl;
            		return;
        		}
    		}
    		cout<<"Term not found."<<endl;
		}
		
		void display(){									//function to display polynomial
			if(n==0){
            	cout<<"Polynomial is Empty.\n";
            	return;
        	}
        	else{
        		cout<<"\nPolynomial is: ";
				for(int i=0;i<n;i++){
            		if(Polyarr[i].coeff>0 && i!=0)
                		cout<<" + ";
            		if(Polyarr[i].coeff<0)
                		cout<<" - ";
            		int c=abs(Polyarr[i].coeff);
           			if(Polyarr[i].exp==0){
                		cout<<c;
            		}
            		else if(Polyarr[i].exp==1){
                		if(c!=1)
                    		cout<<c;
                			cout<<"x";
            		}
            		else{
                		if(c!=1)
                    		cout<<c;
                		cout<<"x^"<<Polyarr[i].exp;
            		}
        		}
        		cout<<endl;	
			}	
		}	
};

int main(){
	Polynomial p1, p2, p3, p4;
	int choice, valx, c, v;
	do{
		cout<<"\nSelect your choice:"<<endl;
		cout<<"1. Create Polynomial \n2. Add two polynomial \n3. Subtract two polynomial \n4. Multiply two polynomial \n5. Degree of Polynomial";
		cout<<"\n6. Evaluate Polynomial \n7. Search Term \n8. Display polynomial \n9. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:									//Case 1: Creating Polynomial
				p1.create();
				break;
			case 2:									//Case 2: Add Two Polynomials
				p1.create();
				p2.create();
				p3=p3.add(p1,p2);
				p3.display();
				break;	
			case 3:									//Case 3: Subtract Two Polynomials
				p1.create();
				p2.create();
				p4=p4.sub(p1,p2);
				p4.display();
				break;
			case 4:
				p1.create();
				p2.create();
				p3=p3.multiply(p1, p2);
				p3.display();
				break;	
			case 5:									//Case 4: Find Degree of Polynomial
				p1.create();
				p1.degree();
				break;
			case 6:									//Case 5: Evaluate Polynomial for a Specific Value
				p1.create();
				cout<<"Enter value of x for evaluation: ";
				cin>>valx;
				p1.evaluate(valx);
				break;
			case 7:									//Case 6: Search for the coefficient of the Specific exponent										
				cout<<"Which Polynomial to search? \n1. Polynomial 1 \n2. Polynomial 2"<<endl;
				cin>>c;
				if(c==1){
					cout<<"Enter value of exponent whose coefficient you want to search: ";
					cin>>v;
					p1.search(v);
				}
				else if(c==2){
					cout<<"Enter value of exponent whose coefficient you want to search: ";
					cin>>v;
					p2.search(v);
				}
				else 
					cout<<"Invaid choice"<<endl;
				break;	
			case 8:								//Case 7: Display Polynomial
				cout<<"Which Polynomial to display? \n1. Polynomial 1 \n2. Polynomial 2"<<endl;
				cout<<"Enter choice: ";
				cin>>c;
				if(c==1)
					p1.display();
				else if(c==2)
					p2.display();
				else
					cout<<"Invaid choice"<<endl;		
				break;	
			case 9:								//Case 8: Exit Program
				cout<<"Exiting Program"<<endl;
				break;
			default:							//Default case
				cout<<"Invalid Choice";
				break;																	
		}
	}while(choice!=8);
	return 0;
}