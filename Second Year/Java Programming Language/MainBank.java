/*Create 2 interfaces 
1. transaction having method deposit and withdraw
2. account info having methods check balance and display details
A class savings account having 3 variable accno(int), name(String), balance(double)*/

import java.util.*;

interface Transaction
{
	void deposit();
	void withdraw();
}

interface AccountInfo
{
	void checkBalance();
	void displayDetails();
}

class SavingsAccount implements Transaction, AccountInfo
{
	Scanner s1 = new Scanner(System.in);
	int accno, balance, deposit, withdraw;
	String name;

	SavingsAccount(String n, int an, int bal)
	{
		accno = an;
		name = n;
		balance = bal;
		deposit=0;
		withdraw=0;
	}

	public void deposit()
	{
		System.out.println("\n---------- --------------- -----------");
		System.out.println("Current Balance: " +balance);
		System.out.println("Enter the amount you want to deposit: ");
		deposit=s1.nextInt();
		balance=balance+deposit;
		System.out.println("\nUpdated account balance is: " +balance);
		System.out.println("---------- --------------- ----------\n");
	}

	public void withdraw()
	{
		System.out.println("\n-------- --------------- -----------");
		System.out.println("Current Balance: " +balance);
		System.out.println("Enter the amount you want to deposit: ");
		withdraw=s1.nextInt();
		if(withdraw>balance)
		{
			System.out.println("Error!! Cannot withdraw amount more than account balance!");
			System.out.println("----------- --------------- ---------\n");

		}
		else
		{
			balance=balance-withdraw;
			System.out.println("\nUpdated account balance is: " +balance);
			System.out.println("----------- --------------- ---------\n");
		}
	}

	public void checkBalance()
	{
		System.out.println("\n---------------- --------------- ---------------");
		System.out.println("Accout Number: " +accno);
		System.out.println("Balance for the above Account Number is: " +balance);
		System.out.println("------------------ --------------- -------------\n");
	}

	public void displayDetails()
	{
		System.out.println("\n------ Account Details ------");
		System.out.println("Accout Number: " +accno);
		System.out.println("Account Holder: " +name);
		System.out.println("Account Balance: "+balance);
		System.out.println("------ --------------- ------\n");
	}
	
}

class MainBank
{
	public static void main(String []args)
	{
		int choice;
		Scanner s = new Scanner(System.in);
		SavingsAccount sa = new SavingsAccount("Jayatu Bhattad", 1012511211, 27169);
		do
		{
			System.out.println("\nSelect you choice: ");
			System.out.println("1. Display details \n2. Check Balance \n3. Withdraw Money \n4. Deposit Money \n5. Exit ");
			System.out.println("Enter your choice: ");
			choice=s.nextInt();
			switch(choice)
			{
				case 1:
					sa.displayDetails();
					break;
				case 2:
					sa.checkBalance();
					break;
				case 3:
					sa.withdraw();
					break;
				case 4:
					sa.deposit();
					break;
				case 5:
					System.out.println("Exiting Program!!\n");
					break;
				default:
					System.out.println("Invalid Choice!!");
					break;
			}	
		}while(choice!=5);
	}
}