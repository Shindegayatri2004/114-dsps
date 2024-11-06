#include <iostream>
using namespace std;

class PizzaParlor {
    int front, rear, size;
    int maxOrders;
    int* queue;
    
public:
    PizzaParlor(int maxOrders) {
        this->maxOrders = maxOrders;
        queue = new int[maxOrders];
        front = -1;
        rear = -1;
        size = 0;
    }
    
    ~PizzaParlor() {
        delete[] queue;
    }
    
    // Check if the queue is full
    bool isFull() {
        return (rear + 1) % maxOrders == front;
    }
    
    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }
    
    // Add an order to the queue
    void placeOrder(int orderNumber) {
        if (isFull()) {
            cout << "Pizza parlor is full. Cannot accept more orders." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxOrders;
        }
        queue[rear] = orderNumber;
        cout << "Order " << orderNumber << " placed." << endl;
    }
    
    // Serve the next order in the queue
    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve." << endl;
            return;
        }
        cout << "Serving order " << queue[front] << endl;
        if (front == rear) {
            front = rear = -1;  // Queue is now empty
        } else {
            front = (front + 1) % maxOrders;
        }
    }
    
    // Display all current orders in the queue
    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue." << endl;
            return;
        }
        cout << "Current orders: ";
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % maxOrders;
        }
        cout << queue[rear] << endl;  // Print the last order
    }
};

int main() {
    int M;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> M;

    PizzaParlor parlor(M);
    
    int choice, orderNumber = 1;
    
    do {
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                parlor.placeOrder(orderNumber++);
                break;
            case 2:
                parlor.serveOrder();
                break;
            case 3:
                parlor.displayOrders();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
} 
