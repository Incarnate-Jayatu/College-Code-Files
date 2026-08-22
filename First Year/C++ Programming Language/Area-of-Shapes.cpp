//Area of Shapes
#include<iostream>
using namespace std;
class shapes
{
	public:
		double side, radius, length, breadth, height, base;
		void square()
		{
			cout<<"Enter length of side: ";
			cin>>side;
			cout<<"Area of square is "<<side*side<<endl;
		}
		void circle()
		{
			cout<<"Enter radius of circle: ";
			cin>>radius;
			cout<<"Area of circle is "<<3.14*radius*radius<<endl;
		}
		void rectangle()
		{
			cout<<"Enter length of ractangle: ";
			cin>>length;
			cout<<"Enter breadth of rectangle: ";
			cin>>breadth;
			cout<<"Area of rectangle is "<<length*breadth<<endl;
		}
		void triangle()
		{
			cout<<"Enter height of triangle: ";
			cin>>height;
			cout<<"Enter length of base of triangle: ";
			cin>>base;
			cout<<"Area of triangle is "<<0.5*height*base<<endl;
		}
};
int main()
{
	shapes s;
	char choice1;
	int choice;
	do
	{
		cout<<"\nSelect shape of your choice: "<<endl;
		cout<<"1. Square"<<endl<<"2. Rectangle"<<endl<<"3. Circle"<<endl<<"4. Triangle"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				s.square();
				break;
			case 2:
				s.rectangle();
				break;
			case 3:
				s.circle();
				break;
			case 4:
				s.triangle();
				break;
			default:
				cout<<"Invalid Choice"<<endl;					
		}
		cout<<"\nDo you want to continue?(Y for yes, N for no):  ";
		cin>>choice1;
	}while(choice1=='Y'||choice1=='y');
	return 0;
}
