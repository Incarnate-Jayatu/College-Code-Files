import java.util.*;

class ExceptionHandlingNestedDemo
{
	public static void main(String []args)
	{
		Scanner s = new Scanner(System.in);
		//Exception Handling (for input mismatch)
		try
		{
			System.out.println("Enter 1st number: ");
			int a = s.nextInt();
			System.out.println("Enter 2nd number: ");
			int b = s.nextInt();
			int res;

			//Exception Handling(for division by 0)
			try
			{
				res = a/b;
				System.out.println("Addition of the two integers: "+res);
			}
			catch(ArithmeticException e)
			{
				System.out.println("Number can't be divided by zero!!");
			}	
		}
		catch(InputMismatchException i)
		{
			System.out.println("Error!!! \nCharacter has been entered!!");
		}	
	}
}