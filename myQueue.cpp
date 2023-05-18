#include <iostream>
using namespace std;

// Node structure for the queue
struct Node
{
    int data;
    Node *next;
};

class MyQueue
{
private:
    Node *front, *rear; // Front and rear pointer for queue
public:
    MyQueue()
    { // Constructor to initialize front and rear pointer
        front = rear = NULL;
    }
    // Function to add element to queue
    void enqueue(int element)
    {
        Node *newNode = new Node;
        newNode->data = element;
        newNode->next = NULL;
        // If queue is empty, make both pointers point to new node
        if (front == NULL && rear == NULL)
        {
            front = rear = newNode;
            return;
        }
        // Add new node at the end of queue
        rear->next = newNode;
        rear = newNode;
    }
    // Function to remove element from queue
    int dequeue()
    {
        if (front == NULL)
        { // If queue is empty
            cout << "Queue is empty" << endl;
            return -1;
        }
        int dequeuedElement = front->data; // Store data of front element to be dequeued
        Node *temp = front;                // Store address of front node
        front = front->next;               // Update front pointer
        if (front == NULL)
        {                // If queue is now empty after dequeuing
            rear = NULL; // Update rear pointer
        }
        delete temp;            // Delete node
        return dequeuedElement; // Return dequeued element
    }
    // Function to display elements of queue
    void display()
    {
        if (front == NULL)
        { // If queue is empty
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = front;
        cout << "Elements in queue are: " << endl;
        while (temp != NULL)
        { // Traverse queue and print elements
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    MyQueue q; // Creating object of MyQueue class
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.display();
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
