class Shape
{
 	int length,breadth;
	float area;
	void area()
	{

	}
}
class Rectangle extends Shape
{
	Rectangle(int a,int b)
	{
	 length=a;
	 breadth=b;
	}
 	void area()
	{
	 area=length*breadth;
	 System.out.println("The area of rectangle is"+area);
	}

}
class Triangle extends Shape
{	Triangle(int x,int y)
	{
	 length=x;
	 breadth=y;
	}
	void area()
	{
	 area=0.5f*length*breadth;
	 System.out.println("Area of triangle is"+area);
	}

}
class CalculateArea
{
	public static void main(String[] args)
	{
	 Rectangle r=new Rectangle(2,2);
	 r.area();
	 Triangle t=new Triangle(4,5);
	 t.area();
	}
}