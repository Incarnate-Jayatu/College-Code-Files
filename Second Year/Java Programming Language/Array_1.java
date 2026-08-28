class Array
{
	public static void main(String []args)
	{
		int[] arr = new int[5];
		arr[0] = 10;
		arr[2] = 20;
		arr[4] = 0;
	
		try
		{
			System.out.println(arr[2]/arr[4]);
			System.out.println(arr[5]);	
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println("Element out of index accessed !!");
		}
		catch(ArithmeticException i)
		{
			System.out.println("Division by 0 is not allowed for integers!!!");
		}
	}
}