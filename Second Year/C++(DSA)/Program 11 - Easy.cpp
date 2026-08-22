//Program 11
/*Evaluate a polynomial for a given value of x.*/

#include<iostream>
#include<cmath>
using namespace std;

class Polynomial{
	private:
		struct PolyTerm{
			int coeff;
			int exp;
		};	
		int n;
		PolyTerm PolyArr[20];
	public:
		Polynomial(){
			n = 0;
		}
		void create(){
			cout<<"Enter Number of Terms in the Polynomial: ";
			cin>>n;
			cout<<"Enter Terms in Descending Order of Exponent"<<endl;
			for(int i=0; i<n; i++){
				cout<<"Enter coefficient of term: ";
				cin>>PolyArr[i].coeff;
				cout<<"Enter exponent of term: ";
				cin>>PolyArr[i].exp;
			}	
		}
		void display(){
			if(n==0){
        		cout<<"Polynomial is empty.\n";
        		return;
    		}
			for(int i=0;i<n;i++){
		        cout<<PolyArr[i].coeff<<"x^"<<PolyArr[i].exp;
				if(i!=n-1)
            	cout<<" + ";
    		}
			cout<<endl;
		}
		void evaluate(){
			int x, res=0;
			cout<<"Enter value of x for evaluation of polynomial: ";
			cin>>x;
        	for(int i=0;i<n;i++){
            	res += PolyArr[i].coeff * (int)pow(x, PolyArr[i].exp);
        	}
        	cout<<"Evaluated Value of Polynomial is: "<<res<<endl;
		}
};

int main(){
	Polynomial p;
	p.create();
	p.display();
	p.evaluate();
	return 0;
}