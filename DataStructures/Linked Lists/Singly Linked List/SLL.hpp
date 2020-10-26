#include <iostream>

using namespace std;


struct Node{

    int key;        // key is the main value for this node. Does not have to be an int.
    Node* next = NULL;         // next is a pointer to the next node in the list.

};

class singlyLinkedList{

    public:

        singlyLinkedList();         // initiator function
        singlyLinkedList(int key);       // initiates the list with the head pointing to a node with the key passed in.
        ~singlyLinkedList();        // destructor function
        bool isEmpty();         // Returns a bool for if the linked list is empty or not
        int size();         // Returns an int of the size of the linked list.
        void addNode(int key);         // Adds a new node into the linked list
        void addNodeAfter(int key, int prevKey);         // Adds a new node after the node with the key prevKey.
        void deleteNode(int key);       // Deletes the Node with the key passed in.
        Node* searchForNode(int key);       // Searches for the node with the key passed in. Returns a pointer to the node with the key.
        void printList();           // Prints the linked list to the standard output.

    private:

        Node* head;         // points to the head node of the linked list.
};