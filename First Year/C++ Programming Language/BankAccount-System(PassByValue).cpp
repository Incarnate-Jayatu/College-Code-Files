//BANK ACCOUNT SYSTEM
#include <iostream>
#include <string>
using namespace std;
class Account                                                   //PARENT CLASS ACCOUNT
{
	private:
    	long long accno;
    	double balance;
	protected:
    	string acctype;
	public:
    	string dep_name;
    	void setAccountNumber(long long accNo)                   //SETTING ACCOUNT NUMBER
    	{	
        	accno = accNo;
    	}
    	void setBalance(double bal)                            //SETTING BALANCE
    	{
        	balance = bal;
    	}
    	long long getAccountNumber()                         //GETTING ACCOUNT NUMBER
    	{
        	return accno;
    	}
    	double getBalance()                                //GETTING BALANCE
    	{
        	return balance;
    	}
};
class SavingsAcc : public Account                     //CHILD CLASS SAVINGS ACCOUNT
{
	public:
    	SavingsAcc()                                    //SETTING ACCOUNT TYPE AS SAVINGS
    	{
        	acctype = "Savings Account";
    	}
    	void deposit(double amount)                           //FUNCTION TO DEPOSIT AMOUNT 
    	{
        	if (amount > 0)
        	{
            	setBalance(getBalance() + amount);
            	cout << "Amount Deposited Successfully.\n";
        	}
        	else
        	{
            	cout << "Invalid deposit amount.\n";
        	}
    	}
    	void withdraw(double amount)                           //FUNCTION TO WITHDRAW AMOUNT
    	{
        	if (amount > 0 && amount <= getBalance())
        	{
            	setBalance(getBalance() - amount);
            	cout << "Amount Withdrawn Successfully.\n";
        	}
        	else
        	{
            	cout << "Insufficient balance or invalid amount.\n";
        	}
    	}
    	void displayDetails()                                //FUNCTION TO DISPLAY DETAILS
    	{
        	cout << "\n--- Account Details ---\n";
        	cout << "Depositor Name : " << dep_name << endl;
        	cout << "Account Number : " << getAccountNumber() << endl;
        	cout << "Account Type   : " << acctype << endl;
        	cout << "Balance        : " << getBalance() << endl;
    	}
};
int main()                            //MAIN CLASS FUNCTION 
{
    SavingsAcc sa;
    sa.dep_name = "Jayatu";
    sa.setAccountNumber(1234567890);
    sa.setBalance(5000);
    sa.deposit(2000);
    sa.withdraw(1500);
    sa.displayDetails();
    return 0;
}
