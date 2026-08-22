//Program 10
/*Store student attendance over a semester as a sparse matrix since many entries 
remain absent or unrecorded initially.*/
#include <iostream>
#include <string>

using namespace std;
const int MAX_ATTENDANCE_RECORDS = 500;	// Maximum capacity limit for the sparse array tracking active records


struct AttendanceRecord // Structure to store a single positive attendance log entry
{
    int studentId;
    int dayIndex;
    string status; // "Present", "Late", "Excused"
};

class AttendanceSparseMatrix 
{
	private:
    	int totalStudents;
    	int totalDays;
    
    	AttendanceRecord recordList[MAX_ATTENDANCE_RECORDS]; 	    // Fixed size array storing only recorded entries
    	int currentRecordCount;

	    int findRecordIndex(int studentId, int dayIndex) 	    // Helper to find the array index of a specific student on a given day
		{
       		for (int i = 0; i < currentRecordCount; ++i) 
			{
            	if (recordList[i].studentId == studentId && recordList[i].dayIndex == dayIndex) 
				{
                	return i; // Found active record
            	}
        	}
        	return -1; // Unrecorded / Absent
    	}

    
    	bool isValid(int studentId, int dayIndex)	// Helper to validate boundaries without using exceptions 
		{
        	if (studentId < 0 || studentId >= totalStudents || dayIndex < 0 || dayIndex >= totalDays) 
			{
	            cout << "Error: Invalid criteria (Student ID: " << studentId << ", Lecture Day: " << dayIndex << ").\n";
    	        return false;
        	}
        	return true;
    	}

	public:
    	AttendanceSparseMatrix(int students, int days) 	// Constructor
		{
        	totalStudents = students;
        	totalDays = days;
        	currentRecordCount = 0;
    	}

    	void markAttendance(int studentId, int dayIndex, string status) 	// ADT Operation: Mark or update student attendance
		{
        	if (!isValid(studentId, dayIndex)) return;
        	int index = findRecordIndex(studentId, dayIndex);

        
        	if (index != -1) 	// Scenario 1: Record exists, update the status
			{
            	recordList[index].status = status;
            	cout << "Attendance updated to " << status << " for Student " << studentId << " on Day " << dayIndex << ".\n";
            	return;
        	}

        
        	if (currentRecordCount < MAX_ATTENDANCE_RECORDS)	// Scenario 2: New positive attendance entry, append to list 
			{
            	recordList[currentRecordCount].studentId = studentId;
            	recordList[currentRecordCount].dayIndex = dayIndex;
            	recordList[currentRecordCount].status = status;
            	currentRecordCount++;
            	cout << "Attendance (" << status << ") recorded for Student " << studentId << " on Day " << dayIndex << ".\n";
        	} 
			else 
			{
            	cout << "Error: Storage capacity limit reached. Cannot log more attendance data.\n";
        	}
    	}

    	void clearRecord(int studentId, int dayIndex) 	// ADT Operation: Remove a record (Treat student as Absent/Unrecorded)
		{
        	if (!isValid(studentId, dayIndex)) return;
        	int index = findRecordIndex(studentId, dayIndex);

        	if (index != -1) 
			{
            	for (int i = index; i < currentRecordCount - 1; ++i) 	// Shift elements left to maintain array compactness
				{
                	recordList[i] = recordList[i + 1];
            	}
            	currentRecordCount--;
            	cout << "Record cleared. Student " << studentId << " on Day " << dayIndex << " is now marked Absent.\n";
        	} 
			else 
			{
            	cout << "Student " << studentId << " on Day " << dayIndex << " is already unrecorded (Absent).\n";
        	}
    	}

    
    	string getAttendance(int studentId, int dayIndex) 	// ADT Operation: Fetch attendance status
		{
        	if (!isValid(studentId, dayIndex)) return "Invalid Inputs";
        	int index = findRecordIndex(studentId, dayIndex);
        	if (index != -1) 
			{
            	return recordList[index].status;
        	}
        	return "Absent / Unrecorded";
    	}

    
    	void displayMetricsReport() 	// Output overall tracking analytics
		{
	        int totalPossibleEntries = totalStudents * totalDays;
    	    double presenceRate = ((double)currentRecordCount / totalPossibleEntries) * 100.0;

        	cout << "\n====================================\n";
        	cout << "   ACADEMIC ATTENDANCE METRICS       \n";
        	cout << "====================================\n";
        	cout << "Total Tracked Students : " << totalStudents << "\n";
        	cout << "Total Semester Days    : " << totalDays << "\n";
        	cout << "Total Possible Matrix Slots : " << totalPossibleEntries << "\n";
        	cout << "Positive Records Logged: " << currentRecordCount << " / " << totalPossibleEntries << "\n";
        	cout << "Sparse Array Allocation: " << currentRecordCount << " / " << MAX_ATTENDANCE_RECORDS << " slots used\n";
        	cout << "Overall Attendance Rate: " << presenceRate << "%\n";
        	cout << "====================================\n";
    	}
};

int main() 
{
    int totalStudents, totalDays;
    
    cout << "=== Initialize Attendance Tracking Matrix ===\n";
    cout << "Enter total number of Students: ";
    cin >> totalStudents;
    cout << "Enter total number of Academic Days in Semester: ";
    cin >> totalDays;

    
    AttendanceSparseMatrix tracker(totalStudents, totalDays);	// Construct the sparse matrix tracker

    int choice;
    do 
	{
        cout << "\n--- ATTENDANCE ADT REGISTRY MENU ---\n";
        cout << "1. Mark Attendance (Present / Late / Excused)\n";
        cout << "2. Clear Attendance Record (Set to Absent)\n";
        cout << "3. Check Student Status\n";
        cout << "4. Generate Semester Summary Report\n";
        cout << "5. Exit\n";
        cout << "Enter choice (1-5): ";
        cin >> choice;

        int studentId, dayIndex;
        string status;

        switch (choice) 
		{
            case 1:
                cout << "Enter Student ID (0 to " << totalStudents - 1 << "): ";
                cin >> studentId;
                cout << "Enter Day Index (0 to " << totalDays - 1 << "): ";
                cin >> dayIndex;
                cout << "Enter Status (Present/Late/Excused): ";
                cin >> status;
                tracker.markAttendance(studentId, dayIndex, status);
                break;

            case 2:
                cout << "Enter Student ID: ";
                cin >> studentId;
                cout << "Enter Day Index: ";
                cin >> dayIndex;
                tracker.clearRecord(studentId, dayIndex);
                break;

            case 3:
                cout << "Enter Student ID: ";
                cin >> studentId;
                cout << "Enter Day Index: ";
                cin >> dayIndex;
                cout << "Status: " << tracker.getAttendance(studentId, dayIndex) << "\n";
                break;

            case 4:
                tracker.displayMetricsReport();
                break;

            case 5:
                cout << "Closing attendance registry application.\n";
                break;

            default:
                cout << "Invalid selection! Please enter a menu number from 1 to 5.\n";
        }
    } while (choice != 5);
    return 0;
}