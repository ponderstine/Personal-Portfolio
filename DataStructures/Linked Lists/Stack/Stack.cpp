#include "Stack.hpp"

/*
Initiator: initiates the stack with the front and rear pointing to NULL and the size counter equalling zero.
Inputs: None
Returns: None
*/
Stack::Stack(){
    top = NULL;
    counter = 0;
};

/*
Initiator: initiates the stack with the front and rear pointing to a node with the key passed in and the size counter equalling one.
Inputs: int key
Returns: None
*/
Stack::Stack(int key){
    top = new Node;
    top->key = key;
    counter = 1;
};

/*
Destructor: destroys the stack by popping off every node in the stack.
Inputs: None
Returns: None
*/
Stack::~Stack(){

    // if stack is empty then nothing to destruct, so return.
    if(isEmpty()){
        return;
    }

    // since we know the size of the stack, we know how many times to pop off the front.
    for (int i = 0; i < counter; i++){
        pop();
    }

    // reset the counter to zero
    counter = 0;
    top = NULL;
    return;
};

/*
peek: peek at the top value in the stack.
Inputs: None
Returns: int topVal
*/
int Stack::peek(){

    // If stack is empty then there is nothing to peek and we can just return.
    if(isEmpty){
        cout << "stack is empty, cannot peek." << endl;
        return;
    }
    
    // just need to return the key of the front node
    return top->key;
};

/*
push: pushes (creates) a new node, with the key passied in, to the back of the stack.
Inputs: int key
Returns: None
*/
void Stack::push(int key){

    // If stack is empty then both the front and rear will point to the new node created.
    if(isEmpty){
        top = new Node;
        top->key = key;
        counter = 1;
        return;
    }

    // create new node, nn, with the key value passed in
    Node* nn = new Node;
    nn->key = key;

    // the new node's next pointer will point to what was the top node
    nn->next = top;
    top = nn;
    counter++;
    return;
};

/*
pop: pop (deletes) the front node off of the front of the stack.
Inputs: None
Returns: None
*/
void Stack::pop(){

    // If stack is empty then there is nothing to pop and we can just return.
    if(isEmpty){
        cout << "stack is empty, cannot pop." << endl;
        return;
    }

    // initialize a temporary pointer to point to the node being popped
    Node* temp = top;

    // assing the top pointer to the new top
    top = top->next;

    // delete the node being popped, iterate size counter, and return.
    delete temp;
    counter--;
    return;
};

/*
size: gives the size (i.e number of nodes) in the stack.
Inputs: None
Returns: int size
*/
int Stack::size(){

    // just needs to return the counter size value.
    return counter;
};

/*
isEmpty: checks if the stack is empty or not
Inputs: None
Returns: bool isEmpty (true -> stack is empty; false -> stack is not empty)
*/
bool Stack::isEmpty(){

    // if count/size is 0 then stack is empty and return true
    if (counter == 0){
        return true;
    } else {
        // if count/size is not 0 then stack is not empty and return false
        return false;
    }
};