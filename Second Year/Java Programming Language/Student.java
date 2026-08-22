/* Take student input
Name, roll no and marks of 3 subjects
Print average of 3 marks in respective methods */

import java.util.*;
class Student
{

	void display(String n, int r, float a, int s1, int s2, int s3, int t)
	{
		System.out.println("Name: "+n);
		System.out.println("Roll No: "+r);
		System.out.println("Marks of Subject 1: "+s1);
		System.out.println("Marks of Subject 2: "+s2);
		System.out.println("Marks of Subject 3: "+s3);
		System.out.println("Total Marks: "+t);
		System.out.println("Average of marks: "+a);
	}
		
	
	public static void main(String []args)
	{
		Scanner s = new Scanner(System.in);
		System.out.print("Enter name of student:  ");
		String name = s.nextLine();
		System.out.println(" ");
		System.out.print("Enter Roll No of student:  ");
		int rollno = s.nextInt();
		System.out.println(" ");
		System.out.print("Enter marks of subject 1:  ");
		int sub1 = s.nextInt();
		System.out.println(" ");
		System.out.print("Enter marks of subject 2:  ");
		int sub2 = s.nextInt();
		System.out.println(" ");
		System.out.print("Enter marks of subject 3:  ");
		int sub3 = s.nextInt();
		System.out.println(" ");
		int total=sub1+sub2+sub3;
		float average=total/3;

		Student st = new Student();
		st.display(name, rollno, average, sub1, sub2, sub3, total);
	}
};