class Parent{
	void education()
	{
		System.out.println("Education: MBA");
	}
	void property()
	{
		System.out.println("Hidden");
	}
}


class Child extends Parent{
void education()
	{
		System.out.println("Education: B.Tech");
	}
}
	

class Inheritance
{
	public static void main(String []args)
	{
		Child c=new Child();
		c.education();
		c.property();
		Parent p=new Parent();
		p.education();
		p.property();
	}
};
