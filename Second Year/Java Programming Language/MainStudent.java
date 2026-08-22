/* Create an abstract class student with following methods:
1. Get student name
2. Get ssc marks
3. Get hsc marks

create class StudentDetails and print marks of harish Jayant and vijay
*/

import java.util.*;
abstract class Student
{
	abstract void SSCdetails();
	abstract void HSCdetails();
}
class StudentDetails extends Student
{
	String name;
	int ssctotal, hsctotal;
	double sscaverage, sscpercentage, hscaverage, hscpercentage;
	StudentDetails(String n, int st, int ht)
	{
		name = n;
		ssctotal=st;
		hsctotal=ht;
	}
	
	public void SSCdetails()
	{
		sscaverage=ssctotal/6;
		sscpercentage=(ssctotal*100)/600;
	}
	public void HSCdetails()
	{
		hscaverage=hsctotal/6;
		hscpercentage=(hsctotal*100)/600;
	}
	void displaydetails()
	{
		System.out.println("\n---------- --------------- -----------");
		System.out.println("Student Name: "+name);
		System.out.println("SSC Total Marks: "+ssctotal);
		System.out.println("SSC Average Marks: "+sscaverage);		
		System.out.println("SSC Percentage: "+sscpercentage +"%");
		System.out.println("HSC Total Marks: "+hsctotal);
		System.out.println("HSC Average Marks: "+sscaverage);
		System.out.println("HSC Percentage: "+hscpercentage +"%");
		System.out.println("\n---------- --------------- -----------");

	}
}
class MainStudent
{
	public static void main(String []args)
	{
		StudentDetails s1 = new StudentDetails("Harish", 485, 440);
		s1.SSCdetails();
		s1.HSCdetails();
		s1.displaydetails();
		StudentDetails s2 = new StudentDetails("Jayant", 370, 455);
		s2.SSCdetails();
		s2.HSCdetails();
		s2.displaydetails();
		StudentDetails s3 = new StudentDetails("Vijay", 595, 598);
		s3.SSCdetails();
		s3.HSCdetails();
		s3.displaydetails();		
	}
}

