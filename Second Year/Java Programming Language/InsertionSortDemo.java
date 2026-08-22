import java.util.*;

public class InsertionSortDemo {

    // Insertion Sort implementation
    public static void insertionSort(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int key = a[i];
            int j = i - 1;

            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
    }

    // Print array elements
    public static void printArray(int[] a) {
        for (int num : a) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();

        System.out.print("Enter array size: ");
        int size = sc.nextInt();

        int choice;
        do {
            System.out.println("\n--- MENU ---");
            System.out.println("1. Ascending array");
            System.out.println("2. Descending array");
            System.out.println("3. Random array");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            int[] arr = new int[size];
            int j;

            switch (choice) {
                case 1: // Ascending
                    j = 10;
                    for (int i = 0; i < size; i++) {
                        arr[i] = j;
                        j += 10;
                    }
                    break;

                case 2: // Descending
                    j = size * 10;
                    for (int i = 0; i < size; i++) {
                        arr[i] = j;
                        j -= 10;
                    }
                    break;

                case 3: // Random
                    for (int i = 0; i < size; i++) {
                        arr[i] = rand.nextInt(100) + 1;
                    }
                    break;

                case 4:
                    System.out.println("Exiting...");
                    continue;

                default:
                    System.out.println("Invalid choice!");
                    continue;
            }

            // Timing
            long start = System.nanoTime();
            insertionSort(arr);
            long end = System.nanoTime();

            System.out.println("Sorting time: " + (end - start) / 1_000_000.0 + " ms");

            System.out.print("Sorted array: ");
            printArray(arr);

        } while (choice != 4);

        sc.close();
    }
}