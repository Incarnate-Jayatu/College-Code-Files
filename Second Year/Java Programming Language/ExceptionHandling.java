import java.util.*;

class ExceptionHandling
{
	public static void main(String []args)
	{
		Scanner inp = new Scanner(System.in);
		System.out.println("Enter first number: ");
		int num1 = inp.nextInt();
		System.out.println("Enter second number: ");
		int num2 = inp.nextInt();
		int res;
		try
		{	
			res = num1/num2;
			System.out.println("Division of number 1 by number 2 gives result: "+res);
		}catch(ArithmeticException e)
		{
			System.out.println("Cannot divide any number by 0!!!");
		}
		finally
		{
			System.out.println("Finally Block Executed!!!");
			inp.close();
		}
	}
}