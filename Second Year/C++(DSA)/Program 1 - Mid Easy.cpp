// Program 1
/* Implement an Array ADT to store marks of students and perform search, update,
   highest marks, average, and ranking. */
#include <iostream>
#include <iomanip>  
#include <string>   
using namespace std;

class Array {
private:
    struct student {
        string name;
        int totalmarks, rollno;
    };
    student starr[10];
    int n;

public:
    Array() {
        n = 0;
    }

    void getdata() {
        cout << "Enter number of students you want to enter data for (Max 10): ";
        cin >> n;
        if (n > 10 || n <= 0) {
            cout << "Invalid number of students! Setting count to 0." << endl;
            n = 0;
            return;
        }
        cout << "Enter data below as follows: " << endl;
        for (int i = 0; i < n; i++) {
            cout << "\n--- Student " << (i + 1) << " ---" << endl;
            cout << "Enter name of student (single word): ";
            cin >> starr[i].name;
            cout << "Enter RollNo of student: ";
            cin >> starr[i].rollno;
            cout << "Enter total marks of student: ";
            cin >> starr[i].totalmarks;
        }
    }

    void showdata() {
        if (n == 0) {
            cout << "No student data available!" << endl;
            return;
        }
        for (int i = 0; i < n; i++) {
            cout << "\nStudent name: " << starr[i].name;
            cout << " | RollNo: " << starr[i].rollno;
            cout << " | Total marks: " << starr[i].totalmarks << endl;
        }
    }

    void search(int roll) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (starr[i].rollno == roll) {
                cout << "\nDetails of Student: " << endl;
                cout << "Name of student: " << starr[i].name << endl;
                cout << "RollNo of student: " << starr[i].rollno << endl;
                cout << "Total Marks: " << starr[i].totalmarks << endl;
                found = true;
                break; // Stop searching once found
            }
        }
        if (!found) {
            cout << "Record not found!!" << endl;
        }
    }

    void update(int roll) {
        int key = -1;
        for (int i = 0; i < n; i++) {
            if (starr[i].rollno == roll) {
                key = i;
                break;
            }
        }
        if (key == -1) {
            cout << "Student with RollNo " << roll << " not found!" << endl;
            return;
        }

        cout << "Select detail to change: ";
        cout << "\n1. Name \n2. RollNo \n3. Total Marks" << endl;
        cout << "Enter your choice: ";
        int ch;
        cin >> ch;
        switch (ch) {
            case 1: {
                string n1;
                cout << "Enter updated name: ";
                cin >> n1;
                starr[key].name = n1;
                break;
            }
            case 2: {
                int rn1;
                cout << "Enter updated rollno: ";
                cin >> rn1;
                starr[key].rollno = rn1;
                break;
            }
            case 3: {
                int tm1;
                cout << "Enter updated total marks: ";
                cin >> tm1;
                starr[key].totalmarks = tm1;
                break;
            }
            default: {
                cout << "Invalid choice!!! No details changed!!" << endl;
                break;
            }
        }
    }

    void ranking() {
        if (n == 0) {
            cout << "No data available to rank!" << endl;
            return;
        }
        student temp_arr[10];
        for(int i = 0; i < n; i++)
			temp_arr[i] = starr[i];
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (temp_arr[j].totalmarks < temp_arr[j + 1].totalmarks) {
                    student t = temp_arr[j];
                    temp_arr[j] = temp_arr[j + 1];
                    temp_arr[j + 1] = t;
                }
            }
        }
        cout << "\nStudent ranking: " << endl;
        cout << left 
             << setw(8)  << "Rank"   << "|| " 
             << setw(15) << "Name"   << "|| " 
             << setw(10) << "Rollno" << "|| " 
             << "Total marks" << endl;
        cout << string(52, '-') << endl;
        for (int i = 0; i < n; i++) {
            cout<<left << setw(6)<<"Rank "<<setw(3)<<i + 1<<"|| "<<setw(15)<< temp_arr[i].name<<"|| "<<setw(10)<<temp_arr[i].rollno<<"|| "<< temp_arr[i].totalmarks<<endl;
        }
    }

    void stats() {
        if (n == 0) {
            cout << "No data available to calculate statistics!" << endl;
            return;
        }
        int high_idx = 0;
        int low_idx = 0;
        double total_sum = 0; // double for accurate average calculation
        for (int i = 0; i < n; i++) {
            if (starr[i].totalmarks > starr[high_idx].totalmarks) {
                high_idx = i;
            }
            if (starr[i].totalmarks < starr[low_idx].totalmarks) {
                low_idx = i;
            }
            total_sum += starr[i].totalmarks;
        }
        double avg = total_sum / n;
        
        cout << "\nDetails of Student having highest marks: " << endl;
        cout << "Name of student: " << starr[high_idx].name << endl;
        cout << "RollNo of student: " << starr[high_idx].rollno << endl;
        cout << "Total Marks: " << starr[high_idx].totalmarks << endl;
        
        cout << "\nOverall Statistics: " << endl;
        cout << "Highest Marks: " << starr[high_idx].totalmarks << " (" << starr[high_idx].name << ")" << endl;
        cout << "Lowest Marks:  " << starr[low_idx].totalmarks  << " (" << starr[low_idx].name << ")" << endl;
        cout << "Average Marks: " << fixed << setprecision(2) << avg << endl;
    }
};

int main() {
    int choice, rn;
    Array a;
    cout << "------- Student Result -------" << endl;
    do {
        cout << "\nSelect your choice: " << endl;
        cout << "1. Add student data \n2. Show student data \n3. Search by roll no \n4. Update student data \n5. Show Statistics \n6. Show Rankings \n7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:  a.getdata();  break;
            case 2:  a.showdata(); break;
            case 3:
                cout << "Enter roll no to search: ";
                cin >> rn;
                a.search(rn);
                break;
            case 4:
                cout << "Enter roll no to update: ";
                cin >> rn;
                a.update(rn);
                break;
            case 5:  a.stats();    break;
            case 6:  a.ranking();  break;
            case 7:  cout << "Exiting Program!!!" << endl; break;
            default: cout << "Invalid Choice!!!" << endl;  break;
        }
    } while (choice != 7);
    return 0;
}