// Animal

abstract class Animal
{
	abstract void walk();
	abstract void talk();
}

class Turtle extends Animal
{
	void walk()
	{
		System.out.println("I walk slowly!");
	}
	void talk()
	{
		System.out.println("Hello I'm Turtle!");
	}
}

class Frog extends Animal
{
	void walk()
	{
		System.out.println("Frog hops!");
	}
	void talk()
	{
		System.out.println("Frog makes Ribbit-Ribbit sound!");
	}
}

class Duck extends Animal
{
	void walk()
	{
		System.out.println("Ducks walks on toes!");
	}
	void talk()
	{
		System.out.println("Duck makes Quack-Quack sound!");
	}
}

class Main
{
	public static void main(String []args)
	{
		System.out.println(" ");
		Turtle t = new Turtle();
		t.talk();
		t.walk();
		System.out.println(" ");
		Frog f = new Frog();
		f.talk();
		f.walk();
		System.out.println(" ");
		Duck d = new Duck();
		d.talk();
		d.walk();
		System.out.println(" ");
		
		Animal a = new Animal();
	}
}