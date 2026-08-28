class ThreadDemo extends Thread
{
	public void run()
	{
		for(int i=0; i<4; i++)
			System.out.println(Thread.currentThread().getName());
	}
	public static void main(String []args)
	{
		ThreadDemo t3 = new ThreadDemo();
		ThreadDemo t4 = new ThreadDemo();
		ThreadDemo t2 = new ThreadDemo();
		ThreadDemo t1 = new ThreadDemo();

		t1.setPriority(3);
		t4.setPriority(10);		

		t1.start();
		t2.start();
		t4.start();
		t3.start();
	}
}