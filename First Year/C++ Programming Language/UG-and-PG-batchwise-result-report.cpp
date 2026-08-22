#include <iostream>
#include <string>
using namespace std;
class Student 
{
private:
    int marks[5]; 
protected:
    string studentname; 
    int studentid;
public:
    void getdata() 
	{
        cout << "Enter Student ID: ";
        cin >> studentid;
        cout << "Enter Name: ";
        cin >> studentname; 
        cout << "Enter Marks for 5 subjects: " << endl;
        for (int i = 0; i < 5; i++) 
		{
            cout << " Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }
    void showdata() 
	{
        cout << "\nStudent ID: " << studentid << "\nStudent Name: " << studentname;
    }
    int getMark(int i) const 
	{
        return marks[i];
    }
};
class UG : public Student 
{
public:
    int total;
    float per;
    void operator+(int m) 
	{
        total = total + m;
    }
    void calculate() 
	{
        total = 0;
        for (int i = 0; i < 5; i++) 
		{
            *this + getMark(i); 
        }
        per = (float)total / 5;
    }
    void displayReport()
	{
        calculate();
        showdata();
        cout << "\nTotal: " << total << "\nPercentage: " << per << "\nGrade: ";
        if (per >= 75) cout << "A";
        else if (per >= 60) cout << "B";
        else if (per >= 40) cout << "C";
        else cout << "Fail";
        cout << endl;
    }
};
class PG : public Student 
{
public:
    int total;
    float per;
    void operator+(int m) 
	{
        total = total + m;
    }
    void calculate() 
	{
        total = 0;
        for (int i = 0; i < 5; i++) 
		{
            *this + getMark(i);
        }
        per = (float)total / 5;
    }
    void displayReport() 
	{
        calculate();
        showdata();
        cout << "\nTotal: " << total << "\nPercentage: " << per << "\nGrade: ";
        if (per >= 80) cout << "Distinction";
        else if (per >= 50) cout << "Pass";
        else cout << "Fail";
        cout << endl;
    }
};

int main() 
{
    int ugCount, pgCount;
    cout << "Enter number of UG students: ";
    cin >> ugCount;
    UG ugBatch[ugCount]; 
    for (int i = 0; i < ugCount; i++) 
	{
        cout << "\n--- UG Student " << i + 1 << " ---" << endl;
        ugBatch[i].getdata();
    }
    cout << "\nEnter number of PG students: ";
    cin >> pgCount;
    PG pgBatch[pgCount];
    for (int i = 0; i < pgCount; i++) 
	{
        cout << "\n--- PG Student " << i + 1 << " ---" << endl;
        pgBatch[i].getdata();
    }
    cout << "\n========================================";
    cout << "\n       UNDERGRADUATE RESULT REPORT";
    cout << "\n========================================" << endl;
    for (int i = 0; i < ugCount; i++) 
	{
        ugBatch[i].displayReport();
    }
    cout << "\n========================================";
    cout << "\n       POSTGRADUATE RESULT REPORT";
    cout << "\n========================================" << endl;
    for (int i = 0; i < pgCount; i++) 
	{
        pgBatch[i].displayReport();
    }
    return 0;
}
