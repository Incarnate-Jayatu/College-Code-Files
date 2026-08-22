//EMPLOYEE SYSTEM 
#include <iostream>
#include<string>
using namespace std;
class Person  //MAIN CLASS: PERSON
{
	private:                   //PRIVATE ACCESS SPECIFIER
    	long long aadhaarNo;  
	protected:            //PROTECTED ACCESS SPECIFIER
    	int age;               
	public:               //PUBLIC ACCESS SPECIFIER
    	string name;           
    	void setAadhaar(long long a)      //PARAMETERISED FUNCTION TO INPUT AADHAR NO
		{
        	aadhaarNo = a;
    	}
    	long long getAadhaar()             //FUNCTION TO RETURN AADHAR NO TO CONSOLE
		{
        	return aadhaarNo;
    	}
    	void setAge(int a)               //PARAMETERISED FUNCTION TO INPUT AGE
		{
        	age = a;
    	}
    	int getAge()             //FUNCTION TO RETURN AGE TO CONSOLE
		{
        	return age;
   	 	}
};
class Employee : public Person          //CLASS EMPLOYEE INHERITING DATA FROM CLASS PERSON
{
	private:                               //PRIVATE ACCESS SPECIFIER
    	int empID;             
	protected:                          //PROTECTED ACCESS SPECIFIER
    	double basicSalary;    
	public:                                //PUBLIC ACCESS SPECIFIER
    	string designation;    
    	void setEmpID(int id)  //FUNCTION TO GET EMPLOYEE ID PARAMETERISED WAY
		{
        	empID = id;
    	}
    	int getEmpID()  //FUNCTION TO RETURN EMPLOYEE ID
		{
        	return empID;
    	}
    	void setBasicSalary(double salary)  //FUNCTION TO GET SALARY PARAMETERISED METHOD
		{
        	basicSalary = salary;
    	}
    	double getBasicSalary()  //FUNCTION TO RETURN SALARY TO CONSOLE
		{
        	return basicSalary;
    	}
};
class Manager : public Employee   //CLASS MANAGER INHERITING DATA FROM CLASS EMPLOYEE
{
	public:                           //PUBLIC ACCESS SPECIFIER
    	double calculateTotalSalary()      //FUNCTION TO CALCULATE TOTAL SALARY
		{
        	double hra = 0.20 * basicSalary;
        	double da  = 0.10 * basicSalary;
        	return basicSalary + hra + da;
    	}
    	void displayDetails()                       //FUNCTION TO DISPLAY DETAILS
		{
        	cout << "\n----- Manager Details -----\n";
        	cout << "Name        : " << name << endl;
        	cout << "Age         : " << getAge() << endl;
        	cout << "Aadhaar No  : " << getAadhaar() << endl;
        	cout << "Employee ID : " << getEmpID() << endl;
        	cout << "Designation : " << designation << endl;
        	cout << "Basic Salary: " << getBasicSalary() << endl;
        	cout << "Total Salary: " << calculateTotalSalary() << endl;
    	}
};

int main()                                    //MAIN FUNCTION
{
    Manager m;
    m.name = "Jayatu";
    m.setAge(18);
    m.setAadhaar(0001000200030004);
    m.setEmpID(211);
    m.designation = "Project Manager";
    m.setBasicSalary(50000);
    m.displayDetails();
    return 0;
}
