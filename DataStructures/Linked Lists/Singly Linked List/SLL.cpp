#include "SLL.hpp"

/*
Initiator function: this function will a linked list with the head node pointing to NULL.
Inputs: None
Returns: None
*/
singlyLinkedList::singlyLinkedList(){
    head = NULL;
};

/*
Initiator function: this function will a linked list with the head node containing the key value passed in.
Inputs: int key
Returns: None
*/
singlyLinkedList::singlyLinkedList(int key){
    head = new Node;
    head->key = key;
};

/*
Destructor function: this function will delete all the nodes in the linked list.
Inputs: None
Returns: None
*/
singlyLinkedList::~singlyLinkedList(){
    
    // If linked list is empty then there is nothing to destruct and we can just return.
    if(isEmpty){
        return;
    }

    // Initiate a current and temporary pointer.
    Node* cur = head;
    Node* temp = NULL;

    // while cur pointer is not NULL, then there is a node to be deleted still.
    while(cur != NULL){

        // move up cur and temp pointers
        temp = cur;
        cur = cur->next;

        // delete temp pointer.
        delete temp;
    }
};

/*
isEmpty: this function will check if the linked list is empty or not.
Inputs: None
Returns: bool isEmpty (true -> linked list is empty; false -> linked list is not empty)
*/
bool singlyLinkedList::isEmpty(){
    
    // If head points to NULL, then there are no nodes in the linked list, the linked list is empty, and return true.
    if (head == NULL){
        return true;
    } else {
        // If head node does not point to NULL, there is a node, the linked list is not empty, and return false.
        return false;
    }
};

/*
size: this function will returns .
Inputs: None
Returns: int size (number of nodes in the linked list)
*/
int singlyLinkedList::size(){

    // if linked list is empty then return 0
    if (isEmpty()){
        return 0;
    }

    // initialize a node pointer, cur, to traverse the linked list and a counter variable.
    Node* cur = head;
    int count = 0;

    // while cur is not NULL (i.e we have not reached the end of the list) need to add to counter and traverse to next node
    while (cur != NULL){

        // add to counter
        count++;

        // traverse to next node
        cur = cur->next;
    }

    // function has traversed through whole linked list and can return the counter variable as the size of the linked list.
    return count;
};

/*
addNode: this function will add a new node at the end of the linked list with the key value passed in. If the linked list is empty, it will create a node with the key passed in and point the head to that new node.
Inputs: int key
Returns: None
*/
void singlyLinkedList::addNode(int key){

    // if linked list is empty then create a node with value key and point the head to that node. Then return.
    if (isEmpty()){
        head = new Node;
        head->key = key;
        return;
    }

    // Need to traverse to end of linked list. Initialize a node pointer, cur, to traverse
    Node* cur = head;

    while (cur->next != NULL){

        // traverse to next node.
        cur = cur->next;
    }

    // at this point, cur is pointing to the last node in the linked list.
    // need to create a new node after cur then return.
    cur->next = new Node;
    cur->next->key = key;
    return;
};

/*
addNode: this function will add a new node to the linked list with the key value passed in. The new node will be inserted after the node with the value prevKey. If there is not a node with value prevKey then the node will be inserted at the end of the linked list.
Inputs: int key
Returns: None
*/
void singlyLinkedList::addNodeAfter(int key, int prevKey){

    // if list is empty then the new node will be created at the end of the list. Since the linked list is empty, the head node will be the new node.
    if (isEmpty()){
        head = new Node;
        head->key = key;
        return;
    }

    // Need to traverse to end of linked list. Initialize a node pointer, cur, to traverse
    Node* cur = head;

    // While cur->next is not NULL (i.e cur is not the last node in the list) and the cur->key is not the key we want, we need to traverse more.
    while (cur->next != NULL && cur->key != key){

        // traverse to next node.
        cur = cur->next;
    }

    // at this point, cur is pointing to the last node in the linked list or to the node that will be before the new node.
    // need to create a new node after cur then return.

    // create the new node, nn, with the key passed in
    Node* nn = new Node;
    nn->key = key;

    // point nn next to the rest of the node (cur->next) then point cur to the new node to insert without memory leak.
    nn->next = cur->next;
    cur->next = nn;
    return;
};

/*
deleteNode: this function will delete the node from the linked list with the key value passed in.
Inputs: int key
Returns: None
*/
void singlyLinkedList::deleteNode(int key){

    // Check if the list is empty or not.
    if (isEmpty()){

        // if linked list is empty then print to standard out that list is empty and return.
        cout << "Linked list is empty." << endl;
        return;
    }

    // check if the head is the node to be deleted.
    if (head->key == key){
        if (head->next == NULL){
            // need to delete node and no other nodes in linked list to replace the head.
            head = NULL;
            return;
        }

        // need to delete head and move head to the second node.
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // create a node pointer, cur, to traverse through the list and a second node pointer, prev, pointing to the node before cur.
    Node* cur = head->next;
    Node* prev = head;
    while (cur != NULL){

        if (cur->key == key){
            // Found the node to be deleted.

            // move prev->next pointer to bypass the cur node to cur->next. Then can delete cur node with no memory leak or issues.
            prev->next = cur->next;
            delete cur;
            return;
        } else {
            // need to keep traversing to find correct node.

            // traverse to next node
            prev = cur;
            cur = cur->next;
        }
    }

    // Traversed through whole list and did not find the value so print to the standard output that the function did not find the desired node.
    cout << "Cannot find node with value " << key << " in this linked list." << endl;
    return;
};

/*
searchForNode: this function will search for the node with the key value passed in. The function returns a node pointer to the node with the key value passed in.
Inputs: int key
Returns: Node* foundNode
*/
Node* singlyLinkedList::searchForNode(int key){

    // Check if the list is empty or not.
    if (isEmpty()){

        // if linked list is empty then print to standard out that list is empty and return.
        cout << "Linked list is empty." << endl;
        return;
    }

    // create a node pointer, cur, to traverse through the list.
    Node* cur = head;
    while (cur != NULL){

        if (cur->key == key){
            // if the current node has the key that we are looking for then return the current node pointer.
            return cur;

        } else {

            // if the current node's key does not match the key we are looking for then continue traversing to next node.
            cur = cur->next;
        }
    }

    // Traversed through whole list and did not find the value so print to the standard output that the function did not find the desired node.
    cout << "Cannot find node with value " << key << " in this linked list." << endl;
    return;
};

/*
printList: this function will print the list to the standard output.
Inputs: None
Returns: None
*/
void singlyLinkedList::printList(){

    // Check if the list is empty or not.
    if (isEmpty()){

        // if linked list is empty then print to standard out that list is empty and return.
        cout << "Linked list is empty." << endl;
        return;
    }

    // Present a message before the list.
    cout << "Printing the linked list." << endl;

    // create a node pointer, cur, to traverse through the list.
    Node* cur = head;
    while (cur != NULL){

        // cout the value and an -> arrow between values to show the direction of the list.
        cout << cur->key << " -> ";

        // traverse to next node.
        cur = cur->next;
    }

    // after the function has traversed the whole list, end the line for the standard out and return.
    cout << endl;
    return;
};
