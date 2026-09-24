#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node* head;
public:
    LinkedList()
    {
        head = NULL;
    }
    
    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Node inserted successfully." << endl;
    }
    
    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            cout << "Node inserted successfully." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Node inserted successfully." << endl;
    }
    
    void insertSorted(int value)
    {
        Node* newNode = new Node(value);
        if (head == NULL || value <= head->data)
        {
            newNode->next = head;
            head = newNode;
            cout << "Node inserted successfully in sorted order." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data < value)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node inserted successfully in sorted order." << endl;
    }
    
    void display()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List:" << endl;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    void search(int value)
    {
        if (head == NULL)
        {
            cout << "Linked List is empty." << endl;
            return;
        }
        Node* temp = head;
        int position = 1;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                cout << "Element " << value
                     << " found at position "
                     << position << "." << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Element " << value << " not found." << endl;
    }
};

int main()
{
    LinkedList list;
    int choice;
    int value;
    do
    {
        cout << "\n------ Singly Linked List ------" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert in Sorted Order" << endl;
        cout << "4. Display" << endl;
        cout << "5. Search" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter value: ";
            cin >> value;
            list.insertSorted(value);
            break;
        case 4:
            list.display();
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}