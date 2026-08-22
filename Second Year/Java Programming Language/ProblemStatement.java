/* There is a vehicle class which has method: 
1. change gear, 2. speed up, 3. apply brake 
Create classes Bike, bicycle and car, implementing functionalities in their own way*/

import java.util.*;
abstract class Vehicle
{	
	abstract void changegear(int g);
	abstract void speedup(int s);
	abstract void applybrake();
}

class Bike extends Vehicle
{
	void changegear(int g)
	{
		System.out.println("Switching to your desired gear.");
		System.out.println("Gear succesfully changed to "+g);
	}

	void speedup(int s)
	{
		int ns=50+s;
		System.out.println("Increasing to your desired speed.");
		System.out.println("New speed is: "+ns);
	
	}


	void applybrake()
	{
		System.out.println("Applying Brake");
		System.out.println("Speed is reducing");
		System.out.println("Current speed is 0 and Bike has stopped");
	}
}

class Car extends Vehicle
{
	void changegear(int g)
	{
		System.out.println("Switching to your desired gear.");
		System.out.println("Gear succesfully changed to "+g);
	
	}

	void speedup(int s)
	{
		int ns=65+s;
		System.out.println("Increasing to your desired speed.");
		System.out.println("New speed is: "+ns);
	}


	void applybrake()
	{
		System.out.println("Applying Brake");
		System.out.println("Speed is reducing");
		System.out.println("Current speed is 0 and Car has stopped");	
	}

}

class Bicycle extends Vehicle
{
	void changegear(int g)
	{
		System.out.println("Switching to your desired gear.");
		System.out.println("Gear succesfully changed to "+g);
	
	}

	void speedup(int s)
	{
		int ns=10+s;
		System.out.println("Increasing to your desired speed.");
		System.out.println("New speed is: "+ns);	
	}


	void applybrake()
	{
		System.out.println("Applying Brake");
		System.out.println("Speed is reducing");
		System.out.println("Current speed is 0 and Bicycle has stopped");	
	}

}

class ProblemStatement
{
	public static void main(String []args)
	{
		Scanner s = new Scanner(System.in);
		System.out.println("");
		System.out.println("Select you vehicle choice: ");
		System.out.println("1. Car \n2.Bike \n3.Bicycle");
		int choice=s.nextInt();
		switch(choice)
		{
			case 1:
				Car c = new Car();
				System.out.println("");
				System.out.println("Select you operation choice for Car: ");
				System.out.println("1. Change Gear \n2.Speed Up \n3.Apply Breake");
				int choice2=s.nextInt();
				switch(choice2)
				{
					case 1:
						System.out.println("");
						System.out.println("Current gear is Neutral.");
						System.out.println("Enter gear you want to switch to: ");
						int gear=s.nextInt();
						c.changegear(gear);
						break;
					case 2:
						System.out.println("");
						System.out.println("Current speed is 65kmph.");
						System.out.println("Enter the speed you want to increase: ");
						int speed=s.nextInt();
						c.speedup(speed);
						break;
					case 3:
						System.out.println("");
						System.out.println("Current speed is 70kmph.");
						c.applybrake();
						break;
					default:
						System.out.println("");
						System.out.println("Invalid Choice!!");
						break;
				}
				break;
			case 2:
				Bike b = new Bike();
				System.out.println("");
				System.out.println("Select you operation choicefor Bike: ");
				System.out.println("1. Change Gear \n2.Speed Up \n3.Apply Breake");
				int choice3=s.nextInt();
				switch(choice3)
				{
					case 1:
						System.out.println("");
						System.out.println("Current gear is Neutral.");
						System.out.println("Enter gear you want to switch to: ");
						int gear=s.nextInt();
						b.changegear(gear);
						break;
					case 2:
						System.out.println("");
						System.out.println("Current speed is 50kmph.");
						System.out.println("Enter the speed you want to increase: ");
						int speed=s.nextInt();
						b.speedup(speed);
						break;
					case 3:
						System.out.println("");
						System.out.println("Current speed is 65kmph.");
						b.applybrake();
						break;
					default:
						System.out.println("");
						System.out.println("Invalid Choice!!");
						break;
				}
				break;
			case 3:
				Bicycle bc = new Bicycle();
				System.out.println("");
				System.out.println("Select you operation choice for Bicycle: ");
				System.out.println("1. Change Gear \n2.Speed Up \n3.Apply Breake");
				int choice4=s.nextInt();
				switch(choice4)
				{
					case 1:
						System.out.println("");
						System.out.println("Current gear is 1.");
						System.out.println("Enter gear you want to switch to: ");
						int gear=s.nextInt();
						bc.changegear(gear);
						break;
					case 2:
						System.out.println("");
						System.out.println("Current speed is 10kmph.");
						System.out.println("Enter the speed you want to increase: ");
						int speed=s.nextInt();
						bc.speedup(speed);
						break;
					case 3:
						System.out.println("");
						System.out.println("Current speed is 20kmph.");
						bc.applybrake();
						break;
					default:
						System.out.println("");
						System.out.println("Invalid Choice!!");
						break;
				}
				break;
			default:
				System.out.println("");
				System.out.println("Invalid Choice!!");
		}
		
	}
}
