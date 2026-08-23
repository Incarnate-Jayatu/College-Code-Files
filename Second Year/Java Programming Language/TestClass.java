import java.util.*;

abstract class Reservation
{
    Integer age;
    String pnr;
    String passengerName;
    Double baseFare;
    Double finalFare;

    void acceptDetails(Scanner scanner)
    {
        System.out.print("Enter PNR Number: ");
        this.pnr = scanner.nextLine();
        System.out.print("Enter Passenger Name: ");
        this.passengerName = scanner.nextLine();
        System.out.print("Enter Age: ");
        this.age = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Enter Base Fare: ");
        this.baseFare = scanner.nextDouble();
        scanner.nextLine();
    }

    abstract void calculateFare();

    void displayDetails()
    {
        System.out.println("\n=============RESERVATION DETAILS=============");
        System.out.println("PNR: " + pnr);
        System.out.println("Passenger Name: " + passengerName);
        System.out.println("Age: " + age);
        System.out.println("Base Fare: Rs. " + baseFare);
        System.out.println("Final Calculated Fare: Rs. " + finalFare);
        System.out.println("---------------------------");
        System.out.println("---------------------------\n");
    }

}

class NormalReservation extends Reservation
{
    void calculateFare()
    {
        if(this.age<12)
        {
            this.finalFare = this.baseFare*0.50;
        }
        else if(this.age>60)
        {
            this.finalFare = this.baseFare*0.70;
        }
        else
        {
            this.finalFare = this.baseFare;
        }
    }
}

class AcReservation extends Reservation
{
    void calculateFare()
    {
        if(this.age<12)
        {
            this.finalFare = this.baseFare*0.50 + this.baseFare*0.30;
        }
        else if(this.age>60)
        {
            this.finalFare = this.baseFare*0.70 + this.baseFare*0.30;
        }
        else
        {
            this.finalFare = this.baseFare + this.baseFare*0.30;
        }
    }
}

class TestClass
{
    public static void main(String []args)
    {
        Scanner inp = new Scanner(System.in);
        NormalReservation nReserve = new NormalReservation();
        AcReservation aReserve = new AcReservation();
        int choice;
        System.out.println("\n===============RAILWAY TICKETING SYSTEM===============");
        do
        {
            System.out.println("Select Reservation Type:");
            System.out.println("1. AC Reservation \n2. Normal Reservation \n3. Exit Program");
            System.out.println("Enter you Choice:  ");
            choice = inp.nextInt();
            inp.nextLine();
            switch(choice)
            {
                case 1:
                    aReserve.acceptDetails(inp);
                    aReserve.calculateFare();
                    aReserve.displayDetails();
                    break;
                case 2:
                    nReserve.acceptDetails(inp);
                    nReserve.calculateFare();
                    nReserve.displayDetails();
                    break;
                case 3:
                    System.out.println("EXITING PROGRAM !!!");
                    break;
                default:
                    System.out.println("Invalid Choice !!!");
                    break;                        
            }
        }while(choice!=3);
    }
}