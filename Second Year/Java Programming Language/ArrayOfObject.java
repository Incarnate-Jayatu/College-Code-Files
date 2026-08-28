class ArrayOfObject
{
	String name;
	int rollNo;
	ArrayOfObject(String n, int r)
	{
		name = n;
		rollNo = r;
	}

	void display()
	{
		System.out.println("Name: "+name +"\nRoll No: "+rollNo);
	}
	public static void main(String []args)
	{
		ArrayOfObject aoo[] = new ArrayOfObject[3];
		aoo[0] = new ArrayOfObject("ACE", 1);
		aoo[1] = new ArrayOfObject("FHJ", 3);
		aoo[2] = new ArrayOfObject("LNP", 4);

		for(int i=0; i<3; i++)
			aoo[i].display();
	}
}