#include<iostream>
using namespace std;
class Animal
{
	public: 
		virtual sound()
		{
			cout<<"Animal makes a sound"<<endl;
		}
};
class Dog:public Animal
{
	sound() override
	{
		cout<<"Sound of Dogs is known as Bark."<<endl;
	}
};
int main()
{
	Animal* obj;
	Dog d;
	obj = &d;
	obj->Animal::sound();
	obj->sound();
	return 0;
}
