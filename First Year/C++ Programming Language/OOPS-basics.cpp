#include<iostream>
using namespace std;
class student
{
	public:
		int rollno;
		string name;
		getdata();
		display();
};
student::getdata()
{
	cout<<"Enter name: ";
	cin>>name;
	cout<<"\nEnter Roll No: ";
	cin>>rollno;
}
student::display()
{
	cout<<"\n"<<name;
	cout<<"\n"<<rollno;
}

int main()
{
	student s;
	s.getdata();
	s.display();
	return 0;
}
 
