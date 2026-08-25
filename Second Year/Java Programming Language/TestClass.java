package railway;
import java.util.*;

abstract class Reservation
{
	Integer age;
	String pnr, passengerName;
	Double baseFare;
	Double finalFare;
 
	void acceptDetails(Scanner s)
	{
		System.out.print("Enter PNR number: ");
		pnr = s.nextLine();
		System.out.print("Enter Passenger Name: ");
		passengerName = s.nextLine();
		do
		{
			System.out.print("Enter Passenger Age: ");
			age = s.nextInt();
			if(age<=0)
			{
				System.out.println("Invalid Age!! \nRe-enter your age!!!");
			}
		}while(age<=0);
		do
		{
			System.out.print("Enter Base Fare: ");
			baseFare = s.nextDouble();
			if(baseFare<=0)
			{
				System.out.println("Invalid Fare Amount!! \nRe-enter your Base Fare Amount!!!");
			}
		}while(baseFare<=0);
		
	}

	abstract void calculateFare();

	void displayDetails()
	{
		System.out.println("\n=========RESERVATION DETAILS=========\n");
		System.out.println("PNR Number: "+pnr);
		System.out.println("Passenger Name: "+passengerName);
		System.out.println("Passenger Age: "+age);
		System.out.println("Base Fare: "+baseFare);
		System.out.println("Final Fare: "+finalFare);
		System.out.println("\n==================================\n");
	}	
}

class NormalReservation extends Reservation
{
	void calculateFare()
	{
		if(super.age<12)
		{
			this.finalFare = baseFare*0.5;
			return;
		}
		else if(super.age>60)
		{
			this.finalFare = baseFare*0.7;
			return;
		}
		else 
		{
			this.finalFare = baseFare;
			return;
		}
	}
}

class AcReservation extends Reservation
{
	void calculateFare()
	{
		if(super.age<12)
		{
			this.finalFare = baseFare*0.5 + baseFare*0.3;
			return;
		}
		else if(super.age>60)
		{
			this.finalFare = baseFare*0.7 + baseFare*0.3;
			return;
		}
		else 
		{
			this.finalFare = baseFare + baseFare*0.3;
			return;
		}
	}
}

class TestClass
{
	public static void main(String []args)
	{
		Reservation nr = new NormalReservation();
		Reservation ar = new AcReservation();
		System.out.println("=========RAILWAY RESERVATION SYSTEM=========");
		Scanner inp = new Scanner(System.in);
		int choice;
		do
		{
			System.out.println("Select Your Reservation Choice: ");
			System.out.println("1. Normal Reservation");
			System.out.println("2. AC Reservation");
			System.out.println("3. Exit Reservation System");
			System.out.println("Enter your choice: ");
			choice = inp.nextInt();
			inp.nextLine();
			switch(choice)
			{
				case 1:
					nr.acceptDetails(inp);
					nr.calculateFare();
					nr.displayDetails();
					break;
				case 2:
					ar.acceptDetails(inp);
					ar.calculateFare();
					ar.displayDetails();
					break;
				case 3:
					System.out.println("Exiting Program !!!");
					break;
				default:
					System.out.println("Invalid Choice !!!");
					break;
			}
		}while(choice!=3);
		inp.close();
	}
}
