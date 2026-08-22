import java.util.*;

class ExceptionHandlingDemo
{
	public static void main(String []args)
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter 1st number: ");
		double a = s.nextDouble();
		System.out.println("Enter 2nd number: ");
		double b = s.nextDouble();
		double res;

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
}