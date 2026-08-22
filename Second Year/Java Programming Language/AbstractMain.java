//Abstract Class

import java.util.*;

abstract class Shape
{
	abstract void area();
}

class Triangle extends Shape
{
	double area;
	Triangle(double ht, double bs)
	{
		double height=ht;
		double base=bs;
		area=0.5*height*base;
	}

	void area()
	{
		System.out.println("Area of Triangle is:" +area +" sq. units");
	}
}

class Rectangle extends Shape
{
	double area;
	Rectangle(double len, double bd)
	{
		double length=len;
		double breadth=bd;
		area=length*breadth;
	}

	void area()
	{
		System.out.println("Area of Rectangle is:" +area +" sq. units");
			
	}
}

class AbstractMain
{
	public static void main(String []args)
	{
		Scanner s = new Scanner(System.in);
		System.out.print("Enter Value of Base of Triangle(decimal values only): ");
		double ba = s.nextDouble();
		System.out.print("Enter Value of Height of Triangle(decimal values only): ");
		double h = s.nextDouble();
		Shape s2 = new Triangle(ba, h);									//Parent Referense = Child Object
		s2.area();
		System.out.println(" ");
		System.out.print("Enter Value of Breadth of Rectangle(decimal values only): ");
		double br = s.nextDouble();
		System.out.print("Enter Value of Length of Rectangle(decimal values only): ");
		double l = s.nextDouble();
		Shape s1 = new Rectangle(l, br);
		s1.area();
	}
}