import java.util.*;

interface Vehicle {
    void start();
    void stop();
    void getSpeed();
    void fuelType();
}

interface Maintenance {
    int charge = 500;
    int performMaintenance();
}

class Car implements Vehicle, Maintenance {
    Scanner s;

    Car(Scanner s) {
        this.s = s;
    }

    public void start() {
        System.out.print("Do you want to start your Car? (Yes/No): ");
        String choice = s.nextLine();

        if (choice.equalsIgnoreCase("Yes") || choice.equalsIgnoreCase("Y"))
            System.out.println("Car started successfully.");
        else
            System.out.println("Didn't start the Car.");
    }

    public void stop() {
        System.out.print("Do you want to stop your Car? (Yes/No): ");
        String choice = s.nextLine();

        if (choice.equalsIgnoreCase("Yes") || choice.equalsIgnoreCase("Y"))
            System.out.println("Car stopped successfully.");
        else
            System.out.println("Didn't stop the Car.");
    }

    public void getSpeed() {
        try {
            System.out.print("Enter your current speed: ");
            int speed = s.nextInt();
            s.nextLine();

            if (speed <= 80) {
                System.out.println("You are driving within the maximum permissible speed.");
                System.out.println("Current Speed: " + speed + " kmph");
            } else {
                System.out.println("Reduce Your Speed!");
                System.out.println("Your speed is " + (speed - 80) + " kmph above the limit.");
            }
        } catch (InputMismatchException e) {
            System.out.println("Error! Speed can only be an integer.");
            s.nextLine();
        }
    }

    public void fuelType() {
        System.out.print("Select Fuel Type (Petrol/Diesel/CNG/Hybrid): ");
        String fuel = s.nextLine();
        System.out.println("Fuel Type: " + fuel);
    }

    public int performMaintenance() {
        return charge + 1520;
    }
}

class Bus implements Vehicle, Maintenance {
    Scanner s;

    Bus(Scanner s) {
        this.s = s;
    }

    public void start() {
        System.out.print("Do you want to start your Bus? (Yes/No): ");
        String choice = s.nextLine();

        if (choice.equalsIgnoreCase("Yes") || choice.equalsIgnoreCase("Y"))
            System.out.println("Bus started successfully.");
        else
            System.out.println("Didn't start the Bus.");
    }

    public void stop() {
        System.out.print("Do you want to stop your Bus? (Yes/No): ");
        String choice = s.nextLine();

        if (choice.equalsIgnoreCase("Yes") || choice.equalsIgnoreCase("Y"))
            System.out.println("Bus stopped successfully.");
        else
            System.out.println("Didn't stop the Bus.");
    }

    public void getSpeed() {
        try {
            System.out.print("Enter your current speed: ");
            int speed = s.nextInt();
            s.nextLine();

            if (speed <= 60) {
                System.out.println("You are driving within the maximum permissible speed.");
                System.out.println("Current Speed: " + speed + " kmph");
            } else {
                System.out.println("Reduce Your Speed!");
                System.out.println("Your speed is " + (speed - 60) + " kmph above the limit.");
            }
        } catch (InputMismatchException e) {
            System.out.println("Error! Speed can only be an integer.");
            s.nextLine();
        }
    }

    public void fuelType() {
        System.out.print("Select Fuel Type (Petrol/Diesel/CNG/Hybrid): ");
        String fuel = s.nextLine();
        System.out.println("Fuel Type: " + fuel);
    }

    public int performMaintenance() {
        return charge + 3585;
    }
}

class Motorcycle implements Vehicle, Maintenance {
    Scanner s;

    Motorcycle(Scanner s) {
        this.s = s;
    }

    public void start() {
        System.out.print("Do you want to start your Motorcycle? (Yes/No): ");
        String choice = s.nextLine();

        if (choice.equalsIgnoreCase("Yes") || choice.equalsIgnoreCase("Y"))
            System.out.println("Motorcycle started successfully.");
        else
            System.out.println("Didn't start the Motorcycle.");
    }

    public void stop() {
        System.out.print("Do you want to stop your Motorcycle? (Yes/No): ");
        String choice = s.nextLine();

        if (choice.equalsIgnoreCase("Yes") || choice.equalsIgnoreCase("Y"))
            System.out.println("Motorcycle stopped successfully.");
        else
            System.out.println("Didn't stop the Motorcycle.");
    }

    public void getSpeed() {
        try {
            System.out.print("Enter your current speed: ");
            int speed = s.nextInt();
            s.nextLine();

            if (speed <= 70) {
                System.out.println("You are driving within the maximum permissible speed.");
                System.out.println("Current Speed: " + speed + " kmph");
            } else {
                System.out.println("Reduce Your Speed!");
                System.out.println("Your speed is " + (speed - 70) + " kmph above the limit.");
            }
        } catch (InputMismatchException e) {
            System.out.println("Error! Speed can only be an integer.");
            s.nextLine();
        }
    }

    public void fuelType() {
        System.out.print("Select Fuel Type (Petrol/Diesel/CNG/Hybrid): ");
        String fuel = s.nextLine();
        System.out.println("Fuel Type: " + fuel);
    }

    public int performMaintenance() {
        return charge + 890;
    }
}

public class TestVehicle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("-------------------------------");
        System.out.println("      Vehicle Type: Car");
        System.out.println("-------------------------------");
        Car c = new Car(sc);
        c.start();
        c.stop();
        c.getSpeed();
        c.fuelType();
        System.out.println("Maintenance Charges: ₹" + c.performMaintenance());

        System.out.println("\n-------------------------------");
        System.out.println("      Vehicle Type: Bus");
        System.out.println("-------------------------------");
        Bus b = new Bus(sc);
        b.start();
        b.stop();
        b.getSpeed();
        b.fuelType();
        System.out.println("Maintenance Charges: ₹" + b.performMaintenance());

        System.out.println("\n-------------------------------");
        System.out.println("   Vehicle Type: Motorcycle");
        System.out.println("-------------------------------");
        Motorcycle m = new Motorcycle(sc);
        m.start();
        m.stop();
        m.getSpeed();
        m.fuelType();
        System.out.println("Maintenance Charges: ₹" + m.performMaintenance());

        sc.close();
    }
}