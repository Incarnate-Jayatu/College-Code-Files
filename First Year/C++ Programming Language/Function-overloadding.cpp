#include<iostream>
using namespace std;
class Addition
{
	public:
		add(int num1, int num2)
		{
			return num1+num2;
		}
		add(int num1, int num2, int  num3)
		{
			return num1+num2+num3;
		}
		float add(float num1, float num2)
		{
			return num1+num2;
		}
};
int main()
{
	Addition obj;
	cout<<"Addition of 4 & 78 is: "<<obj.add(4, 78)<<endl;
	cout<<"Addition of numbers 34, 123, 9878 is: "<<obj.add(34, 123, 9878)<<endl;
	cout<<"Addition of 12.67 & 7.2 is: "<<obj.add(12.67f, 7.2f)<<endl;
	return 0;
}
