#include <iostream>
#define SIZE 15
using namespace std;

class Deque {
public:
    int a[SIZE], front, rear;

    Deque() {
        front = rear = -1;
    }

    void add_at_end(int item) {
        if ((rear + 1) % SIZE == front) {  // Check for overflow
            cout << "\nInsertion is not possible, overflow!!!";
        } else {
            if (front == -1) {  // Empty deque
                front = rear = 0;
            } else {
                rear = (rear + 1) % SIZE;
            }
            a[rear] = item;
            cout << "\nInserted item at rear: " << a[rear];
        }
    }

    void add_at_beg(int item) {
        if ((front - 1 + SIZE) % SIZE == rear) {  // Check for overflow
            cout << "\nInsertion at the beginning is not possible, overflow!!!";
        } else {
            if (front == -1) {  // Empty deque
                front = rear = 0;
            } else {
                front = (front - 1 + SIZE) % SIZE;
            }
            a[front] = item;
            cout << "\nInserted item at front: " << a[front];
        }
    }

    void display() {
        if (front == -1) {
            cout << "\nDeque is empty";
        } else {
            cout << "\nElements in Deque are: ";
            int i = front;
            while (true) {
                cout << a[i] << " ";
                if (i == rear) break;
                i = (i + 1) % SIZE;
            }
        }
    }

    void delete_fr_front() {
        if (front == -1) {
            cout << "\nDeletion is not possible, Deque is empty";
        } else {
            cout << "\nThe deleted element from front is: " << a[front];
            if (front == rear) {  // Only one element was present
                front = rear = -1;
            } else {
                front = (front + 1) % SIZE;
            }
        }
    }

    void delete_fr_rear() {
        if (front == -1) {
            cout << "\nDeletion is not possible, Deque is empty";
        } else {
            cout << "\nThe deleted element from rear is: " << a[rear];
            if (front == rear) {  // Only one element was present
                front = rear = -1;
            } else {
                rear = (rear - 1 + SIZE) % SIZE;
            }
        }
    }
};

int main() {
    int c, item;
    Deque d1;

    do {
        cout << "\n\nDeque OPERATION\n";
        cout << "1] Insert at beginning\n";
        cout << "2] Insert at end\n";
        cout << "3] Display\n";
        cout << "4] Deletion from front\n";
        cout << "5] Deletion from rear\n";
        cout << "6] Exit\n";
        cout << "Enter your choice: ";
        cin >> c;

        switch (c) {
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> item;
                d1.add_at_beg(item);
                break;

            case 2:
                cout << "Enter the element to be inserted: ";
                cin >> item;
                d1.add_at_end(item);
                break;

            case 3:
                d1.display();
                break;

            case 4:
                d1.delete_fr_front();
                break;

            case 5:
                d1.delete_fr_rear();
                break;

            case 6:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
                break;
        }
    } while (c != 6);

    return 0;
}
