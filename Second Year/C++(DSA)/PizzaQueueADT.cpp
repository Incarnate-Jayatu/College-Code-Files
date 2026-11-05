//Pizza Parlour Order Management (Queue ADT)
#include<iostream>
#include<string>
using namespace std;

struct Order{
    int orderNumber;
    string customerName;
    string pizzaDetails;
};

class PizzaQueue{
private:
    Order* queue;
    int front;
    int rear;
    int capacity;
    int currentSize;

public:
    PizzaQueue(int maxCapacity){
        capacity = maxCapacity;
        queue = new Order[capacity];
        front = 0;
        rear = -1;
        currentSize = 0;
    }

    ~PizzaQueue(){
        delete[] queue;
    }

    bool isFull(){
        return currentSize == capacity;
    }

    bool isEmpty(){
        return currentSize == 0;
    }

    void acceptOrder(int id, string name, string details){
        if (isFull()){
            cout << "\nError: Cannot accept order. The pizza parlour queue is FULL!\n";
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = {id, name, details};
        currentSize++;
        cout << "\nSuccess: Order #" << id << " for " << name << " has been added to the queue.\n";
    }

    void deliverOrder(){
        if (isEmpty()){
            cout << "\nError: No orders to deliver. The queue is EMPTY!\n";
            return;
        }
        Order deliveredOrder = queue[front];
        front = (front + 1) % capacity;
        currentSize--;
        cout << "\n--- Delivering Order ---\n";
        cout << "Order Number : " << deliveredOrder.orderNumber << "\n";
        cout << "Customer Name: " << deliveredOrder.customerName << "\n";
        cout << "Pizza Details: " << deliveredOrder.pizzaDetails << "\n";
        cout << "------------------------\n";
    }

    void displayWaitingOrders(){
        if (isEmpty()) {
            cout << "\nThere are currently no pending orders in the queue.\n";
            return;
        }
        cout << "\n======= PENDING ORDERS (FIFO Order) =======\n";
        int index = front;
        for (int i = 0; i < currentSize; i++) {
            cout << "Position: " << (i + 1) 
                 << " | Order #" << queue[index].orderNumber 
                 << " | Name: " << queue[index].customerName 
                 << " | Pizza: " << queue[index].pizzaDetails << "\n";
            
            // Move to next logical index in a circular fashion
            index = (index + 1) % capacity;
        }
        cout << "===========================================\n";
    }
};

int main(){
    int maxCapacity;
    cout << "Enter the maximum order capacity for the pizza parlour: ";
    if (!(cin >> maxCapacity) || maxCapacity <= 0) {
        cout << "Invalid capacity. Exiting program.\n";
        return 1;
    }
    PizzaQueue parlourQueue(maxCapacity);
    int choice;
    do{
        cout << "\n*** PIZZA PARLOUR ORDER MANAGEMENT ***\n";
        cout << "1. Accept Order\n";
        cout << "2. Deliver Order\n";
        cout << "3. Display Waiting Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        switch (choice){
            case 1:
                int id;
                string name, details;
                cout << "Enter Unique Order Number: ";
                cin >> id;
                cin.ignore();                
                cout << "Enter Customer Name: ";
                getline(cin, name);                
                cout << "Enter Pizza Details: ";
                getline(cin, details);
                parlourQueue.acceptOrder(id, name, details);
                break;
            case 2:
                parlourQueue.deliverOrder();
                break;
            case 3:
                parlourQueue.displayWaitingOrders();
                break;
            case 4:
                cout << "\nExiting program. Thank you!\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 4);
    return 0;
}