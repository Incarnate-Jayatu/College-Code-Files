//Basic student management system
#include<iostream>
#include<string>
using namespace std;
class Student
{
	public:
		int rollno;
		string name, branch, year;
		void getdata()
		{
			cout<<"Enter Name: ";
			cin>>name;
			cout<<"Enter Roll Number: ";
			cin>>rollno;
			cout<<"Enter Branch: ";
			cin>>branch;
			cout<<"Enter year: ";
			cin>>year;
		}
		void showdata()
		{
			cout<<"Name of Student: "<<name<<endl;
			cout<<"Roll Number: "<<rollno<<endl;
			cout<<"Branch: "<<branch<<endl;
			cout<<"Year: "<<year<<endl;
		}
};
int main()
{
	Student s;
	s.getdata();
	cout<<"------Student Details-----"<<endl;
	s.showdata();
	return 0;
}
