class Shadow
{
	int x=10;
	void display(int x)
	{
		System.out.println(x);
		System.out.println(this.x);
	}
}
class ShadowPro
{
	public static void main(String []args)
	{
		Shadow s = new Shadow();
		s.display(12);
	}
}