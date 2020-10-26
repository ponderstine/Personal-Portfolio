#include <iostream>

using namespace std;


struct Node{                    // A struct for the nodes of the the queue

    int key;                    // key is the main value for this node. Does not have to be an int.
    Node* next = NULL;          // next points to the next node in the queue. The next pointers point from rear to front.

};

class Queue{                    // A class for the methods and variables of the queue

    public:
    
    Queue();                    // Initiator
    Queue(int key);             // Initiator that creates a node with the value key passed in
    ~Queue();                   // Destructor
    int peek();                 // Peek returns the key value of the front node
    void enqueue(int key);      // Enqueues (adds) a new node to the rear of the queue
    void dequeue();             // Dequeues (deletes) the node at the front of the queue
    int size();                 // Returns the size (i.e number of nodes) in the queue
    bool isEmpty();             // Returns a bool for if the queue is empty or not

    private:

        int counter=0;          // a counter for the size of the queue
        Node* front = NULL;     // a pointer to the front of the queue (i.e the next node to be dequeued)
        Node* rear = NULL;      // a pointer to the rear of the queue (i.e the latest node to be enqueued)
};