//Hourglass Sum

#include<iostream>
using namespace std;

class Array{
	private:
		int arr[6][6];
		int sum;
	public:
		Array(){         
			sum=0;
		}
		
		void CreateMatrix(){
			cout<<"Enter Elements for 6x6 Matrix : ";
			for(int i=0; i<6; i++){
				for(int j=0; j<6; j++){
					cin>>arr[i][j];
				}
			}
		}	
		
		void DisplayMatrix(){
			cout<<"Your 6x6 Matrix is: "<<endl;
			for(int i=0; i<6; i++){
				for(int j=0; j<6; j++){
					cout<<arr[i][j]<<"\t";
				}
				cout<<"\n";
			}
		}
		
		int HourGlassSum(int r, int c){
				sum=arr[r][c]+arr[r][c+1]+arr[r][c+2]+arr[r+1][c+1]+arr[r+2][c]+arr[r+2][c+1]+arr[r+2][c+2];
			return sum;
		}
		
		int MaxHourGlassSum(){
    		int s;
    		sum=arr[0][0]+ arr[0][1] + arr[0][2] + arr[1][1] + arr[2][0] + arr[2][1] + arr[2][2];
    		for(int i=0; i<4; i++)
    		{
        		for(int j=0; j<4; j++)
    	    	{
	            	s = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            		if(s > sum)
            		{
                		sum = s;
            		}
        		}
    		}
    		return sum;
		}
};

int main(){
	int choice, row, cols;
	Array a;
	do{
		cout<<"Select your choice for Array Hourglass: "<<endl;
		cout<<"1. Create matrix \n2. Display Matrix \n3. Hourglass Sum \n4. Maximum Hourglass sum \n5. Exit"<<endl;
		cout<<"Enter your choice:  ";
		cin>>choice;
		switch(choice){
			case 1:
				a.CreateMatrix();
				break;
			case 2:
				a.DisplayMatrix();
				break;	
			case 3:
				cout<<"Enter row index of top-left position of hourglass (0-indexed): ";
				cin>>row;
				cout<<"Enter column index of top-left position of hourglass (0-indexed): ";
				cin>>cols;
				if(row<0 || row>3 || cols<0 || cols>3){
					cout<<"Hourglass can't be formed at given position.\n"<<endl;
				}
				else{
					cout<<"\nHourglass sum for your specified position is:  "<<a.HourGlassSum(row, cols)<<endl;	
				}
				break;	
			case 4:
				cout<<"Maximum HourGlass sum is: "<<a.MaxHourGlassSum()<<endl;
				break;
			case 5:
				cout<<"Exiting Program!!"<<endl;
				break;
			default:
				cout<<"Invalid choice!!"<<endl;
				break;	
		}
	}while(choice!=5);
	return 0;
}