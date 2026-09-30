class Example implements Runnable
{
	synchronized public void run()
	{
		for(int i=0; i<=10; i++)
			System.out.println("Value: " + i +" || Printed by: " + Thread.currentThread().getName());
	}
}

class Test
{
	public static void main(String []args)
	{
		Example e1 = new Example();
		Thread t1 = new Thread(e1);
		Thread t2 = new Thread(e1);
		t1.start(); t2.start();
	}
}