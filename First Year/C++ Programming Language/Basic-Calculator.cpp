#include<iostream>
using namespace std;
class maths
{
	public:
		float n1, n2;
		getdata();
		add();
		sub();
		mul();
		div();
};
maths::getdata()
{
	cout<<"\nEnter first number: ";
	cin>>n1;
	cout<<"Enter second number: ";
	cin>>n2;
}
maths::add()
{
	cout<<"\nSum of given two numbers is: "<<n1+n2<<endl;
}
maths::sub()
{
	cout<<"Difference of given two numbers is: "<<n1-n2<<endl;
}
maths::mul()
{
	cout<<"Product of given two numbers is: "<<n1*n2<<endl;
}
maths::div()
{
	cout<<"Division of given two numbers is: "<<n1/n2<<endl;
}
int main()
{
	int ch;
	int c;
	maths m;
	do
	{
	m.getdata();
	cout<<"\nEnter your choice: "<<endl<<"1. Addition"<<endl<<"2. Subtraction"<<endl<<"3. Multiplication"<<endl<<"4. Division\n"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
		m.add();
		break;
		case 2:
		m.sub();
		break;
		case 3:
		m.mul();
		break;
		case 4:
		m.div();
		break;
		default:
		cout<<"Invalid choice code";
		break;		
	}
	cout<<"Do you want to continue(1 for yes, 0 for no):";
	cin>>c;
	}while(c==1);
	return 0;
}
