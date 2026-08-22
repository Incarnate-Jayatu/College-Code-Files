class Overloading
{
	void add(int a, int b)
	{	
		int c = a+b;
		System.out.println("Addition of 2 integer numbers is: "+c);
	}
	void add(int a, int b, int c)
	{	
		int d = a+b+c;
		System.out.println("Addition of 3 integer numbers is: "+d);
	}
	void add(float a, float b, float c)
	{	
		float d = a+b+c;
		System.out.println("Addition of 3 float numbers is: "+d);
	}
	public static void main(String []args)
	{
		Overloading obj=new Overloading();
		obj.add(23, 45);
		obj.add(29, 98, 47);
		obj.add(23.4f, 43.1f, 76.78f);
	}

};