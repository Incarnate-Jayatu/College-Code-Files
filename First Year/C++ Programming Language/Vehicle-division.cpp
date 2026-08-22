#include <iostream>
#include <string>
using namespace std;

class vehicle
{
protected:
    int sp;
    string type, color;

public:
    void getdata()
    {
        cout << "Enter Wheel Arrangement of Vehicle: ";
        cin >> type;
        cout << "Enter Color of Vehicle: ";
        cin >> color;
        cout << "Enter Speed: ";
        cin >> sp;
    }

    void showdata()
    {
        cout << "Vehicle Type: " << type << endl;
        cout << "Vehicle Color: " << color << endl;
        cout << "Speed of Vehicle: " << sp << endl;
    }
};

class car : public vehicle
{
public:
    void calcfine()
    {
        if (sp > 80)
            cout << "You are fined Rs. 5000\n";
        else
            cout << "You are good to go!!\n";
    }
};

class truck : public vehicle
{
public:
    void calcfine()
    {
        if (sp > 55)
            cout << "You are fined Rs. 5000\n";
        else
            cout << "You are good to go!!\n";
    }
};

class bike : public vehicle
{
public:
    void calcfine()
    {
        if (sp > 65)
            cout << "You are fined Rs. 5000\n";
        else
            cout << "You are good to go!!\n";
    }
};

int main()
{
    string name;
    cout << "Enter name of vehicle: ";
    cin >> name;

    if (name == "car" || name == "Car")
    {
        car c;
        c.getdata();
        cout << "-------------------------------\n";
        c.showdata();
        c.calcfine();
    }
    else if (name == "truck" || name == "Truck")
    {
        truck t;
        t.getdata();
        cout << "-------------------------------\n";
        t.showdata();
        t.calcfine();
    }
    else if (name == "bike" || name == "Bike")
    {
        bike b;
        b.getdata();
        cout << "-------------------------------\n";
        b.showdata();
        b.calcfine();
    }
    else
    {
        cout << "Invalid vehicle type!";
    }

    return 0;
}
