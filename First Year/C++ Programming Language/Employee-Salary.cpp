#include <iostream>
#include <string>
using namespace std;

class Employee {
  protected:
    string name;
    double basicSalary;
  public:
    void getDetails() {
      cout << "Enter Employee Name: ";
      cin >> name;
      cout << "Enter Basic Salary: ";
      cin >> basicSalary;
    }

    virtual double calculateSalary() {
      return basicSalary;
    }

    void displaySalary(double totalSalary) {
      cout << "\nEmployee Name: " << name;
      cout << "\nTotal Salary: " << totalSalary << endl;
    }
};

class Manager : public Employee {
  public:
    double calculateSalary() {
      double hra = 0.30 * basicSalary;
      double bonus = 0.20 * basicSalary;
      return basicSalary + hra + bonus;
    }
};

class Developer : public Employee {
  public:
    double calculateSalary() {
      double hra = 0.20 * basicSalary;
      double bonus = 0.10 * basicSalary;
      return basicSalary + hra + bonus;
    }
};

class Intern : public Employee {
  public:
    double calculateSalary() {
      return 5000;
    }
};

int main() {
  int choice;
  Employee *emp;

  cout << "Select Employee Type:\n";
  cout << "1. Manager\n2. Developer\n3. Intern\n";
  cout << "Enter Choice: ";
  cin >> choice;

  if (choice == 1) {
    emp = new Manager();
  }
  else if (choice == 2) {
    emp = new Developer();
  }
  else if (choice == 3) {
    emp = new Intern();
  }
  else {
    cout << "Invalid Choice!";
    return 0;
  }

  emp->getDetails();
  double totalSalary = emp->calculateSalary();
  emp->displaySalary(totalSalary);
  delete emp;
  return 0;
}
