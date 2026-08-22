#include<iostream>
using namespace std;
class Complex
{
	public:
		float real, imag;
    	void getdata()
    	{
        	cout<<"Enter real part: ";
        	cin>>real;
        	cout<<"Enter imaginary part: ";
        	cin>>imag;
    	}
    	void display()
    	{
        	cout<<real<<" + "<<imag<<"i";
    	}
    	Complex operator + (Complex c)
    	{
        	Complex temp;
        	temp.real = real + c.real;
        	temp.imag = imag + c.imag;
        	return temp;
    	}
};
int main()
{
    Complex c1, c2, c3;
    cout<<"Enter first complex number"<<endl;
    c1.getdata();
    cout<<"\nEnter second complex number"<<endl;
    c2.getdata();
    c3 = c1 + c2;
    cout<<"\nFirst Complex Number: ";
    c1.display();
    cout<<"\nSecond Complex Number: ";
    c2.display();
    cout<<"\nResultant Complex Number: ";
    c3.display();
    return 0;
}
