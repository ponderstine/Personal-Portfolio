#include <iostream>

using namespace std;


struct Node{

    int key;        // key is the main value for this node. Does not have to be an int.
    Node* next = NULL;         // next is a pointer to the next node in the list.
    Node* prev = NULL;         // prev is a pointer to the previous node in the list.

};

class doublyLinkedList{

    public:

        doublyLinkedList();         // initiator function
        doublyLinkedList(int key);       // initiates the list with the head pointing to a node with the key passed in.
        ~doublyLinkedList();        // destructor function
        bool isEmpty();         // Returns a bool for if the linked list is empty or not
        int size();         // Returns an int of the size of the linked list.
        void addNode(int key);         // Adds a new node into the linked list
        void addNodeAfter(int key, int prevKey);         // Adds a new node after the node with the key prevKey.
        void deleteNode(int key);       // Deletes the Node with the key passed in.
        Node* searchForNode(int key);       // Searches for the node with the key passed in. Returns a pointer to the node with the key.
        void printListForward();           // Prints the linked list to the standard output from head to tail.
        void printListBackward();           // Prints the linked list to the standard output from tail to head.

    private:

        Node* head;         // Points to the head node of the linked list.
        Node* tail;         // Points to the tail node of the linked list.
};