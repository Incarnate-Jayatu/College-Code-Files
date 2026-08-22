//Hospital Databse
#include<iostream>
#include<string>
using namespace std;
class Person            //Class PERSON
{
	public:	
		string name;
		int age;
		void getperson()                         //GET Details
		{
			cout<<"Enter Name: ";
			cin>>name;
			cout<<"Enter Age: ";
			cin>>age;
		}
		void showperson()         //Show Details
		{
			cout<<"Name: "<<name<<endl;
			cout<<"Age: "<<age<<endl;	
		}
};
class Patient:public Person         //INHERITED Class Patient
{
	public:
		string dis;
		int patid;
		void getpatient()          //Get pateint data for record
		{
			cout<<"Enter Patient ID: ";
			cin>>patid;	
			cout<<"Enter Disease: ";
			cin>>dis;
		}
		void showpatient()        //Show  patient data
		{
			cout<<"Patient ID: "<<patid<<endl;;
			cout<<"Patient Diagnosed with: "<<dis<<endl;	
		}	
};
class InPatient:public Patient          //Inherited CLass InPatient
{
	public:
		char abc;
		int roomno, nod, totalbill, extradays;
		int chargespd=3000;
		void getInpat()
		{
			cout<<"Enter Room Number: ";
			cin>>roomno;
			cout<<"Enter no of days in hospital: ";
			cin>>nod;
		}
		void showInpat()
		{
			cout<<"Room Number: "<<roomno<<endl;
			cout<<"no of days in hospital: "<<nod<<endl;
		}
		void calcbill()
		{
			totalbill=nod*chargespd;
		}
		void extendstay()
		{
			cout<<"Was there any extension in the stay?(Y = yes, N = no): " ;
			cin>>abc;
			if(abc=='Y' || abc=='y')
			{
				cout << "Enter number of extra days: ";
        		cin >> extradays;
				totalbill= totalbill+(extradays*chargespd);
			}
		}
		void discharge()
		{
			cout<<"Your total bill: "<<totalbill<<endl;
			cout<<"Stay Safe"<<endl;
		}
};

int main()
{
    char choice;
    do
    {
        InPatient p;
        p.getperson();
        p.getpatient();
        p.getInpat();
        p.calcbill();
        p.extendstay();
        cout << "-----YOUR DETAILS OF WHOLE DURATION IN RECORD FOR THIS TREATMENT-----" << endl;
        p.showperson();
        p.showpatient();
        p.discharge();
        cout << "\nDo you want to enter details for another patient? (Y/N): ";
        cin >> choice;
        cout << "--------------------------------------------" << endl;
        cout << "--------------------------------------------" << endl;
    } while (choice == 'Y' || choice == 'y');
    cout << "Program Ended. Thank You!" << endl;
    return 0;
}
