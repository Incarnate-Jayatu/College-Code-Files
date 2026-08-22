import java.util.*;
class SwitchInput
{
	public static void main(String []args)
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
};