#include<iostream>
#include<string>
#include<fstream>
#include<cstdio>
using namespace std;

void addR();
void displayR();
void searchR(int);
void updateR(int);
void deleteR(int);

class Student{
public:
    int stid;
    float marks;
    string name;
    void getdata(){
        cout<<"Enter Student ID: ";
        cin>>stid;
        cin.ignore();
        cout<<"Enter Student Name: ";
        getline(cin,name);
        cout<<"Enter Marks: ";
        cin>>marks;
        if(cin.fail()){
            throw runtime_error("Invalid marks entered.");
        }
    }
    void showdata(){
        cout<<"\nStudent ID: "<<stid<<endl;
        cout<<"Student Name: "<<name<<endl;
        cout<<"Total Marks: "<<marks<<endl;
    }
};

void addR(){
    try{
        Student s;
        ofstream myFile("students.txt", ios::app);
        if(!myFile)
            throw runtime_error("Unable to open file.");
        s.getdata();
        myFile<<s.stid<<endl;
        myFile<<s.name<<endl;
        myFile<<s.marks<<endl;
        myFile.close();
        cout<<"\nRecord Added Successfully.\n";
    }
    catch(exception &e){
        cout<<"\nError: "<<e.what()<<endl;
    }
}

void displayR(){
    try{
        Student s;
        ifstream myFile("students.txt");
        if(!myFile)
            throw runtime_error("Unable to open file.");
        while(myFile>>s.stid){
            myFile.ignore();
            getline(myFile,s.name);
            myFile>>s.marks;
            myFile.ignore();
            s.showdata();
        }
        myFile.close();
    }
    catch(exception &e){
        cout<<"\nError: "<<e.what()<<endl;
    }
}

void searchR(int id){
    try{
        Student s;
        ifstream myFile("students.txt");
        if(!myFile)
            throw runtime_error("Unable to open file.");
        int found=0;
        while(myFile>>s.stid){
            myFile.ignore();
            getline(myFile,s.name);
            myFile>>s.marks;
            myFile.ignore();
            if(s.stid==id){
                s.showdata();
                found=1;
                break;
            }
        }
        if(!found)
            throw runtime_error("Record Not Found.");
        myFile.close();
    }
    catch(exception &e){
        cout<<"\nError: "<<e.what()<<endl;
    }
}

void updateR(int id){
    try{
        Student s;
        ifstream myFile("students.txt");
        ofstream file("temp.txt");
        if(!myFile || !file)
            throw runtime_error("Unable to open file.");
        int found=0;
        while(myFile>>s.stid){
            myFile.ignore();
            getline(myFile,s.name);
            myFile>>s.marks;
            myFile.ignore();
            if(s.stid==id){
                cout<<"\nEnter New Details:\n";
                s.getdata();
                found=1;
            }
            file<<s.stid<<endl;
            file<<s.name<<endl;
            file<<s.marks<<endl;
        }
        myFile.close();
        file.close();
        remove("students.txt");
        rename("temp.txt","students.txt");
        if(!found)
            throw runtime_error("Record Not Found.");
        cout<<"\nRecord Updated Successfully.\n";
    }
    catch(exception &e){
        cout<<"\nError: "<<e.what()<<endl;
    }
}

void deleteR(int id){
    try{
        Student s;
        ifstream myFile("students.txt");
        ofstream file("temp.txt");
        if(!myFile || !file)
            throw runtime_error("Unable to open file.");
        int found=0;
        while(myFile>>s.stid){
            myFile.ignore();
            getline(myFile,s.name);
            myFile>>s.marks;
            myFile.ignore();
            if(s.stid==id){
                found=1;
                continue;
            }
            file<<s.stid<<endl;
            file<<s.name<<endl;
            file<<s.marks<<endl;
        }
        myFile.close();
        file.close();
        remove("students.txt");
        rename("temp.txt","students.txt");
        if(!found)
            throw runtime_error("Record Not Found.");
        cout<<"\nRecord Deleted Successfully.\n";
    }
    catch(exception &e){
        cout<<"\nError: "<<e.what()<<endl;
    }
}

int main(){
    int choice,id;
    do{
        try{
            cout<<"\nSelect your choice";
            cout<<"\n1.Add";
            cout<<"\n2.Display";
            cout<<"\n3.Search";
            cout<<"\n4.Update";
            cout<<"\n5.Delete";
            cout<<"\n6.Exit";
            cout<<"\nChoice: ";
            cin>>choice;
            if(cin.fail())
                throw runtime_error("Invalid menu choice.");
            switch(choice){
                case 1:
                    addR();
                    break;
                case 2:
                    displayR();
                    break;
                case 3:
                    cout<<"Enter ID to Search: ";
                    cin>>id;
                    searchR(id);
                    break;
                case 4:
                    cout<<"Enter ID to Update: ";
                    cin>>id;
                    updateR(id);
                    break;
                case 5:
                    cout<<"Enter ID to Delete: ";
                    cin>>id;
                    deleteR(id);
                    break;
                case 6:
                    cout<<"Exiting Program...\n";
                    break;
                default:
                    cout<<"Invalid Choice.\n";
            }
        }
        catch(exception &e){
            cout<<"\nError: "<<e.what()<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
	}while(choice!=6);
    return 0;
}
