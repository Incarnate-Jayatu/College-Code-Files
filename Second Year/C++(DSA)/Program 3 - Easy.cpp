//Program 3
/*Store monthly electricity usage in an array and generate yearly statistics. */
#include<iostream>
using namespace std;

class Electricity{
	private:
		int monthlyusage[12];
		int year, yusage, maxusage, minusage, len;
	public:
		Electricity(){
			year=0;
			maxusage = 0;
			yusage = 0;
			minusage = 0;
			len =0;
		}
		void getmonthlydata(){
			cout<<"Enter year: ";
			cin>>year;
			cout<<"Enter electricity usage data for 12-months: ";
			for(int i=0; i<12; i++){
				cin>>monthlyusage[i];
			}
			len = 12;
		}
		void yearlystatictics(){
			if(len!=12){
				cout<<"Incomplete monthly data!!!"<<endl;
			}
			cout<<"Yearly statics for "<<year<<":"<<endl;
			for(int i=0; i<12; i++){
				yusage += monthlyusage[i]; 	
			}
			cout<<"\nElectricity usage for whole year: "<<yusage<<" units"<<endl;
			for(int i=0; i<12; i++){
				if(monthlyusage[i]>maxusage){
					maxusage = monthlyusage[i];
				}
			}
			minusage = maxusage;
			cout<<"Maximum electricity used in month: "<<maxusage<<endl;
			for(int i=0; i<12; i++){
				if(monthlyusage[i]<minusage){
					minusage = monthlyusage[i];
				}
			}
			cout<<"Minimum electricity used in month: "<<minusage<<endl;
		}	
};

int main(){
	Electricity e;
	int choice;
	do{
		cout<<"Select your choice: "<<endl;
		cout<<"1. Enter monthly data \n2. Get year Statistics \n3. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:{
				e.getmonthlydata();
				break;
			}
			case 2:{
				e.yearlystatictics();
				break;
			}
			case 3:{
				cout<<"Exiting Program !!!"<<endl;
				break;
			}
			default:{
				cout<<"Invalid Choice !!!"<<endl;
				break;
			}
		}
	}while(choice!=3);
	return 0;
}