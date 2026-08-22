import java.util.*;

class Student 
{
    Scanner inp = new Scanner(System.in);
    int prn;
    String name, department, division, mobile, year;
    double percentage;
    
    enum Year { FY, SY, TY, Final };
    Year yr;

    Student() {}

    Student(String name, int prn) 
    {
        while(name.equals(""))
        {
            System.out.print("Invalid Name! Enter again: ");
            name = inp.nextLine();
        }
        this.name = name;
        while(prn <= 0)
        {
            System.out.print("Invalid PRN! Enter again: ");
            prn = inp.nextInt();
        }
        this.prn = prn;
        inp.nextLine();
        do
        {
            System.out.print("Enter Year (FY/SY/TY/Final): ");
            year = inp.nextLine();
        }while(!(year.equals("FY") || year.equals("SY") || year.equals("TY") || year.equals("Final")));
        yr = Year.valueOf(year);
        do
        {
            System.out.print("Enter Department: ");
            department = inp.nextLine();
        }while(department.equals(""));
        do
        {
            System.out.print("Enter Division: ");
            division = inp.nextLine();
        }while(division.equals(""));
        do
        {
            System.out.print("Enter Mobile No: ");
            mobile = inp.nextLine();
        }while(mobile.length() != 10);
        do
        {  
            System.out.print("Enter Percentage: ");
            percentage = inp.nextDouble();
        }while(percentage < 0 || percentage > 100);
        this.department = department;
        this.division = division;
        this.mobile = mobile;
        this.percentage = percentage;
    }

    Student(String name, int prn, String department, String division, String mobile, double percentage) 
    {
        this.name = name;
        this.prn = prn;
        this.department = department;
        this.division = division;
        this.mobile = mobile;
        this.percentage = percentage;
        this.yr = Year.SY;
    }

    void display() {
        System.out.println("\n-----------------------");
        System.out.println("Name : " + name);
        System.out.println("PRN : " + prn);
        System.out.println("Year : " + yr);
        System.out.println("Department : " + department);
        System.out.println("Division : " + division);
        System.out.println("Mobile : " + mobile);
        System.out.println("Percentage : " + percentage);
        System.out.println("-----------------------");
    }
}

class Test {
    public static void main(String args[]) {

        Scanner input = new Scanner(System.in);

        System.out.println("\n-------------------------------");
		System.out.println("---------STUDENT 1-------------");
		System.out.println("-------------------------------\n");
        System.out.print("Enter Name: ");
        String name = input.nextLine();

        System.out.print("Enter PRN: ");
        int prn = input.nextInt();
        input.nextLine();

        Student s1 = new Student(name, prn);
        s1.display();

        System.out.println("\n-------------------------------");
		System.out.println("---------STUDENT 2-------------");
		System.out.println("-------------------------------\n");
        String department, division, mobile;
        double percentage;
        do
        {
            System.out.print("Enter Department: ");
            department = input.nextLine();
        }while(department.equals(""));
        do
        {
            System.out.print("Enter Division: ");
            division = input.nextLine();
        }while(division.equals(""));
        do
        {
            System.out.print("Enter Mobile No: ");
            mobile = input.nextLine();
        }while(mobile.length() != 10);
        do
        {  
            System.out.print("Enter Percentage: ");
            percentage = input.nextDouble();
        }while(percentage < 0 || percentage > 100);

        Student s2 = new Student("Ashwin", 215, department, division, mobile, percentage);
        s2.display();
    }
}

