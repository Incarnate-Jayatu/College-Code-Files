//Program 6
/* Represent hospital occupancy using a Sparse Matrix ADT where only occupied beds 
are stored.*/
#include <iostream>
#include <string>

using namespace std;

const int MAX_OCCUPIED = 100;	// Maximum capacity limit for the sparse array
struct OccupiedBed 
{
    int ward;
    int bed;
    string patientId;
};

class HospitalSparseMatrix 
{
	private:
    	int totalWards;
    	int bedsPerWard;
    	OccupiedBed occupiedList[MAX_OCCUPIED];		    // Fixed size array storing only occupied beds
    	int currentOccupiedCount;
    	int findBedIndex(int ward, int bed) 		// Helper to find the array index of a specific bed
		{
        	for (int i = 0; i < currentOccupiedCount; ++i) 
			{
            	if (occupiedList[i].ward == ward && occupiedList[i].bed == bed) 
				{
                	return i; 	// Found the entry
            	}
        	}
        	return -1;	 // Bed is empty
    	}

    
    	bool isValid(int ward, int bed) 		// Helper to validate boundaries without using exceptions
		{
        	if (ward < 0 || ward >= totalWards || bed < 0 || bed >= bedsPerWard) 
			{
	            cout << "Error: Out of bounds selection (Ward: " << ward << ", Bed: " << bed << ").\n";
    	        return false;
        	}
        	return true;
    	}

	public:
    	HospitalSparseMatrix(int wards, int beds) 	// Constructor
		{
        	totalWards = wards;
        	bedsPerWard = beds;
        	currentOccupiedCount = 0;
    	}
    	void allocateBed(int ward, int bed, string patientId) 	    // ADT Operation: Allocate an empty bed
		{
        	if (!isValid(ward, bed)) return;
        	int index = findBedIndex(ward, bed);
        	
			if (index != -1) 	        // Scenario 1: Bed is already occupied, update the patient ID
			{
            	occupiedList[index].patientId = patientId;
            	cout << "Patient info updated for Ward " << ward << ", Bed " << bed << ".\n";
            	return;
        	}

	        if (currentOccupiedCount < MAX_OCCUPIED) 	// Scenario 2: New bed allocation, add to the end of our list
			{
    	        occupiedList[currentOccupiedCount].ward = ward;
        	    occupiedList[currentOccupiedCount].bed = bed;
            	occupiedList[currentOccupiedCount].patientId = patientId;
            	currentOccupiedCount++;
            	cout << "Patient successfully admitted to Ward " << ward << ", Bed " << bed << ".\n";
        	} 
			else 
			{
            	cout << "Error: Sparse array storage limit reached. Cannot admit more patients.\n";
        	}
    	}

  
    	void dischargePatient(int ward, int bed) 	  // ADT Operation: Discharge a patient (remove item and shift remaining array elements)
		{
        	if (!isValid(ward, bed)) return;
        	int index = findBedIndex(ward, bed);

        	if (index != -1) 
			{
            	for (int i = index; i < currentOccupiedCount - 1; ++i) 	// Shift remaining elements left to fill the gap left by discharged patient
				{
                	occupiedList[i] = occupiedList[i + 1];
            	}
            	currentOccupiedCount--;
            	cout << "Patient discharged from Ward " << ward << ", Bed " << bed << ".\n";
        	} 
			else 
			{
            	cout << "Ward " << ward << ", Bed " << bed << " is already empty.\n";
        	}
    	}

    	string getOccupant(int ward, int bed) 	// ADT Operation: Read occupant value
		{
        	if (!isValid(ward, bed)) return "Invalid Coordinates";
        	int index = findBedIndex(ward, bed);
        
        	if (index != -1) 
			{
            	return occupiedList[index].patientId;
        	}
        	return "Empty Bed";
    	}

    
    	void displayOccupancyReport() 	// Output stats
		{
        	int totalBeds = totalWards * bedsPerWard;
        	double rate = ((double)currentOccupiedCount / totalBeds) * 100.0;

        	cout << "\n===============================\n";
        	cout << "   HOSPITAL OCCUPANCY REPORT   \n";
        	cout << "===============================\n";
        	cout << "Total Wards Available  : " << totalWards << "\n";
        	cout << "Beds Per Ward          : " << bedsPerWard << "\n";
        	cout << "Total Bed Capacity     : " << totalBeds << "\n";
        	cout << "Occupied Beds Total    : " << currentOccupiedCount << " / " << totalBeds << "\n";
        	cout << "Sparse Array Usage     : " << currentOccupiedCount << " / " << MAX_OCCUPIED << " slots used\n";
        	cout << "Current Occupancy Rate : " << rate << "%\n";
        	cout << "===============================\n";
    	}
};

int main() 
{
    int totalWards, bedsPerWard;
    
    cout << "=== Initialize Hospital Configuration ===\n";
    cout << "Enter total number of Wards: ";
    cin >> totalWards;
    cout << "Enter number of Beds per Ward: ";
    cin >> bedsPerWard;

    HospitalSparseMatrix hospital(totalWards, bedsPerWard);	// Construct the sparse matrix system

    int choice;
    do 
	{
        cout << "\n--- HOSPITAL ADT MANAGEMENT MENU ---\n";
        cout << "1. Allocate Bed (Admit Patient)\n";
        cout << "2. Discharge Patient\n";
        cout << "3. Search Bed Occupant\n";
        cout << "4. Generate Occupancy Report\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        int ward, bed;
        string patientId;

        switch (choice) 
		{
            case 1:
                cout << "Enter Ward Number: ";
                cin >> ward;
                cout << "Enter Bed Number: ";
                cin >> bed;
                cout << "Enter Patient ID: ";
                cin >> patientId;
                hospital.allocateBed(ward, bed, patientId);
                break;

            case 2:
                cout << "Enter Ward Number: ";
                cin >> ward;
                cout << "Enter Bed Number: ";
                cin >> bed;
                hospital.dischargePatient(ward, bed);
                break;

            case 3:
                cout << "Enter Ward Number: ";
                cin >> ward;
                cout << "Enter Bed Number: ";
                cin >> bed;
                cout << "Result: " << hospital.getOccupant(ward, bed) << "\n";
                break;

            case 4:
                hospital.displayOccupancyReport();
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