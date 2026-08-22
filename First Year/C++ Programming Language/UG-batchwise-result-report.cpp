#include<iostream>
#include<string>
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
        cout << "\nEnter Student ID: ";
        cin >> studentid;
        cout << "Enter Student Name: ";
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
        cout << "Student Name: " << studentname << endl;
        cout << "Student ID: " << studentid << endl;
        for (int i = 0; i < 5; i++) 
		{
            cout << "Marks of Subject " << i + 1 << ": " << marks[i] << endl;
        }
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
            operator+(getMark(i)); 
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
int main() {
    int ugC;
    cout << "Enter number of UG students: ";
    cin >> ugC;
    UG ugBatch[ugC]; 
    for (int i = 0; i < ugC; i++) 
	{
        cout << "\n--- UG Student " << i + 1 << " ---" << endl;
        ugBatch[i].getdata();
    }
    cout << "\n========================================";
    cout << "\n        UNDERGRADUATE RESULT REPORT";
    cout << "\n========================================" << endl;
    for (int i = 0; i < ugCount; i++) 
	{
        ugBatch[i].displayReport();
    }
    return 0;
}
