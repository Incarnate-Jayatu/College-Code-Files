import java.util.*;
class BasicViaMethods {
	void arithmeticop() 
	{
		System.out.println(" ");
		System.out.println("Arithmetic Operators (using number 26 & 17): ");
		int a = 26, b = 17;
		System.out.println(a + b);
		System.out.println(a - b);
		System.out.println(a * b);
		System.out.println(a / b);
	}

	void relationalop() 
	{
		System.out.println(" ");
		System.out.println("Relational & Special Operators (using number 26 & 17): ");
		int a = 26, b = 17;
		System.out.println(a % b);
		System.out.println(a >= b);
		System.out.println(a <= b);
		System.out.println(a == b);
		System.out.println(a != b);
	}

	void incdec() 
	{
		System.out.println(" ");
		int i = 10;
		System.out.println("Increment: ");
		System.out.println(i++);
		System.out.println(i++);
		System.out.println(++i);
		System.out.println(i++);
		System.out.println(i);
		System.out.println(" ");

		System.out.println("Decrement:");
		System.out.println(i--);
		System.out.println(--i);
		System.out.println(i--);
		System.out.println(--i);
		System.out.println(i);
		System.out.println(" ");
	}

	void oddeven() 
	{
		System.out.println(" ");
		System.out.println("Alternate Odd Number:");
		for (int y = 1; y <= 20; y = y + 4)
			System.out.println(y);

		System.out.println(" ");
		System.out.println("Alternate Even Number:");
		for (int y = 2; y <= 20; y = y + 4)
			System.out.println(y);
	}

	void elseifladder() 
	{
		System.out.println(" ");
		System.out.println("Grade Calculation: ");
		int marks = 200;
		if (marks >= 250)
			System.out.println("A+");
		else if (marks < 250 && marks >= 200)
			System.out.println("A");
		else if (marks < 200 && marks >= 150)
			System.out.println("A");
		else
			System.out.println("F");
	}

	void table() 
	{
		System.out.println(" ");
		System.out.println("Table of 25:");
		for (int x = 1; x <= 10; x++)
			System.out.println(25 * x);
	}

	void switchcase()    //new
	{
		System.out.println(" ");
		System.out.println("Switch Case");
		int choice=2;
		int a=24, b=13;
		switch(choice)
		{
			case 1: System.out.println(a + b);
				break;
			case 2: System.out.println(a - b);
				break;
			case 3: System.out.println(a * b);
				break;
			case 4: System.out.println(a / b);
				break;
			default: System.out.println("Invalid choice");
				break;
		}
		System.out.println(" ");
	}

	void dowhileloop()	//new
	{
		System.out.println(" ");
		System.out.println("Do While Loop ");
		int count=10;
		do
		{
			System.out.println(count);
			count--;
		}while(count>5);
	}

	void weekdays()     //new
	{
		Scanner s = new Scanner(System.in);
		System.out.println(" ");
		System.out.println("7 Days of Week:-");
		System.out.print("Enter any integer from 1 to 7:   ");
		int week = s.nextInt();
		switch(week)
		{
			case 1: System.out.println("First Day of week is Monday");
				break;
			case 2: System.out.println("Second Day of week is Tuesday");
				break;
			case 3: System.out.println("Third Day of week is Wednesday");
				break;
			case 4: System.out.println("Fourth Day of week is Thursday");
				break;
			case 5: System.out.println("Fifth Day of week is Friday");
				break;
			case 6: System.out.println("Sixth Day of week is Saturday");
				break;
			case 7: System.out.println("Seventh Day of week is Sunday");
				break;
			default: System.out.println("Invalid input");
				break;		
		}
	}

	public static void main(String[] args) 
	{
		BasicViaMethods myp = new BasicViaMethods();
		myp.table();
		myp.arithmeticop();
		myp.relationalop();
		myp.oddeven();
		myp.incdec();
		myp.elseifladder();
		myp.dowhileloop();
		myp.switchcase();
		myp.weekdays();
	}
};