//Calculator
#include<iostream>
using namespace std;
class data
{
	public:
		double num1, num2;
		void getdata()
		{
			cout<<"Enter number 1: ";
			cin>>num1;
			cout<<"Enter number 2: ";
			cin>>num2;
		}
		void add();
		void subtract();
		void divide();
		void multiply();
};
void data::add()
{
	cout<<"Result of Addition of the two numbers is "<<num1+num2<<endl;
}
void data::subtract()
{
	cout<<"Result of Subtraction of the two numbers is "<<num1-num2<<endl;
}
void data::multiply()
{
	cout<<"Result of Product of the two numbers is "<<num1*num2<<endl;
}
void data::divide()
{
	if(num2!=0)
	{
		cout<<"Result of Division of the two numbers is "<<num1/num2<<endl;
	}
	else
	{
		cout<<"Error: Division by zero not allowed."<<endl;
	}
}
int main()
{
	data d;
	char choice;
	int option;
	do
	{
		d.getdata();
		cout<<"Select the operation that you want to perform:"<<endl;
		cout<<"1. Addition \n2. Subtraction \n3. Multiplication \n4. Division \n";
		cin>>option;
		switch(option)
		{
			case 1:
				d.add();
				break;
			case 2:
				d.subtract();
				break;
			case 3:
				d.multiply();
				break;
			case 4:
				d.divide();
				break;
			default:
				cout<<"Invalid choice"<<endl;				
		}
		cout<<"Do you want to continue??{Y for yes, N for no):  ";
		cin>>choice;
		if(choice!='Y'&&choice!='y')
		{
			cout<<"Exiting Program"<<endl;
		}
	}while(choice=='Y'||choice=='y');
	return 0;
}
