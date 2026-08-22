//Program 9
/*Use a Sparse Matrix ADT to store only occupied rack locations in a warehouse. */
#include <iostream>
#include <string>

using namespace std;

const int MAX_OCCUPIED_RACKS = 200;		// Maximum capacity limit for warehouse storage tracking array

struct OccupiedRack 	// Structure to store a single occupied rack coordinate
{
    int aisle;
    int layer;
    string palletId;
};

class WarehouseSparseMatrix 
{
	private:
    	int totalAisles;
    	int layersPerAisle;
    
    	OccupiedRack occupiedList[MAX_OCCUPIED_RACKS]; 	    // Fixed-size array tracking only occupied locations
    	int currentOccupiedCount;

    	int findRackIndex(int aisle, int layer) 	    // Helper to find the array index of a specific rack slot
		{
        	for (int i = 0; i < currentOccupiedCount; ++i) 
			{
            	if (occupiedList[i].aisle == aisle && occupiedList[i].layer == layer) 
				{
                	return i; // Target location found
            	}
        	}
        	return -1; // Target location is empty
    	}

    	bool isValid(int aisle, int layer) 	// Helper to validate rack physical boundaries without exceptions
		{
        	if (aisle < 0 || aisle >= totalAisles || layer < 0 || layer >= layersPerAisle) 
			{
            	cout << "Error: Out of warehouse physical bounds (Aisle: " << aisle << ", Layer: " << layer << ").\n";
            	return false;
        	}
        	return true;
    	}

	public:
    	WarehouseSparseMatrix(int aisles, int layers) 	// Constructor
		{
        	totalAisles = aisles;
        	layersPerAisle = layers;
        	currentOccupiedCount = 0;
    	}

    	void storePallet(int aisle, int layer, string palletId) 	    // ADT Operation: Place Pallet / Stock on a specific rack
		{
        	if (!isValid(aisle, layer)) return;
        	int index = findRackIndex(aisle, layer);

        	if (index != -1) 	// Scenario 1: Location is occupied, overwrite with new stock data
			{
	            occupiedList[index].palletId = palletId;
	            cout << "Location updated. Existing stock replaced with Pallet \"" << palletId << "\" at Aisle " << aisle << ", Layer " << layer << ".\n";
    	        return;
	        }

        
        	if (currentOccupiedCount < MAX_OCCUPIED_RACKS)	// Scenario 2: Location is empty, add entry to the end of the collection
			{
            	occupiedList[currentOccupiedCount].aisle = aisle;
            	occupiedList[currentOccupiedCount].layer = layer;
            	occupiedList[currentOccupiedCount].palletId = palletId;
            	currentOccupiedCount++;
            	cout << "Pallet \"" << palletId << "\" registered successfully at Aisle " << aisle << ", Layer " << layer << ".\n";
        	} 
			else 
			{
            	cout << "Error: Storage system tracking limit reached. Cannot accept more pallets.\n";
        	}
    	}

    
    	void removePallet(int aisle, int layer) 	// ADT Operation: Remove Pallet (Free the structural slot and shift array elements)
		{
        	if (!isValid(aisle, layer)) return;
        	int index = findRackIndex(aisle, layer);

        	if (index != -1) 
			{
            	string removedPallet = occupiedList[index].palletId;
            	for (int i = index; i < currentOccupiedCount - 1; ++i) 	            // Shift remaining elements left to maintain array continuity	
				{
                	occupiedList[i] = occupiedList[i + 1];
            	}
            	currentOccupiedCount--;
            	cout << "Pallet \"" << removedPallet << "\" successfully dispatched from Aisle " << aisle << ", Layer " << layer << ".\n";
        	} 
			else 
			{
            	cout << "Aisle " << aisle << ", Layer " << layer << " is already vacant.\n";
        	}
    	}

    
    	string checkRack(int aisle, int layer) 	// ADT Operation: Search / Retrieve stock identifier
		{
        	if (!isValid(aisle, layer)) return "Invalid Location";
        	int index = findRackIndex(aisle, layer);
        	if (index != -1) 
			{
	            return "Occupied by [" + occupiedList[index].palletId + "]";
    	    }
        	return "Vacant Slot";
    	}

    
    	void displayLogisticsReport()	// Output warehouse space utilization statistics 
		{
        	int totalRacks = totalAisles * layersPerAisle;
        	double utilization = ((double)currentOccupiedCount / totalRacks) * 100.0;

        	cout << "\n====================================\n";
        	cout << "   WAREHOUSE CONFIGURATION & LOGS   \n";
        	cout << "====================================\n";
        	cout << "Total Layout Aisles    : " << totalAisles << "\n";
        	cout << "Layers Per Aisle       : " << layersPerAisle << "\n";
        	cout << "Total Virtual Racks    : " << totalRacks << "\n";
        	cout << "Physically Occupied    : " << currentOccupiedCount << " / " << totalRacks << "\n";
        	cout << "Tracking Array Load    : " << currentOccupiedCount << " / " << MAX_OCCUPIED_RACKS << " slots\n";
        	cout << "Warehouse Utilization  : " << utilization << "%\n";
        	cout << "====================================\n";
    	}
};

int main() 
{
    int totalAisles, layersPerAisle;
    cout << "=== Initialize Warehouse Matrix System ===\n";
    cout << "Enter total number of Aisles: ";
    cin >> totalAisles;
    cout << "Enter number of Rack Layers per Aisle: ";
    cin >> layersPerAisle;
    WarehouseSparseMatrix warehouse(totalAisles, layersPerAisle);	  // Instantiate Sparse Matrix System

    int choice;
    do 
	{
        cout << "\n--- WAREHOUSE MANAGEMENT SYSTEM MENU ---\n";
        cout << "1. Store Pallet (Occupy Rack)\n";
        cout << "2. Dispatch Pallet (Vacate Rack)\n";
        cout << "3. Inspect Rack Location\n";
        cout << "4. Generate Warehouse Logistics Report\n";
        cout << "5. Exit System\n";
        cout << "Enter choice (1-5): ";
        cin >> choice;

        int aisle, layer;
        string palletId;

        switch (choice) 
		{
            case 1:
                cout << "Enter Target Aisle: ";
                cin >> aisle;
                cout << "Enter Target Layer: ";
                cin >> layer;
                cout << "Enter Pallet ID/SKU Code: ";
                cin >> palletId;
                warehouse.storePallet(aisle, layer, palletId);
                break;

            case 2:
                cout << "Enter Target Aisle: ";
                cin >> aisle;
                cout << "Enter Target Layer: ";
                cin >> layer;
                warehouse.removePallet(aisle, layer);
                break;

            case 3:
                cout << "Enter Target Aisle: ";
                cin >> aisle;
                cout << "Enter Target Layer: ";
                cin >> layer;
                cout << "Status: " << warehouse.checkRack(aisle, layer) << "\n";
                break;

            case 4:
                warehouse.displayLogisticsReport();
                break;

            case 5:
                cout << "Exiting logistics database application. System shutdown complete.\n";
                break;

            default:
                cout << "Invalid choice selection! Please choose an option from 1 to 5.\n";
        }
    } while (choice != 5);

    return 0;
}
