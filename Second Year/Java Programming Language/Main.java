import java.util.*;

class LibraryBook {
    int bookid, qty;
    String bookname, authorname;
    static final int MAX_CAPACITY = 100;
    static LibraryBook[] bookList = new LibraryBook[MAX_CAPACITY];
    static int bookCount = 0;
    
    Scanner s = new Scanner(System.in);
    LibraryBook(){ }

    void addbook() 
	{
        if (bookCount >= MAX_CAPACITY) 
		{
            System.out.println("Library is full! Cannot add more books.");
            return;
        }

        System.out.print("Enter Book ID: ");
        int id = s.nextInt();
        s.nextLine(); 

        for (int i = 0; i < bookCount; i++) 
		{
            if (bookList[i].bookid == id) 
			{
                System.out.println("Book ID already exists! Try updating instead.");
                return;
            }
        }

        LibraryBook newBook = new LibraryBook();

        newBook.bookid = id;
        System.out.print("Enter Book Name: ");
        newBook.bookname = s.nextLine();
        System.out.print("Enter Author Name: ");
        newBook.authorname = s.nextLine();
        System.out.print("Enter Quantity: ");
        newBook.qty = s.nextInt();

        bookList[bookCount] = newBook;
        bookCount++;
        System.out.println("Book added successfully!");
    }

    void deletebook() 
	{
        System.out.print("Enter Book ID to delete: ");
        int id = s.nextInt();
        int indexFound = -1;

        for (int i = 0; i < bookCount; i++) 
		{
            if (bookList[i].bookid == id) 
			{
                indexFound = i;
                break;
            }
        }

        if (indexFound != -1) 
		{
            for (int i = indexFound; i < bookCount - 1; i++) 
			{
                bookList[i] = bookList[i + 1];
            }
            bookList[bookCount - 1] = null; 
            bookCount--; // Decrement book total
            System.out.println("Book deleted successfully!");
        } 
        else 
        {
            System.out.println("Book not found!");
        }
    }

    void updatebook() 
    {
        System.out.print("Enter Book ID to update: ");
        int id = s.nextInt();
        s.nextLine(); 

        for (int i = 0; i < bookCount; i++) 
        {
            if (bookList[i].bookid == id) 
            {
                System.out.print("Enter New Book Name: ");
                bookList[i].bookname = s.nextLine();
                System.out.print("Enter New Author Name: ");
                bookList[i].authorname = s.nextLine();
                System.out.print("Enter New Quantity: ");
                bookList[i].qty = s.nextInt();
                System.out.println("Book updated successfully!");
                return;
            }
        }
        System.out.println("Book not found!");
    }

    void searchbook() 
    {
        System.out.print("Enter Book ID to search: ");
        int id = s.nextInt();

        for (int i = 0; i < bookCount; i++) 
        {
            if (bookList[i].bookid == id)
            {
                System.out.println("\n--- Book Found ---");
                System.out.println("ID: " + bookList[i].bookid);
                System.out.println("Name: " + bookList[i].bookname);
                System.out.println("Author: " + bookList[i].authorname);
                System.out.println("Quantity: " + bookList[i].qty);
                return;
            }
        }
        System.out.println("Book not found!");
    }

    void returnbook() 
    {
        System.out.println("1. Issue Book\n2. Return Book");
        System.out.print("Enter choice: ");
        int choice = s.nextInt();
        System.out.print("Enter Book ID: ");
        int id = s.nextInt();

        for (int i = 0; i < bookCount; i++) 
        {
            if (bookList[i].bookid == id) 
            {
                if (choice == 1)
                {
                    if (bookList[i].qty > 0) 
                    {
                        bookList[i].qty--;
                        System.out.println("Book issued successfully! Remaining: " + bookList[i].qty);
                    } 
                    else 
                    {
                        System.out.println("Book is out of stock!");
                    }
                } 
                else if (choice == 2) 
                {
                    bookList[i].qty++;
                    System.out.println("Book returned successfully! Total: " + bookList[i].qty);
                } 
                else 
                {
                    System.out.println("Invalid option!");
                }
                return;
            }
        }
        System.out.println("Book not found!");
    }

    void displaybook() 
    {
        if (bookCount == 0) 
        {
            System.out.println("No books available in the library.");
            return;
        }
        System.out.println("\n----------------- Library Catalog -----------------");
        System.out.printf("%-10s %-25s %-20s %-10s\n", "Book ID", "Title", "Author", "Quantity");
        System.out.println("---------------------------------------------------");
        for (int i = 0; i < bookCount; i++) 
        {
            System.out.printf("%-10d %-25s %-20s %-10d\n", 
                bookList[i].bookid, bookList[i].bookname, bookList[i].authorname, bookList[i].qty);
        }
        System.out.println("---------------------------------------------------");
    }
}

class Main 
{
    public static void main(String []args) 
    {
        LibraryBook lib = new LibraryBook();
        Scanner s = new Scanner(System.in);
        int choice;

        do 
        {
            System.out.println("\n------ Select Your Choice ------");
            System.out.println("1. Add Book \n2. Delete Book \n3. Update Book \n4. Search Book \n5. Issue/Return Book \n6. Display Book \n7. Exit");
            System.out.print("Enter your choice: ");
            choice = s.nextInt();

            switch(choice) 
            {
                case 1: 
                    lib.addbook(); 
                    break;
                case 2: 
                    lib.deletebook(); 
                    break;
                case 3: 
                    lib.updatebook(); 
                    break;
                case 4: 
                    lib.searchbook(); 
                    break;
                case 5: 
                    lib.returnbook(); 
                    break;
                case 6: 
                    lib.displaybook(); 
                    break;
                case 7: 
                    System.out.println("Exiting Program!!"); 
                    break;
                default: 
                    System.out.println("Invalid Choice! Please enter a number between 1 and 7.");
            }
        } while(choice != 7);
        s.close();
    }
}
