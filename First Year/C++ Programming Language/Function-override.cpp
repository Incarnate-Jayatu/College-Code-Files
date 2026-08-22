#include<iostream>
#include<string>
using namespace std;
class Employee
{
	public:
		string name;
		int basesalary;
		getdata()
		{
			cout<<"Enter Name: ";
			cin>>name;
			cout<<"Enter Base Salary: ";
			cin>>basesalary;
		}
		showdata()
		{
			cout<<"Employee Name: "<<name<<endl;
			cout<<"Base Salary: "<<basesalary<<endl;
		}
		virtual calculatesalary(int basesalary)
		{
			return basesalary;
		}
};
class Manager:public Employee
{
	public:
		int calculatesalary(int basesalary) override
		{
			return basesalary+((30*basesalary)/100)+((20*basesalary)/100);
		}
};
class Developer:public Employee
{
	public:
		calculatesalary(int basesalary) override
		{
			return basesalary+((20*basesalary)/100)+((10*basesalary)/100);
		}
};
class Intern:public Employee
{
	public:
		calculatesalary(int basesalary) override
		{
			return basesalary;
		}
};
int main()
{
	Employee* e;
	Manager m;
	Developer d;
	Intern i;
	int des;
	cout<<"Designations:\n 1.Manager \n 2.Developer \n 3.Intern"<<endl;
	cout<<"Enter designation of employee: ";
	cin>>des;
	switch(des)
	{
		case 1:
			e = &m;
			m.Employee::getdata();
			cout<<"----------------------------------"<<endl;	
			cout<<"-----------Final Payslip----------"<<endl;
			cout<<"----------------------------------"<<endl;
			m.Employee::showdata();
			cout<<"Designation: Manager"<<endl;
			cout<<"Total Salary: "<<m.calculatesalary(m.basesalary)<<endl;
			break;
		case 2:
			e = &d;
			d.Employee::getdata();
			cout<<"----------------------------------"<<endl;
			cout<<"-----------Final Payslip----------"<<endl;
			cout<<"----------------------------------"<<endl;
			d.Employee::showdata();
			cout<<"Designation: Developer"<<endl;
			cout<<"Total Salary: "<<d.calculatesalary(d.basesalary)<<endl;	
			break;
		case 3:
			e = &i;
			i.Employee::getdata();
			cout<<"----------------------------------"<<endl;
			cout<<"-----------Final Payslip----------"<<endl;
			cout<<"----------------------------------"<<endl;
			i.Employee::showdata();
			cout<<"Designation: Intern"<<endl;
			cout<<"Total Salary: "<<i.calculatesalary(i.basesalary)<<endl;
			break;
		default: 
			cout<<"Incorrect choice!!"<<endl;
			break;		
	}
	return 0;
}
