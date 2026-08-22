//Employee Payroll System
#include<iostream>
#include<string>
using namespace std;
class Employee
{
	private:
    	int empID;
    	string empName;
    	double basicSalary;
	public:
    	void getData()            // Function to get employee data
    	{
        	cout<<"Enter Employee ID: ";
        	cin>>empID;
        	cout<<"Enter Employee Name: ";
        	cin.ignore();
        	getline(cin, empName);
        	cout<<"Enter Basic Salary: ";
        	cin>>basicSalary;
    	}
    	friend void generatePayslip(Employee e);             	// Friend function declaration
    	inline double calculateBonus()                  	// Inline function to calculate bonus
    	{
        	return basicSalary * 0.10;   // 10% bonus
    	}
};
void generatePayslip(Employee e)                   // Friend function definition (Payroll Department)
{
    double hra = e.basicSalary * 0.20;
    double da  = e.basicSalary * 0.15;
    double bonus = e.calculateBonus();
    double finalSalary = e.basicSalary + hra + da + bonus;
    cout<<"\n========== PAYSLIP ==========\n";
    cout<<"Employee ID   : "<<e.empID<<endl;
    cout<<"Employee Name : "<<e.empName<<endl;
    cout<<"Basic Salary  : "<<e.basicSalary<<endl;
    cout<<"HRA (20%)     : "<<hra<<endl;
    cout<<"DA  (15%)     : "<<da<<endl;
    cout<<"Bonus (10%)   : "<<bonus<<endl;
    cout<<"------------------------------\n";
    cout<<"Final Salary  : "<<finalSalary<<endl;
    cout<<"==============================\n";
}
int main()
{
    Employee emp;
    emp.getData();
    generatePayslip(emp);
    return 0;
}
