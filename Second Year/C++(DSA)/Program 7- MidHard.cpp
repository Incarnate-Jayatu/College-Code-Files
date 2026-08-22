//Program 7
/* Represent occupied shelves using a Sparse Matrix ADT and efficiently search, add, 
or remove books. */

#include <iostream>
#include <string>

using namespace std;
const int MAX_OCCUPIED_SHELVES = 150;	// Maximum capacity limit for the sparse array

struct OccupiedShelf 	// Structure to store a single occupied shelf entry
{
    int aisle;
    int shelf;
    string bookTitle;
};

class LibrarySparseMatrix 
{
	private:
    	int totalAisles;
    	int shelvesPerAisle;
    	OccupiedShelf occupiedList[MAX_OCCUPIED_SHELVES]; 		// Fixed size array storing only occupied shelves
    	int currentOccupiedCount;
    
    	int findShelfIndex(int aisle, int shelf) 	// Helper to find the array index of a specific shelf
		{
        	for (int i = 0; i < currentOccupiedCount; ++i) {
        		
            	if (occupiedList[i].aisle == aisle && occupiedList[i].shelf == shelf) 
				{
                	return i; // Found the entry
            	}
        	}
        	return -1; // Shelf is empty
    	}

    	bool isValid(int aisle, int shelf) 		// Helper to validate boundaries without using exceptions
		{
        	if (aisle < 0 || aisle >= totalAisles || shelf < 0 || shelf >= shelvesPerAisle) 
			{
            	cout << "Error: Out of bounds (Aisle: " << aisle << ", Shelf: " << shelf << ").\n";
            	return false;
        	}
        	return true;
    	}

	public:
    	LibrarySparseMatrix(int aisles, int shelves) 	// Constructor
		{
        	totalAisles = aisles;
        	shelvesPerAisle = shelves;
    	    currentOccupiedCount = 0;
	    }

    	void addBook(int aisle, int shelf, string bookTitle) 	// ADT Operation: Add/Place a book on a shelf
		{
        	if (!isValid(aisle, shelf)) return;
        	int index = findShelfIndex(aisle, shelf);

        	if (index != -1) 	 // Scenario 1: Shelf is already occupied, overwrite/update the book title
			{
            	occupiedList[index].bookTitle = bookTitle;
            	cout << "Shelf updated. Old book replaced with \"" << bookTitle << "\" at Aisle " << aisle << ", Shelf " << shelf << ".\n";
            	return;
        	}

        	if (currentOccupiedCount < MAX_OCCUPIED_SHELVES) 	// Scenario 2: New shelf assignment, add to the end of our list
			{
            	occupiedList[currentOccupiedCount].aisle = aisle;
            	occupiedList[currentOccupiedCount].shelf = shelf;
            	occupiedList[currentOccupiedCount].bookTitle = bookTitle;
            	currentOccupiedCount++;
            	cout << "Book \"" << bookTitle << "\" successfully added to Aisle " << aisle << ", Shelf " << shelf << ".\n";
        	} 
			else 
			{
            	cout << "Error: Storage limit reached. Cannot add more books to the sparse matrix.\n";
        	}
    	}

    
    	void removeBook(int aisle, int shelf) 	// ADT Operation: Remove a book (remove item and shift remaining array elements)
		{
        	if (!isValid(aisle, shelf)) return;
        	int index = findShelfIndex(aisle, shelf);

        	if (index != -1) 
			{
            	string removedBook = occupiedList[index].bookTitle;
            	for (int i = index; i < currentOccupiedCount - 1; ++i) 		// Shift remaining elements left to fill the gap
				{
                	occupiedList[i] = occupiedList[i + 1];
            	}
            	currentOccupiedCount--;
            	cout << "Book \"" << removedBook << "\" removed from Aisle " << aisle << ", Shelf " << shelf << ".\n";
        	} 
			else 
			{
            	cout << "Aisle " << aisle << ", Shelf " << shelf << " is already empty.\n";
        	}
    	}

    	string getBook(int aisle, int shelf) 	// ADT Operation: Search / Look up a book title
		{
        	if (!isValid(aisle, shelf)) return "Invalid Location";
        	int index = findShelfIndex(aisle, shelf);
        	if (index != -1) 
			{
            	return "\"" + occupiedList[index].bookTitle + "\"";
        	}
        	return "Empty Shelf";
    	}

    	void displayInventoryReport() 	  // Output stats
		{
        	int totalShelves = totalAisles * shelvesPerAisle;
        	double storageUtilization = ((double)currentOccupiedCount / totalShelves) * 100.0;

        	cout << "\n===============================\n";
        	cout << "   LIBRARY INVENTORY REPORT   \n";
        	cout << "===============================\n";
        	cout << "Total Aisles Available : " << totalAisles << "\n";
        	cout << "Shelves Per Aisle      : " << shelvesPerAisle << "\n";
        	cout << "Total Shelf Capacities : " << totalShelves << "\n";
        	cout << "Occupied Shelves Total : " << currentOccupiedCount << " / " << totalShelves << "\n";
        	cout << "Sparse Array Storage   : " << currentOccupiedCount << " / " << MAX_OCCUPIED_SHELVES << " tracking slots used\n";
        	cout << "Space Utilization Rate : " << storageUtilization << "%\n";
        	cout << "===============================\n";
    	}
};

int main() 
{
    int totalAisles, shelvesPerAisle;
    cout << "=== Initialize Library Configuration ===\n";
    cout << "Enter total number of Aisles: ";
    cin >> totalAisles;
    cout << "Enter number of Shelves per Aisle: ";
    cin >> shelvesPerAisle;

    LibrarySparseMatrix library(totalAisles, shelvesPerAisle);		// Construct the sparse matrix system

    int choice;
    do 
	{
        cout << "\n--- LIBRARY ADT MANAGEMENT MENU ---\n";
        cout << "1. Add Book (Occupy Shelf)\n";
        cout << "2. Remove Book (Free Shelf)\n";
        cout << "3. Search Shelf (Look up Book)\n";
        cout << "4. Generate Inventory Report\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        int aisle, shelf;
        string bookTitle;

        switch (choice) 
		{
            case 1:
                cout << "Enter Aisle Number: ";
                cin >> aisle;
                cout << "Enter Shelf Number: ";
                cin >> shelf;
                cout << "Enter Book Title (Use underscores instead of spaces): ";
                cin >> bookTitle; // Simple extraction
                library.addBook(aisle, shelf, bookTitle);
                break;

            case 2:
                cout << "Enter Aisle Number: ";
                cin >> aisle;
                cout << "Enter Shelf Number: ";
                cin >> shelf;
                library.removeBook(aisle, shelf);
                break;

            case 3:
                cout << "Enter Aisle Number: ";
                cin >> aisle;
                cout << "Enter Shelf Number: ";
                cin >> shelf;
                cout << "Result: " << library.getBook(aisle, shelf) << "\n";
                break;

            case 4:
                library.displayInventoryReport();
                break;

            case 5:
                cout << "Exiting system. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please select an option between 1 and 5.\n";
        }
    } while (choice != 5);
    return 0;
}
