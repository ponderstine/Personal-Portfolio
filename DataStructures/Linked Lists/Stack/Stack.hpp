#include <iostream>

using namespace std;


struct Node{                    // A struct for the nodes of the the stack

    int key;                    // key is the main value for this node. Does not have to be an int.
    Node* next = NULL;          // next points to the next node in the stack. The next pointers point from the top down.

};

class Stack{                    // A class for the methods and variables of the stack

    public:
    
    Stack();                    // Initiator
    Stack(int key);             // Initiator that creates a node with the value key passed in
    ~Stack();                   // Destructor
    int peek();                 // Peek returns the key value of the front node
    void push(int key);         // Pushes (adds) a new node to the top of the stack
    void pop();                 // Pops (deletes) the node at the top of the stack
    int size();                 // Returns the size (i.e number of nodes) in the stack
    bool isEmpty();             // Returns a bool for if the stack is empty or not

    private:

        int counter=0;          // a counter for the size of the stack
        Node* top = NULL;       // a pointer to the top of the stack (i.e the next node to be destackd)
};