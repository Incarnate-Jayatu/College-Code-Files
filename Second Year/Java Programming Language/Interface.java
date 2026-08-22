//Interface
interface Exam
{
	void per_cal();
}
class Student
{
	String name;
	int rollno, s1, s2, s3, total, avg, per;
}
class Result extends Student implements Exam
{
	Result(String n, int r, int m1, int m2, int m3)
	{
		name=n;
		rollno=r;
		s1=m1;
		s2=m2;
		s3=m3;
		total=s1+s2+s3;
		avg=total/3;
	}
	public void per_cal()
	{
		per = (total*100)/75;

	}
	void display()
	{
		System.out.println("Name of Student: "+name);
		System.out.println("Roll No of Student: "+rollno);
		System.out.println("Marks of subject 1: "+s1);
		System.out.println("Marks of subject 2: "+s2);
		System.out.println("Marks of subject 3: "+s3);
		System.out.println("Total Marks Scored: "+total);
		System.out.println("Average Marks : "+avg);
		System.out.println("Percentage: "+per +"%");
	}
}
class Interface
{
	public static void main(String []args)
	{

		Result r = new Result("Jayatu", 211, 23, 24, 25);
		r.per_cal();
		r.display();
	}
}