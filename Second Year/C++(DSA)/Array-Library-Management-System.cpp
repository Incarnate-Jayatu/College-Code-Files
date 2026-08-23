// Library Management System
#include <iostream>
#include <string>
#include<cctype>
using namespace std;

class ArrayLibrary {
private:
    struct Book {
        int isbn;
        string bookName;
        string authorName;
        string publisherName;
    };

    Book library[100];
    int count;

    void sortBooks() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {	
                if (library[j].isbn > library[j + 1].isbn) {
                    Book temp = library[j];
                    library[j] = library[j + 1];
                    library[j + 1] = temp;
                }
            }
        }
    }
    
    string toLower(string text) {
    	for(int i = 0; i < text.length(); i++) {
        	text[i] = tolower(text[i]);
    	}
    	return text;
	}

public:
    ArrayLibrary() {
        count = 0;
    }

    void addBook() {
        if (count == 100) {
            cout<<"Library is Full!\n";
            return;
        }
        cout<<"\nEnter ISBN: ";
        cin>>library[count].isbn;
        cin.ignore();
        cout<<"Enter Book Name: ";
        getline(cin, library[count].bookName);
        cout<<"Enter Author Name: ";
        getline(cin, library[count].authorName);
        cout<<"Enter Publisher Name: ";
        getline(cin, library[count].publisherName);
        count++;
        sortBooks();
        cout << "Book Added Successfully!\n";
    }

    void displayBooks() {
        if (count == 0) {
            cout << "\nNo Books Available!\n";
            return;
        }

        cout << "\n========== BOOK LIST ==========\n";

        for (int i = 0; i < count; i++) {
            cout<<"\nBook "<<i + 1<<endl;
            cout<<"ISBN      : "<<library[i].isbn<<endl;
            cout<<"Book Name : "<<library[i].bookName<<endl;
            cout<<"Author    : "<<library[i].authorName<<endl;
            cout<<"Publisher : "<<library[i].publisherName<<endl;
        }
    }

    void linearSearch() {
    	if(count == 0) {
        	cout<<"\nLibrary is Empty!\n";
        	return;
    	}
    	int choice;
    	cout<<"\nSearch By:";
    	cout<<"\n1. ISBN";
    	cout<<"\n2. Author Name";
    	cout<<"\n3. Publisher Name";
    	cout<<"\nEnter Choice: ";
    	cin>>choice;
    	cin.ignore();
    	bool found = false;
    	switch (choice) {
	    	case 1: {
    	    	int key;
        		cout<<"Enter ISBN: ";
        		cin>>key;
        		for(int i = 0; i < count; i++) {
    	        	if(library[i].isbn == key) {
	                	cout<<"\nBook Found!\n";
	                	cout<<"ISBN      : "<<library[i].isbn << endl;
    	        	    cout << "Book Name : "<<library[i].bookName << endl;
        		        cout<<"Author    : "<<library[i].authorName << endl;
    	    	        cout<<"Publisher : "<<library[i].publisherName << endl;
	            	    found = true;
            	    	break;
        	    	}
    	    	}
	        	break;
    		}
    		case 2: {
	        	string author;
    	    	cout<<"Enter Author Name: ";
        		getline(cin, author);
        		author = toLower(author);
	        	for(int i = 0; i < count; i++) {
    	        	if(toLower(library[i].authorName) == author) {
    	        		cout << "\n----------------------\n";
        	        	cout<<"\nBook Found!\n";
            	    	cout<<"ISBN      : "<<library[i].isbn << endl;
            		    cout<<"Book Name : "<<library[i].bookName << endl;
	        	        cout<<"Publisher : "<<library[i].publisherName << endl;
    		            found = true;
	    	        }
        		}
        		break;
    		}
    		case 3: {
        		string publisher;
        		cout<<"Enter Publisher Name: ";
        		getline(cin, publisher);
        		publisher = toLower(publisher);
        		for(int i = 0; i <count; i++) {
	            	if(toLower(library[i].publisherName) == publisher) {
	            		cout << "\n----------------------\n";
	                	cout<<"\nBook Found!\n";
	                	cout<<"ISBN      : "<<library[i].isbn << endl;
	                	cout<<"Book Name : "<<library[i].bookName << endl;
	                	cout<<"Author    : "<<library[i].authorName << endl;
	                	found = true;
	            	}
	        	}
	        	break;
	    	}
    		default:
	        	cout<<"Invalid Choice!\n";
	        	return;
	    	}
    		if(!found)
    		    cout<<"\nBook Not Found!\n";
		}

    void binarySearch() {
        int key;
        cout<<"\nEnter ISBN to Search: ";
        cin>>key;
        int low = 0, high = count - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (library[mid].isbn == key) {
                cout<<"\nBook Found!\n";
                cout<<"Book Name : "<<library[mid].bookName<<endl;
                cout<<"Author    : "<<library[mid].authorName<<endl;
                cout<<"Publisher : "<<library[mid].publisherName<<endl;
                return;
            }
            else if (key < library[mid].isbn)
                high = mid - 1;
            else
                low = mid + 1;
        }
        cout<<"Book Not Found!\n";
    }

    void modifyBook() {
        int key;
        cout<<"\nEnter ISBN of Book to Modify: ";
        cin>>key;
        cin.ignore();
        for (int i = 0; i < count; i++) {
            if (library[i].isbn == key) {
                cout<<"Enter New Book Name: ";
                getline(cin, library[i].bookName);
                cout<<"Enter New Author Name: ";
                getline(cin, library[i].authorName);
                cout<<"Enter New Publisher Name: ";
                getline(cin, library[i].publisherName);
                cout<<"Book Modified Successfully!\n";
                return;
            }
        }
        cout<<"Book Not Found!\n";
    }
};

int main() {
    int choice;
    ArrayLibrary arrlib;

    cout<<"========== LIBRARY MANAGEMENT SYSTEM ==========\n";
    do {
        cout<<"\n1. Add Book";
        cout<<"\n2. Display All Books";
        cout<<"\n3. Linear Search";
        cout<<"\n4. Binary Search";
        cout<<"\n5. Modify Book";
        cout<<"\n6. Exit";
        cout<<"\n\nEnter Your Choice: ";
        cin>>choice;
        switch (choice) {
        case 1:
            arrlib.addBook();
            break;
        case 2:
            arrlib.displayBooks();
            break;
        case 3:
            arrlib.linearSearch();
            break;
        case 4:
            arrlib.binarySearch();
            break;
        case 5:
            arrlib.modifyBook();
            break;
        case 6:
            cout<<"\nExiting Library Management System...\n";
            break;
        default:
            cout<<"Invalid Choice!\n";
            break;
        }
    } while (choice != 6);
    return 0;
}
