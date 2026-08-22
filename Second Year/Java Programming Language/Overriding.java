class Sachin
{
 	void eat()
	{
		System.out.print("Sachin is veg");
	}

}
class Arjun extends Sachin
{
	void eat()
	{
		System.out.print("Arjun is non veg");
	}
}

class Overriding
{
	public static void main(String[] args)
	{
		Sachin s=new Sachin();
		s.eat();
		Arjun a=new Arjun();
		a.eat();
	}

}











