class Parent
{
	String name="A";
	int age=47;
}

class Child extends Parent
{
	String name="J";
	int age=18;
	void display()
	{
		System.out.println("Child's name is: "+name);
		System.out.println("Child's age is: "+age);
		System.out.println("Parent's name is: "+super.name);
		System.out.println("Parent's age is: "+super.age);
	}
}

class Super
{
	public static void main(String []args)
	{
		Child ch = new Child();
		ch.display();
	}
}