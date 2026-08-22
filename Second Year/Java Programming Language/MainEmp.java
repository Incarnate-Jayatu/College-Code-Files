import java.util.*;

class Employee
{
    int empID, yearsOfService, basicSalary;
    String name, department;

    void addEmployee(int empID, String name, String department, int yearsOfService, int basicSalary)
    {
        this.empID = empID;
        this.name = name;
        this.department = department;
        this.yearsOfService = yearsOfService;
        this.basicSalary = basicSalary;
    }

    double calculateSalary()
    {
        double allowance = 0.20 * basicSalary;
        double increments = yearsOfService * (0.07 * basicSalary);

        return basicSalary + allowance + increments;
    }
    void display()
    {
        System.out.println("Employee ID     : " + empID);
        System.out.println("Name            : " + name);
        System.out.println("Department      : " + department);
        System.out.println("Years of Service: " + yearsOfService);
        System.out.println("Basic Salary    : " + basicSalary);
        System.out.println("Total Salary    : " + calculateSalary());
    }
}


class Manager extends Employee
{
    int teamSize;
    String level, task;
    void addManager(int empID, String name, String department, int yearsOfService, int basicSalary, int teamSize, String level)
    {
        super.addEmployee(empID, name, department, yearsOfService, basicSalary);
        this.level = level;
        this.teamSize = teamSize;
    }
    void assignTask(String task)
    {
        this.task = task;
    }
    double calculateSalary()
    {
        double demoCalculated = super.calculateSalary();
        double bonus = teamSize * 0.03 * basicSalary;
        return demoCalculated + bonus;
    }
    void display()
    {
        System.out.println("\n----------------------------------------------------------");
        super.display();
        System.out.println("Team Size       : " + teamSize);
        System.out.println("Manager Level   : " + level);
        System.out.println("Assigned Task   : " + task);
        System.out.println("----------------------------------------------------------\n");
    }
}


class Developer extends Employee
{
    String language, level;
    double certBonusPercent;
    void addDeveloper(int empID, String name, String department, int yearsOfService, int basicSalary, String language, String level)
    {
        super.addEmployee(empID, name, department, yearsOfService, basicSalary);
        this.level = level;
        this.language = language;
    }
    void writeCode()
    {
        System.out.println("\nDeveloper is writing code in "+ language + " language.");
        System.out.println("----------------------------------------------------------\n");
    }
    double calculateSalary()
    {
        double demoCalculated = super.calculateSalary();
        if(language.equalsIgnoreCase("C"))
        {
            certBonusPercent = 0.02;
        }
        else if(language.equalsIgnoreCase("Java"))
        {
            certBonusPercent = 0.05;
        }
        else if(language.equalsIgnoreCase("CPP"))
        {
            certBonusPercent = 0.03;
        }
        else if(language.equalsIgnoreCase("Python"))
        {
            certBonusPercent = 0.05;
        }
        else
        {
            certBonusPercent = 0.0;
        }
        double certBonus = certBonusPercent * basicSalary;
        return demoCalculated + certBonus;
    }
    void display()
    {
        System.out.println("\n----------------------------------------------------------");
        super.display();
        System.out.println("Skill/Language  : " + language);
        System.out.println("Developer Level : " + level);
        System.out.println("----------------------------------------------------------\n");
    }
}


class SeniorManager extends Manager
{
    int numberOfTeams, budget;
    String projectType;
    void addSeniorManager(int empID, String name, String department, int yearsOfService, int basicSalary, int numberOfTeams, String projectType)
    {
        super.addEmployee(empID, name, department, yearsOfService, basicSalary);
        this.numberOfTeams = numberOfTeams;
        this.projectType = projectType;
        this.teamSize = numberOfTeams;
        this.level = "Senior Manager";
    }
    void allocateBudget(int budget)
    {
        this.budget = budget;
        System.out.println("Allocated Budget For Your Project: " + budget);
    }
    double calculateSalary()
    {
        return super.calculateSalary();
    }
    void display()
    {
        super.display();
        System.out.println("Number of Teams : " + numberOfTeams);
        System.out.println("Project Type    : " + projectType);
        System.out.println("Allocated Budget: " + budget);
        System.out.println("----------------------------------------------------------\n");
    }
}


class MainEmp
{
    public static void main(String[] args)
    {
        // Object Declarations
        Scanner input = new Scanner(System.in);
        SeniorManager srmgr = new SeniorManager();
        Manager mgr = new Manager();
        Developer dev = new Developer();

        // Super function Variables
        int empID, yearsOfService, basicSalary;
        String name, department;

        // Additional Variables
        int numberOfTeams, teamSize;
        String level, language, projectType, task;

        // Main Code
        int choice;
        do
        {
            System.out.println("Select your employee choice: ");
            System.out.println("1. Senior Manager");
            System.out.println("2. Manager");
            System.out.println("3. Developer");
            System.out.println("4. Exit");
            System.out.println("Enter your choice: ");
            choice = input.nextInt();

            if(choice >= 1 && choice <= 3)
            {
                System.out.println("\n----------------------------------------------------------");
                System.out.println("--------------------ENTER EMPLOYEE DETAILS----------------");
                System.out.println("----------------------------------------------------------\n");
                System.out.println("Enter Employee ID: ");
                empID = input.nextInt();
                input.nextLine();
                System.out.println("Enter Employee Name: ");
                name = input.nextLine();
                System.out.println("Enter Department: ");
                department = input.nextLine();
                System.out.println("Enter year of Service: ");
                yearsOfService = input.nextInt();
                System.out.println("Enter Basic Salary: ");
                basicSalary = input.nextInt();
                input.nextLine();
                switch(choice)
                {
                    case 1:
                    {
                        System.out.println("Enter Project Type: ");
                        projectType = input.nextLine();
                        System.out.println("Number of Teams: ");
                        numberOfTeams = input.nextInt();
                        System.out.println("Enter Budget to be Allocated: ");
                        int budget = input.nextInt();
                        srmgr.addSeniorManager(empID, name, department, yearsOfService, basicSalary, numberOfTeams, projectType);
                        srmgr.allocateBudget(budget);
                        srmgr.display();
                        break;
                    }
                    case 2:
                    {
                        System.out.println("Enter Level: ");
                        level = input.nextLine();
                        System.out.println("Enter Team Size: ");
                        teamSize = input.nextInt();
                        input.nextLine();
                        System.out.println("Enter Task: ");
                        task = input.nextLine();
                        mgr.addManager(empID, name, department, yearsOfService, basicSalary, teamSize, level);
                        mgr.assignTask(task);
                        mgr.display();
                        break;
                    }
                    case 3:
                    {
                        System.out.println("Enter Level: ");
                        level = input.nextLine();
                        System.out.println("Enter Language/Skill: ");
                        language = input.nextLine();
                        dev.addDeveloper(empID, name, department, yearsOfService, basicSalary, language, level);
                        dev.writeCode();
                        dev.display();
                        break;
                    }
                }
            }
            else if(choice == 4)
            {
                System.out.println("Exiting Program !!!");
            }
            else
            {
                System.out.println("Invalid Choice !!!");
            }
        } while(choice != 4);
        input.close();
    }
}