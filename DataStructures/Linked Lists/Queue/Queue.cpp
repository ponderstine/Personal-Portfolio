#include "Queue.hpp"

/*
Initiator: initiates the Queue with the front and rear pointing to NULL and the size counter equalling zero.
Inputs: None
Returns: None
*/
Queue::Queue(){
    front = NULL;
    rear = NULL;
    counter = 0;
};

/*
Initiator: initiates the Queue with the front and rear pointing to a node with the key passed in and the size counter equalling one.
Inputs: int key
Returns: None
*/
Queue::Queue(int key){
    front = new Node;
    front->key = key;
    rear = front;
    counter = 1;
};

/*
Destructor: destroys the Queue by popping off every node in the queue.
Inputs: None
Returns: None
*/
Queue::~Queue(){

    // if Queue is empty then nothing to destruct, so return.
    if(isEmpty()){
        return;
    }

    // since we know the size of the queue, we know how many times to pop off the front.
    for (int i = 0; i < counter; i++){
        dequeue();
    }

    // reset the counter to zero
    counter = 0;
    front = NULL;
    rear = NULL;
    return;
};

/*
peek: peek at the top value in the Queue.
Inputs: None
Returns: int topVal
*/
int Queue::peek(){

    // If queue is empty then there is nothing to peek and we can just return.
    if(isEmpty){
        cout << "Queue is empty, cannot peek." << endl;
        return;
    }
    
    // just need to return the key of the front node
    return front->key;
};

/*
enqueue: enqueues (creates) a new node, with the key passied in, to the back of the queue.
Inputs: int key
Returns: None
*/
void Queue::enqueue(int key){

    // If queue is empty then both the front and rear will point to the new node created.
    if(isEmpty){
        front = new Node;
        rear = front;
        front->key = key;
        return;
    }

    // create new node, nn, with the key value passed in
    Node* nn = new Node;
    nn->key = key;

    // the new node's next pointer will point to what was the rear node
    nn->next = rear;

    // repoint the rear to the node that was just added, and return
    rear = nn;
    return;
};

/*
dequeue: dequeues (deletes) the front node off of the front of the queue.
Inputs: None
Returns: None
*/
void Queue::dequeue(){

    // If queue is empty then there is nothing to peek and we can just return.
    if(isEmpty){
        cout << "Queue is empty, cannot dequeue." << endl;
        return;
    }

    // create node pointer, cur, to traverse to second-from-front node
    Node* cur = rear;
    while(cur->next != front){

        // While we are not at the second-from-front node (i.e the next node is not the front) we need to traverse to the next node
        cur = cur->next;
    }

    // cur is pointing to second-from-front node. Need to delete front and point front to cur.
    delete front;
    front = cur;
    cur->next = NULL;
    return;
};

/*
size: gives the size (i.e number of nodes) in the queue.
Inputs: None
Returns: int size
*/
int Queue::size(){

    // just needs to return the counter size value.
    return counter;
};

/*
isEmpty: checks if the queue is empty or not
Inputs: None
Returns: bool isEmpty (true -> queue is empty; false -> queue is not empty)
*/
bool Queue::isEmpty(){

    // if count/size is 0 then Queue is empty and return true
    if (counter == 0){
        return true;
    } else {
        // if count/size is not 0 then Queue is not empty and return false
        return false;
    }
};