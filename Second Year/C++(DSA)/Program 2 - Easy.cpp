//Program 2
/*Implement an Array ADT to manage products in a shopping cart with insert, delete, 
update quantity, and total bill.*/
#include<iostream>
#include<string>
#include<iomanip>
#define MAX 1000
using namespace std;

class ShoppingCart{
	private:
		struct Pro{
			string productname;
			int total, quantity, productid;
			double itemprice, totalproductcost;
		};
		int itemcount, productcount;
		Pro Product[MAX];
	public:
		ShoppingCart(){
			itemcount = 0;
			productcount = 0;
		}
		
		void addproduct(int procount){
			for(int i=0; i<procount; i++){
				cout<<"Enter Product ID: ";
				cin>>Product[i].productid;
				cout<<"Enter Product Name: ";
				cin>>Product[i].productname;
				cout<<"Enter Product Price: ";
				cin>>Product[i].itemprice;
				Product[i].totalproductcost = (Product[i].itemprice*Product[i].quantity);
				productcount++;
			}	
		}
		
		void removeproduct(int Pid){
			if(productcount == 0){
				cout<<"No Products are added!!!"<<endl;
				return;
			}
			else{
				for(int i=0; i<productcount; i++){
					if(Product[i].productid == Pid){
						for(int j=i; j<productcount; j++){
							Product[j] = Product[j+1];
						}
						productcount--;
					}
					else{
						cout<<"Product not found in cart!!!"<<endl;
					}
				}
			}	
		}	
		
		void updatequantity(int pid){
			if(productcount == 0){
				cout<<"No Products are added!!!"<<endl;
				return;
			}
			else{
				for(int i=0; i<productcount; i++){
					if(Product[i].productid == pid){
						int npq;
						cout<<"Enter updated quantity for the product: ";
						cin>>npq;
						Product[i].quantity = npq;
						Product[i].totalproductcost = (Product[i].itemprice*Product[i].quantity);
						cout<<"Product Quantity Updated Successfully!!!"<<endl;
					}
					else{
						cout<<"Product not found in the cart!!!"<<endl;
					}
				}
			}
		}
		
		void totalbill(){
			int totalitems;
			if(productcount == 0){
				cout<<"No Products are added!!!"<<endl;
				return;
			}
			else{
				cout<<string(24, '-')<<" FINAL BILL "<<string(24, '-')<<endl;
				cout << left 
             	<<setw(10)<<"Product ID"<<"||" 
             	<<setw(25)<<"Product Name"<<"||" 
             	<<setw(5)<<"Quantity"<<"||" 
             	<<setw(10)<<"Item Cost"<<"||"
             	<<"Total Cost"<<endl;
        		cout << string(55, '-') << endl;
        		for(int i=0; i<productcount; i++){
        			cout<<left<<setw(10)<<Product[i].productid<<"||"<<setw(25)<<Product[i].productname<<"||"<<setw(5)<<Product[i].itemprice<<"||"<<Product[i].totalproductcost<<endl;
				}
				cout << string(60, '-') << endl;
				for(int i=0; i<productcount; i++){
					totalitems += Product[i].totalproductcost;
				}
				cout<<"Total Items: "<<totalitems<<endl;
				cout<<"Total products: "<<productcount<<endl;
				cout << string(60, '-') << endl;
			}
		}
};

int main(){
	ShoppingCart sc;
	int choice, pd;
	do{
		cout<<"Select your choice: "<<endl;
		cout<<"1. Add Product \n2. Remove product \n3. Update Quantity for a product \n4. Display bill \n5. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:{
				cout<<"Enter number of products to add: ";
				cin>>pd;
				sc.addproduct(pd);
				break;
			}
			case 2:{
				cout<<"Enter ID of product you want to remove: ";
				cin>>pd;
				sc.removeproduct(pd);
				break;
			}
			case 3:{
				cout<<"Enter Product ID for updating qty: ";
				cin>>pd;
				sc.updatequantity(pd);
				break;
			}
			case 4:{
				sc.totalbill();
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