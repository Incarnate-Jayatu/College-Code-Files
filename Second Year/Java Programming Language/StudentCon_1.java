class StudentCon
{
	String name;
	int rollno, s1, s2,s3, total;
	float average;
	StudentCon()
	{
		name="Jayatu";
		rollno=1012511211;
		s1=95;
		s2=89;
		s3=93;
		total=0;
		average=0;		
	}
	StudentCon(String n, int rn, int x, int y, int z)
	{
		name=n;
		rollno=rn;
		s1=x;
		s2=y;
		s3=z;	
	}

	void calculate()
	{
		total=s1+s2+s3;
		average=total/3;
	}
	void display()
	{
		System.out.println("Name of Student: "+name);
		System.out.println("Roll No of Student: "+rollno);
		System.out.println("Marks of subject 1: "+s1);
		System.out.println("Marks of subject 2: "+s2);
		System.out.println("Marks of subject 3: "+s3);
		System.out.println("Total Marks: "+total);
		System.out.println("Average Marks: "+average);		
		System.out.println(" ");		

	}
	public static void main(String []args)
	{
		StudentCon st = new StudentCon();
		st.calculate();
		st.display();
		StudentCon st1 = new StudentCon("XYZ", 1012511215, 91, 79, 86);
		st1.calculate();
		st1.display();	
	}
};