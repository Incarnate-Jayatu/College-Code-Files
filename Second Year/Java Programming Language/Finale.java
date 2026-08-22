//final keyword

final class Parent
{
	final void education()
	{
		System.out.println("B.Com Graduate!");
	}
}
class Child extends Parent
{
	void education()
	{
		final int age=18;
		age++;
		System.out.println("B.Tech Graduate!");
	}

}
class Finale
{
	public static void main(String []args)
	{
		Child c = new Child();
		c.education();
	}
}